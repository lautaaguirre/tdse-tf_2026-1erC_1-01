/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 *
 */

/********************** inclusions *******************************************/
#include <task_pwm.h>
#include "main.h"
#include "logger.h"
#include "dwt.h"
#include "board.h"

#include "task_system_interface.h"
#include "task_system_normal.h"
#include "task_system_setup.h"
#include "task_system_falla.h"
#include "task_display_interface.h"

/********************** macros and definitions *******************************/
/* Cantidad de modos de sistema que vamos a soportar (uno por cada modo definido) */
#define SYSTEM_DTA_QTY MODE_QTY

/********************** internal data declaration ****************************/
/* Vector que almacena el estado y las variables de control de cada modo */
static task_system_dta_t task_system_dta_list[SYSTEM_DTA_QTY];

/* Variable que define en qué modo de funcionamiento está el sistema actualmente */
static task_system_mode_t g_task_system_mode;

/********************** external functions definition ************************/

/*
 * Inicializa la tarea de sistema: limpia las variables de estado
 * y decide con qué modo arrancamos según el hardware (DIP Switch).
 */
void task_system_init(void *parameters)
{
    uint32_t index;

    LOGGER_INFO("  task_system is running - Tick [mS] = %lu", HAL_GetTick());

    /* Inicializamos la cola de eventos propia de la capa de sistema */
    init_event_task_system();

    /*
     * Recorremos la lista de datos del sistema para limpiar la memoria RAM
     * y evitar que arranque con valores aleatorios (basura).
     */
    for (index = 0; index < SYSTEM_DTA_QTY; index++)
    {
        task_system_dta_list[index].state = ST_SYS_IDLE;
        task_system_dta_list[index].event = EV_SYS_IDLE;
        task_system_dta_list[index].flag  = false;
        task_system_dta_list[index].tick  = 0;
    }

    /*
     * Lectura inicial del hardware (DIP Switch) para definir
     * si arrancamos en modo configuración o en modo operación normal.
     */
    if (HAL_GPIO_ReadPin(DIP_SW_GPIO_Port, DIP_SW_Pin) == GPIO_PIN_SET)
    {
    	task_system_set_mode(SETUP);
    }
    else
    {
        /* Mensajes iniciales que mandamos al display antes de arrancar */
    	put_event_task_display(0, 0, "MODO NORMAL     ");
    	put_event_task_display(0, 1, "ENTER: EMPEZAR  ");
    	task_system_set_mode(NORMAL);
    }
}

/*
 * Se ejecuta en cada ciclo de la tarea. Se encarga de derivar la
 * ejecución hacia la máquina de estados que corresponda según el modo actual.
 */
void task_system_update(void *parameters)
{
    /*
     * Enrutador de modos: según el modo en el que esté la aspiradora,
     * llamamos a su máquina de estados correspondiente.
     */
    switch (g_task_system_mode)
    {
        case NORMAL:
            /* Modo de operación normal (aspirando) */
            task_system_normal_statechart(&task_system_dta_list[NORMAL]);
            break;

        case SETUP:
            /* Modo configuración, se entra con el DIP Switch en ON */
            task_system_setup_statechart(&task_system_dta_list[SETUP]);
            break;

        case FALLA:
            /* Modo falla, se entra cuando se detecta algún error del sistema */
            task_system_falla_statechart(&task_system_dta_list[FALLA]);
            break;

        default:
            /* Si ocurre un error de modo inválido, volvemos a normal por seguridad */
            task_system_set_mode(NORMAL);
            break;
    }
}

/* Función auxiliar para cambiar el modo de operación desde otros módulos */
void task_system_set_mode(task_system_mode_t mode)
{
    g_task_system_mode = mode;
}

/********************** end of file ******************************************/

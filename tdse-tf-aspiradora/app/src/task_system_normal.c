/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 *
 */

/********************** inclusions *******************************************/
#include "logger.h"
#include <task_pwm.h>
#include "task_system_normal.h"
#include "task_system_interface.h"
#include "task_actuator_interface.h"
#include "task_display_interface.h"
#include "task_actuator_attribute.h"
#include "task_bluetooth.h"
#include "task_bluetooth_attribute.h"
#include "task_bluetooth_interface.h"

/********************** macros and definitions *******************************/

/********************** internal data declaration ****************************/
/* Sub-estados internos de la maniobra de evasión de obstáculos */
typedef enum {
    PHASE_STOP,     // Frenamos antes de empezar a retroceder
    PHASE_REVERSE,  // Retrocedemos un poco para alejarnos del obstáculo
    PHASE_SPIN      // Giramos para cambiar de dirección y esquivarlo
} avoid_phase_t;

/********************** external functions definition ************************/

void task_system_normal_statechart(task_system_dta_t *p_task_system_dta)
{
    /* Guarda en qué fase de la evasión estamos (se mantiene entre llamadas) */
    static avoid_phase_t fase_evasion = PHASE_STOP;

    /* Descuenta el tick mientras esperamos que termine alguna fase temporizada */
    if (p_task_system_dta->tick > 0) {
            p_task_system_dta->tick--;
    }

    if (true == any_event_task_system())
    {
        p_task_system_dta->flag = true;
        p_task_system_dta->event = get_event_task_system();
    }

    switch (p_task_system_dta->state)
    {
        case ST_SYS_IDLE:
            if (true == p_task_system_dta->flag)
            {
                if (EV_SYS_ENTER == p_task_system_dta->event)
                {
                    /* Arrancamos la limpieza: prendemos motores y avisamos por display */
                    p_task_system_dta->state = ST_SYS_NORMAL_CLEANING;
                    put_event_task_display(0, 0, "LIMPIANDO...    ");
                    put_event_task_display(0, 1, "                ");
                    put_event_task_actuator(EV_ACT_MOTORS_FORWARD);
                }
                /* SALTO MANUAL HACIA EL SETUP MEDIANTE EL BOTÓN 4 */
                else if (EV_SYS_SETUP_BTN == p_task_system_dta->event)
                {
                    p_task_system_dta->state = ST_SYS_IDLE; // Reset p/ la prox vez
                    task_system_set_mode(SETUP);
                }
            }
            break;

        case ST_SYS_NORMAL_CLEANING:
            if (true == p_task_system_dta->flag)
            {
                if (EV_SYS_FAULT_STALL == p_task_system_dta->event)
                {
                    /* Detectamos que el motor se trabó (sobrecarga), pasamos a modo Falla */
                    p_task_system_dta->state = ST_SYS_IDLE;
                    task_system_set_mode(FALLA);
                    put_event_task_bluetooth(NULL, BT_MSG_CARGA);
                	LOGGER_INFO("Mensaje de MSG_CARGA");
                }
                else if (EV_SYS_SENSOR_OBSTACLE == p_task_system_dta->event)
                {
                    /* Detectamos un obstáculo: paramos motores e iniciamos la evasión */
                    p_task_system_dta->state = ST_SYS_NORMAL_AVOIDING;
                    fase_evasion = PHASE_STOP;
                    p_task_system_dta->tick = 200;

                    put_event_task_display(0, 0, "OBSTACULO!      ");
                    put_event_task_display(0, 1, "EVADIENDO...    ");
                    put_event_task_actuator(EV_ACT_MOTORS_STOP);
                    put_event_task_bluetooth(NULL, BT_MSG_CHOQUE);
                    LOGGER_INFO("Mensaje de MSG_CHOQUE");
                }
                else if (EV_SYS_ESCAPE == p_task_system_dta->event)
                {
                    /* El usuario cancela la limpieza manualmente y volvemos a IDLE */
                    p_task_system_dta->state = ST_SYS_IDLE;
                    put_event_task_actuator(EV_ACT_MOTORS_STOP);
                    put_event_task_display(0, 0, "MODO NORMAL     ");
                    put_event_task_display(0, 1, "ENTER: EMPEZAR  ");
                }
            }
            break;

        case ST_SYS_NORMAL_AVOIDING:
            if (true == p_task_system_dta->flag) {
                if (EV_SYS_FAULT_STALL == p_task_system_dta->event) {
                    /* También puede fallar en medio de la evasión, cortamos igual */
                    p_task_system_dta->state = ST_SYS_IDLE;
                    task_system_set_mode(FALLA);
                }
                p_task_system_dta->flag = false;
            }

            /* Cuando se termina el tick de la fase actual, pasamos a la siguiente */
            if (0 == p_task_system_dta->tick)
            {
                switch(fase_evasion)
                {
                    case PHASE_STOP:
                        /* Ya frenamos, ahora arrancamos a retroceder */
                        fase_evasion = PHASE_REVERSE;
                        p_task_system_dta->tick = 500;
                        put_event_task_actuator(EV_ACT_MOTORS_REVERSE);
                        break;
                    case PHASE_REVERSE:
                        /* Ya retrocedimos, ahora giramos para cambiar de rumbo */
                        fase_evasion = PHASE_SPIN;
                        p_task_system_dta->tick = 800;
                        put_event_task_actuator(EV_ACT_MOTORS_SPIN);
                        break;
                    case PHASE_SPIN:
                        /* Terminamos la maniobra, retomamos la limpieza normal */
                        p_task_system_dta->state = ST_SYS_NORMAL_CLEANING;
                        put_event_task_display(0, 0, "LIMPIANDO...    ");
                        put_event_task_display(0, 1, "                ");
                        put_event_task_actuator(EV_ACT_MOTORS_FORWARD);
                        break;
                }
            }
            break;

        default: p_task_system_dta->state = ST_SYS_IDLE; break;
    }
    p_task_system_dta->flag = false;
}

/********************** end of file ******************************************/

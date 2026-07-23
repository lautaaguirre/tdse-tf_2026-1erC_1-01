/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 *
 */

/********************** inclusions *******************************************/
#include "task_sensor_button.h"
#include "task_system_interface.h" // Para put_event_task_system

/********************** macros and definitions *******************************/
#define DEL_BTN_MIN 0ul

/********************** internal data declaration ****************************/

/********************** external functions definition ************************/

void task_sensor_button_statechart(const task_sensor_btn_cfg_t *p_cfg, task_sensor_btn_dta_t *p_dta)
{
    /* Lectura cruda de GPIO */
    if (p_cfg->pressed == HAL_GPIO_ReadPin(p_cfg->gpio_port, p_cfg->pin)) {
        p_dta->event = EV_BTN_DOWN;
    } else {
        p_dta->event = EV_BTN_UP;
    }

    /* Tu Máquina de Estados Original */
    switch (p_dta->state)
    {
        case ST_BTN_UP:
            /* Detectamos flanco de bajada, arrancamos a contar el antirrebote */
            if (EV_BTN_DOWN == p_dta->event) {
                p_dta->tick = p_cfg->tick_max;
                p_dta->state = ST_BTN_FALLING;
            }
            break;

        case ST_BTN_FALLING:
            p_dta->tick--;
            if (DEL_BTN_MIN == p_dta->tick) {
                /* Pasado el antirrebote, si seguía apretado confirmamos la pulsación */
                if (EV_BTN_DOWN == p_dta->event) {
                    put_event_task_system(p_cfg->signal_down); // Inyección al Sistema
                    p_dta->state = ST_BTN_DOWN;
                } else {
                    /* Era un rebote, volvemos a soltado */
                    p_dta->state = ST_BTN_UP;
                }
            }
            break;

        case ST_BTN_DOWN:
            /* Detectamos flanco de subida, arrancamos a contar el antirrebote */
            if (EV_BTN_UP == p_dta->event) {
                p_dta->state = ST_BTN_RISING;
                p_dta->tick = p_cfg->tick_max;
            }
            break;

        case ST_BTN_RISING:
            p_dta->tick--;
            if (DEL_BTN_MIN == p_dta->tick) {
                /* Pasado el antirrebote, si seguía soltado confirmamos la liberación */
                if (EV_BTN_UP == p_dta->event) {
                    put_event_task_system(p_cfg->signal_up);
                    p_dta->state = ST_BTN_UP;
                } else {
                    /* Era un rebote, volvemos a apretado */
                    p_dta->state = ST_BTN_DOWN;
                }
            }
            break;

        default:
            p_dta->tick  = DEL_BTN_MIN;
            p_dta->state = ST_BTN_UP;
            p_dta->event = EV_BTN_UP;
            break;
    }
}

/********************** end of file ******************************************/

/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 *
 */

/********************** inclusions *******************************************/
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "logger.h"
#include "task_bluetooth.h"
#include "task_bluetooth_attribute.h"
#include "task_bluetooth_interface.h"

/********************** macros and definitions *******************************/

/********************** internal data declaration ****************************/
extern UART_HandleTypeDef huart3;

/* Datos de la tarea (estado, buffer a enviar, etc.) — usados también desde la interface */
task_bluetooth_dta_t task_bluetooth_dta;

static UART_HandleTypeDef *h_bluetooth_uart;

/* Bandera propia para saber si la UART está libre para transmitir (además del estado del HAL) */
static volatile bool g_bt_tx_complete = true;

/********************** internal functions declaration ***********************/
static void task_bluetooth_statechart(void);

/********************** external functions definition ************************/

void task_bluetooth_init(void *parameters) {
    h_bluetooth_uart = &huart3;

    task_bluetooth_dta.state = ST_BT_IDLE;
    task_bluetooth_dta.event = EV_BT_IDLE;
    task_bluetooth_dta.tick = 0;
    task_bluetooth_dta.flag = false;
    g_bt_tx_complete = true;
    LOGGER_INFO("%s initialized successfully", GET_NAME(task_bluetooth_init));
}

void task_bluetooth_update(void *parameters) {
    task_bluetooth_statechart();
}

static void task_bluetooth_statechart(void) {

    switch(task_bluetooth_dta.state) {
        case ST_BT_IDLE:
            /* Solo procesamos si hay evento Y la UART terminó el envío anterior */
            if (task_bluetooth_dta.flag && g_bt_tx_complete) {

                /* Consumimos la bandera SOLO AHORA que sí la vamos a procesar */
                task_bluetooth_dta.flag = false;
                task_bluetooth_dta.event = EV_BT_IDLE;

                LOGGER_INFO("BT sending event trigger registered");

                /* Encendemos el LED de transmisión */
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);

                /* Transmisión UART por Interrupciones (no bloqueante) */
                if (h_bluetooth_uart != NULL) {
                    uint16_t size = strlen(task_bluetooth_dta.buffer);
                    g_bt_tx_complete = false; // Marcamos UART como ocupada

                    if (HAL_UART_Transmit_IT(h_bluetooth_uart, (uint8_t *)task_bluetooth_dta.buffer, size) != HAL_OK) {
                        g_bt_tx_complete = true; // Si falló la invocación, liberamos
                    }
                }

                task_bluetooth_dta.tick = 0;
                task_bluetooth_dta.state = ST_BT_SEND_DATA;
            }
            break;

        case ST_BT_SEND_DATA:
            /* Evaluamos si la UART ya terminó de transmitir, de forma no bloqueante */
            if (h_bluetooth_uart->gState == HAL_UART_STATE_READY) {
                /* La UART ya terminó de mandar el mensaje: apagamos el LED y volvemos a IDLE */
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
                g_bt_tx_complete = true;
                task_bluetooth_dta.state = ST_BT_IDLE;
            }
            break;

        default:
            task_bluetooth_dta.state = ST_BT_IDLE;
            break;
    }
}

/* Callback del HAL: se dispara solo cuando la UART termina de transmitir de verdad */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART3) {
        g_bt_tx_complete = true; // Avisamos a la máquina de estados que la UART quedó libre
    }
}

/********************** end of file ******************************************/

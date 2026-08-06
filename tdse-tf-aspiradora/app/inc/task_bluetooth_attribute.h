/*
 * task_bluetooth_attribute.h
 *
 *  Created on: Jul 13, 2026
 *      Author: Laura
 */

#ifndef INC_TASK_BLUETOOTH_ATTRIBUTE_H_
#define INC_TASK_BLUETOOTH_ATTRIBUTE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdint.h>
#include <stdbool.h>

/* Identificadores de los mensajes predefinidos que se pueden mandar por bluetooth.
 * El texto de cada uno está definido en task_bluetooth_interface.c (g_bluetooth_messages).
 * BT_MSG_COUNT queda al final para saber la cantidad total de mensajes (no es un mensaje en sí). */
typedef enum {
	BT_MSG_ENCENDIDO,
	BT_MSG_FUNCIONAMIENTO,
	BT_MSG_CHOQUE,
	BT_MSG_APAGADO,
	BT_MSG_CARGA,
    BT_MSG_COUNT
} bt_msg_id_t;

/* Eventos que puede recibir la máquina de estados de Task Bluetooth */
typedef enum task_bluetooth_ev {
    EV_BT_IDLE,     // Sin evento pendiente
    EV_BT_UPDATE    // Hay un mensaje nuevo cargado, listo para enviar
} task_bluetooth_ev_t;

/* Estados posibles de la máquina de estados de Task Bluetooth */
typedef enum task_bluetooth_st {
    ST_BT_IDLE,         // Esperando que se cargue un mensaje para enviar
    ST_BT_SEND_DATA     // Transmisión en curso por UART
} task_bluetooth_st_t;

/* Datos propios de la tarea: estado actual, buffer con el mensaje a enviar, etc. */
typedef struct
{
    uint32_t            tick;      // Contador de tiempo (sin uso actualmente)
    task_bluetooth_st_t state;     // Estado actual de la FSM
    task_bluetooth_ev_t event;     // Último evento recibido
    bool                flag;      // Indica si hay un evento nuevo sin procesar
    char                buffer[64]; // Mensaje a transmitir por bluetooth
} task_bluetooth_dta_t;

/* Instancia única de los datos de la tarea, definida en task_bluetooth.c */
extern task_bluetooth_dta_t task_bluetooth_dta;

#ifdef __cplusplus
}
#endif

#endif /* INC_TASK_BLUETOOTH_ATTRIBUTE_H_ */

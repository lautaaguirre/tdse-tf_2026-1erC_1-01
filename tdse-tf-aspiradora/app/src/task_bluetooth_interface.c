/*
 * task_bluetooth_interface.c
 *
 *  Created on: Jul 13, 2026
 *      Author: Laura
 */

/********************** inclusions *******************************************/
#include <stdio.h>
#include "task_bluetooth.h"
#include "task_bluetooth_attribute.h"
#include "task_bluetooth_interface.h"

/* Declaramos externamente los datos de la tarea, reservados en task_bluetooth.c */
extern task_bluetooth_dta_t task_bluetooth_dta;

/********************** internal data declaration ****************************/
/* Textos fijos que se mandan por bluetooth según el id de mensaje */
const char * const g_bluetooth_messages[BT_MSG_COUNT] = {
    [BT_MSG_ENCENDIDO] = "¡Buen día te desea Aspi!\r\n",
    [BT_MSG_FUNCIONAMIENTO] = "[INFO]: Funciono bien.\r\n",
    [BT_MSG_CHOQUE] = "[ALERTA]: Colisión con obstaculo!\r\n",
    [BT_MSG_APAGADO] = "Hasta Luego\r\n",
    [BT_MSG_CARGA] = "[INFO]: SOBRECARGA.\r\n"
};

/********************** external functions definition ************************/

/*
 * Carga un mensaje en el buffer de la tarea y levanta la bandera para que
 * se envíe por bluetooth. Si la tarea está ocupada (no está en IDLE), se ignora
 * el pedido para no pisar un envío en curso.
 */
void put_event_task_bluetooth(const char *message, bt_msg_id_t message_bt) {

	if (task_bluetooth_dta.state != ST_BT_IDLE) {
	        return;
	 }

	/* Si el id es válido usamos el mensaje predefinido, sino el texto que nos pasaron */
	if (message_bt < BT_MSG_COUNT) {
        snprintf(task_bluetooth_dta.buffer, sizeof(task_bluetooth_dta.buffer), "%s", g_bluetooth_messages[message_bt]);
    } else {
        snprintf(task_bluetooth_dta.buffer, sizeof(task_bluetooth_dta.buffer), "%s", message);
    }

    // Levantamos la bandera para que el statechart procese el envío
    task_bluetooth_dta.event = EV_BT_UPDATE;
    task_bluetooth_dta.flag = true;
}

/********************** end of file ******************************************/

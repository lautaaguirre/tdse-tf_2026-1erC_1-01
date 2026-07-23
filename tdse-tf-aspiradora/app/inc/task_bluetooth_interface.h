/*
 * task_bluetooth_interface.h
 *
 *  Created on: Jul 13, 2026
 *      Author: Laura
 */

#ifndef INC_TASK_BLUETOOTH_INTERFACE_H_
#define INC_TASK_BLUETOOTH_INTERFACE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/
#include <stdint.h>

/********************** macros ***********************************************/
#define BT_MSG_MAX_LEN    64

/********************** typedef **********************************************/

/********************** external data declaration ****************************/
extern const char * const g_bluetooth_messages[BT_MSG_COUNT];

/********************** external functions declaration ***********************/
extern void put_event_task_bluetooth(const char *message, bt_msg_id_t message_bt);

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif




#endif /* INC_TASK_BLUETOOTH_INTERFACE_H_ */

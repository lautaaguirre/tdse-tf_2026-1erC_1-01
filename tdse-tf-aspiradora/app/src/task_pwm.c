/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 *
 */

/********************** inclusions *******************************************/
/* Project includes. */
#include "main.h"

///PWM PAAA

/* App includes. */
#include <stdlib.h>
#include "logger.h"
#include <stdint.h>
#include <stdbool.h>
#include <task_pwm.h>

/* Application includes. */

/********************** macros and definitions *******************************/
/* Frecuencias (Hz) de las notas usadas en la melodía */
#define NOTE_E4  330
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523


#define DELAY_TICKS (4)
#define STEP (100)
#define PERIOD (65535)


/*
 * Melodía tipo "beep" que suena al terminar (o al fallar). Cada nota tiene
 * frecuencia en Hz y duración en ms. Freq = 0 significa silencio.
 */
static const note_t melody[] = {
		// --- Piiiiii (Largo) ---
		    {1000, 500},
		    {0,    100}, // Breve silencio

		    // --- Pi (Corto) ---
		    {1000, 150},
		    {0,    100}, // Breve silencio

		    // --- Piiiiii (Largo) ---
		    {1000, 500},
		    {0,    100}, // Breve silencio

		    // --- Pi (Corto) ---
		    {1000, 150},
		    {0,    100}  // Silencio final
};


/********************** external data declaration *****************************/
extern TIM_HandleTypeDef htim2;

/********************** external functions definition ************************/

/********************** internal data declaration ****************************/
uint32_t tickstart;


/********************** internal data definition *****************************/
/* Config del timer/canal que maneja el buzzer, con su frecuencia y duty por defecto */
const task_pwm_cfg_t task_pwm_cfg_list[]= {
	    {
	        .htim           = &htim2,
	        .channel        = TIM_CHANNEL_1,
	        .timer_clock_hz   = 1000000, //sale del prescaler en 72-1 y el counter period (ARR) en 100-1
	        .default_freq   = 2000, //frec predeterminada, audible
	        .default_duty   = 50
	    }
};

/* Estado de la reproducción: si está sonando, qué nota va y cuántas notas tiene la melodía */
static task_pwm_dta_t task_pwm_dta =
{
    .busy          = false,
    .tick          = 0,
    .note_index    = 0,
    .melody_length = 0
};


/********************** internal functions definitions ***********************/
void pwm_init(void *parameters)
{
    task_pwm_dta.busy = false;

    task_pwm_dta.tick = 0;

    task_pwm_dta.note_index = 0;

    task_pwm_dta.melody_length = 0;

    /* Arrancamos el PWM del buzzer en 0 (silencio) */
    HAL_TIM_PWM_Start(task_pwm_cfg_list[0].htim,
                      task_pwm_cfg_list[0].channel);

    __HAL_TIM_SET_COMPARE(task_pwm_cfg_list[0].htim,
                          task_pwm_cfg_list[0].channel,
                          0);
}

bool pwm_is_busy(void)
{
    return task_pwm_dta.busy;
}

/*
 * Configura el timer para que el buzzer suene a la frecuencia pedida.
 * Recalcula el ARR (periodo) en base al freq y deja el duty en 50%.
 * freq = 0 apaga el buzzer (deja el compare en 0).
 */
static void buzzer_set_frequency(uint16_t freq)
{
    uint32_t arr;

    if(freq == 0)
    {
        __HAL_TIM_SET_COMPARE(
            task_pwm_cfg_list[0].htim,
            task_pwm_cfg_list[0].channel,
            0);
        return;
    }

    arr = task_pwm_cfg_list[0].timer_clock_hz/freq - 1;

    __HAL_TIM_SET_AUTORELOAD(
        task_pwm_cfg_list[0].htim,
        arr);

    __HAL_TIM_SET_COMPARE(
        task_pwm_cfg_list[0].htim,
        task_pwm_cfg_list[0].channel,
        arr/2);

    __HAL_TIM_SET_COUNTER(
        task_pwm_cfg_list[0].htim,
        0);

//    __HAL_TIM_GENERATE_EVENT(
//        task_pwm_cfg_list[0].htim,
//        TIM_EVENTSOURCE_UPDATE);
}


/* Arranca la reproducción de la melodía desde la primera nota (no bloqueante) */
void buzzer_play_finish_melody(void)
{
    task_pwm_dta.busy = true;
    task_pwm_dta.note_index = 0;
    task_pwm_dta.tick = HAL_GetTick();
    LOGGER_INFO(" Dale que reproduzo????");
    // Apuntamos al nuevo array de Inocente
    buzzer_set_frequency(melody[task_pwm_dta.note_index].freq);
    LOGGER_INFO(" Dale que reproduzo");
    task_pwm_dta.melody_length = sizeof(melody) / sizeof(note_t);

}

/*
 * Se llama en cada ciclo. Si no hay melodía sonando no hace nada.
 * Si ya pasó la duración de la nota actual, pasa a la siguiente;
 * si se acabaron las notas, apaga el buzzer y marca busy = false.
 */
void pwm_update(void *parameters)
{
    if(!task_pwm_dta.busy)
    {
        return;
    }

    // Cambiado finish_melody por inocente_melody
    if(HAL_GetTick() - task_pwm_dta.tick >= melody[task_pwm_dta.note_index].duration)
    {
        task_pwm_dta.note_index++;

        if(task_pwm_dta.note_index >= task_pwm_dta.melody_length)
        {
            task_pwm_dta.busy = false;
            buzzer_set_frequency(0);
            LOGGER_INFO(" entre al return ");
            return;
        }

        // Cambiado finish_melody por inocente_melody
        buzzer_set_frequency(melody[task_pwm_dta.note_index].freq);

        task_pwm_dta.tick = HAL_GetTick();
    }
}



//    __HAL_TIM_SET_AUTORELOAD(htim, period); //cambia el ARR -> modifica frec
//
//    __HAL_TIM_SET_COMPARE(htim, channel, pulse); //cambia el CCR -> modifica duty cycle
//
//    __HAL_TIM_SET_COUNTER(htim, 0); //reinicia contador

//    __HAL_TIM_GENERATE_EVENT(htim, TIM_EVENTSOURCE_UPDATE); //actualiza	para cargar rapido ARR y CCR



/********************** end of file ******************************************/

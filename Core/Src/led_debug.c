/*
 * control_led.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "led_debug.h"
//Control the led for debugging in 2.5
void control_led_run(){
	if(timer1_flag == 1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer1(1000);
	}
}

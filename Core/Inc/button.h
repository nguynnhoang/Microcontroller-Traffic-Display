/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE 		GPIO_PIN_SET
#define PRESSED_STATE	 	GPIO_PIN_RESET



int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInput_button1();
void getKeyInput_button2();
void getKeyInput_button3();



#endif /* INC_BUTTON_H_ */

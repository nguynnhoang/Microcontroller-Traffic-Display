/*
 * fsm_7LED.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_button_7led.h"

void fsm_simple_buttons_run (){
	switch(status){
	case INIT:
		display7SEG(0);
		counter_7led = 0;
		status = RESET;
		setTimer2(10000);
		break;

	case RESET:
		display7SEG(counter_7led);
		if(isButtonRESETPressed() == 1){
			counter_7led = 0;
			setTimer2(10000);
			status = RESET;
		}
		if(isButtonINCPressed() == 1){
			counter_7led++;
			if(counter_7led > 9) counter_7led = 0;
			setTimer2(10000);
			status = INC;
		}
		if(isButtonDECPressed() == 1){
			counter_7led--;
			if(counter_7led < 0) counter_7led = 9;
			setTimer2(10000);
			status = DEC;
		}
		break;

	case INC:
		display7SEG(counter_7led);

		if(isButtonRESETPressed() == 1){
			counter_7led = 0;
			setTimer2(10000);
			status = RESET;
		}
		else if(isButtonINCPressed() == 1){
			counter_7led++;
			if(counter_7led > 9) counter_7led = 0;
			setTimer2(10000);
			status = INC;
		}

		else if(isButtonDECPressed() == 1){
			counter_7led--;
			if(counter_7led < 0) counter_7led = 9;
			setTimer2(10000);
			status = DEC;
		}
		else{
			if(timer2_flag==1){
				setTimer3(1000);
			status = NO_PRESSED;
			}
		}
		break;

	case DEC:
		display7SEG(counter_7led);
		if(isButtonRESETPressed() == 1){
			counter_7led = 0;
			setTimer2(10000);
			status = RESET;
		}
		else if(isButtonINCPressed() == 1){
			counter_7led++;
			if(counter_7led > 9) counter_7led = 0;
			setTimer2(1000);
			status = INC;
		}
		else if(isButtonDECPressed() == 1){
			counter_7led--;
			if(counter_7led < 0) counter_7led = 9;
			setTimer2(10000);
			status = DEC;
		}
		else{

			if(timer2_flag==1){
				setTimer3(1000);
				status = NO_PRESSED;
			}
		}
		break;

	case NO_PRESSED:
		if(timer3_flag==1){
			if(counter_7led >= 0){
				counter_7led--;
					display7SEG(counter_7led);
					setTimer3(1000);
			}
		}
		if(isButtonINCPressed()==1){
			setTimer2(10000);
			status = INC;
		}
		if(isButtonDECPressed()==1){
			setTimer2(10000);
			status = DEC;
		}
		break;

	default:
		break;
	}
}

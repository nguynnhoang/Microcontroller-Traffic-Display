/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */


#include "button.h"

int buttonRESET_flag = 0;
int buttonINC_flag = 0;
int buttonDEC_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int TimeOutForKeyPress =  300;
int check_press_button2 = 0;

int isButtonRESETPressed(){
	if(buttonRESET_flag == 1){
		buttonRESET_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonINCPressed(){
	if(buttonINC_flag == 1){
		buttonINC_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonDECPressed(){
	if(buttonDEC_flag == 1){
		buttonDEC_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess_buttonRESET(){
	buttonRESET_flag = 1;
}
void subKeyProcess_buttonINC(){
	buttonINC_flag = 1;
}
void subKeyProcess_buttonDEC(){
	buttonDEC_flag = 1;
}

void getKeyInput_buttonRESET(){
	  KeyReg0 = KeyReg1;
	  KeyReg1 = KeyReg2;
	  KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
	    if (KeyReg3 != KeyReg2){
	      KeyReg3 = KeyReg2;

	    if (KeyReg2 == PRESSED_STATE){
		    subKeyProcess_buttonRESET();
	        TimeOutForKeyPress = 300;
	      }
	    }else{
	       TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
	        	if(KeyReg2 == PRESSED_STATE) subKeyProcess_buttonRESET();
	        	TimeOutForKeyPress = 300;
	        }
	    }
	  }

}

void getKeyInput_buttonINC(){
	  KeyReg4 = KeyReg5;
	  KeyReg5 = KeyReg6;
	  KeyReg6 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	  if ((KeyReg4 == KeyReg5) && (KeyReg5 == KeyReg6)){
	    if (KeyReg7 != KeyReg6){
	      KeyReg7 = KeyReg6;
	      if (KeyReg6 == PRESSED_STATE){
		    subKeyProcess_buttonINC();
	        TimeOutForKeyPress = 300;
	      }
	    }
	    else{
	    		TimeOutForKeyPress --;
				if (TimeOutForKeyPress == 0){
		        	if(KeyReg6 == PRESSED_STATE) subKeyProcess_buttonINC();
					TimeOutForKeyPress = 300;
				}


	    }
	  }
}

void getKeyInput_buttonDEC(){
	  KeyReg8 = KeyReg9;
	  KeyReg9 = KeyReg10;
	  KeyReg10 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	  if ((KeyReg8 == KeyReg9) && (KeyReg9 == KeyReg10)){
	    if (KeyReg11 != KeyReg10){
	      KeyReg11 = KeyReg10;
	      if (KeyReg10 == PRESSED_STATE){
		    subKeyProcess_buttonDEC();
	        TimeOutForKeyPress = 300;
	      }
	    }else{
	       TimeOutForKeyPress --;
	        if (TimeOutForKeyPress == 0){
	        	if(KeyReg10 == PRESSED_STATE)subKeyProcess_buttonDEC();
	        	TimeOutForKeyPress = 300;
	        }
	    }
	  }
}

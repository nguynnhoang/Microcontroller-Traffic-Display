/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "software_timer.h"
#define TIMER_CYCLE 10

int counter_timer1;
int timer1_flag = 0;

int counter_timer2;
int timer2_flag = 0;

int counter_timer3;
int timer3_flag = 0;

void setTimer1(int duration){
	counter_timer1 = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){
	counter_timer2 = duration/TIMER_CYCLE;
	timer2_flag = 0;
}

void setTimer3(int duration){
	counter_timer3 = duration/TIMER_CYCLE;
	timer3_flag = 0;
}

void timerRun(){
	if(counter_timer1 > 0){
		counter_timer1--;
		if(counter_timer1<=0) timer1_flag = 1;
	}
	if(counter_timer2 > 0){
		counter_timer2--;
		if(counter_timer2<=0) timer2_flag = 1;
	}
	if(counter_timer3 > 0){
		counter_timer3--;
		if(counter_timer3<=0) timer3_flag = 1;
	}
}

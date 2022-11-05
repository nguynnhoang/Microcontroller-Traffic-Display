/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"


#define RESET			1
#define INC				2
#define DEC				3
#define INIT 			4
#define NO_PRESSED		5

extern int status;
extern int status_1;
extern int status_2;
extern int counter_7led;

#endif /* INC_GLOBAL_H_ */

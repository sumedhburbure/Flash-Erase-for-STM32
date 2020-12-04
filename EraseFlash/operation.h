#ifndef OPERATION_H
#define OPERATION_H

#include "stm32f4xx.h"
#include <stdio.h>
#include <stdint.h>
//DEFINATIONS
#define HIGH 1
#define LOW  0

/*****************function declarations*****************/
//FLASH FUNCTIONS
void FlashErase(void);

//GPIO FUNCTIONS
void ButtonInit(void);
void LED_Init(void);
void LED_Status(int);

#endif

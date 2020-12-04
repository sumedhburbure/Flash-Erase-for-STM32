/***********************************************************/
/*   This Code is designed to Work With the STM32F429xx    */
/*	 Development Board. This code will Erase Flash Memory. */
/*   This code is written purely for Educational Purpose   */
/*   Author: Sumedh Burbure.                               */
/***********************************************************/

#include "operation.h"

int main(void){
ButtonInit();
LED_Init();	
	while(1){
		LED_Status(HIGH);										//Making OnBoard LED high to acknowledge that program is present in Flash Memory
		if((GPIOA->IDR & 0x01) == HIGH){		//Checking GPIOA Input DATA Register for button Pressed
			FlashErase();
		}
	}
}
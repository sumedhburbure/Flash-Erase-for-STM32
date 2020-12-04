#include "operation.h"

/***************** void Flash_Unlock(void) ********************/
/*** Unlock the flash for gaining access to erase command   ***/
/*** by giving the KEYR register the unlock key sequence    ***/
/*** provided in the reference manual of the micro-controller */
/**************************************************************/
void Flash_Unlock(void){
		FLASH->KEYR = 0x45670123;			//Code Sequence 1
		FLASH->KEYR = 0xCDEF89AB;			//Code Sequence 2
}

/***************** void FlashErase(void) **********************/
/***    Erase the Flash by selecting the sectors to erase   ***/
/*** from the Flash registers shown below.More information  ***/
/*** provided in the reference manual of the micro-controller */
/**************************************************************/
void FlashErase(void){
		uint32_t flash_status = FLASH->CR;						 //CHecking Flash Lock/Unlock Status
		Flash_Unlock();																 //Summoning Flash Unlock Function
		flash_status = FLASH->CR;											 //Debug flash status to ensure if Flash is unlocked

		if(((flash_status >> 31) & 0x01) == LOW){			 //If flash is unlocked...
			while(((FLASH->SR>>16) & 0x01)!= 0){}			   //wait for the flash operations to complete
			FLASH->CR |= (0x01<<15)|(0x01<<2)|(0x01<<1); //Set bits MER1,MER,SER to erase
			FLASH->CR |= (0x01 << 16);									 //Start Mass Erase of Bank1 and Bank2 Flash Memory
			while(((FLASH->SR>>16) & 0x01)!= 0){}			   //Wait for the flash operations to complete
		}
}



void ButtonInit(void){
	RCC->AHB1ENR |= 0x01;									//Enable clock for gpio port A
	GPIOA->MODER &= ~(0x11);							//Enable GPIO-0 as input	
}

void LED_Init(void){
			RCC->AHB1ENR |= 0x40;							//Enable Clock for PORT G
			GPIOG->MODER |= (0X01 << 28);  		//Configure PIN 14 as Output
			GPIOG->OTYPER &= ~(0X01 << 14);		//Configure PIN 14 as PUSHPULL Configuration	
			GPIOG->MODER |= (0X01 << 26);  		//Configure PIN 13 as OUTPUT
			GPIOG->OTYPER &= ~(0X01 << 13);		//Configure PIN 13 as PUSHPULL Configuration	
}

void LED_Status(int val){
	if(val == HIGH){										
		GPIOG->ODR |= (0x01<< 14);					//Make PIN 14 High
		GPIOG->ODR |= (0x01 << 13);					//Make PIN 13 High
	}
	else{
		GPIOG->ODR &= ~(0x01 <<14);					//Make PIN 14 Low
		GPIOG->ODR &= ~(0x01 <<13);					//Make PIN 13 Low
	}
}

# Flash-Erase-for-STM32
Flash Erase Example Code for STM32F429 Development Board.

You can read the article about brief introduction and use cases for flash erase here:
https://sumedhburbure.medium.com/flash-erase-for-stm32-5abf8e206bec

### What does this Code do?
This code example is uploaded for educational purpose to demonstrate how to mass erase the STM32F4x microcontroller.
In this code example, the code does the following things:
* Initialize the Onboard LEDs of STM32F429 development board and turn both LEDs on to indicate that the code is running in the micro-controller.
* Initialize the Onboard User Button of STM32F429 development board as input so it acts as a trigger to perform mass erase of the flash memory.
* After pressing the user button, the entire flash memory get wiped off and if you reset the board again, the Onboard LEDs do not light up indicating that the code is erased from the flash memory.

### Reference
The code contains comments to explain step by step process on how to mass erase flash.There is a flash driver library provided to handle mass erase but __this code manipulate flash registers__ of micro-controller to __reduce size of the code__ and to have a __good understanding of what is happening under the hood.__
It is advisible to look at [reference manual](https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf) (STM32F429x in this case) Section 3.6 Erase and program operations.while following the step by step code to have a greater understanding of the operation.



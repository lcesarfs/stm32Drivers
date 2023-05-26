/*
 * stm32f106_gpio.h
 *
 *  Created on: 26 May 2023
 *      Author: luizcsil
 */

#ifndef INC_STM32F106_GPIO_H_
#define INC_STM32F106_GPIO_H_

#include "stm32f106cbt6.h"


/*This is handle structure for a GPIO pin*/

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx; /* This holds the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig; /* This holds GPIO pin configuration settings */
}GPIO_Handle_t;


/**********************************************************************************************
 * APIs supported by this driver
 * For more information about the APIs check the function definitions
 * ********************************************************************************************/
/* Peripheral Clock setup */
void GPIO_PeriClockControl(void);

/* Peripheral Ini and De-init */
void GPIO_Init(void);
void GPIO_DeInit(void);

/* Read and write data to pin or port */
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_ToggleOutputPin(void);

/* IRQ Configuration and ISR handling */
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);

#endif /* INC_STM32F106_GPIO_H_ */

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
	uint8_t GPIO_PinMode;			/* Possible values @ GPIO MODES MACROS*/
	uint8_t GPIO_PinSpeed;			/* Possible values @ GPIO SPEED MACROS*/
	uint8_t GPIO_PinPuPdControl; 	/* Possible values @ GPIO PULL-UP PULL-DOWN MACROS*/
	uint8_t GPIO_PinOPType; 		/* Possible values @ GPIO OUTPUT TYPE MACROS*/
	uint8_t GPIO_PinAltFunMode; 	/* Possible values @ GPIO MODES MACROS*/
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx; 				/* This holds the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig; 	/* This holds GPIO pin configuration settings */
}GPIO_Handle_t;


//@GPIO PIN NUMBER MACROS
//GPIO pin number
#define GPIO_PIN_NO_0	 	0
#define GPIO_PIN_NO_1 		1
#define GPIO_PIN_NO_2 		2
#define GPIO_PIN_NO_3 		3
#define GPIO_PIN_NO_4 		4
#define GPIO_PIN_NO_5 		5
#define GPIO_PIN_NO_6 		6
#define GPIO_PIN_NO_7 		7
#define GPIO_PIN_NO_8 		8
#define GPIO_PIN_NO_9 		9
#define GPIO_PIN_NO_10 		10
#define GPIO_PIN_NO_11 		11
#define GPIO_PIN_NO_12 		12
#define GPIO_PIN_NO_13 		13
#define GPIO_PIN_NO_14 		14
#define GPIO_PIN_NO_15 		15



//@GPIO MODES MACROS
//GPIO pin possible modes
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANA 		3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

//@GPIO OUTPUT TYPE MACROS
//GPIO pin possible output type
#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

//@GPIO SPEED MACROS
//GPIO pin possible output speeds
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

//@GPIO PULL-UP PULL-DOWN MACROS
//GPIO port pull-up/pull-down register
#define GPIO_NO_PUPD		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2


/**********************************************************************************************
 * APIs supported by this driver
 * For more information about the APIs check the function definitions
 * ********************************************************************************************/
/* Peripheral Clock setup */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi );

/* Peripheral Ini and De-init */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* Read and write data to pin or port */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/* IRQ Configuration and ISR handling */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F106_GPIO_H_ */

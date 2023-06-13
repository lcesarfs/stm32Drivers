/*
 * 001led_toggle.c
 *
 *  Created on: 12 Jun 2023
 *      Author: luizcsil
 */


#include "stm32f106cbt6.h"

void delay(void)
{
	for (uint32_t i = 0; i<50000; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed,GpioButton;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GpioButton.pGPIOx = GPIOA;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioButton);

	while(1)
	{

		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_6))
		{
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, SET);
		}else
		{
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, RESET);
		}

		delay();
	}

	return 0;
}

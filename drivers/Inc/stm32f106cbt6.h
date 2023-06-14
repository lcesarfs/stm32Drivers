/*
 * stm32f106cbt6.h
 *
 *  Created on: May 22, 2023
 *      Author: lcesa
 */

#ifndef INC_STM32F106CBT6_H_
#define INC_STM32F106CBT6_H_
#include <stdint.h>


#define FLASH_BASEADDR		0x8000000U
#define ROM_BASEADDR		0x1FFF0000U
#define SRAM 				0x2000000U

#define PERIPH_BASE			0x40000000U
#define APBPERIPH_BASE		PERIPH_BASE
#define	AHBPERIPH_BASE		0x40020000U
#define IOPORT_BASE			0x50000000U

/*Base address of the peripherals which are hanging on on IOPORT bus*/
#define GPIOA_BASEADDR 		(IOPORT_BASE + 0x0000)
#define GPIOB_BASEADDR 		(IOPORT_BASE + 0x0400)
#define GPIOC_BASEADDR 		(IOPORT_BASE + 0x0800)
#define GPIOD_BASEADDR 		(IOPORT_BASE + 0x0C00)
#define GPIOE_BASEADDR 		(IOPORT_BASE + 0x1000)
#define GPIOF_BASEADDR 		(IOPORT_BASE + 0x1400)

/*Base address of the peripherals which are hanging on AHB*/
#define EXTI_BASEADDR 		(AHBPERIPH_BASE + 0x1800)
#define RCC_BASEADDR		(AHBPERIPH_BASE + 0x1000)
/*Base address of the peripherals which are hanging on APB*/
#define USART6_BASEADDR 	(APBPERIPH_BASE + 0x13C00)
#define USART1_BASEADDR 	(APBPERIPH_BASE + 0x13800)
#define SPI1_BASEADDR 		(APBPERIPH_BASE + 0x13000)
#define SYSCFG_BASEADDR 	(APBPERIPH_BASE + 0x10000)
#define I2C3_BASEADDR 		(APBPERIPH_BASE + 0x8800)
#define I2C2_BASEADDR 		(APBPERIPH_BASE + 0x5800)
#define I2C1_BASEADDR 		(APBPERIPH_BASE + 0x5400)
#define USART5_BASEADDR 	(APBPERIPH_BASE + 0x5000)
#define USART4_BASEADDR 	(APBPERIPH_BASE + 0x4C00)
#define USART3_BASEADDR 	(APBPERIPH_BASE + 0x4800)
#define USART2_BASEADDR 	(APBPERIPH_BASE + 0x4400)
#define SPI3_BASEADDR 		(APBPERIPH_BASE + 0x3C00)
#define SPI2_BASEADDR 		(APBPERIPH_BASE + 0x3800)

//GPIO Registers
typedef struct
{
	volatile uint32_t MODER;	// 00
	volatile uint32_t OTYPER;	// 04
	volatile uint32_t OSPEEDR;	// 08
	volatile uint32_t PUPDR;	// 0c
	volatile uint32_t IDR;		// 10
	volatile uint32_t ODR;		// 14
	volatile uint32_t BSRR;		// 18
	volatile uint32_t LCKR;		// 1C
	volatile uint32_t AFR[2];	// 20 and 24
	volatile uint32_t BRR;		// 28
}GPIO_RegDef_t;

//peripheral register definition structure for EXTI
typedef struct
{
	volatile uint32_t RTSR1;		// 00
	volatile uint32_t FTSR1;		// 04
	volatile uint32_t SWIER1;		// 08
	volatile uint32_t RPR1;			// 0c
	volatile uint32_t FPR1;			// 10
	volatile uint32_t RESERVED1;	// 14
	volatile uint32_t RESERVED2;	// 18
	volatile uint32_t RESERVED3;	// 1C
	volatile uint32_t RESERVED4;	// 20
	volatile uint32_t RESERVED5;	// 24
	volatile uint32_t RTSR2;		// 28
	volatile uint32_t FTSR2;		// 2C
	volatile uint32_t SWIER2;		// 30
	volatile uint32_t RPR2;			// 34
	volatile uint32_t FPR2;			// 38
	volatile uint32_t RESERVED6;	// 3C
	volatile uint32_t RESERVED7;	// 40
	volatile uint32_t RESERVED8;	// 44
	volatile uint32_t RESERVED9;	// 48
	volatile uint32_t RESERVED10;	// 4C
	volatile uint32_t RESERVED11;	// 50
	volatile uint32_t RESERVED12;	// 54
	volatile uint32_t RESERVED13;	// 58
	volatile uint32_t RESERVED14;	// 5C
	volatile uint32_t EXTICR1;		// 60
	volatile uint32_t EXTICR2;		// 64
	volatile uint32_t EXTICR3;		// 68
	volatile uint32_t EXTICR4;		// 6C
	volatile uint32_t RESERVED15;	// 70
	volatile uint32_t RESERVED16;	// 74
	volatile uint32_t RESERVED17;	// 78
	volatile uint32_t RESERVED18;	// 7C
	volatile uint32_t IMR1;			// 80
	volatile uint32_t EMR1;			// 84
	volatile uint32_t RESERVED19;	// 88
	volatile uint32_t RESERVED20;	// 8C
	volatile uint32_t IMR2;			// 90
	volatile uint32_t EMR2;			// 94

}EXTI_RegDef_t;

//Reset Clock Control Registers
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t ICSCR;
	volatile uint32_t CFGR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t Reserved;
	volatile uint32_t CRRCR;
	volatile uint32_t CIER;
	volatile uint32_t CIFR;
	volatile uint32_t CICR;
	volatile uint32_t IOPRSTR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t APBRSTR1;
	volatile uint32_t APBRSTR2;
	volatile uint32_t IOPENR;
	volatile uint32_t AHBENR;
	volatile uint32_t APBENR1;
	volatile uint32_t APBENR2;
	volatile uint32_t IOPSMENR;
	volatile uint32_t AHBSMENR;
	volatile uint32_t APBSMENR1;
	volatile uint32_t APBSMENR2;
	volatile uint32_t CCIPR;
	volatile uint32_t CCIPR2;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_RegDef_t;

/*Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)*/
#define GPIOA	((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB	((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC	((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD	((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE	((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF	((GPIO_RegDef_t*) GPIOF_BASEADDR)

#define RCR		((RCC_RegDef_t*) RCC_BASEADDR)
#define EXTI	((EXTI_RegDef_t*) EXTI_BASEADDR)

/*Clock enable macros for GPIOx peripherals*/
#define GPIOA_PCLK_EN() (RCR -> IOPENR |= (1<<0))
#define GPIOB_PCLK_EN() (RCR -> IOPENR |= (1<<1))
#define GPIOC_PCLK_EN() (RCR -> IOPENR |= (1<<2))
#define GPIOD_PCLK_EN() (RCR -> IOPENR |= (1<<3))
#define GPIOE_PCLK_EN() (RCR -> IOPENR |= (1<<4))
#define GPIOF_PCLK_EN() (RCR -> IOPENR |= (1<<5))


/*Clock enable macros for I2C peripherals*/
#define I2C1_PCLK_EN() (RCR -> APBENR1 |= (1<<21))
#define I2C2_PCLK_EN() (RCR -> APBENR1 |= (1<<22))
#define I2C3_PCLK_EN() (RCR -> APBENR1 |= (1<<23))

/*Clock enable macros for SPI peripherals*/
#define SPI1_PCLK_EN() (RCR -> APBENR2 |= (1<<12))
#define SPI2_PCLK_EN() (RCR -> APBENR1 |= (1<<14))
#define SPI3_PCLK_EN() (RCR -> APBENR1 |= (1<<15))

/*Clock enable macros for USART peripherals*/
#define USART1_PCLK_EN() (RCR -> APBENR2 |= (1<<14))
#define USART2_PCLK_EN() (RCR -> APBENR1 |= (1<<17))
#define USART3_PCLK_EN() (RCR -> APBENR1 |= (1<<18))
#define USART4_PCLK_EN() (RCR -> APBENR1 |= (1<<19))
#define USART5_PCLK_EN() (RCR -> APBENR1 |= (1<<8))
#define USART6_PCLK_EN() (RCR -> APBENR1 |= (1<<9))

/*Clock enable macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_EN() (RCR -> APBENR2 |= (1<<0))

/*Clock disable macros for GPIOx peripherals*/
#define GPIOA_PCLK_DI() (RCR -> IOPENR &= ~(1<<0))
#define GPIOB_PCLK_DI() (RCR -> IOPENR &= ~(1<<1))
#define GPIOC_PCLK_DI() (RCR -> IOPENR &= ~(1<<2))
#define GPIOD_PCLK_DI() (RCR -> IOPENR &= ~(1<<3))
#define GPIOE_PCLK_DI() (RCR -> IOPENR &= ~(1<<4))
#define GPIOF_PCLK_DI() (RCR -> IOPENR &= ~(1<<5))

/*Clock disable macros for I2C peripherals*/
#define I2C1_PCLK_DI() (RCR -> APBENR1 &= ~(1<<21))
#define I2C2_PCLK_DI() (RCR -> APBENR1 &= ~(1<<22))
#define I2C3_PCLK_DI() (RCR -> APBENR1 &= ~(1<<23))

/*Clock disable macros for SPI peripherals*/
#define SPI1_PCLK_DI() (RCR -> APBENR2 &= ~(1<<12))
#define SPI2_PCLK_DI() (RCR -> APBENR1 &= ~(1<<14))
#define SPI3_PCLK_DI() (RCR -> APBENR1 &= ~(1<<15))

/*Clock disable macros for USART peripherals*/
#define USART1_PCLK_DI() (RCR -> APBENR2 &= ~(1<<14))
#define USART2_PCLK_DI() (RCR -> APBENR1 &= ~(1<<17))
#define USART3_PCLK_DI() (RCR -> APBENR1 &= ~(1<<18))
#define USART4_PCLK_DI() (RCR -> APBENR1 &= ~(1<<19))
#define USART5_PCLK_DI() (RCR -> APBENR1 &= ~(1<<8))
#define USART6_PCLK_DI() (RCR -> APBENR1 &= ~(1<<9))

/*Clock disable macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_DI() 	(RCR -> APBENR2 &= ~(1<<0))

/*Macros to rest GPIOx peripherals*/
#define GPIOA_REG_RST()		do{(RCR -> IOPRSTR |=(1<<0)); (RCR -> IOPRSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RST()		do{(RCR -> IOPRSTR |=(1<<1)); (RCR -> IOPRSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RST()		do{(RCR -> IOPRSTR |=(1<<2)); (RCR -> IOPRSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RST()		do{(RCR -> IOPRSTR |=(1<<3)); (RCR -> IOPRSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RST()		do{(RCR -> IOPRSTR |=(1<<4)); (RCR -> IOPRSTR &= ~(1<<4));}while(0)
#define GPIOF_REG_RST()		do{(RCR -> IOPRSTR |=(1<<5)); (RCR -> IOPRSTR &= ~(1<<5));}while(0)


#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

#include "stm32f106_gpio.h"

#endif /* INC_STM32F106CBT6_H_ */




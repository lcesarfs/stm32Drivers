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


typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
	volatile uint32_t BRR;
}GPIO_RegDef_t;


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

#define RCR		((GPIO_RegDef_t*) RCC_BASEADDR)

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
#define SPI2_PCLK_EN() (RCR -> APBENR2 |= (1<<12))
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
#define SPI2_PCLK_DI() (RCR -> APBENR2 &= ~(1<<12))
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
#define SYSCFG_PCLK_DI() (RCR -> APBENR2 &= ~(1<<0))

#endif /* INC_STM32F106CBT6_H_ */




/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */



//Mastering_Embedded System online diploma
typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC    0x40021000
#define RCC_CR      *(volatile uint32_t *)(RCC + 0x00)
#define RCC_CFGR    *(volatile uint32_t *)(RCC + 0x04)
#define RCC_APB2ENR *(volatile uint32_t *)(RCC + 0x18)

int main(void)
{
	//init clock for GPIOA
	RCC_CFGR |= (0b10<<0); // SW it's 0b10 >> (PLLCLK)
	RCC_CFGR |= (0b0110<<18); //PLLMUL to * 8 so SYSCLK = 32MHZ

	RCC_CR |= (1UL<<24); // Enable PLL (4MHZ)
	RCC_CFGR |= (1UL<<16); // PLLSCR to choose the HSI freq /2 >> enables PLLON
	RCC_CFGR |= (0b0000<<4); // HPRE (AHB prescaler) by default it's 0b0xxx because of reset value(32MHZ )
	RCC_CFGR |= (0b100<<24); // MCO to out SYSCLK

	RCC_CFGR |= (0b101<<11); // Bits 13:11 PPRE2: APB high-speed prescaler (APB2) to be devided by 4 ( 8MHZ)
	RCC_CFGR |= (0b100<<8); //PPRE1: APB low-speed prescaler (APB1) to be devided by 2 (16MHZ)

	RCC_APB2ENR |=(1UL<<2);	//IOPAEN: IO port A clock enable > 1

	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}

/*
 * gpio_user.c
 *
 *  Created on: Jul 19, 2022
 *      Author: oscar
 */

#include "gpio_user.h"

void GPIO_PB2_Init(void) {
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOBEN);

	GPIOB->MODER &= ~(GPIO_MODER_MODER2);
	GPIOB->MODER |= (GPIO_MODER_MODER2_0);
	GPIOB->MODER &= ~(GPIO_MODER_MODER2_1);

	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT2);

	GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR2);

	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR2);
}

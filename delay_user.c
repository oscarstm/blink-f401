/*
 * delay_user.c
 *
 *  Created on: Jul 20, 2022
 *      Author: oscar
 */

#include "delay_user.h"

void delay(uint16_t ms) {
	if (ms == 0) {
		return;
	}
	/*
	 * Counter settings
	 * */

	RCC->APB1ENR |= (RCC_APB1ENR_TIM5EN);

	TIM5->CR1 &= ~(TIM_CR1_CEN);

	TIM5->SR = 0;
	TIM5->CNT = 0;
	TIM5->PSC = 8400 - 1; // 10 KHz
	TIM5->ARR = ms - 1;

	TIM5->CR1 |= (TIM_CR1_CEN);
	TIM5->CR1 &= ~(TIM_CR1_DIR);

	TIM5->DIER |= (TIM_DIER_UIE);

	NVIC_EnableIRQ(TIM5_IRQn);

	while ((TIM5->SR & (TIM_SR_UIF)) == 0) {
		//
	}
}


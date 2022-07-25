#include "stm32f4xx.h"
#include "clk_user.h"
#include "delay_user.h"
#include "gpio_user.h"

volatile uint8_t count = 0;

int main(void) {
	clk_user();
	/*
	 * GPIO
	 */
	GPIO_PB2_Init();
	delay(10000);

	while (1) {
		/*GPIOB->ODR |= (GPIO_ODR_ODR_2);
		 delay(1000);
		 GPIOB->ODR &= ~(GPIO_ODR_ODR_2);
		 delay(1000);*/
	}

}
void TIM5_IRQHandler(void) {
	if ((TIM5->SR & (TIM_SR_UIF)) != 0) {
		TIM5->SR &= ~(TIM_SR_UIF);
		switch (count) {
		case 0:
			GPIOB->ODR |= (GPIO_ODR_ODR_2);
			break;
		case 1:
			GPIOB->ODR &= ~(GPIO_ODR_ODR_2);
			break;
		}
		count++;
		if (count > 1) {
			count = 0;
		}
	}
}


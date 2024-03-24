#include "stdio.h"
#include "Platform_Types.h"

#define RCC_BASE         0x40021000
#define APB2ENR_OFFSET   0x18
#define AFIO_base 0x40010000

#define GPIO_PORTA       0x40010800
#define PA_CRH_OFFSET    0x04
#define PA_ODR_OFFSET    0x0C

#define APB2ENR      *((vuint32_t*)(RCC_BASE  +APB2ENR_OFFSET))
#define CRH          *((vuint32_t*)(GPIO_PORTA+PA_CRH_OFFSET))
#define ODR          *((vuint32_t*)(GPIO_PORTA+PA_ODR_OFFSET))
#define AFIO_EXTICR1  *((volatile uint32 *)(AFIO_base + 0x8)) // External interrupt config for PA0 for EXTI0

#define GPIOA_CRL  *((vuint32_t*)(GPIO_PORTA+ 0x00)) //to enable floating input on PA0 (1<<0)

#define EXTI_base 0x40010400
#define EXTI_IMR  *((volatile uint32 *)(EXTI_base + 0x00)) // MASK FOR PORT A 0

#define EXTI_RTSR *((volatile uint32 *)(EXTI_base + 0x08)) // TRIGGER FOR RISING EDGE

#define EXTI_PR  *((volatile uint32 *)(EXTI_base + 0x14)) // WRITE 1 TO CLEAR PENDING REQ AFTER TAKING ACTION (ACKNOLEDGE )

#define NVIC_ISER0  *((volatile uint32 *)(0xE000E100))

void clock_init(void){

	APB2ENR |= (1<<2);
	APB2ENR |= (1<<0);
}

void GPIOA_INIT(void){
	CRH &= 0xff0fffff;
	CRH |= 0x00200000;
	GPIOA_CRL |= (1<<2);


}


int main(void){
	clock_init();
	GPIOA_INIT();

	AFIO_EXTICR1 = 0;

	EXTI_RTSR |= (1<<0);

	EXTI_IMR |= (1<<0);
	NVIC_ISER0 |= (1<<6);

	while(1);

}


void EXTI0_IRQHandler(void){
	ODR ^= (1<<13);// toggle the led on PA 13

	EXTI_PR |= (1<<0); //to ACK

}

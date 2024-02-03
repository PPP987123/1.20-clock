#include "tim.h"
#include "led.h"
#include "stdlib.h"
#include "stdio.h"
void TIM3_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
	NVIC_InitTypeDef NVIC_Initstructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_BaseInitStructure.TIM_Period = arr-1;
	TIM_BaseInitStructure.TIM_Prescaler = psc-1;
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_BaseInitStructure);
	
	NVIC_Initstructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_Initstructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_Initstructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Initstructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);	
	TIM_Cmd(TIM3,ENABLE);						//开启定时器
}
uint8_t tim_flag_s=0;

//秒针计时
void tim_clock(void){
	tim_flag_s++;
}

void TIM3_IRQHandler(void)				
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		tim_clock();
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}

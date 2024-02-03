#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "stdio.h"
#include "OLED.h"
#include "stdlib.h"
#include "stdio.h"

#define MAX_TIM 60

extern uint8_t tim_flag_s;

int main(void)
{
	TIM3_Init(10000,4200);
	OLED_Init();
	uint8_t tim_flag_m=0;
	uint8_t tim_flag_h=0;
	
	while(1){
		OLED_ShowNum(1,1,tim_flag_s);
		if(tim_flag_s>=MAX_TIM){
			tim_flag_s=0;
			tim_flag_m++;
			OLED_ShowNum(2,1,tim_flag_m);
		}
		else if(tim_flag_m>=MAX_TIM){
			tim_flag_m=0;
			tim_flag_h++;
			OLED_ShowNum(3,1,tim_flag_h);
		}
	}
	
}


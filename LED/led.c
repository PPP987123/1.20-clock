#include "led.h"  
#include "delay.h"
#include "OLED.h"
#include "string.h"
#include "stdlib.h"

//extern void led_out_gpio(uint8_t arg_int, int led_n);
//extern uint8_t led_in_gpio(int led_n);

//void led_set_level(pLED_Class pthis,const int led_n,const led_bit led_level);
//void led_set_level_arr(pLED_Class pthis,const led_bits led_sta);
//void led_read_level(pLED_Class pthis,const int led_n,led_bit *led_level);
//void led_read_level_arr(pLED_Class pthis, led_bits* led_sta);

///*********************
//�޲ι���
//*********************/
//pLED_Class createLedClass(void){
//	pLED_Class led_c = (pLED_Class)malloc(sizeof(LED_Class));//malloc�����ڴ�ռ�
//	
//	if(led_c == NULL){				//��ֹ����Ұָ��
//		return NULL;
//	}
//	led_c ->led_amount = 0;
//	led_c ->led_curent_level = (led_bits)0;   
//	led_c ->set_level = led_set_level;   		//���õ���LED״̬
//	led_c ->set_level_arr = led_set_level_arr; 	//���ö��LED״̬
//	led_c ->set_level_arr(led_c,(led_bits)0x00);
//	
//	return led_c;
//}
///*********************
//�вι���
//*********************/
//pLED_Class createLedClassWtihArgs(int led_amount){
//	pLED_Class led_c = createLedClass();
//	if(led_c == NULL){				//��ֹ����Ұָ��
//		return NULL;
//	}
//	led_c ->led_amount = led_amount;
//}

//void led_set_level(pLED_Class pthis,const int led_n,const led_bit led_level){	//pLED_Class pthis������ָ��
//	led_out_gpio((uint8_t)led_level,led_n);										//led_nĳһλ��LED��led_level��ƽ
//	//
//	pthis ->led_curent_level &= ~(0x1 << led_n);								//����nλLED��0
//	pthis ->led_curent_level |= (led_level << led_n);							//��led_level����nλ���ֵ �� led_curent_level
//}

//void led_set_level_arr(pLED_Class pthis, const led_bits led_sta){				//��λд
//	for(int i=0;i < pthis -> led_amount;++i){                                   //ʹ��ѭ���޸�LEDÿ����˸��״̬��λ������
//		led_out_gpio((uint8_t)(led_sta >> i)&1,i);
//	}
//	pthis -> led_curent_level = led_sta;
//}

//void led_read_level(pLED_Class pthis,const int led_n,led_bit *led_level){	
//	*led_level = (led_bits)led_in_gpio(led_n);									
//	pthis ->led_curent_level &= ~(0x1 << led_n);								
//	pthis ->led_curent_level |= (*led_level << led_n);		
//	
//}

//void led_read_level_arr(pLED_Class pthis, led_bits *led_sta){				
//	for(int i=0;i < pthis -> led_amount;++i){                                   
//		*led_sta &=~(0x01 << i);
//		*led_sta |=(led_bits)led_in_gpio(i)<<i;
//		
//	}
//	pthis -> led_curent_level = *led_sta;
//}

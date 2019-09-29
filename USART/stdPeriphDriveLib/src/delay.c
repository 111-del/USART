#include "delay.h"
#include "stm32f10x_conf.h"

static unsigned short int mul_us = 0;	//����us�ı���
static unsigned short int mul_ms = 0;	//����ms�ı���

void delay_init(void){
	
	SysTick_CLKSourceConfig( SysTick_CLKSource_HCLK_Div8 );
	
	SysTick -> CTRL &= 0x0000;	//���õ�������ʱ����Ӧ��ʽ��1Ϊ�жϣ�0Ϊ����Ӧ  0000 
	mul_us = SystemCoreClock / 8000000;
	mul_ms = mul_us * 1000;
}

void delay_ms( unsigned short int mstime ){
	SysTick -> LOAD = mul_ms * mstime;
	SysTick -> VAL  = 0x00;
	SysTick -> CTRL = 0x01;
	while( ( SysTick -> CTRL & 1<<16 ) == 0 );
	SysTick -> CTRL = 0x00;
}
void delay_us( unsigned int ustime ){
	SysTick -> LOAD = mul_us * ustime;
	SysTick -> VAL  = 0x00;
	SysTick -> CTRL = 0x01;
	while( ( SysTick -> CTRL & 1<<16 ) == 0 );
	SysTick -> CTRL = 0x00;
}

void delay_se( unsigned char setime ){
	SysTick -> LOAD = mul_ms * 1000;
	SysTick -> VAL  = 0x00;
	SysTick -> CTRL = 0x01;
	
	while(1){
		if ( setime > 0 ){
			while( ( SysTick -> CTRL & 1<<16 ) == 0 );
			setime--;
		}else{
			SysTick -> CTRL = 0x00;
			break;
		}
	}
	
}

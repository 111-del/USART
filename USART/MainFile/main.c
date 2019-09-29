#include "stm32f10x_conf.h"
#include "UART.h"

int main(){
	
	uint8_t res;   //接收到的数据
	
	USARTNV();
	
	USART_SEND_DATA( USART1, "你好！" );
	
	while(1){
	
		if( USART_GetFlagStatus( USART1, USART_FLAG_RXNE ) != 0 ){
			
			res = USART1 -> DR;
			while( USART_GetFlagStatus( USART1, USART_FLAG_TC ) == 0 );
			USART1 -> DR = res;
			
		}
					   
	}
}

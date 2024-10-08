#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h"
/************************************************
 
************************************************/

int main(void)
{
	Cache_Enable();                 //打开L1-Cache
	HAL_Init();				        //初始化HAL库
	Stm32_Clock_Init(160,5,2,4);    //设置时钟,400Mhz 
	delay_init(400);				//延时初始化
	uart_init(115200);				//串口初始化
	LED_Init();						//初始化LED
	while(1)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET); //PE13置0
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET); //PE14置0
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_RESET); //PE15置0
		delay_ms(500);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);	//PE13置1
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);	//PE14置1
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_SET);  //PE15置1
		delay_ms(500);
	}
}


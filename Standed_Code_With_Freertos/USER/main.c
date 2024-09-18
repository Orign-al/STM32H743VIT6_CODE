#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h"

#include "freertos.h"
#include "task.h"
/************************************************
 
************************************************/


static void led1_task(void *args) {
	while (1){
	
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET); //PE13��0
		vTaskDelay(1000);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);	//PE13��1
		vTaskDelay(1000);
	}
	
	
	
}

static void led2_task(void *args) {
	while (1){
	
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET); //PE13��0
		vTaskDelay(1000);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);	//PE13��1
		vTaskDelay(1000);
		
	}
	
	
	
}



int main(void)
{
	Cache_Enable();                 //��L1-Cache
	HAL_Init();				        //��ʼ��HAL��
	Stm32_Clock_Init(160,5,2,4);    //����ʱ��,400Mhz 
	delay_init(400);				//��ʱ��ʼ��
	uart_init(115200);				//���ڳ�ʼ��
	LED_Init();						//��ʼ��LED
	
	xTaskCreate(led1_task, "led", configMINIMAL_STACK_SIZE, NULL, 2, NULL );
	xTaskCreate(led2_task, "led", configMINIMAL_STACK_SIZE, NULL, 2, NULL );

	vTaskStartScheduler();

	
	while(1)
	{
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET); //PE13��0
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET); //PE14��0
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_RESET); //PE15��0
//		delay_ms(500);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);	//PE13��1
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);	//PE14��1
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_SET);  //PE15��1
//		delay_ms(500);
	}
}


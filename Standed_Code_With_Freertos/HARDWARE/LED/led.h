#ifndef _LED_H
#define _LED_H
#include "sys.h"	

//LED端口定义
//LED端口定义
#define LED0(n)		(n?HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET))
#define LED0_Toggle (HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13)) //LED0输出电平翻转
#define LED1(n)		(n?HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET))
#define LED1_Toggle (HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14)) //LED1输出电平翻转
#define LED2(n)		(n?HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_RESET))
#define LED2_Toggle (HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_15)) //LED1输出电平翻转

void LED_Init(void); //LED初始化函数
#endif

## STM32H743VIT6 介绍

STM32H743VIT6 是一款基于ARM Cortex-M7内核的高性能MCU，具有丰富的特性，可满足各类应用的需求。

- 主频：216MHz
- 片上SRAM：128KB
- 片上Flash：512KB



### Freertos支持
    使用FreeRTOS202212.01版本

#### RTOS API 介绍
- 任务管理api

    - 动态方式创建任务 xTaskCreate

        - 任务所需的栈空间由系统自动分配，从FreeRTOS的堆中分配

        -创建流程:
        ~~~
        1、将宏configSUPPORT_DYNAMIC_ALLOCATION设置为1
        2、定义函数入口参数
        3、编写任务函数
        ~~~
        
    - 静态方式创建任务 xTaskCreateStatic

        - 定义前需要有空闲任务，任务堆栈，TCB，定时器任务（可选）
        - 任务所需的栈空间由用户提供，需要提前分配
        - 返回值：任务句柄

        -创建流程：
        ~~~
        1、将宏configSUPPORT_STATIC_ALLOCATION设置为1
        2、定义空闲任务&定时器任务的任务堆栈及TCB
        3、实现两个接口函数 vApplicationGetIdleTaskMemory & vApplicationGetTimerTaskMemory
        4、定义函数入口参数
        5、编写任务函数
        ~~~

    - 删除任务 vTaskDelete(TankHandle_t xTaskToDelete);
        
        - 用于删除已经被创建的任务
        - 传入null 则删除当前任务（正在运行的）
        - 空闲任务(其他任务)会删除   系统分配的内存  而用户在删除前面申请的内存！！要提前释放！！！
        -删除流程
        ~~~
        1、将宏INCLUDE_vTaskDelete设置为1
        2、入口参数输入要删除的任务句柄
        ~~~

    - 任务控制块 tskTaskControlBlock   （TCB）
        - 每个任务都有唯一的TCB

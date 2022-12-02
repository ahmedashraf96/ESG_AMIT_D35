#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "FreeRTOS.h"
#include "task.h"

void taskInit(void* pvParameters)
{
    while(1)
    {
        hled_init(LED0);
        hled_init(LED1);
        hled_init(LED2);

        vTaskDelete(NULL);
    }

    return;
}

void task1(void* pvParameters)
{
    while(1)
    {
        hled_toggleLedValue(LED0);
        vTaskDelay((const TickType_t)1000);
    }

    return;
}

void task2(void* pvParameters)
{
    while(1)
    {
        hled_toggleLedValue(LED1);
        vTaskDelay((const TickType_t)500);
    }

    return;
}

void task3(void* pvParameters)
{
    while(1)
    {
        hled_toggleLedValue(LED2);
        vTaskDelay((const TickType_t)250);
    }

    return;
}

int main(void)
{
    xTaskCreate(taskInit, "Init", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
    xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(task3, "task3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1)
    {
        /*Report system failure*/
    }

    return 0;
}
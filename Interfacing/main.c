#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

SemaphoreHandle_t xSemaphore;

void taskInit(void* pvParameters)
{
    while(1)
    {
        xSemaphore = xSemaphoreCreateBinary();

        hled_init(LED0);
        hpbutt_init(PUSH_BUTTON_0);

        vTaskDelete(NULL);
    }

    return;
}

void pbTask(void* pvParameters)
{
    u8_t pbStatus;

    while(1)
    {
        hpbutt_getStatus(PUSH_BUTTON_0, &pbStatus);
        
        if(pbStatus == PRESSED)
        {
            xSemaphoreGive(xSemaphore);
        }
        else
        {
            /*Do nothing*/
        }

        vTaskDelay((TickType_t) 100);
    }

    return;
}

void ledTask(void* pvParameters)
{
    while(1)
    {
        if(xSemaphoreTake(xSemaphore, (TickType_t)10) == pdTRUE)
        {
            hled_toggleLedValue(LED0);
        }
        else
        {
            /*Do nothing*/
        }

        vTaskDelay((TickType_t) 100);
    }

    return;
}


int main(void)
{
    xTaskCreate(taskInit, "Init", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(pbTask, "PB", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(ledTask, "LED", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1)
    {
        /*Report system failure*/
    }

    return 0;
}
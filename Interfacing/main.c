#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

QueueHandle_t xQueueHandler;

void taskInit(void* pvParameters)
{
    while(1)
    {
        xQueueHandler = xQueueCreate(1, sizeof(u8_t));
        hled_init(LED0);

        vTaskDelete(NULL);
    }

    return;
}

void msgTask1(void* pvParameters)
{
    static u8_t x = 'A';

    while(1)
    {
        if(x == 'A')
        {
            x = 'B';
        }
        else if(x == 'B')
        {
            x = 'A';
        }
        else
        {
            /*Do nothing*/
        }

        xQueueSend(xQueueHandler, (const void*)&x, (TickType_t)10);

        vTaskDelay(1000);
    }

    return;
}

void msgTask2(void* pvParameters)
{
    u8_t tempData;
  
    while(1)
    {
        if( xQueueReceive(xQueueHandler, (void* const)&tempData, (TickType_t)10) == pdTRUE )
        {
            if(tempData == 'A')
            {
                hled_ledValueON(LED0);
            }
            else if(tempData == 'B')
            {
                hled_ledValueOFF(LED0);
            }
            else
            {
                /*Do nothing*/
            }
        }
        else
        {
            /*Do nothing*/
        }

        vTaskDelay(1000);
    }

    return;
}


int main(void)
{
    xTaskCreate(taskInit, "Init", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(msgTask1, "T1", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(msgTask2, "T2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1)
    {
        /*Report system failure*/
    }

    return 0;
}
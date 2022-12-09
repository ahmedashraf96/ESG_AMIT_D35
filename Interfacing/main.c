#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

#define LED0_EVENT    (1 << 0)
#define LED1_EVENT    (1 << 1)
#define LED2_EVENT    (1 << 2)

EventGroupHandle_t xEventGroup_handler;
EventBits_t xEventGroupBits;

void taskInit(void* pvParameters)
{
    while(1)
    {
        xEventGroup_handler = xEventGroupCreate();

        hled_init(LED0);
        hled_init(LED1);
        hled_init(LED2);

        hpbutt_init(PUSH_BUTTON_0);
        hpbutt_init(PUSH_BUTTON_1);
        hpbutt_init(PUSH_BUTTON_2);

        vTaskDelete(NULL);
    }

    return;
}

void pbTask(void* pvParameters)
{
    u8_t pb0_status = 0;
    u8_t pb1_status = 0;
    u8_t pb2_status = 0;
    u8_t eventsToSet = 0;

    while(1)
    {
        hpbutt_getStatus(PUSH_BUTTON_0, &pb0_status);
        hpbutt_getStatus(PUSH_BUTTON_1, &pb1_status);
        hpbutt_getStatus(PUSH_BUTTON_2, &pb2_status);

        if(pb0_status == PRESSED)
        {
            SET_BIT(eventsToSet, 0);
        }
        else
        {
            /*Do nothing*/
        }

        if(pb1_status == PRESSED)
        {
            SET_BIT(eventsToSet, 1);
        }
        else
        {
            /*Do nothing*/
        }

        if(pb2_status == PRESSED)
        {
            SET_BIT(eventsToSet, 2);
        }
        else
        {
            /*Do nothing*/
        }

        if(eventsToSet != 0)
        {
            xEventGroupSetBits(xEventGroup_handler, eventsToSet);
        }
        else
        {
            /*Do nothing*/
        }

        vTaskDelay(100);
    }

    return;
}

void ledTask(void* pvParameters)
{  
    while(1)
    {
        // Task will be blocked until one of the pb is pressed
        xEventGroupWaitBits(xEventGroup_handler, (LED0_EVENT | LED1_EVENT | LED2_EVENT), pdFALSE, pdFALSE, portMAX_DELAY);
        xEventGroupBits = xEventGroupGetBits(xEventGroup_handler);

        if(GET_BIT(xEventGroupBits, 0) == pdTRUE)
        {
            hled_toggleLedValue(LED0);
        }
        else
        {
            /*Do nothing*/
        }

        if(GET_BIT(xEventGroupBits, 1) == pdTRUE)
        {
            hled_toggleLedValue(LED1);
        }
        else
        {
            /*Do nothing*/
        }

        if(GET_BIT(xEventGroupBits, 2) == pdTRUE)
        {
            hled_toggleLedValue(LED2);
        }
        else
        {
            /*Do nothing*/
        }

        xEventGroupClearBits(xEventGroup_handler, (LED0_EVENT | LED1_EVENT | LED2_EVENT));
        
        vTaskDelay(100);
    }

    return;
}


int main(void)
{
    xTaskCreate(taskInit, "Init", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(pbTask, "T1", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(ledTask, "T2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1)
    {
        /*Report system failure*/
    }

    return 0;
}
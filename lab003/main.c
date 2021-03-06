#include "FreeRTOS.h"
#include "task.h"

#include "basic_io.h"

#define mainDELAY_LOOP_COUNT		(0xfffff)

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

unsigned long ulTaskNumber[configEXPECTED_NO_RUNNING_TASKS];

int main(void)
{
				
  xTaskCreate(vTask1, "Task 1", 200, (void *)'1', 1, NULL);

  xTaskCreate(vTask2, "Task 2", 200, NULL, 2, NULL);

  vTaskStartScheduler();

  for(;;);
}

void vTask1(void *pvParameters)
{
			
  volatile unsigned long ul;

  for(;;) {
		
		if( (unsigned char)pvParameters == '1' )
		{
			vPrintString("Task 1 is running\n");
		}
		else
		{
			vPrintString("Task 2 is running\n");
		}

    for(ul = 0; ul < mainDELAY_LOOP_COUNT; ul++) {

    }
  }
}

void vTask2(void *pvParameters)
{
  const char *pcTaskName = "Task 2 is running\n";
  volatile unsigned long ul;

  for(;;) {
    vPrintString( pcTaskName );

    for(ul = 0; ul < mainDELAY_LOOP_COUNT; ul++) {

      }
  }
}

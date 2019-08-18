#include "maintask.h"

#include "iconinit.h"
#include "paraminit.h"
#include "icon.h"
#include "gpio.h"
#include "ft5x06/ft5x16.h"
#include "gui/GUI.h"
#include "gui/usually.h"
#include "Src/../adc.h"
#include "mcp492x.h"
#include "mytimer.h"
#include "paramboady.h"
#include "rtc.h"
//#include "analogio.h"
int Ten_ms = 0;
int S = 0;
//#include "icon.h"
//using namespace iconinit;
void Task_Init()
{
	
	MCP_Init();
	GUI_Init();
	LCD_Clear(BLACK);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);	
	paraminit::init();
    iconinit::init();
	
	Init_Timer();


}




void Main_Task()
{

	Task_Init();
	
	while (1)
	{
		Main_Refresh();
		FT5X16_TrigEN(0);	
		GUI_FillCircle(FT5X16_GetX1(), FT5X16_GetY1(), 10);
		 
	}
}
void Main_SysTick()
{
	FT5X16_SYSTICK();
	parameter::parameter::Schedule();

	++Ten_ms;
	if (Ten_ms == 10)
	{
		Ten_ms = 0;	
	}
	++S;
	if (S == 1000)
	{
		S = 0;	
		if ((iconinit::Start.Get_IconStat() == 0)&&(iconinit::Stop.Get_IconStat() == 1))
		{
		//	if (iconinit::Volt.Value != paraminit::Voltage.Rel_Value){
				iconinit::Volt.Set_Value(paraminit::Voltage.Get_RValue());
				iconinit::Volt.Show_Value2();		
		//	}
		//	if (iconinit::Amper.Value != paraminit::Current.Rel_Value){
				iconinit::Amper.Set_Value(paraminit::Current.Get_RValue());
				iconinit::Amper.Show_Value2();	
			//}
			if (iconinit::Time.Value != Get_ElapseTime())
			{
				int t = Get_ElapseTime();
				if (t >= 60)
				{
					iconinit::Time.Set_Value(t / 60);
					iconinit::Time.Set_IconCaption2("Min");
					iconinit::Time.Show_IconCaption2();
					
				}
				else if (t<60)
				{
					iconinit::Time.Set_Value(t % 60);
					
					iconinit::Time.Set_IconCaption2("Sec");
				
					iconinit::Time.Show_IconCaption2();
				}
				
				iconinit::Time.Show_Value2();		
				iconinit::Time.Set_Value(Get_ElapseTime());
			}
			
			
			
		}
	}
	
}

void Main_Refresh()
{
	FT5X16_Refresh(200);
	icon::icon::Refresh();
	parameter::parameter::Refresh();
	
}

extern "C"
{

	void SysTick_Handler(void)
	{
		/* USER CODE BEGIN SysTick_IRQn 0 */

		/* USER CODE END SysTick_IRQn 0 */
		HAL_IncTick();
		Main_SysTick();
		
		/* USER CODE BEGIN SysTick_IRQn 1 */

		/* USER CODE END SysTick_IRQn 1 */
	}
	void EXTI15_10_IRQHandler(void)
	{
		/* USER CODE BEGIN EXTI15_10_IRQn 0 */
		
		/* USER CODE END EXTI15_10_IRQn 0 */
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
		/* USER CODE BEGIN EXTI15_10_IRQn 1 */

		/* USER CODE END EXTI15_10_IRQn 1 */
	}
	void EXTI2_IRQHandler(void)
	{
		/* USER CODE BEGIN EXTI2_IRQn 0 */

		/* USER CODE END EXTI2_IRQn 0 */
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
		/* USER CODE BEGIN EXTI2_IRQn 1 */
		FT5X16_TrigEN(1);

		/* USER CODE END EXTI2_IRQn 1 */
	}

	void RTC_IRQHandler(void)
	{
		/* USER CODE BEGIN RTC_IRQn 0 */
		Alarm_CallBack();
		//Cancel();
		  /* USER CODE END RTC_IRQn 0 */
		  HAL_RTCEx_RTCIRQHandler(&hrtc);
		HAL_RTC_AlarmIRQHandler(&hrtc);
		/* USER CODE BEGIN RTC_IRQn 1 */

		/* USER CODE END RTC_IRQn 1 */
	}
}
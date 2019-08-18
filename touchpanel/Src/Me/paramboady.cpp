#include "paramboady.h"
#include "parameter.h"
#include "paraminit.h"
#include "iconinit.h"
#include "MCP492x.h"
#include "tim.h"
#include "mytimer.h" 

extern  TIM_OC_InitTypeDef sConfigOC;
TIM_OC_InitTypeDef sConfigOC;
void Volt_Ev()
{
	
}
void Voltage_Ev()
{
	int Dac_Data = 0;
	if (paraminit::Voltage.Fall_Enable == 1)
	{
		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);	
		paraminit::Voltage.Rise_Enable = 0;	
		if ((MCP_GetDac(1)!=0)&&(paraminit::Voltage.Now_Value > 0))
		{
			
			MCP_FallDac(1);
		}
		else
		{
			MCP_SetValue(2, 0);
			paraminit::Voltage.Now_Value = 0;
			paraminit::Voltage.Fall_Enable = 0;
			Deactive_Alaram();
			iconinit::Time.Hide_Value2();
			iconinit::Volt.Hide_Value2();
			iconinit::Amper.Hide_Value2();
			iconinit::Start.Show_Icon();
			iconinit::Back.Show_Icon();
			
			//MCP_SetValue(1, 400);
			
		}
		
		
	}
	
	else if (paraminit::Voltage.Rise_Enable == 1)
	{
		//MCP_SetDac(1, 0);
		//paraminit::Voltage.Fall_Enable = 0;		
		//paraminit::Voltage.Now_Value = 0;
		if((paraminit::Voltage.Now_Value < paraminit::Voltage.Set_Value)) {
			/*&&(paraminit::Voltage.Now_Value < paraminit::Voltage.Max_Value)*/
			//++paraminit::Voltage.Now_Value; 
			MCP_RiseDac(1);
		paraminit::Voltage.Now_Value = (float)MCP_GetDac(1)*(float)(30.1/ 2048);
		}
		else
		{
			if (paraminit::Voltage.Now_Value >= paraminit::Voltage.Set_Value)
			{
				MCP_SetValue(2,(float)paraminit::Current.Set_Value*((float)(2048/30)));
				
				htim1.Init.Period = 10000 / (int)(paraminit::Freq.Set_Value);
				if (HAL_TIM_Base_Init(&htim1) != HAL_OK){Error_Handler();}
				sConfigOC.Pulse = ((int)paraminit::DC.Set_Value *100)/ (int)(paraminit::Freq.Set_Value);
				if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK){Error_Handler();}
				
				HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
				Set_Alarm(paraminit::Time.Set_Value);
					


			}
			paraminit::Voltage.Rise_Enable =0;
			
		}
		//paraminit::Voltage.Now_Value = 30;
		//	MCP_SetValue(1, (30 * 2048) / 30);
		//Dac_Data = (float)(paraminit::Voltage.Now_Value * 2048) / 30;
		//MCP_SetValue(1, Dac_Data);
		//MCP_SetValue(1,1500);
	}
//	MCP_SetValue(Voltage.Now_Value);
	
}

void Current_Ev()
{
	
	
	if (paraminit::Voltage.Rise_Enable == 1)
		{
			
			if ((paraminit::Voltage.Now_Value != paraminit::Voltage.Set_Value)&&(paraminit::Voltage.Now_Value < paraminit::Voltage.Max_Value)) {
				++paraminit::Voltage.Now_Value;
			}
			else
			{
				paraminit::Voltage.Rise_Enable == 0;
			}
		}
	//	MCP_SetValue(Voltage.Now_Value);
	}

void Alarm_CallBack()
{
	paraminit::Voltage.Rise_Enable = 0;
	paraminit::Voltage.Fall_Enable = 1;
}
/*void Set_DC(int i)
{
	sConfigOC.Pulse = 10;
	//if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK){Error_Handler();}
}*/
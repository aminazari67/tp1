#include "paraminit.h"
#include "parameter.h"
#include "paramboady.h"
#include "analogio.h"
#include "usart.h"
uint16_t ADC_DMA_Buffer[2];
namespace paraminit
{
	
	

	parameter::parameter Voltage;
	parameter::parameter Current;
	parameter::parameter Time;
	parameter::parameter Freq;
	parameter::parameter DC;
	
	parameter::parameter Motor;
	analogio::	analogio Volt;
	analogio::analogio Amp;
void init(){
	parameter::parameter::Load_Param();
	paraminit::Voltage.Set_Step();
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_DMA_Buffer,2);
	
	Voltage.Fall_Enable = 0;
	Voltage.Rise_Enable = 0;
	Voltage.Set_Handler(Voltage_Ev);
	Current.Fall_Enable = 0;
	Current.Rise_Enable = 0;
	Current.Set_Handler(Current_Ev);
	
	}
	
	
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	
	float DATA1 = (float)paraminit::Volt.Read(paraminit::Volt.ReadFifo(ADC_DMA_Buffer[0]));
	float DATA2 = (float)paraminit::Amp.Read(paraminit::Amp.ReadFifo(ADC_DMA_Buffer[1]));
	
	//paraminit::Voltage.Set_RValue(34.2);
	if (DATA1 !=-1)
	{
	//	HAL_UART_Transmit(&huart1, (unsigned char*)ADC_DMA_Buffer, 1, 100);
		paraminit::Voltage.Set_RValue(DATA1);
			//char dbuff[10];	printf(dbuff,"%d",ADC_DMA_Buffer[0]);
	}
	if (DATA2 != -1)
	{
		//	HAL_UART_Transmit(&huart1, (unsigned char*)ADC_DMA_Buffer, 1, 100);
			paraminit::Current.Set_RValue(DATA2);
		//char dbuff[10];	printf(dbuff,"%d",ADC_DMA_Buffer[0]);
	}
	//HAL_ADC_Start_DMA(&hadc1, ADC_DMA_Buffer, 2);
	
	//	HAL_ADC_Start_DMA(&hadc1, adcdma, 2);
}	
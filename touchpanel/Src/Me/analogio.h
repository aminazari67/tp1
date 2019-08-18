#pragma once
#include "stm32f1xx_hal.h"
#include "Src/../adc.h"
namespace analogio
{

	class analogio
	{
	public:
		analogio();
		~analogio();
	private:
		int size;
		float Avereage;
		float FifoAvereage;
		int Sum;
		int Index;
		int Data[10];
		int Count;
	
		int ADC_CH;
	public:
		uint32_t ADC_Buff[10];

		void Write(float data);
		float Read(float data);
		float ReadFifo(float data);
		float Get_Avereage();
		static void Init();
	};
}

#include "analogio.h"
namespace analogio
{
	analogio::analogio()
	{
		size = 10;
		Avereage = 0;
		Sum = 0;
		Index = 0;
		//
	}


	analogio::~analogio()
	{
	}


	void analogio::Write(float data)
	{
	}


	float analogio::ReadFifo(float data)
	{
		Data[Index] = data;
		Sum += Data[Index];

		Index = (Index + 1) % (size);

		Sum -= Data[Index];
		FifoAvereage = Sum / size;
		//HAL_ADC_Start_DMA(&hadc1, ADC_Buff, 1);
	
	
		return FifoAvereage;
	}

	float analogio::Read(float data)
	{
	
		Avereage = ReadFifo(data);
		Count++;
		if (Count >= size)
		{	
			Count = 0;
			return Avereage;
		}
		return -1;
	}
	float analogio::Get_Avereage()
	{
		return Avereage;
	}
	void analogio::Init()
	{
		//analogio Volt;
	}
}
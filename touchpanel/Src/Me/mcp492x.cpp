#include "mcp492x.h"
#include "stm32f1xx_hal.h"
#include "spi.h"
int Dac[3];
void MCP_Init()
{
	Dac[1] = 0;Dac[2] = 0;
	MCP_LDAC(1);
	MCP_CS(0);
	MCP_SetValue(1,0);
	MCP_SetValue(2,300);

	
}
void MCP_CS(int i)
{
	switch (i)
	{
	case 0:
		HAL_GPIO_WritePin(MCP_CS1_PORT, MCP_CS1_PIN, GPIO_PIN_SET);	
		HAL_GPIO_WritePin(MCP_CS2_PORT, MCP_CS2_PIN, GPIO_PIN_SET);	
		break;
	case 1:
		HAL_GPIO_WritePin(MCP_CS2_PORT, MCP_CS2_PIN, GPIO_PIN_SET);	
        HAL_GPIO_WritePin(MCP_CS1_PORT, MCP_CS1_PIN, GPIO_PIN_RESET);	
	break;
	case 2:
		HAL_GPIO_WritePin(MCP_CS1_PORT, MCP_CS1_PIN, GPIO_PIN_SET);	
		HAL_GPIO_WritePin(MCP_CS2_PORT, MCP_CS2_PIN, GPIO_PIN_RESET);	
		break;
	}
}
void MCP_LDAC(int i)
{
	switch (i)
	{
	case 0:
		HAL_GPIO_WritePin(MCP_LDAC1_PORT, MCP_LDAC1_PIN, GPIO_PIN_SET);	
		HAL_GPIO_WritePin(MCP_LDAC2_PORT, MCP_LDAC2_PIN, GPIO_PIN_SET);	
		break;
	case 1:
		HAL_GPIO_WritePin(MCP_LDAC2_PORT, MCP_LDAC2_PIN, GPIO_PIN_SET);	
		HAL_GPIO_WritePin(MCP_LDAC1_PORT, MCP_LDAC1_PIN, GPIO_PIN_RESET);	
		
		break;
	case 2:
		HAL_GPIO_WritePin(MCP_LDAC1_PORT, MCP_LDAC1_PIN, GPIO_PIN_RESET);	
		HAL_GPIO_WritePin(MCP_LDAC2_PORT, MCP_LDAC2_PIN, GPIO_PIN_RESET);	
		break;
	}
}
void MCP_SetValue(int i,int dac)
{
	if (dac<2048)
	{
		MCP_CS(i);
		
		//HAL_Delay(10);
		char d = 0x50 | (dac >> 8); //(dac << 8);//0x7f;
		char d2 =  dac&(0xFF); //dac;
		char dat[2];dat[0] = 0x50 | (dac >> 8);dat[1] = dac&(0xFF);
		char *data3;
		char *data4;
		data3 =&d;data4 =&d2;
		HAL_SPI_Transmit(&hspi2, (unsigned char*)dat, 2, 10000);	
		//HAL_SPI_Transmit(&hspi2, (unsigned char*)data3,1, 10000);	
		//HAL_SPI_Transmit(&hspi2, (unsigned char*)data4,1, 10000);	
		//HAL_Delay(10);
		//MCP_LDAC(0);
		MCP_CS(0);
	}
	
}
void MCP_RiseDac(int i)
{
	if (Dac[i]<2048)
	{
		++Dac[i];
		MCP_SetValue(i,Dac[i]);
	}
}
void MCP_FallDac(int i)
{
	if (Dac[i] >0)
	{
		--Dac[i];
		MCP_SetValue(i, Dac[i]);
	}
}
void MCP_SetDac(int i,int val)
{
	Dac[i] = val;
}
int MCP_GetDac(int i)
{
	return Dac[i];
}
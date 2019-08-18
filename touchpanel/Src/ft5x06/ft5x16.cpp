#include "ft5x16.h"
#include "i2c.h"
#include "usart.h"
#include "src/gui/GUI.h"
int FT5X16_Tick = 0;
int FT5X16_Trig = 0;
int FT5X16_X1 = 1000;
int FT5X16_Y1 = 1000;
int FT5X16_W1= 0;

void FT5X16_X()
{
	uint8_t i2c_buff1[2];
	HAL_I2C_Mem_Read(&hi2c2, (uint16_t)(0x38 << 1), 3, I2C_MEMADD_SIZE_8BIT, & i2c_buff1[0], 1, 500);
	HAL_I2C_Mem_Read(&hi2c2, (uint16_t)(0x38 << 1), 4, I2C_MEMADD_SIZE_8BIT, &i2c_buff1[1], 1, 500);
	//i2c_buff1[0] = 0x0d;i2c_buff1[1] = 0xab;
	FT5X16_X1 = ((i2c_buff1[0]&(0x0f)) << 8) + i2c_buff1[1];
	char txbuff[3];sprintf(txbuff, "X=%d", FT5X16_X1);//debug
	HAL_UART_Transmit(&huart1, (unsigned char*)txbuff, 6, 100); //debug
}
int FT5X16_GetX1()
{
	
	return FT5X16_X1;
}
 void FT5X16_Y()
{
	uint8_t i2c_buff1[2];
	
	HAL_I2C_Mem_Read(&hi2c2, (uint16_t)(0x38 << 1), 5, I2C_MEMADD_SIZE_8BIT, & i2c_buff1[0], 1, 500);
	HAL_I2C_Mem_Read(&hi2c2, (uint16_t)(0x38 << 1), 6, I2C_MEMADD_SIZE_8BIT, &i2c_buff1[1], 1, 500);
	//i2c_buff1[0] = 0x0d;i2c_buff1[1] = 0xab;
	FT5X16_Y1 = ((i2c_buff1[0]&(0x0f)) << 8) + i2c_buff1[1];
		
	char txbuff[10]; sprintf(txbuff, "Y=%d", FT5X16_Y1);
	HAL_UART_Transmit(&huart1, (unsigned char*)txbuff, 6, 100);  //debug
}
void FT5X16_W()
{
	uint8_t i2c_buff1[2];
	
	HAL_I2C_Mem_Read(&hi2c2, (uint16_t)(0x38 << 1), 7, I2C_MEMADD_SIZE_8BIT, & i2c_buff1[0], 1, 500);
	
	//i2c_buff1[0] = 0x0d;i2c_buff1[1] = 0xab;
	FT5X16_W1= i2c_buff1[0];
	char txbuff[10]; sprintf(txbuff, "W=%d", FT5X16_W1);
	HAL_UART_Transmit(&huart1, (unsigned char*)txbuff, 6, 100);   //debug

}
int FT5X16_GetW()
{
	return int(FT5X16_W1);
	//return 51;
}
int FT5X16_GetY1()
{
	return FT5X16_Y1;
	
	
}
void FT5X16_SYSTICK()
{
	
	if (FT5X16_Tick<1000000)
	{
		//FT5X15_Empty();
		FT5X16_Tick++;	
		
	}
	
	
}
void FT5X16_Refresh(int interval)
{
	
	if ((FT5X16_Tick > interval)&&(FT5X16_Trig == 1))
	{
		
		FT5X16_X();
		FT5X16_Y();
		FT5X16_W();
		FT5X16_Trig = 0;
		FT5X16_Tick = 0;
		//FT5X16_GUI_Test();
	}
	
	
}
void FT5X16_TrigEN(int EN)
{
	FT5X16_Trig = EN;
}

void FT5X16_GUI_Test()
{
	GUI_FillCircle(FT5X16_X1,FT5X16_Y1, 10);
	
}
void FT5X15_Empty()
{
	FT5X16_X1 = 2000;
	FT5X16_X1 = 2000;	
	FT5X16_W1 = 2000;
}
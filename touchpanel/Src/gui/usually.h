#ifndef __USUALLY_H
#define __USUALLY_H

#include "stm32f1xx.h"


extern void Delay_Ms(uint16_t time);  
extern void Delay_Us(uint16_t time);  



#define KEY PCout(13)	   


#define KEY_SEN   PEout(0)	   
#define KEY_DOWN  PEout(1)	   
#define KEY_LEFT  PEout(2)	   
#define KEY_RIGHT PEout(3)	  
#define KEY_UP 	  PEout(4)	   



#define LED1 PDout(6)	   
#define LED2 PDout(12)	   
#define LED3 PDout(13)	 

#define ID_AM         001


#define LCD_With 800//240//W
#define LCD_Hight 600//320



/***********************************************************************************

***********************************************************************************/

#define   BLACK        0x0000                   
#define   NAVY         0x000F                    
#define   DGREEN       0x03E0                    
#define   DCYAN        0x03EF                   
#define   MAROON       0x7800                    
#define   PURPLE       0x780F                   
#define   OLIVE        0x7BE0                   
#define   LGRAY        0xC618                    
#define   DGRAY        0x7BEF                    
#define   BLUE         0x001F                    
#define   GREEN        0x07E0                 	 
#define   CYAN         0x07FF                    
#define   RED          0xF800                    
#define   MAGENTA      0xF81F                    
#define   YELLOW       0xFFE0                    
#define   WHITE        0xFFFF   
            
/************************************************************************************

*************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
void LCD_Init(void);
void LCD_Clear(uint16_t Color);
void LCD_WriteCOM(uint16_t RGB_Code);
void LCD_WriteRAM_Prepare(void); 
void LCD_WriteRAM(uint16_t RGB_Code);
void LCD_SetCursor(uint16_t x,uint16_t y);
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue);
void LCD_DisplyBMP(uint8_t Xpos, uint16_t Ypos, uint8_t Height, uint16_t Width, uint8_t *bitmap);
void DisplayString(uint16_t x0, uint16_t y0,uint8_t *pcStr, uint16_t color);
void LCD_SetDisplayWindow(uint8_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width);
uint16_t GUI_Color565(uint32_t RGB);
uint16_t LCD_BGR2RGB(uint16_t Color);
uint16_t DisplayOneHzChar(uint8_t *pucMsk, uint16_t x0,uint16_t y0,uint16_t Color);
#ifdef __cplusplus
}
#endif
#endif


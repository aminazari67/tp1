/*********************************************************************
*          Portions COPYRIGHT 2016 STMicroelectronics                *
*          Portions SEGGER Microcontroller GmbH & Co. KG             *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.32 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to STMicroelectronics International
N.V. a Dutch company with a Swiss branch and its headquarters in Plan-
les-Ouates, Geneva, 39 Chemin du Champ des Filles, Switzerland for the
purposes of creating libraries for ARM Cortex-M-based 32-bit microcon_
troller products commercialized by Licensee only, sublicensed and dis_
tributed under the terms and conditions of the End User License Agree_
ment supplied by STMicroelectronics International N.V.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : LCDConf_FlexColor_Template.c
Purpose     : Display controller configuration (single layer)
---------------------------END-OF-HEADER------------------------------
*/

/**
  ******************************************************************************
  * @attention
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
#include "stm32f1xx_hal.h"

#include "GUI.h"
#include "GUIDRV_FlexColor.h"
//#include "st7735.h"
//#include "tft2.h"
#include "usually.h"



/*********************************************************************
*
*       Layer configuration (to be modified)
*
**********************************************************************
*/

//
// Physical display size
//
#define XSIZE_PHYS 800 //480// // To be adapted to x-screen size
#define YSIZE_PHYS 480// 272////128 // To be adapted to y-screen size

/*********************************************************************
*
*       Configuration checking
*
**********************************************************************
*/
#ifndef   VXSIZE_PHYS
  #define VXSIZE_PHYS XSIZE_PHYS
#endif
#ifndef   VYSIZE_PHYS
  #define VYSIZE_PHYS YSIZE_PHYS
#endif
#ifndef   XSIZE_PHYS
  #error Physical X size of display is not defined!
#endif
#ifndef   YSIZE_PHYS
  #error Physical Y size of display is not defined!
#endif
#ifndef  GUICC_M565 // GUICC_M565
  #error Color conversion not defined!
#endif
#ifndef   GUIDRV_FLEXCOLOR
  #error No display driver defined!
#endif

/*********************************************************************
*
*       Local functions
*
**********************************************************************
*/
/********************************************************************
*
*       LcdWriteReg
*
* Function description:
*   Sets display register
*/

static void LcdWriteReg(U16 Data) {
  //
 
 // ST7735_WriteCommand(Data);st7735
  LCD_WriteCOM(Data);
 
  
}



/********************************************************************
*
*       LcdWriteData
*
* Function description:
*   Writes a value to a display register
*/
static void LcdWriteData(U16 Data) {
  // ... TBD by user
 
 // HAL_GPIO_WritePin(ST7735_DC_GPIO_Port, ST7735_DC_Pin, GPIO_PIN_SET); //st7735
   // HAL_SPI_Transmit(&ST7735_SPI_PORT, &Data, sizeof(Data), HAL_MAX_DELAY);//st7735
	 // LCD_WriteRAM_Prepare();
   
LCD_WriteRAM(Data);
	// LCD_WriteCOM(Data);

}

/********************************************************************
*
*       LcdWriteDataMultiple
*
* Function description:
*   Writes multiple values to a display register.
*/
static void LcdWriteDataMultiple(U16* pData, int NumItems) {
 while (NumItems--) {
    
   
	 // ... TBD by user
	//lcd_write_wdr(*pData);
	// ST7735_WriteData(pData,1);//st7735
	//ST7735_WriteCommand(*pData);  
	 // LCD_WriteRAM_Prepare();
	 LCD_WriteRAM(pData);
	// *pData++;
  }

}

/********************************************************************
*
*       LcdReadDataMultiple
*
* Function description:
*   Reads multiple values from a display register.
*/
static void LcdReadDataMultiple(U16* pData, int NumItems) {
  while (NumItems--) {
	  // ... TBD by user
	 // lcd_read_rdr();
	  // LCD_ReadReg();
		//LCD_ReadRAM();
	 // *pData++;
	// LCD_ReadReg();
  }
}

/*********************************************************************
*
*       Public functions
*
**********************************************************************
*/
/*********************************************************************
*
*       LCD_X_Config
*
* Function description:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*
*/
void LCD_X_Config(void) {
  GUI_DEVICE * pDevice;
  CONFIG_FLEXCOLOR Config = {0};
  GUI_PORT_API PortAPI = {0};
  // Set display driver and color conversion
  pDevice = GUI_DEVICE_CreateAndLink(GUIDRV_FLEXCOLOR, GUICC_M565, 0, 0);       //GUICC_565
  // Display driver configuration, required for Lin-driver
  LCD_SetSizeEx (0, XSIZE_PHYS , YSIZE_PHYS);
  LCD_SetVSizeEx(0, VXSIZE_PHYS, VYSIZE_PHYS);
	// Orientation
	//Config.Orientation = //GUI_MIRROR_X;// | GUI_SWAP_XY;  //GUI_MIRROR_Y;//|GUI_SWAP_XY; //| GUI_MIRROR_Y;
  
	
	//Config.Orientation = DISPLAY_ORIENTATION;  
	
	Config.RegEntryMode = 0;
	Config.NumDummyReads = -1;// 2;
	Config.FirstCOM = 1;
	GUIDRV_FlexColor_Config(pDevice, &Config);
  // Set controller and operation mode
	/*
  PortAPI.pfWrite8_A0   =  LcdWriteReg;
  PortAPI.pfWrite8_A1  =  LcdWriteData;
  PortAPI.pfWriteM8_A1  =  LcdWriteDataMultiple;
  PortAPI.pfReadM8_A1   =  LcdReadDataMultiple;*/
	
	PortAPI.pfWrite16_A0   = LCD_WriteCOM;  //LcdWriteReg;
	PortAPI.pfWrite16_A1  = LcdWriteData; //LCD_WriteRAM; //
	PortAPI.pfWriteM16_A1  = LcdWriteDataMultiple;   //LCD_WriteRAM; 
	PortAPI.pfReadM16_A1   =  LcdReadDataMultiple;
	
	
	GUIDRV_FlexColor_SetReadFunc66720_B16(pDevice, GUIDRV_FLEXCOLOR_READ_FUNC_II);
	GUIDRV_FlexColor_SetFunc(pDevice, &PortAPI, GUIDRV_FLEXCOLOR_F66720, GUIDRV_FLEXCOLOR_M16C0B16);  ////GUIDRV_FLEXCOLOR_F66708, GUIDRV_FLEXCOLOR_M16C0B8
  //GUIDRV_FLEXCOLOR_F66720 ssd1963 GUIDRV_FLEXCOLOR_M16C0B16
  //GUIDRV_FLEXCOLOR_F66709 st7735
 
}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Function description:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*
* Return Value:
*   < -1 - Error
*     -1 - Command not handled
*      0 - Ok
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void * pData) {
  int r;
  (void) LayerIndex;
  (void) pData;
  
  switch (Cmd) {
  case LCD_X_INITCONTROLLER: {
    //
    // Called during the initialization process in order to set up the
    // display controller and put it into operation. If the display
    // controller is not initialized by any external routine this needs
    // to be adapted by the customer...
    //
    // ...
   //lcd_init();
 // ST7735_Init();//st7735
    // LCD_Init();HAL_Delay(50);LCD_Init(); HAL_Delay(50);LCD_Init(); HAL_Delay(50);
	  LCD_Init(); HAL_Delay(1000);
    return 0;
  }
  default:
    r = -1;
  }
  return r;
}

/*************************** End of file ****************************/


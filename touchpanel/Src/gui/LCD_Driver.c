/**************************************************************
** 	启航号开发板
**	功能描述: LCD底层操作
**  版本：V1.0  
**	论坛：www.openmcu.com
**	淘宝：http://shop36995246.taobao.com/   
**  技术支持群： 
***************************************************************/ 
#include "usually.h"
#include  "hz16.h"
#include "Font_Lib.h"	 //字库文件库
#include "stm32f1xx_hal.h"


uint16_t DeviceCode;


/*unsigned int  HDP=799;
unsigned int  HT=850;
unsigned int  HPS=51;
unsigned int  LPS=3;
unsigned char HPW=48;

unsigned int  VDP=479;
unsigned int  VT=530;
unsigned int  VPS=50;
unsigned int  FPS=30;
unsigned char VPW=21;*/

unsigned int  HDP=799;
unsigned int  HT=1000;
unsigned int  HPS=51;
unsigned int  LPS=46;
unsigned char HPW=20;

unsigned int  VDP=479;
unsigned int  VT=625;
unsigned int  VPS=22;
unsigned int  FPS=23;
unsigned char VPW=3;


/* LCD is connected to the FSMC_Bank1_NOR/SRAM1 and NE4 is used as ship select signal */
#define LCD_RAM    *(__IO uint16_t *) ((uint32_t)0x60020000)    //disp Data ADDR
#define LCD_REG    *(__IO uint16_t *) ((uint32_t)0x60000000)	 //disp Reg ADDR
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void LCD_WriteCOM(uint16_t RGB_Code)
{
  	/* Write 16-bit GRAM Reg */
  	LCD_REG = RGB_Code;
}
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void LCD_WriteRAM(uint16_t RGB_Code)
{
  	/* Write 16-bit GRAM Reg */
  	LCD_RAM = RGB_Code;
}
/*****************************************************************************
** 函数名称: LCD_ReadRAM
** 功能描述: 读取RAM中的数据
** 参数描述：还回一个值
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
uint16_t LCD_ReadRAM(void)
{
  	/* Write 16-bit Index (then Read Reg) */
  	LCD_REG = 0x22; /* Select GRAM Reg */
  	/* Read 16-bit Reg */
  	return LCD_RAM;
}
/*****************************************************************************
** 函数名称: LCD_WriteReg
** 功能描述: 同时写指令和数据
** 参数描述：无
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue)
{
	/* Write 16-bit Index, then Write Reg */
	LCD_REG= LCD_Reg;
  	/* Write 16-bit Reg */
	LCD_RAM= LCD_RegValue;
}
/*****************************************************************************
** 函数名称: LCD_ReadReg
** 功能描述: LCD读函数
** 参数描述：LCD_Reg 返回值temp
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
uint16_t LCD_ReadReg(uint8_t LCD_Reg)
{
	uint16_t temp;

  	/* Write 16-bit Index (then Read Reg) */
	LCD_REG= LCD_Reg;
 
	temp= LCD_RAM; //
  
  	/* Read 16-bit Reg */
  	return temp;
}
/*****************************************************************************
** 函数名称: LCD_WriteRAM_Prepare
** 功能描述: 向LCD RAM中写数据准备函数
** 参数描述：无
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void LCD_WriteRAM_Prepare(void)
{
	LCD_REG= 0X22;
}
/*****************************************************************************
** 函数名称: FSMC_GPIO_Configuration
** 功能描述: FSMC引脚配置
** 参数描述：无
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void FSMC_GPIO_Configuration()
{
  /*
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO
							,ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
                                 GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
								 GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_15;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_Init(GPIOD, &GPIO_InitStructure);

  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
                                GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
                                GPIO_Pin_15;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_Init(GPIOE, &GPIO_InitStructure);
        */
}
/*****************************************************************************
** 函数名称: FSMC_LCD_Init
** 功能描述: FSMC配置使用FSMC的Bank1 NOR/PSRAM
** 参数描述：无
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void FSMC_LCD_Init()
{
  /*
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef  p;

  	

  	p.FSMC_AddressSetupTime = 0x02;
  	p.FSMC_AddressHoldTime = 0x00;
  	p.FSMC_DataSetupTime = 0x05;
  	p.FSMC_BusTurnAroundDuration = 0x00;
  	p.FSMC_CLKDivision = 0x00;
  	p.FSMC_DataLatency = 0x00;
  	p.FSMC_AccessMode = FSMC_AccessMode_B;

  	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
  	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
  	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
  	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
  	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
  	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;	  
 
  	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 

  	
  	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  
*/
}
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 参数描述：无
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void LCD_Init(void)
{
	FSMC_GPIO_Configuration();
	FSMC_LCD_Init();


	LCD_WriteCOM(0x00E2);	//PLL multiplier, set PLL clock to 120M
	LCD_WriteRAM(0x001D);	    //N=0x36 for 6.5M, 0x23 for 10M crystal
	LCD_WriteRAM(0x0002);
	LCD_WriteRAM(0x0004);
	
	LCD_WriteCOM(0x00E0);  // PLL enable
	LCD_WriteRAM(0x0001);
	HAL_Delay(5);//Delay_Ms(5);
	LCD_WriteCOM(0x00E0);
	LCD_WriteRAM(0x0003);
	HAL_Delay(5);//Delay_Ms(5);
	LCD_WriteCOM(0x0001);  // software reset
	HAL_Delay(5);//Delay_Ms(5);
	LCD_WriteCOM(0x00E6);	//PLL setting for PCLK, depends on resolution
	LCD_WriteRAM(0x0004);	//0x0003
	LCD_WriteRAM(0x0093);	//0x0033
	LCD_WriteRAM(0x00e0);	//0x0033

	LCD_WriteCOM(0x00B0);	//LCD SPECIFICATION
	LCD_WriteRAM(0x0000);
	LCD_WriteRAM(0x0000);
	LCD_WriteRAM((HDP>>8)&0X00FF);  //Set HDP
	LCD_WriteRAM(HDP&0X00FF);
    LCD_WriteRAM((VDP>>8)&0X00FF);  //Set VDP
	LCD_WriteRAM(VDP&0X00FF);
    LCD_WriteRAM(0x0000);

	LCD_WriteCOM(0x00B4);	//HSYNC
	LCD_WriteRAM((HT>>8)&0X00FF);  //Set HT
	LCD_WriteRAM(HT&0X00FF);
	LCD_WriteRAM((HPS>>8)&0X00FF);  //Set HPS
	LCD_WriteRAM(HPS&0X00FF);
	LCD_WriteRAM(HPW);			   //Set HPW
	LCD_WriteRAM((LPS>>8)&0X00FF);  //Set HPS
	LCD_WriteRAM(LPS&0X00FF);
	LCD_WriteRAM(0x0000);

	LCD_WriteCOM(0x00B6);	//VSYNC
	LCD_WriteRAM((VT>>8)&0X00FF);   //Set VT
	LCD_WriteRAM(VT&0X00FF);
	LCD_WriteRAM((VPS>>8)&0X00FF);  //Set VPS
	LCD_WriteRAM(VPS&0X00FF);
	LCD_WriteRAM(VPW);			   //Set VPW
	LCD_WriteRAM((FPS>>8)&0X00FF);  //Set FPS
	LCD_WriteRAM(FPS&0X00FF);

	LCD_WriteCOM(0x00BA);
	LCD_WriteRAM(0x0005);    //GPIO[3:0] out 1

	LCD_WriteCOM(0x00B8);
	LCD_WriteRAM(0x0007);    //GPIO3=input, GPIO[2:0]=output
	LCD_WriteRAM(0x0001);    //GPIO0 normal

	LCD_WriteCOM(0x0036); //rotation
	LCD_WriteRAM(0x0000);
//	LCD_WriteRAM(0x0060);
	//============================================

	//============================================
//	LCD_WriteCOM(0x003A); //rotation
//	LCD_WriteRAM(0x0050);

//		LCD_WriteCOM(0x0026); //rotation
//	LCD_WriteRAM(0x0003);
//		LCD_WriteCOM(0x0030); //rotation
//	LCD_WriteRAM(0x0000);

	//=============================================
	LCD_WriteCOM(0x00F0); //pixel data interface
	LCD_WriteRAM(0x0003);

	HAL_Delay(5);//Delay_Ms(5);

	LCD_Clear(BLUE);
	
	LCD_WriteCOM(0x0026); //display on
	LCD_WriteRAM(0x0001);

	LCD_WriteCOM(0x0029); //display on

/*	LCD_WriteCOM(0x00BE); //set PWM for B/L
	LCD_WriteRAM(0x0006);
	//LCD_WriteRAM(0x0008);
	LCD_WriteRAM(0x0080);
	//LCD_WriteRAM(0x00f0);	 
	
	LCD_WriteRAM(0x0001);
	LCD_WriteRAM(0x00f0);
	LCD_WriteRAM(0x0000);
	LCD_WriteRAM(0x0000);  */

	LCD_WriteCOM(0x00d0);//设置动态背光控制配置 
	LCD_WriteRAM(0x000d);	

	LCD_WriteCOM(0x0029); //display on	 
}
/*****************************************************************************
** 函数名称: LCD_SetCursor
** 功能描述: LCD初始化
** 参数描述：x      行座标 
**           y      列座标
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
void LCD_SetCursor(uint16_t x,uint16_t y)
{
#if   ID_AM==000       
	LCD_WriteReg(0x20, x);
	LCD_WriteReg(0x21, y);

#elif ID_AM==001  
	LCD_WriteReg(0x20, 239-x);
	LCD_WriteReg(0x21, 319-y);
#endif 	

/*  	if(DeviceCode==0x8989)
  	{
    	LCD_WriteReg(0x004e,y);        //行
    	LCD_WriteReg(0x004f,0x13f-x);  //列
  	}
  	else if(DeviceCode==0x9919)
  	{
    	LCD_WriteReg(0x004e,x);        //行
  		LCD_WriteReg(0x004f,y);        //列	
  	}
  	else
  	{
    	LCD_WriteReg(0x20,x);        //行
  		LCD_WriteReg(0x21,y);  //列
  	}*/
}
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2011年5月15日
*****************************************************************************/
void LCD_Clear(uint16_t Color)
{
     unsigned int l=800,w;

	LCD_WriteCOM(0x002A);	
	LCD_WriteRAM(0);	    
	LCD_WriteRAM(0);
	LCD_WriteRAM(HDP>>8);	    
	LCD_WriteRAM(HDP&0x00ff);
    LCD_WriteCOM(0x002b);	
	LCD_WriteRAM(0);	    
	LCD_WriteRAM(0);
	LCD_WriteRAM(VDP>>8);	    
	LCD_WriteRAM(VDP&0x00ff);
	LCD_WriteCOM(0x002c);
	
	
	while(l--)
	{
	    for(w=0;w<480;w++)
		{    
          	LCD_WriteRAM(LCD_BGR2RGB(Color));
		}
	} 
}
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 参数描述：无
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_SetDisplayWindow
** 功能描述: 设置窗口函数 (将Width和Height调换一下，前提是)
** 参数描述：Xpos  Ypos 分别为屏的X和Y的起始位置
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
void LCD_SetDisplayWindow(uint8_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width)
{
  	LCD_WriteReg(0x50, Xpos);	   	   	//水平方向GRAM起始地址
  	LCD_WriteReg(0x51, Xpos+Height); 	//水平方向GRAM结束地址 
  	LCD_WriteReg(0x52, Ypos);		  	//垂直方向GRAM起始地址
  	LCD_WriteReg(0x53, Ypos+Width);  	//垂直方向GRAM结束地址

//  	LCD_SetCursor(Xpos, Ypos);			//设置光标位置
}
/*****************************************************************************
** 函数名称: LCD_WriteBMP
** 功能描述: 在指定的位置显示一幅图片			
** 参数描述：Xpos和Ypos为图片显示地址，Height和Width 为图片的宽度和高度
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
void LCD_DisplyBMP(uint8_t Xpos, uint16_t Ypos, uint8_t Height, uint16_t Width, uint8_t *bitmap)
{
  	uint32_t index;
  	uint32_t size = Height * Width;
  	uint16_t *bitmap_ptr = (uint16_t *)bitmap;

  	LCD_SetDisplayWindow(Xpos, Ypos, Width-1, Height-1);

    LCD_WriteReg(0x20,Xpos);        //行
  	LCD_WriteReg(0x21,Ypos);  //列
  	//LCD_WriteReg(0x03, 0x1038);	//如果需要横向显示图片，将此去掉屏蔽 ，同时将Width和Hight调换一下就可以

  	LCD_WriteRAM_Prepare();

  	for(index = 0; index < size; index++)
  	{
    	LCD_RAM= (*bitmap_ptr++);
  	}
	//恢复窗体大小	 
	LCD_WriteReg(0x50, 0x0000); //水平方向GRAM起始地址
	LCD_WriteReg(0x51, 0x00EF); //水平方向GRAM结束地址
	LCD_WriteReg(0x52, 0x0000); //垂直方向GRAM起始地址
	LCD_WriteReg(0x53, 0x013F); //垂直方向GRAM结束地址
}
/*****************************************************************************
** 函数名称: DisplayOneHzChar
** 功能描述: 显示一个指定大小的汉字
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
uint16_t DisplayOneHzChar(uint8_t *pucMsk,
                               uint16_t x0,
                               uint16_t y0,
                               uint16_t Color)
{
    uint16_t i,j;
    uint16_t mod[16];                                      /* 当前字模 */
    uint16_t *pusMsk;                                      /* 当前字库地址 */
    uint16_t y;
    
    pusMsk = (uint16_t *)pucMsk;
    for(i=0; i<16; i++)                                    /* 保存当前汉字点阵式字模 */
    {
        mod[i] = *pusMsk++;                                /* 取得当前字模，半字对齐访问*/
        mod[i] = ((mod[i] & 0xff00) >> 8) | ((mod[i] & 0x00ff) << 8);/* 字模交换高低字节（为了显示   */
                                                           /* 需要） */
    }
    y = y0;
    for(i=0; i<16; i++)                                    /* 16行 */
    { 
	    #ifdef __DISPLAY_BUFFER                            /* 使用显存显示  */
        for(j=0; j<16; j++)                                /* 16列 */
        {
		    if((mod[i] << j)& 0x8000)                      /* 显示字模 */
            {
			    DispBuf[240*(y0+i) + x0+j] = color;
            }
        }
        #else                                              /* 直接显示 */

#if   ID_AM==000               
        LCD_SetCursor(x0, y);                              /* 设置写数据地址指针 */

#elif ID_AM==001 
        LCD_SetCursor(y, x0);                              /* 设置写数据地址指针 */
#endif
		LCD_WriteRAM_Prepare();        					   /*开始写入GRAM	*/   
        for(j=0; j<16; j++)                                /* 16列                         */
        {
		    if((mod[i] << j)& 0x8000)                     /* 显示字模  */
            { 
			    LCD_RAM= Color;
            } 
			else 
			{
                LCD_RAM= BLACK;                     /* 用读方式跳过写空白点的像素*/
            	//LCD_ReadRAM();
			}
        }
        y++;
        #endif
    }
    return (16);                                          /* 返回16位列宽 */
}
/*****************************************************************************
** 函数名称: DisplayOneASCII
** 功能描述: 显示一个指定大小的字符
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
uint16_t DisplayOneASCII(uint8_t *pucMsk,
                              uint16_t x0,
                              uint16_t y0,
                              uint16_t Color)
{
    uint16_t i,j;
    uint16_t y;
    uint8_t ucChar;
    
    y = y0;
    for(i=0; i<16; i++) {                                 /* 16行 */
        ucChar = *pucMsk++;
        #ifdef __DISPLAY_BUFFER                           /* 使用显存显示 */
        for(j=0; j<8; j++) {                              /* 8列 */
            if((ucChar << j)& 0x80) {                     /* 显示字模 */
                DispBuf[240*(y0+i) + x0+j] = color;
            }
        }
        #else                                             /* 直接显示 */
        
#if   ID_AM==000               
        LCD_SetCursor(x0, y);                              /* 设置写数据地址指针 */

#elif ID_AM==001 
        LCD_SetCursor(y, x0);                              /* 设置写数据地址指针 */
#endif
		LCD_WriteRAM_Prepare();        					  /* 开始写入GRAM */
        for(j=0; j<8; j++) {                              /* 8列 */
            if((ucChar << j)& 0x80)   LCD_RAM= Color;     /* 显示字模 */      
            else LCD_RAM= BLACK;   
                 //LCD_ReadDat();
        }
        y++;
        #endif
    }
    return (8);                                           /* 返回16位列宽 */
}
/*****************************************************************************
** 函数名称: WriteString
** 功能描述: 在指定位置开始显示一个字符串和一串汉字
				支持自动换行
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/   			   
void DisplayString(uint16_t x0, uint16_t y0,uint8_t *pcStr, uint16_t color)
{
	uint16_t usIndex;
    uint16_t usWidth = 0;
    FNT_GB16 *ptGb16 = 0;
    
    ptGb16 = (FNT_GB16 *)GBHZ_16;  
	while(1)
    {
        if(*pcStr == 0) 
		{
            break;                                     /* 字符串结束            */
        }      
        x0 = x0 + (usWidth);                           /* 调节字符串显示松紧度         */
        if(*pcStr > 0x80)                              /* 判断为汉字                   */
        {
		    if((x0 + 16) > LCD_With)                      /* 检查剩余空间是否足够         */
            {
			    x0 = 0;
                y0 = y0 + 16;                          /* 改变显示坐标                 */
                if(y0 > LCD_Hight)                         /* 纵坐标超出                   */
                {
				    y0 = 0;
                }
            }
            usIndex = findHzIndex(pcStr);
            usWidth = DisplayOneHzChar((uint8_t *)&(ptGb16[usIndex].Msk[0]), x0, y0, color);
                                                       /* 显示字符                     */
            pcStr += 2;
        }
		else 
		{                                               /* 判断为非汉字 */
            if (*pcStr == '\r')                         /* 换行 */
            { 
			    y0 = y0 + 16;                           /* 改变显示坐标 */
                if(y0 > LCD_Hight)                          /* 纵坐标超出 */
                {
				    y0 = 0;
                }
                pcStr++;
                usWidth = 0;
                continue;
            } 
			else if (*pcStr == '\n')                    /* 对齐到起点 */
            {
			    x0 = 0;
                pcStr++;
                usWidth = 0;
                continue;
            } 
			else 
			{
                if((x0 + 8) > LCD_With)                     /* 检查剩余空间是否足够 */
                {
				    x0 = 0;
                    y0 = y0 + 16;                        /* 改变显示坐标 */
                    if(y0 > LCD_Hight)                       /* 纵坐标超出 */
                    { 
					    y0 = 0;
                    }
                }
                usWidth = DisplayOneASCII((uint8_t *)&ASCII_1608_CU[(*pcStr - 0x20)][0], x0, y0, color);
                                                         /* ASCII码表21H的值对应区位码3区*/
                pcStr += 1;
            }
		}
	}												  	  
}
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/****************************************************************************
* 名    称：u16 GUI_Color565(u32 RGB)
* 功    能：将RGB颜色转换为16位颜色。
* 入口参数：RGB  颜色值
* 出口参数：返回16位RGB颜色值。
* 说    明：
* 调用方法：i=GUI_Color565(0xafafaf);
****************************************************************************/
uint16_t GUI_Color565(uint32_t RGB)
{
  uint8_t  r, g, b;

  b = ( RGB >> (0+3) ) & 0x1f;		// 取B色的高5位
  g = ( RGB >> (8+2) ) & 0x3f;		// 取G色的高6位
  r = ( RGB >> (16+3)) & 0x1f;		// 取R色的高5位
   
  return( (r<<11) + (g<<5) + (b<<0) );		
}
/****************************************************************************
* 名    称：u16 ili9320_BGR2RGB(u16 c)
* 功    能：RRRRRGGGGGGBBBBB 改为 BBBBBGGGGGGRRRRR 格式
* 入口参数：c      BRG 颜色值
* 出口参数：RGB 颜色值
* 说    明：内部函数调用
* 调用方法：
****************************************************************************/
uint16_t LCD_BGR2RGB(uint16_t Color)
{
  uint16_t  r, g, b, rgb;

  b = (Color>>0)  & 0x1f;
  g = (Color>>5)  & 0x3f;
  r = (Color>>11) & 0x1f;
  
  rgb =  (b<<11) + (g<<5) + (r<<0);

  return( rgb );
}

/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/
/*****************************************************************************
** 函数名称: LCD_Init
** 功能描述: LCD初始化
** 作  　者: Dream
** 日　  期: 2010年12月06日
*****************************************************************************/

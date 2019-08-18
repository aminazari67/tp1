/**************************************************************
** 	�����ſ�����
**	��������: LCD�ײ����
**  �汾��V1.0  
**	��̳��www.openmcu.com
**	�Ա���http://shop36995246.taobao.com/   
**  ����֧��Ⱥ�� 
***************************************************************/ 
#include "usually.h"
#include  "hz16.h"
#include "Font_Lib.h"	 //�ֿ��ļ���
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
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
*****************************************************************************/
void LCD_WriteCOM(uint16_t RGB_Code)
{
  	/* Write 16-bit GRAM Reg */
  	LCD_REG = RGB_Code;
}
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
*****************************************************************************/
void LCD_WriteRAM(uint16_t RGB_Code)
{
  	/* Write 16-bit GRAM Reg */
  	LCD_RAM = RGB_Code;
}
/*****************************************************************************
** ��������: LCD_ReadRAM
** ��������: ��ȡRAM�е�����
** ��������������һ��ֵ
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
*****************************************************************************/
uint16_t LCD_ReadRAM(void)
{
  	/* Write 16-bit Index (then Read Reg) */
  	LCD_REG = 0x22; /* Select GRAM Reg */
  	/* Read 16-bit Reg */
  	return LCD_RAM;
}
/*****************************************************************************
** ��������: LCD_WriteReg
** ��������: ͬʱдָ�������
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
*****************************************************************************/
void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_RegValue)
{
	/* Write 16-bit Index, then Write Reg */
	LCD_REG= LCD_Reg;
  	/* Write 16-bit Reg */
	LCD_RAM= LCD_RegValue;
}
/*****************************************************************************
** ��������: LCD_ReadReg
** ��������: LCD������
** ����������LCD_Reg ����ֵtemp
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
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
** ��������: LCD_WriteRAM_Prepare
** ��������: ��LCD RAM��д����׼������
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
*****************************************************************************/
void LCD_WriteRAM_Prepare(void)
{
	LCD_REG= 0X22;
}
/*****************************************************************************
** ��������: FSMC_GPIO_Configuration
** ��������: FSMC��������
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
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
** ��������: FSMC_LCD_Init
** ��������: FSMC����ʹ��FSMC��Bank1 NOR/PSRAM
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
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
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
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

	LCD_WriteCOM(0x00d0);//���ö�̬����������� 
	LCD_WriteRAM(0x000d);	

	LCD_WriteCOM(0x0029); //display on	 
}
/*****************************************************************************
** ��������: LCD_SetCursor
** ��������: LCD��ʼ��
** ����������x      ������ 
**           y      ������
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
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
    	LCD_WriteReg(0x004e,y);        //��
    	LCD_WriteReg(0x004f,0x13f-x);  //��
  	}
  	else if(DeviceCode==0x9919)
  	{
    	LCD_WriteReg(0x004e,x);        //��
  		LCD_WriteReg(0x004f,y);        //��	
  	}
  	else
  	{
    	LCD_WriteReg(0x20,x);        //��
  		LCD_WriteReg(0x21,y);  //��
  	}*/
}
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2011��5��15��
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
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ������������
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_SetDisplayWindow
** ��������: ���ô��ں��� (��Width��Height����һ�£�ǰ����)
** ����������Xpos  Ypos �ֱ�Ϊ����X��Y����ʼλ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
void LCD_SetDisplayWindow(uint8_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width)
{
  	LCD_WriteReg(0x50, Xpos);	   	   	//ˮƽ����GRAM��ʼ��ַ
  	LCD_WriteReg(0x51, Xpos+Height); 	//ˮƽ����GRAM������ַ 
  	LCD_WriteReg(0x52, Ypos);		  	//��ֱ����GRAM��ʼ��ַ
  	LCD_WriteReg(0x53, Ypos+Width);  	//��ֱ����GRAM������ַ

//  	LCD_SetCursor(Xpos, Ypos);			//���ù��λ��
}
/*****************************************************************************
** ��������: LCD_WriteBMP
** ��������: ��ָ����λ����ʾһ��ͼƬ			
** ����������Xpos��YposΪͼƬ��ʾ��ַ��Height��Width ΪͼƬ�Ŀ�Ⱥ͸߶�
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
void LCD_DisplyBMP(uint8_t Xpos, uint16_t Ypos, uint8_t Height, uint16_t Width, uint8_t *bitmap)
{
  	uint32_t index;
  	uint32_t size = Height * Width;
  	uint16_t *bitmap_ptr = (uint16_t *)bitmap;

  	LCD_SetDisplayWindow(Xpos, Ypos, Width-1, Height-1);

    LCD_WriteReg(0x20,Xpos);        //��
  	LCD_WriteReg(0x21,Ypos);  //��
  	//LCD_WriteReg(0x03, 0x1038);	//�����Ҫ������ʾͼƬ������ȥ������ ��ͬʱ��Width��Hight����һ�¾Ϳ���

  	LCD_WriteRAM_Prepare();

  	for(index = 0; index < size; index++)
  	{
    	LCD_RAM= (*bitmap_ptr++);
  	}
	//�ָ������С	 
	LCD_WriteReg(0x50, 0x0000); //ˮƽ����GRAM��ʼ��ַ
	LCD_WriteReg(0x51, 0x00EF); //ˮƽ����GRAM������ַ
	LCD_WriteReg(0x52, 0x0000); //��ֱ����GRAM��ʼ��ַ
	LCD_WriteReg(0x53, 0x013F); //��ֱ����GRAM������ַ
}
/*****************************************************************************
** ��������: DisplayOneHzChar
** ��������: ��ʾһ��ָ����С�ĺ���
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
uint16_t DisplayOneHzChar(uint8_t *pucMsk,
                               uint16_t x0,
                               uint16_t y0,
                               uint16_t Color)
{
    uint16_t i,j;
    uint16_t mod[16];                                      /* ��ǰ��ģ */
    uint16_t *pusMsk;                                      /* ��ǰ�ֿ��ַ */
    uint16_t y;
    
    pusMsk = (uint16_t *)pucMsk;
    for(i=0; i<16; i++)                                    /* ���浱ǰ���ֵ���ʽ��ģ */
    {
        mod[i] = *pusMsk++;                                /* ȡ�õ�ǰ��ģ�����ֶ������*/
        mod[i] = ((mod[i] & 0xff00) >> 8) | ((mod[i] & 0x00ff) << 8);/* ��ģ�����ߵ��ֽڣ�Ϊ����ʾ   */
                                                           /* ��Ҫ�� */
    }
    y = y0;
    for(i=0; i<16; i++)                                    /* 16�� */
    { 
	    #ifdef __DISPLAY_BUFFER                            /* ʹ���Դ���ʾ  */
        for(j=0; j<16; j++)                                /* 16�� */
        {
		    if((mod[i] << j)& 0x8000)                      /* ��ʾ��ģ */
            {
			    DispBuf[240*(y0+i) + x0+j] = color;
            }
        }
        #else                                              /* ֱ����ʾ */

#if   ID_AM==000               
        LCD_SetCursor(x0, y);                              /* ����д���ݵ�ַָ�� */

#elif ID_AM==001 
        LCD_SetCursor(y, x0);                              /* ����д���ݵ�ַָ�� */
#endif
		LCD_WriteRAM_Prepare();        					   /*��ʼд��GRAM	*/   
        for(j=0; j<16; j++)                                /* 16��                         */
        {
		    if((mod[i] << j)& 0x8000)                     /* ��ʾ��ģ  */
            { 
			    LCD_RAM= Color;
            } 
			else 
			{
                LCD_RAM= BLACK;                     /* �ö���ʽ����д�հ׵������*/
            	//LCD_ReadRAM();
			}
        }
        y++;
        #endif
    }
    return (16);                                          /* ����16λ�п� */
}
/*****************************************************************************
** ��������: DisplayOneASCII
** ��������: ��ʾһ��ָ����С���ַ�
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
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
    for(i=0; i<16; i++) {                                 /* 16�� */
        ucChar = *pucMsk++;
        #ifdef __DISPLAY_BUFFER                           /* ʹ���Դ���ʾ */
        for(j=0; j<8; j++) {                              /* 8�� */
            if((ucChar << j)& 0x80) {                     /* ��ʾ��ģ */
                DispBuf[240*(y0+i) + x0+j] = color;
            }
        }
        #else                                             /* ֱ����ʾ */
        
#if   ID_AM==000               
        LCD_SetCursor(x0, y);                              /* ����д���ݵ�ַָ�� */

#elif ID_AM==001 
        LCD_SetCursor(y, x0);                              /* ����д���ݵ�ַָ�� */
#endif
		LCD_WriteRAM_Prepare();        					  /* ��ʼд��GRAM */
        for(j=0; j<8; j++) {                              /* 8�� */
            if((ucChar << j)& 0x80)   LCD_RAM= Color;     /* ��ʾ��ģ */      
            else LCD_RAM= BLACK;   
                 //LCD_ReadDat();
        }
        y++;
        #endif
    }
    return (8);                                           /* ����16λ�п� */
}
/*****************************************************************************
** ��������: WriteString
** ��������: ��ָ��λ�ÿ�ʼ��ʾһ���ַ�����һ������
				֧���Զ�����
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
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
            break;                                     /* �ַ�������            */
        }      
        x0 = x0 + (usWidth);                           /* �����ַ�����ʾ�ɽ���         */
        if(*pcStr > 0x80)                              /* �ж�Ϊ����                   */
        {
		    if((x0 + 16) > LCD_With)                      /* ���ʣ��ռ��Ƿ��㹻         */
            {
			    x0 = 0;
                y0 = y0 + 16;                          /* �ı���ʾ����                 */
                if(y0 > LCD_Hight)                         /* �����곬��                   */
                {
				    y0 = 0;
                }
            }
            usIndex = findHzIndex(pcStr);
            usWidth = DisplayOneHzChar((uint8_t *)&(ptGb16[usIndex].Msk[0]), x0, y0, color);
                                                       /* ��ʾ�ַ�                     */
            pcStr += 2;
        }
		else 
		{                                               /* �ж�Ϊ�Ǻ��� */
            if (*pcStr == '\r')                         /* ���� */
            { 
			    y0 = y0 + 16;                           /* �ı���ʾ���� */
                if(y0 > LCD_Hight)                          /* �����곬�� */
                {
				    y0 = 0;
                }
                pcStr++;
                usWidth = 0;
                continue;
            } 
			else if (*pcStr == '\n')                    /* ���뵽��� */
            {
			    x0 = 0;
                pcStr++;
                usWidth = 0;
                continue;
            } 
			else 
			{
                if((x0 + 8) > LCD_With)                     /* ���ʣ��ռ��Ƿ��㹻 */
                {
				    x0 = 0;
                    y0 = y0 + 16;                        /* �ı���ʾ���� */
                    if(y0 > LCD_Hight)                       /* �����곬�� */
                    { 
					    y0 = 0;
                    }
                }
                usWidth = DisplayOneASCII((uint8_t *)&ASCII_1608_CU[(*pcStr - 0x20)][0], x0, y0, color);
                                                         /* ASCII���21H��ֵ��Ӧ��λ��3��*/
                pcStr += 1;
            }
		}
	}												  	  
}
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/****************************************************************************
* ��    �ƣ�u16 GUI_Color565(u32 RGB)
* ��    �ܣ���RGB��ɫת��Ϊ16λ��ɫ��
* ��ڲ�����RGB  ��ɫֵ
* ���ڲ���������16λRGB��ɫֵ��
* ˵    ����
* ���÷�����i=GUI_Color565(0xafafaf);
****************************************************************************/
uint16_t GUI_Color565(uint32_t RGB)
{
  uint8_t  r, g, b;

  b = ( RGB >> (0+3) ) & 0x1f;		// ȡBɫ�ĸ�5λ
  g = ( RGB >> (8+2) ) & 0x3f;		// ȡGɫ�ĸ�6λ
  r = ( RGB >> (16+3)) & 0x1f;		// ȡRɫ�ĸ�5λ
   
  return( (r<<11) + (g<<5) + (b<<0) );		
}
/****************************************************************************
* ��    �ƣ�u16 ili9320_BGR2RGB(u16 c)
* ��    �ܣ�RRRRRGGGGGGBBBBB ��Ϊ BBBBBGGGGGGRRRRR ��ʽ
* ��ڲ�����c      BRG ��ɫֵ
* ���ڲ�����RGB ��ɫֵ
* ˵    �����ڲ���������
* ���÷�����
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
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/
/*****************************************************************************
** ��������: LCD_Init
** ��������: LCD��ʼ��
** ��  ����: Dream
** �ա�  ��: 2010��12��06��
*****************************************************************************/

#include "at45db16.h"
#include "spi.h"
#include "lcd.h"
#include "usart.h"

void AT45_init(){
AT45_Reset();
AT45_WP(1);AT45_CS(1);
//AT45_EraseChip();
//AT45_Reset();//HAL_Delay(100);
/*
for(int i=0;i<150;++i){
AT45_WriteBuffer(500,i);
AT45_ReadBuffer(500);
AT45_BufferToPage(i);
AT45_PageToBuffer(i);
//AT45_ReadBuffer(500);
AT45_ReadMain(i,500);
}
*/
// 


}

void AT45_SendCmd(char  _cmd){
  
 char *data;
//_cmd=0xD1;
data=&_cmd;
//sprintf(buff,"%d",_cmd);
  HAL_SPI_Transmit(&hspi2,(unsigned char*)data,sizeof(_cmd),2000);

}
void AT45_EraseChip(){
  AT45_Reset();HAL_Delay(100);
  AT45_ReadyToWrite();
  AT45_SendCmd(AT45_ERASECHIP1);
  AT45_SendCmd(AT45_ERASECHIP2);
  AT45_SendCmd(AT45_ERASECHIP3);
  AT45_SendCmd(AT45_ERASECHIP4);
  AT45_EndOperation();
  HAL_Delay(500);


/*
AT45_BufferToPage(0);
 HAL_Delay(500);
 AT45_ReadMain(0);
*/
//AT45_PageToBuffer(0);
//AT45_ReadBuffer(0);

}
void AT45_CS(int _status){
if(_status==0){
    HAL_GPIO_WritePin(AT45_CSPORT,AT45_CSPIN,GPIO_PIN_RESET);}
if(_status==1){
    HAL_GPIO_WritePin(AT45_CSPORT,AT45_CSPIN,GPIO_PIN_SET);}
}
void AT45_Reset(){
HAL_GPIO_WritePin(AT45_CSPORT,AT45_RSTPIN,GPIO_PIN_RESET);
HAL_Delay(100);
HAL_GPIO_WritePin(AT45_CSPORT,AT45_RSTPIN,GPIO_PIN_SET);
}
void AT45_WP(int _status){
  if(_status==0){
    //HAL_GPIO_WritePin(AT45_CSPORT,AT45_WPPIN,GPIO_PIN_RESET);
  }
  if(_status==1){
    HAL_GPIO_WritePin(AT45_CSPORT,AT45_WPPIN,GPIO_PIN_SET);}
}


char AT45_ReadMain(int pa,int ba){
/*  
  char buff[8];
  buff[0]=1;
  int ba1=(pa>>6);//(pa>>6);
  int ba2=((pa<<1)&0xff)|((ba>>8));
  int ba3=ba&(0xff);
AT45_ReadyToWrite();
HAL_Delay(100);
AT45_SendCmd(0xD2);
AT45_SendCmd(ba1);
AT45_SendCmd(ba2);
AT45_SendCmd(ba3);
AT45_SendCmd(0x00);
AT45_SendCmd(0x00);
AT45_SendCmd(0x00);
AT45_SendCmd(0x01);

HAL_SPI_Receive(&hspi2,(unsigned char*)buff,sizeof(buff),10000);
//char lcd[16];sprintf(lcd,"c=%d",buff[0]);lcd_clear();lcd_gotoxy(2,0);lcd_puts(lcd);
  AT45_EndOperation();

HAL_UART_Transmit(&huart1,(unsigned char*)buff,1,20000);
*/
//return buff[0];
  AT45_PageToBuffer(pa);
	HAL_Delay(1);
return AT45_ReadBuffer(ba);

}
void AT45_Write(int pa,int ba, char data){
AT45_PageToBuffer(pa);
HAL_Delay(1);
 AT45_WriteBuffer(ba,data);
	//HAL_Delay(10);

// AT45_ReadBuffer(ba);//debug
 AT45_BufferToPage(pa);
	HAL_Delay(10);

 //AT45_PageToBuffer(pa);//debug
// AT45_ReadBuffer(ba);//debug


}
void AT45_WriteBuffer(int ba,char data){
  
 AT45_ReadyToWrite();
	//HAL_Delay(10);
 /*
 char buff[10];
  buff[0]=0x84;
  buff[1]=0x00;
  buff[2]=0x00;
  buff[3]=0x01;
  buff[4]=0x06;
  HAL_SPI_Transmit(&hspi2,(unsigned char*)buff,5,2000);*/
 
  
AT45_SendCmd(0x84);
AT45_SendCmd(0x00);
AT45_SendCmd(ba>>8);//ba&(0xFF)
AT45_SendCmd((ba&(0xFF)));//ba<<8
AT45_SendCmd(data);//data

AT45_EndOperation();

}

char AT45_ReadBuffer(int ba){
  char rbuff[5];
  rbuff[0]=1;
   AT45_ReadyToWrite();
	//HAL_Delay(100);
  /*
  char buff[10];
  char *data;
  buff[0]=0xd4;
  buff[1]=0x00;
  buff[2]=0x00;
  buff[3]=0x01;
 buff[4]=0x00;
 HAL_SPI_Transmit(&hspi2,(unsigned char*)buff,5,2000);
*/
 
AT45_SendCmd(0xD1);
AT45_SendCmd(0x00);
//AT45_SendCmd(0x00);
AT45_SendCmd(ba>>8);
AT45_SendCmd(ba&(0xFF));
HAL_SPI_Receive(&hspi2,(unsigned char*)rbuff,1,10000);
AT45_EndOperation();
HAL_UART_Transmit(&huart1,(unsigned char*)rbuff, 1, 20000);
return rbuff[0];
//char lcd[16];sprintf(lcd,"B=%d",buff[0]);lcd_clear();lcd_gotoxy(2,0);lcd_puts(lcd);HAL_Delay(2000);
}
void AT45_ReadyToWrite(){
//AT45_WP(1);
AT45_CS(0);
}
void AT45_EndOperation(){
//AT45_WP(0);
AT45_CS(1);
}

void AT45_BufferToPage(int pa){
  int pa1=(pa>>6);//6
 int pa2=(pa<<1)&0xff;
AT45_ReadyToWrite();
	//HAL_Delay(10);
AT45_SendCmd(0x83);//83
AT45_SendCmd(pa1);//page addres M 6
AT45_SendCmd(pa2);//page addres L 6pa<<1)&&(0xff)
AT45_SendCmd(0x00);
AT45_EndOperation();
}
void AT45_PageToBuffer(int pa){
  int pa1=(pa>>6);//6
 int pa2=(pa<<1)&0xff;
	HAL_Delay(1);
AT45_ReadyToWrite();
AT45_SendCmd(0x53);
AT45_SendCmd(pa1);//pa>>6
AT45_SendCmd(pa2);//(pa<<1)&0xff
AT45_SendCmd(0x00);
AT45_EndOperation();
}

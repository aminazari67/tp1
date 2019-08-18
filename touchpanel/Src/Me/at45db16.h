#ifndef _AT45DB16_H
#define _AT45DB16_H
#define AT45_CSPORT   GPIOA
#define AT45_CSPIN    GPIO_PIN_2
#define AT45_WPPORT   GPIOA
#define AT45_WPPIN    GPIO_PIN_6
#define AT45_RSTPORT   GPIOA
#define AT45_RSTPIN    GPIO_PIN_6
#define AT45_ERASECHIP1 0xC7
#define AT45_ERASECHIP2 0x94
#define AT45_ERASECHIP3 0x80
#define AT45_ERASECHIP4 0x9A
#define AT45_MAINMEMORYPAGEREAD 0xD2
#define AT45_BUFFERWRITE 0x84
#define AT45_BUFFERREAD 0xD1
#ifdef __cplusplus
extern "C"
{
#endif
void AT45_init();
void AT45_erase();
void AT45_SendCmd(char  _cmd);
void AT45_EraseChip();
void AT45_CS(int _status);
void AT45_Reset();
void AT45_WP(int _status);
char AT45_ReadMain(int pa,int ba);
void AT45_WriteBuffer(int ba,char data);
void AT45_Write(int pa,int ba, char data);
char AT45_ReadBuffer(int _pageadd);
void AT45_ReadyToWrite();
void AT45_EndOperation();
void AT45_BufferToPage(int pa);
void AT45_PageToBuffer(int pa);
#ifdef __cplusplus
}
#endif
#endif
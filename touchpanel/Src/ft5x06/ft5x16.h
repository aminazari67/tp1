#ifndef _FT5X16_H
#define _FT5X16_H

#ifdef __cplusplus
extern "C"
{
#endif
#define FTTX16_OPERATION 0X00
#define FTTX16_XH1 0X01
#define FTTX16_XL1 0X02
//#define FTTX16_XH1 0X03
#define FTTX16_XH2 0X04
int FT5X16_GetX1();
int FT5X16_GetY1();
int FT5X16_GetW();
void FT5X16_Y();
void FT5X16_X();
void 	FT5X16_W();
void FT5X16_Refresh(int interval);
void FT5X16_SYSTICK();
void FT5X16_TrigEN(int EN);
void FT5X16_GUI_Test();
	void FT5X15_Empty();
#ifdef __cplusplus
}
#endif
#endif
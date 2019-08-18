#ifndef _MYTIMER_H
#define _MYTIMER_H

#ifdef __cplusplus
extern "C"
{
#endif
void Init_Timer();
void Schedule_Timer();
void Refresh_Timer();
void Set_Time(int _hours,int _min,int _second);
void Set_Date(int _year,int _month,int _day);
void Set_Alarm(int _min);
	void Deactive_Alaram();
int Get_ElapseTime();
int Get_H();
int Get_m();
int Get_M();
int Get_D();
#ifdef __cplusplus
}
#endif
#endif
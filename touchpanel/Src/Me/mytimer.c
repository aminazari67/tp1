#include "mytimer.h"
#include "main.h"

extern RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime;
RTC_AlarmTypeDef sAlarm;
RTC_DateTypeDef DateToUpdate;

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */

void Refresh_Timer(){}
void Schedule_Timer(){
uint32_t x=0;
char lcd_buff[16];
HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
//HAL_RTC_GetAlarm(&hrtc,&sAlarm,RTC_ALARM_A,RTC_FORMAT_BIN);
//x=RTC_ReadAlarmCounter(&hrtc);
//lcd_gotoxy(5,1);
//sprintf(lcd_buff,"%d:%d:%d",sTime.Hours,sTime.Minutes,sTime.Seconds);
//sprintf(lcd_buff,"counter=%d",x);
//lcd_puts(lcd_buff);

}
void Set_Time(int _hours,int _min,int _second){
sTime.Hours=_hours;sTime.Minutes=_min;sTime.Seconds=_second;
HAL_RTC_SetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
}
void Init_Timer(){

//MX_RTC_Init();
Set_Time(12,13,50);
}

void Set_Alarm(int _min){
 
  sAlarm.Alarm=RTC_ALARM_A;
	
	Set_Time(0, 0,0);
  HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
  sAlarm.AlarmTime.Hours=sTime.Hours + (sTime.Minutes+_min)/60;;
  sAlarm.AlarmTime.Minutes=(sTime.Minutes+_min)%60;
 	sAlarm.AlarmTime.Seconds = sTime.Seconds;
  HAL_RTC_SetAlarm_IT(&hrtc,&sAlarm,RTC_FORMAT_BIN);

 }
void Deactive_Alaram()
{
	HAL_RTC_DeactivateAlarm(&hrtc, &sAlarm);	
}
 int Get_ElapseTime(){
    HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);
	 //  int t=((sAlarm.AlarmTime.Hours-sTime.Hours)*60+sAlarm.AlarmTime.Minutes)-sTime.Minutes;
	 	// int t = ((sAlarm.AlarmTime.Hours - sTime.Hours) * 3600) + (sAlarm.AlarmTime.Minutes - sTime.Minutes) * 60 + sAlarm.AlarmTime.Seconds - sTime.Seconds;
	 	 int t = ((sAlarm.AlarmTime.Hours * 3600) + (sAlarm.AlarmTime.Minutes * 60) + sAlarm.AlarmTime.Seconds) - ((sTime.Hours * 3600) + (sTime.Minutes * 60) + sTime.Seconds);
	
	 
// HAL_RTC_GetAlarm(&hrtc,&sAlarm,RTC_ALARM_A,RTC_FORMAT_BIN);
//return();
 return t;
 }

 int Get_H(){
     HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);return sTime.Hours;

 }
 int Get_m(){
      HAL_RTC_GetTime(&hrtc,&sTime,RTC_FORMAT_BIN);return sTime.Minutes;
}
 int Get_D(){
        HAL_RTC_GetDate(&hrtc,&DateToUpdate,RTC_FORMAT_BIN);return DateToUpdate.Date;

 }
 int Get_M(){
         HAL_RTC_GetDate(&hrtc,&DateToUpdate,RTC_FORMAT_BIN);return DateToUpdate.Month;

 }


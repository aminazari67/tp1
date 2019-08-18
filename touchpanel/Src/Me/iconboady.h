#ifndef _ICONBOADY_H
#define _ICONBOADY_H
void Logo_Ev(int w);
void Settings_Ev(int w);
void Operation_Ev(int w);
void VoltageUp_Ev(int w);
void VoltageDn_Ev(int w);
void CurrentUp_Ev(int w);
void CurrentDn_Ev(int w);
void TimeUp_Ev(int w);
void TimeDn_Ev(int w);
void DCUp_Ev(int w);
void DCDn_Ev(int w);
void FreqUp_Ev(int w);
void FreqDn_Ev(int w);
void  Motor_Ev(int w);

void Save_Ev(int w);
void Back_Ev(int w);
void Start_Ev(int w);
void Stop_Ev(int w);

void Show_Main();
void Hide_Settings();
void Hide_Operation();
void Show_Operation();

#endif
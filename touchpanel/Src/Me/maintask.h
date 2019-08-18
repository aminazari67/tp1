#ifndef _MAINTASK_H
#define _MAINTASK_H


#ifdef __cplusplus
extern "C"
{
#endif
	void Task_Init();
	void Main_Task();
	void Main_SysTick();
	void Main_Refresh();
#ifdef __cplusplus
}
#endif
#endif
#pragma once
#include "gui/GUI.h"

#define Max_Number_icon 20
extern GUI_CONST_STORAGE GUI_FONT GUI_FontModernNo;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontModernNo2;

extern GUI_CONST_STORAGE GUI_BITMAP bmoperations;
extern GUI_CONST_STORAGE GUI_BITMAP bmsettings;
extern GUI_CONST_STORAGE GUI_BITMAP bmminus;
extern GUI_CONST_STORAGE GUI_BITMAP bmadd;
extern GUI_CONST_STORAGE GUI_BITMAP bmvolt;
extern GUI_CONST_STORAGE GUI_BITMAP bmstopwatch;
extern GUI_CONST_STORAGE GUI_BITMAP bmvoltmeter;
extern GUI_CONST_STORAGE GUI_BITMAP bmstart;
extern GUI_CONST_STORAGE GUI_BITMAP bmstop;
extern GUI_CONST_STORAGE GUI_BITMAP bmcur;
extern GUI_CONST_STORAGE GUI_BITMAP bmstopwatch;
extern GUI_CONST_STORAGE GUI_BITMAP bmlogo;
extern GUI_CONST_STORAGE GUI_BITMAP bmback;
extern GUI_CONST_STORAGE GUI_BITMAP bmsave;
extern GUI_CONST_STORAGE GUI_BITMAP bmmotor;
extern GUI_CONST_STORAGE GUI_BITMAP bmplay;











//extern GUI_CONST_STORAGE GUI_FONT GUI_Fontarial;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontLatin48;

namespace icon{

	class icon;
	typedef void(*pFunction_t)(int); 

	static icon*		Allicons[Max_Number_icon];
	static unsigned int Index = 0;
	//pFunction_t			Handler; 
		class icon
	{
	public:
		icon();
		~icon();
		float Value;
	private:
		int XLeftUp;
		int XLeftDn;
		int XRightUp;
		int XRightDn;
		int YLeftUp;
		int YLeftDn;
		int YRightUp;
		int YRightDn;
		int XCenter;
		int YCenter;
		int Size;
		bool IconStat;
		const GUI_BITMAP * pic;
		char *IconText;
		char *IconText2;
		
		
	public:
		
		void Show_Icon();
		void Set_Icon(const GUI_BITMAP * pBM);
		void Set_IconCaption(char *text);
		void Set_IconCaption2(char *text);

		void Show_IconCaption();
		void Show_IconCaption2();
		void Active_IconCaption();
		void Set_Pos(int x, int y,int size);
		int Match_Touch();
		static void Refresh();
		static void UpdateVal(int val,icon * icon);
		static void Enable(icon* _icon);
		void SetHandler(pFunction_t handler);
		void Hide_Icon();
		bool Get_IconStat();
		void Set_Value(float _val);
		float Get_Value();
	
		void Show_Value();
		void Show_Value2();
		void Hide_Value2();
		pFunction_t			Handler; 
		
	private:
		
	}
	;
}


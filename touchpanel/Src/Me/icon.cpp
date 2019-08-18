#include "icon.h"
#include "src/gui/GUI.h"
#include "Src/ft5x06/ft5x16.h"
#include "stdio.h"

namespace icon
{

	icon::icon()
	{
		if (Index < Max_Number_icon)
		{
			Allicons[Index++] = this;                                              //Add this key to AllKeys container for update
			IconStat = 0;
		}	
	}


	icon::~icon()
	{
	}


	void icon::Set_Pos(int x, int y,int size)
	{
		XLeftDn=XLeftUp = x;
		YRightUp=YLeftUp = y;
		XRightDn=XRightUp = x + size;
		YRightDn=YLeftDn = y + size;
		XCenter = x + (size / 2);
		YCenter = y + (size / 2);
		Size = size;
	}


	void icon::Show_Icon()
	{
		GUI_DrawBitmap(pic, XLeftUp, YLeftUp);
		Show_IconCaption();
		IconStat = 1;
	}


	void icon::Hide_Icon()
	{
		/*
		GUI_SetBkColor(0x0000);
		GUI_FillRect(XLeftUp, YLeftUp, XRightDn, YRightDn);
		GUI_DispStringAt("", XCenter, YLeftDn + 10);
		GUI_DispCEOL();
		*/
		//GUI_Clear();
		IconStat = 0;
	}
	void icon::Set_Icon(const GUI_BITMAP * pBM)
	{
		pic = pBM;	
	}
	void icon::Set_IconCaption(char *text)
	{
		IconText = text;
	}
	void icon::Set_IconCaption2(char *text)
	{
		IconText2 = text;
	}
	void icon::Show_IconCaption()
	{
		GUI_SetFont(&GUI_FontModernNo2);//GUI_Font32B_1
		//GUI_SetBkColor(GUI_RED);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt(IconText, XCenter, YLeftDn + 10);
	}
	
	void icon::Show_IconCaption2()
	{
		GUI_SetFont(&GUI_FontModernNo2); //GUI_Font32B_1
		//GUI_SetBkColor(GUI_RED);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt(IconText2, XCenter+350, YLeftDn + 10);
	}
	
	void icon::Active_IconCaption()
	{
		GUI_SetFont(&GUI_FontModernNo2); //GUI_Font32B_1
		//GUI_SetBkColor(GUI_RED);
		GUI_SetColor(GUI_GREEN);
		GUI_DispStringAt(IconText, XCenter, YLeftDn + 10);
	}
	void icon::Set_Value(float _val)
	{
		
		Value = _val;
	}
	
	float icon::Get_Value()
	{
		return Value;
	}
	void icon::Show_Value()
	{
		
		char lcd[30];
		int val=Value * 10;
		

		
		  GUI_SetFont(&GUI_FontD36x48);
		GUI_SetBkColor(GUI_BLACK);	
		GUI_SetColor(GUI_GREEN);	
		GUI_GotoXY(XCenter + 10, YLeftUp - 60);
		GUI_DispFloat(Value, 4);
		if (val % 10 != 0)
		{
			GUI_GotoXY( XCenter + 10, YLeftUp - 60);
		//	GUI_DispFloat(Value, 4);
		}
		else if (val % 10 == 0)
		{
			//GUI_DispDecAt((int)Value, XRightUp + 130, YCenter, 2);
			GUI_GotoXY( XCenter + 10, YLeftUp - 60);
			//GUI_DispDecMin((int)Value);
		//	GUI_DispDec((int)Value, 3);
		}
	

		
/*
		GUI_SetFont(&GUI_FontModernNo);  //GUI_FontLatin48	
		GUI_SetColor(GUI_BLACK);
		sprintf(lcd, "000000");
		GUI_DispStringAt(lcd, XCenter + 10, YLeftUp - 60);
		GUI_SetColor(GUI_WHITE);
		if (val % 10 != 0)
		{
				
			sprintf(lcd, "%d.%d", val / 10, val % 10);
			
		}
		else if (val % 10 == 0)
		{
			
			
			sprintf(lcd, "%d", val / 10);
			
		}
		GUI_DispStringAt(lcd, XCenter + 10, YLeftUp - 60);
		//GUI_GotoXY(XCenter + 10, YLeftUp - 60);
		//GUI_SetTextStyle(GUI_TS_OVERLINE);
		//if(Value>999){Value = 2;}
		
		//GUI_DispDecAt(Value, XCenter + 10, YLeftUp - 60,2);
		*/
		}
	
	void icon::Show_Value2()
	{
		char lcd[30];
		int val = Value * 10;
		if (Value < 0){Value = 0; }
		//Hide_Value2();
		//GUI_SetFont(&GUI_FontLatin48);     //GUI_FontModern54
		 GUI_SetFont(&GUI_FontD36x48);
		GUI_SetBkColor(GUI_BLACK);	
			GUI_SetColor(GUI_GREEN);	
		if (val % 10 != 0)
		{
			GUI_GotoXY(XRightUp + 130, YCenter);
			GUI_DispFloat(Value,5);
		}
		else if (val % 10 == 0)
		{
			//GUI_DispDecAt((int)Value, XRightUp + 130, YCenter, 2);
			GUI_GotoXY(XRightUp + 130, YCenter);
			//GUI_DispDecMin((int)Value);
			GUI_DispDec((int)Value, 4);
		}
		
		if (val % 10 != 0)
		{
			
			sprintf(lcd, "%d.%d", val / 10,val%10); }
		else if (val % 10 == 0)
		{
			
			

			
			sprintf(lcd, "%d", val / 10);
			}
		GUI_SetBkColor(GUI_BLACK);
	//	GUI_DispStringAt(lcd, XRightUp + 130, YCenter); 
		//GUI_DispDecAt(val, XRightUp + 130, YCenter, 3);
		
		
	}
	
	void icon::Hide_Value2()
	{
		char lcd[30];
		int val =99.0;
		
		
			//GUI_SetFont(&GUI_FontLatin48);    //GUI_FontModern54
		 GUI_SetFont(&GUI_FontD36x48);
			GUI_SetColor(GUI_BLACK);
		sprintf(lcd, "000000");
	GUI_DispStringAt(lcd, XRightUp + 130, YCenter);
		
			
		
		
	/*	
		GUI_SetFont(&GUI_FontLatin48);   //GUI_FontModern54
		GUI_SetColor(GUI_BLACK);
		sprintf(lcd, "%d.%d", 99, 9);
		GUI_DispStringAt(lcd, XRightUp + 130, YCenter);*/
	}
	void icon::Refresh()
	{
		for (int var =0; var <18; ++var)
		{
			if (Allicons[var]->Match_Touch() == 1)
			{
				
				Allicons[var]->Handler(FT5X16_GetW());
				
			}
			
		}	
		FT5X15_Empty();
	}
	
	void icon::UpdateVal(int val, icon *icon )
	{
		if (icon->IconStat == 1)
		{
			icon->Show_Value2();	
		}
		
	}
	

	void icon::SetHandler(pFunction_t handler)
	{
		Handler = handler;
	}
	
	void icon::Enable(icon* icon)
	{
	
	}
	bool icon::Get_IconStat()
	{
		return IconStat;
	}
	int icon:: Match_Touch()
	{
		int xm = Size/2; int ym =Size/2;
		int x = FT5X16_GetX1(); int y = FT5X16_GetY1();
		

		if (x < (XCenter + xm)&&(x > XCenter - xm))
		{
			
			if ((y < (YCenter + ym))&&(y > YCenter - ym))
			{
				return 1;
			}
		}
	
		return 0;
	}
}
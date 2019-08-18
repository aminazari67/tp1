
#include "iconboady.h"
#include "icon.h"
#include "iconinit.h"
#include "parameter.h"
#include "paraminit.h"
#include "analogio.h"
#include "src/gui/usually.h"
#include "mytimer.h" 

void Logo_Ev(int w)
{
}

void Settings_Ev(int w)
{
	if (iconinit::Settings.Get_IconStat() == 1)
	{
		
		//LCD_Clear(BLACK);
		iconinit::Settings.Hide_Icon();
		iconinit::Operation.Hide_Icon();
		iconinit::Logo.Hide_Icon();
		LCD_Clear(BLACK);
		//GUI_Clear();
		/*voltage*/
		iconinit::VoltageUp.Show_Icon();
		iconinit::VoltageDn.Show_Icon();
		iconinit::VoltageUp.Show_Value();
		/*current*/
		iconinit::CurrentUp.Show_Icon();
		iconinit::CurrentDn.Show_Icon();
		iconinit::CurrentUp.Show_Value();
		/*time*/
		iconinit::TimeUp.Show_Icon();
		iconinit::TimeDn.Show_Icon();
		iconinit::TimeUp.Show_Value();
       /*duty cycle*/
		iconinit::DCUp.Show_Icon();
		iconinit::DCDn.Show_Icon();
		iconinit::DCUp.Show_Value();
		/*frequency*/
		iconinit::FreqUp.Show_Icon();
		iconinit::FreqDn.Show_Icon();
		iconinit::FreqUp.Show_Value();
		
		iconinit::Back.Show_Icon();
		iconinit::Save.Show_Icon();
		iconinit::Motor.Show_Icon();

	}
}

void Operation_Ev(int w) {
	if (iconinit::Operation.Get_IconStat() == 1)
	{

		iconinit::Settings.Hide_Icon();
		iconinit::Operation.Hide_Icon();

		Show_Operation();

		
	}
}

void VoltageUp_Ev(int w)
{
	float val;
	if (iconinit::VoltageUp.Get_IconStat() == 1)
	{
		val = iconinit::VoltageUp.Get_Value();
		
		 if (w >50)
		{
		val = val + 1;
		}
		else if (w < 25)
		{
			val = val + 0.1;
		}
		
		if (val > 30.1)
		{
			val = 0;	
		}
		
		iconinit::VoltageUp.Set_Value(val);
		iconinit::VoltageUp.Show_Value();
		}
}


void VoltageDn_Ev(int w)
{
	float val;
	if (iconinit::VoltageDn.Get_IconStat() == 1)
	{
		val = iconinit::VoltageUp.Get_Value();
		val = iconinit::VoltageUp.Get_Value();
		if (w>25)
		{
			val = val - 1;
		}
		else if (w<20)
		{
			val = val - 0.1;

		}
		if (val < 0)
		{
			val = 30.1;	
		}
		//val = 13;
		iconinit::VoltageUp.Set_Value(val);
		iconinit::VoltageUp.Show_Value();
		//iconinit::VoltageUp.Hide_Icon();
		
		
		
	}
}
void CurrentUp_Ev(int w)
{
	float val;
	if (iconinit::CurrentUp.Get_IconStat() == 1)
	{
		val = iconinit::CurrentUp.Get_Value();
		if (w>25)
		{
			val = val + 1;
		}
		else if (w <20)
		{
			val = val + 0.1;

		}


		if (val > 30.1)
		{
			val = 0;
		}
		iconinit::CurrentUp.Set_Value(val);
		iconinit::CurrentUp.Show_Value();
	}
}
void CurrentDn_Ev(int w)
{
	float val;
	if (iconinit::CurrentDn.Get_IconStat() == 1)
	{
		val = iconinit::CurrentUp.Get_Value();

		if (w > 25)
		{
			val = val - 1;
		}
		else if (w <20)
		{
			val = val - 0.1;

		}
		if (val < 0)
		{
			val = 30.1;
		}
		//val = 13;
		iconinit::CurrentUp.Set_Value(val);
		iconinit::CurrentUp.Show_Value();
		//iconinit::VoltageUp.Hide_Icon();



	}
}
/*time*/
void TimeUp_Ev(int w)
{
	float val;
	if (iconinit::TimeUp.Get_IconStat() == 1)
	{
		val = iconinit::TimeUp.Get_Value();
		
		 if (w >25)
		{
			val = val + 1;
		}


		if (val > 99)
		{
			val = 0;
		}
		iconinit::TimeUp.Set_Value(val);
		iconinit::TimeUp.Show_Value();
	}
}
void TimeDn_Ev(int w)
{
	float val;
	if (iconinit::TimeDn.Get_IconStat() == 1)
	{
		val = iconinit::TimeUp.Get_Value();

		
		 if (w >25)
		{
			val = val - 1;
		}
		if (val < 0)
		{
			val = 999;
		}
		//val = 13;
		iconinit::TimeUp.Set_Value(val);
		iconinit::TimeUp.Show_Value();
		//iconinit::VoltageUp.Hide_Icon();



	}
}



/*duty cycle*/
void DCUp_Ev(int w)
{
	float val;
	if (iconinit::DCUp.Get_IconStat() == 1)
	{
		val = iconinit::DCUp.Get_Value();
		 if (w >25)
		{
			val = val + 1;
		}


		if (val > 100)
		{
			val = 0;
		}
		iconinit::DCUp.Set_Value(val);
		iconinit::DCUp.Show_Value();
	}
}

void DCDn_Ev(int w)
{
	float val;
	if (iconinit::DCDn.Get_IconStat() == 1)
	{
		val = iconinit::DCUp.Get_Value();

		 if (w >25)
		{
			val = val - 1;
		}
		if (val < 0)
		{
			val = 100;
		}
		//val = 13;
		iconinit::DCUp.Set_Value(val);
		iconinit::DCUp.Show_Value();
		//iconinit::VoltageUp.Hide_Icon();



	}
}
/*frequency*/
void FreqUp_Ev(int w)
{
	float val;
	if (iconinit::FreqUp.Get_IconStat() == 1)
	{
		val = iconinit::FreqUp.Get_Value();
		 if (w >25)
		{
			val = val + 1;
		}


		if (val > 100)
		{
			val = 0;
		}
		iconinit::FreqUp.Set_Value(val);
		iconinit::FreqUp.Show_Value();
	}
}

void FreqDn_Ev(int w)
{
	float val;
	if (iconinit::FreqDn.Get_IconStat() == 1)
	{
		val = iconinit::FreqUp.Get_Value();

		 if (w >25)
		{
			val = val - 1;
		}
		if (val < 0)
		{
			val = 100;
		}
		//val = 13;
		iconinit::FreqUp.Set_Value(val);
		iconinit::FreqUp.Show_Value();
		//iconinit::VoltageUp.Hide_Icon();



	}
}
void  Motor_Ev(int w)
{
	if (iconinit::Motor.Get_IconStat() == 1)
	{
		if (w > 25)
		{
			++iconinit::Motor.Value; if (iconinit::Motor.Value > 1){iconinit::Motor.Value = 0; }
			switch ((int)iconinit::Motor.Value)
			{
			case 0:
				iconinit::Motor.Set_IconCaption("LEFT");
				break;
			case 1:
				iconinit::Motor.Set_IconCaption("RIGHT");
				break;
	
			
			}
			iconinit::Motor.Show_IconCaption();
		}
	}
}
void Save_Ev(int w)
{
	if (iconinit::Save.Get_IconStat() == 1)
	{
		if (w>30)
		{
			
			paraminit::Current.Set_SValue(iconinit::CurrentUp.Get_Value());
			paraminit::Time.Set_SValue(iconinit::TimeUp.Get_Value());
			paraminit::DC.Set_SValue(iconinit::DCUp.Get_Value()); //iconinit::DCUp.Get_Value()
			paraminit::Freq.Set_SValue(iconinit::FreqUp.Get_Value());
			paraminit::Voltage.Set_SValue(iconinit::VoltageUp.Get_Value()); //iconinit::VoltageUp.Get_Value()
			paraminit::Voltage.Set_Step();
			paraminit::Motor.Set_SValue(iconinit::Motor.Get_Value());
			iconinit::Time.Set_Value(iconinit::TimeUp.Get_Value());
			parameter::parameter::Save_Param();
			Hide_Settings();
			Show_Main();
		}	
		
		
	}
	
}

void Back_Ev(int w)
{
	if ((iconinit::Back.Get_IconStat() == 1))
	{
		iconinit::VoltageUp.Set_Value(paraminit::Voltage.Get_SValue());
		if (iconinit::VoltageUp.Get_IconStat() == 1)
		{
			Hide_Settings();
		}
		if (iconinit::Start.Get_IconStat() == 1)
		{
			Hide_Operation();
		}
		
		Show_Main();
	}
	
}
void Start_Ev(int w)
{
	if (iconinit::Start.Get_IconStat() == 1)
	{
		if (w > 30)
		{
			iconinit::Start.Active_IconCaption();
			iconinit::Stop.Show_IconCaption();
			
		//	Set_Alarm(paraminit::Time.Set_Value);

			iconinit::Start.Hide_Icon();
			iconinit::Back.Hide_Icon();
			
			paraminit::Voltage.Fall_Enable = 0;
			paraminit::Voltage.Rise_Enable = 1;
			//paraminit::Current.Rise_Enable = 1;
		}
	}
	
}

void Stop_Ev(int w)
{
	if (iconinit::Stop.Get_IconStat() == 1)
	{
		if (w > 30)
		{
			iconinit::Start.Show_IconCaption();
			iconinit::Stop.Active_IconCaption();
			paraminit::Voltage.Rise_Enable = 0;
			paraminit::Voltage.Fall_Enable = 1;
			//paraminit::Current.Fall_Enable = 1;
		}
	}
	
}

void Show_Main()
{
	GUI_Clear();
	LCD_Clear(BLACK);
	iconinit::Settings.Show_Icon();
	iconinit::Operation.Show_Icon();
	iconinit::Logo.Show_Icon();
}
void Hide_Settings()
{
	GUI_Clear();
	iconinit::VoltageUp.Hide_Icon();
	iconinit::VoltageDn.Hide_Icon();
	iconinit::CurrentUp.Hide_Icon();
	iconinit::CurrentDn.Hide_Icon();
	iconinit::DCUp.Hide_Icon();
	iconinit::DCDn.Hide_Icon();
	iconinit::TimeUp.Hide_Icon();
	iconinit::TimeDn.Hide_Icon();
	iconinit::FreqUp.Hide_Icon();
	iconinit::FreqDn.Hide_Icon();
	iconinit::Motor.Hide_Icon();
	iconinit::Save.Hide_Icon();
	iconinit::Back.Hide_Icon();
	
}
void Show_Operation()
{
	//GUI_Clear();
	LCD_Clear(BLACK);
	iconinit::Volt.Show_Icon();
	iconinit::Volt.Show_IconCaption2();
	//iconinit::Volt.Show_Value2();
	iconinit::Amper.Show_Icon();
	iconinit::Amper.Show_IconCaption2();
	//iconinit::Amper.Show_Value2();
	iconinit::Time.Show_Icon();
	iconinit::Time.Show_IconCaption2();
	//iconinit::Time.Show_Value2();
	iconinit::Start.Show_Icon();
	iconinit::Stop.Show_Icon();
	
	iconinit::Back.Show_Icon();
	
}
void Hide_Operation()
{
	
	GUI_Clear();
	iconinit::Volt.Hide_Icon();
	iconinit::Amper.Hide_Icon();
	iconinit::Time.Hide_Icon();
	iconinit::Start.Hide_Icon();
	iconinit::Stop.Hide_Icon();
	iconinit::Back.Hide_Icon();
	
}

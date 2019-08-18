#include "iconinit.h"
#include "icon.h"
#include "iconboady.h"
#include "paraminit.h"
namespace iconinit
{
	icon::icon Settings;
	icon::icon Operation;
	icon::icon Logo;
	icon::icon VoltageUp;
	icon::icon VoltageDn;
	icon::icon CurrentUp;
	icon::icon CurrentDn;
	icon::icon TimeUp;
	icon::icon TimeDn;
	icon::icon DCUp;
	icon::icon DCDn;
	icon::icon FreqDn;
	icon::icon FreqUp;
	
	icon::icon Back;
	icon::icon Save;
	
	icon::icon Motor;
	icon::icon Start;
	icon::icon Stop;
	
	icon::icon Volt;
    icon::icon Amper;
	icon::icon Time;
	icon::icon Freq;
	icon::icon DC;
	 

void init()
	{
		

Logo.Set_Icon(&bmlogo);
		Logo.Set_IconCaption("Logo");
		
		Logo.Set_Pos(520, 100, 150);
		Logo.SetHandler(Logo_Ev);
		Logo.Show_Icon();
		Logo.Show_IconCaption();

		Settings.Set_Icon(&bmsettings);
		Settings.Set_IconCaption("Settings");
		Settings.Set_Pos(260, 130,200);
		Settings.Show_Icon();
		Settings.Show_IconCaption();
		Settings.SetHandler(Settings_Ev);

		Operation.Set_Icon(&bmoperations);
		Operation.Set_Pos(15, 100,150);
		Operation.Set_IconCaption("Operations");
		Operation.SetHandler(Operation_Ev);
		Operation.Show_Icon();
		/*voltage*/
		VoltageUp.Set_Icon(&bmadd);
		VoltageUp.Set_Pos(10, 100, 100);
		VoltageUp.Set_IconCaption("Set Voltage");
		VoltageUp.SetHandler(VoltageUp_Ev);
		VoltageUp.Set_Value(paraminit::Voltage.Set_Value);

		VoltageDn.Set_Icon(&bmminus);
		VoltageDn.Set_Pos(150, 100, 100);
		VoltageDn.SetHandler(VoltageDn_Ev);

		/*current*/
		CurrentUp.Set_Icon(&bmadd);
		CurrentUp.Set_Pos(10, 320, 100);
		CurrentUp.Set_IconCaption("Set Current");
		CurrentUp.SetHandler(CurrentUp_Ev);
		CurrentUp.Set_Value(paraminit::Current.Set_Value);

		CurrentDn.Set_Icon(&bmminus);
		CurrentDn.Set_Pos(150, 320, 100);
		CurrentDn.SetHandler(CurrentDn_Ev);
		/*time*/
		TimeUp.Set_Icon(&bmadd);
		TimeUp.Set_Pos(270, 100, 100);
		TimeUp.Set_IconCaption("Set Time");
		TimeUp.SetHandler(TimeUp_Ev);
		TimeUp.Set_Value(paraminit::Time.Set_Value);

		TimeDn.Set_Icon(&bmminus);
		TimeDn.Set_Pos(410, 100, 100);
		TimeDn.SetHandler(TimeDn_Ev);
		/*duty cycle*/
		DCUp.Set_Icon(&bmadd);
		DCUp.Set_Pos(270, 320, 100);
		DCUp.Set_IconCaption("Set DutyCyc");
		DCUp.SetHandler(DCUp_Ev);
		DCUp.Set_Value(paraminit::DC.Set_Value);

		DCDn.Set_Icon(&bmminus);
		DCDn.Set_Pos(410, 320, 100);
		DCDn.SetHandler(DCDn_Ev);

		/* frequency*/
		FreqUp.Set_Icon(&bmadd);
		FreqUp.Set_Pos(550, 100, 100);
		FreqUp.Set_IconCaption("Set Frequency");
		FreqUp.SetHandler(FreqUp_Ev);     //
		FreqUp.Set_Value(paraminit::Freq.Set_Value); //

		FreqDn.Set_Icon(&bmminus);
		FreqDn.Set_Pos(690, 100, 100);
		FreqDn.SetHandler(FreqDn_Ev);    //

		Back.Set_Icon(&bmback);
		Back.Set_Pos(600,390, 70);
		Back.SetHandler(Back_Ev);

		Save.Set_Icon(&bmsave);
		Save.Set_Pos(690, 390, 70);
		Save.SetHandler(Save_Ev);  //Save_Ev

		Motor.Set_IconCaption("Set Motor Spin");
		Motor.Set_Icon(&bmmotor);
		Motor.Set_Pos(550, 270, 70);
		Motor.Set_Value(0);
		Motor.SetHandler(Motor_Ev);
		//FreqDn.SetHandler(FreqDn_Ev);
		/*OPERATION*/
		/*vlot*/
		Volt.Set_Icon(&bmvolt);
		Volt.Set_Pos(20, 20, 100);
		Volt.Set_IconCaption("VoltMeter");
		Volt.Set_IconCaption2("Volt");
		Volt.Set_Value(0);

		/*amper*/
		Amper.Set_Icon(&bmcur);
		Amper.Set_Pos(20, 170, 100);
		Amper.Set_IconCaption("AmperMeeter");
		Amper.Set_IconCaption2("Amp");
		Amper.Set_Value(0);

		/*time*/
		Time.Set_Icon(&bmstopwatch);  //&bmstopwatch
		Time.Set_Pos(20, 320, 100);
		Time.Set_IconCaption("StopWatch");
		Time.Set_IconCaption2("Min");
		Time.Set_Value(paraminit::Time.Set_Value);

		/*start*/
		Start.Set_Icon(&bmplay);
		Start.Set_Pos(600, 20, 150);
		Start.Set_IconCaption("Start");
		Start.SetHandler(Start_Ev); 

		Stop.Set_Icon(&bmstop);
		Stop.Set_Pos(600,220, 150);
		Stop.Set_IconCaption("Stop");
		Stop.SetHandler(Stop_Ev); 


	}

}    

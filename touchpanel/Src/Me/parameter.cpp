#include "parameter.h"
#include "at45db16.h"


namespace parameter
{
	
parameter::parameter()
{
	if (Index < Max_Number_icon)
	{
		Allparameters[Index++] = this;                                                //Add this key to AllKeys container for update
		
	}	
	
	Rel_Value = 0.0f;
	Set_Value = 0.0f;
	Now_Value = 0.0f;
	Max_Value = 30.1;
	Refresh_Time = 10000;
	Schedule_Time = 0;
	Step = 0;
}


parameter::~parameter()
{
}


void parameter::Set_RValue(float value)
{
	Rel_Value = value;
}


float parameter::Get_RValue()
{
	return Rel_Value;
}


void parameter::Set_SValue(float value)
{
	Set_Value = value;
}


float parameter::Get_SValue()
{
	return Set_Value;
}
	void parameter::Set_Handler(pFunction_t handler )
	{
		Handler = handler;	
	}
	void parameter::Set_Step()
	{
		Refresh_Time = 4000 / (Set_Value /((float) (30.1 / 2048)));
		//Refresh_Time = 3;
	}	
	
	
	
	void parameter::Refresh()
	{
		for (int var = 0; var < 2; ++var)
		{
			 if(Allparameters[var]->Schedule_Time >= Allparameters[var]->Refresh_Time)
			{
				Allparameters[var]->Handler();	
				Allparameters[var]->Schedule_Time = 0;
			}
		
				
		}
	}
	void parameter::Schedule()
	{
		for (int var = 0; var < 2; ++var)
		{
			if (Allparameters[var]->Schedule_Time < Allparameters[var]->Refresh_Time)
			{
				++Allparameters[var]->Schedule_Time;
			}
			
						
		}	
	}
	void parameter::Save_Param()
	{
		for (int obj = 0; obj < Index;++obj)
		{
			char dot = (int)(Allparameters[obj]->Set_Value * 10) % 10;
			AT45_Write(1, 2*obj, Allparameters[obj]->Set_Value);	
			AT45_Write(1, (2*obj) + 1, dot);	
		}
	}
	void parameter::Load_Param()
	{
		for (int obj = 0; obj < Index; ++obj)
		{
			char dot = ((int)Allparameters[obj]->Set_Value * 10) % 10;
			int a = AT45_ReadMain(1, 2*obj);
			int b = AT45_ReadMain(1, (2*obj)+1);
			Allparameters[obj]->Set_Value = (float)((a * 10) + b) / 10;	
		}	
		
	}
}

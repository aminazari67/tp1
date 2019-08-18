#pragma once
namespace parameter
{
#define Max_Number_icon 20
	class parameter;
	typedef void(*pFunction_t)(void); 

	static parameter*		Allparameters[Max_Number_icon];
	static unsigned int Index = 0;
	class parameter
	{
	public:
		parameter();
		~parameter();
		static void Refresh();
		static void Schedule();
		static void Save_Param();
		static void Load_Param();
		static bool ParamClass_EN ;
		float Rel_Value;
		float Set_Value;
		float Now_Value;
		float Max_Value;
		int Step;
		bool Fall_Enable;
		bool Rise_Enable;
		int Schedule_Time;
		int Refresh_Time;
		void Set_RValue(float value);
		float Get_RValue();
		void Set_SValue(float value);
		float Get_SValue();
		void Set_Step();
		
		void Step_Func();
		void Rise();
		void Fall();
		void Set_Handler(pFunction_t);
		pFunction_t			Handler; 
	
	};

}
#pragma once
#ifndef _PARAMINIT_H
#define _PARAMINIT_H
#include "parameter.h"
#include "analogio.h"
namespace paraminit
{
	extern parameter::parameter Voltage;
	extern parameter::parameter Current;
	extern parameter::parameter Time;
	extern parameter::parameter DC;
	extern parameter::parameter Freq;
	extern parameter::parameter Motor;
	extern analogio::analogio Volt;
	extern analogio::analogio Amp;
	void init();
}
#endif


#include "weatherInfo.h"
#ifndef MainWindow_h
#include "MainWindow.h"
#endif
using namespace System;


weatherInfo::weatherInfo()
{
	//  temp = 0;

}

void weatherInfo::parseData(System::String^ info)
{
	array<String^>^ dane = info->Split(':');
	int found = 0;
	temp = dane[1];
	pressure = dane[7];
	humidity = dane[9];
	tempMIN = dane[11];
	tempMAX = dane[13];
	windSpeed = dane[15];
	icon = dane[17]+".png";
}

void weatherInfo::putData()
{
}

void weatherInfo::ToString(System::String^ text)
{
	text += "Temp:" + temp + "\n\r";
	text += "Pressure" + pressure + "\n\r";
	text += "Humidity" + humidity + "\n\r";
	text += "WindSpeed" + windSpeed + "\n\r";
	text += "TempMIN" + tempMIN + "\n\r";
	text += "TempMAX" + tempMAX + "\n\r";
	text += "Icon" + icon + "\n\r";
}

#pragma once
ref class weatherInfo
{
	
public:

	weatherInfo();
	System::String^ city;
//	int temp;
	System::String^ temp;
	System::String^ humidity;
	System::String^ tempMIN;
	System::String^ tempMAX;
	System::String^  windSpeed;
	System::String^ pressure;
	System::String^ icon;
	void parseData(System::String^ info);

	void putData();

	void ToString(System::String ^ text);

};


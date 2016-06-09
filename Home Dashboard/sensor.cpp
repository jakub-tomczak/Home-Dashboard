#include "sensor.h"





sensor::sensor()
{
	name = "";
	state = 0;
};

void sensor::parseData(System::String^ info)
{
	array<System::String^>^ dane = info->Split(':');
	name = dane[0];
	state = System::Convert::ToInt16(dane[1]);
	
}


void sensor::ToString(System::String^ pom)
{
	pom += "Czujnik : " + name+"\n\r";
	pom += "\tstan : " + state + "\n\r";
}
 
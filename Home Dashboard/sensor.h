
#pragma once
ref class sensor
{
public:
	//std::string nazwa=L"ada";
	System::String^ name;
	System::Int16 state;
	sensor();
	void parseData(System::String ^ info);
	void ToString(System::String ^ pom);
};


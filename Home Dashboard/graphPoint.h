#pragma once
ref class graphPoint 
{
public:
	graphPoint();

private:
	//attributes
	int X, Y;
	//timestamp
	System::DateTime timestamp;
	//sensor id
	System::String^ id;
};


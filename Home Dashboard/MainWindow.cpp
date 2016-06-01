#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)

{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	HomeDashboard::MainWindow form;
	Application::Run(%form);

}
//my methods
void HomeDashboard::MainWindow::moveGroupox()
{
	Point endPointA = System::Drawing::Point(0, HomeDashboard::MainWindow::Height);
	Point startPointA = System::Drawing::Point(0, HomeDashboard::MainWindow::Height);
	int endPoint = HomeDashboard::MainWindow::groupBox1->Height;
	int endPoint2 = HomeDashboard::MainWindow::Height;
	Console::WriteLine(endPoint2);

	if (stateVisible)
	{
		endPoint /= 2;
		for (int i = 41; i <= endPointA.Y + 41;i += 2)
		{
			Sleep(10);
			//wait(10);
			HomeDashboard::MainWindow::groupBox1->Update();
			HomeDashboard::MainWindow::groupBox1->Location = System::Drawing::Point(30, i);
		}
		// HomeDashboard::MainWindow::button1->Visible = true;
		stateVisible = false;
	}
	else {
		stateVisible = true;

		for (int i = endPoint + 82;i >= 82;i--)

		{

			// System::Threading::Timeout();
			wait(5);Update();
			HomeDashboard::MainWindow::groupBox1->Update();
			HomeDashboard::MainWindow::groupBox1->Location = System::Drawing::Point(30, i);
		}
		HomeDashboard::MainWindow::button1->Visible = false;
		wait(2);
	}

	HomeDashboard::MainWindow::CurrentAutoScaleDimensions;


}
void HomeDashboard::MainWindow::wait(unsigned timeout)
{
	timeout += clock();
	while (clock() < timeout) continue;
}


//components methods
System::Void HomeDashboard::MainWindow::groupBox1_OnMouseHover(System::Object ^sender, System::EventArgs ^e)
{
	Console::WriteLine("group hover!");


	//	 Thread^ newThread = gcnew Thread(gcnew ThreadStart(&MainWindow::moveGroupox()));
	// newThread->Start();
//	moveGroupox();
	Console::WriteLine("lecimy dalej!");
}
/*
System::Void groupBox1_OnMouseHover(System::Object ^sender, System::EventArgs ^e)
{
	Console::WriteLine("group hover!");


	//	 Thread^ newThread = gcnew Thread(gcnew ThreadStart(&MainWindow::moveGroupox()));
	// newThread->Start();
	//HomeDashboard::MainWindow::moveGroupox();
	Console::WriteLine("lecimy dalej!");
}
*/
System::Void HomeDashboard::MainWindow::DataChart_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	HomeDashboard::MainWindow::DataChart->Series->Add("temperatura");
	HomeDashboard::MainWindow::DataChart->Series["temperature"]->ChartType = System::Windows::Forms::DataVisualization::Charting->Chart;

	Home
}
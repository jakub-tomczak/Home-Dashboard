#pragma once
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include "graphPoint.h"
#include "sensor.h"
#include "weatherInfo.h"
#include <fstream>
#include <iostream>
#include <msclr/marshal_cppstd.h>

namespace HomeDashboard {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Windows::Forms::DataVisualization;
	using namespace System::Data::SqlClient;
	using namespace System::IO;
	//using namespace System::Web;
	using namespace System::Net;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>

	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			/*
			System::String^ connectionString = "Server=tcp:homedashboard.database.windows.net,1433;Data Source=homedashboard.database.windows.net;Initial Catalog=czujniki;Persist Security Info=False;User ID=jakubtomczak;Password=@Kapusta12!;Pooling=False;MultipleActiveResultSets=False;Encrypt=True;TrustServerCertificate=False;Connection Timeout=30;";
			SqlConnection ^sql = gcnew SqlConnection(connectionString);
			try
			{
				sql->Open();
			}
			catch (Exception^ e)
			{
				////Console::WriteLine("Nie uda�o si� po��czy� z baz� danych!");
				////Console::WriteLine(e->ToString());
			}
			////Console::Write("Stan polaczenia = ");
			////Console::WriteLine(sql->State);
			*/

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			////Console::WriteLine("inicjalizacja\n");
			
			timer1->Interval = 30000;
			timer1->Start();
			WeatherUpdate();

			timer2->Interval = 5000;
			timer2->Start();
			////Console::WriteLine("Added a chart");

			//TemperatureChart->Series["temperatura"]->Points->AddXY(0, 0);
			//HumidityChart->Series["humidity"]->Points->AddXY(0, 0);

			timer3->Interval = 3000;
			timer3->Start();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			
			if (components)
			{
				delete components;
			}
		}


	protected:

	protected:









	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;

















































	private: System::Windows::Forms::Timer^  timer1;


















private: System::Windows::Forms::SaveFileDialog^  Ustawienia_DialogSaveFile;
private: System::Windows::Forms::OpenFileDialog^  Ustawienia_DialogOpenFile;
private: System::Windows::Forms::TabPage^  pageSettings;
private: System::Windows::Forms::GroupBox^  Ustawienia_GroupInternetConnection;
private: System::Windows::Forms::Label^  Ustawienia_labelStatus;
private: System::Windows::Forms::Label^  Ustawienia_LabelStatusWeb;
private: System::Windows::Forms::Button^  Ustawienia_buttonInternetConnection;
private: System::Windows::Forms::GroupBox^  Ustawienia_GroupSavingData;
private: System::Windows::Forms::ComboBox^  comboBox1;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  Ustawienia_LabelSave;
private: System::Windows::Forms::Label^  Ustawienia_SaveFormat;
private: System::Windows::Forms::TabPage^  pageSensors;
private: System::Windows::Forms::Panel^  Czujniki_PanelAkwarium;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioAkwariumOFF;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioAkwariumON;
private: System::Windows::Forms::Label^  Czujnik_labelLampaAkwarium;
private: System::Windows::Forms::Panel^  Czujniki_PanelRolety;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioRoletyON;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioRoletyOFF;
private: System::Windows::Forms::Label^  Czujnik_labelRolety;
private: System::Windows::Forms::Panel^  Czujniki_PanelKontakt;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioKontaktON;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioKontaktOFF;
private: System::Windows::Forms::Label^  Czujnik_labelKontakt;
private: System::Windows::Forms::Panel^  Czujniki_PanelLampa;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioLampaON;
private: System::Windows::Forms::RadioButton^  Czujniki_RadioLampaOFF;
private: System::Windows::Forms::Label^  Czujnik_labelLampa;
private: System::Windows::Forms::TabPage^  tabHumidity;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  HumidityChart;
private: System::Windows::Forms::TabPage^  tabTemperature;






private: System::Windows::Forms::DataVisualization::Charting::Chart^  TemperatureChart;
private: System::Windows::Forms::TabControl^  tabData;
private: System::Windows::Forms::GroupBox^  menuBox;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TabPage^  tabWeather;
private: System::Windows::Forms::GroupBox^  Ustawienia_LogBox;
private: System::Windows::Forms::TextBox^  ustawienia_LogTextBox;

private: System::Windows::Forms::GroupBox^  pogoda_currentWeather;
private: System::Windows::Forms::PictureBox^  pogoda_picture;

private: System::Windows::Forms::Label^  pogoda_generalLabel;
private: System::Windows::Forms::Label^  pogoda_humVal;

private: System::Windows::Forms::Label^  pogoda_pressureVal;
public: System::Windows::Forms::Label^  pogoda_tempVal;
private:


private: System::Windows::Forms::Label^  pogoda_tempMaxVal;


private: System::Windows::Forms::Label^  pogoda_tempMinVal;
private: System::Windows::Forms::Label^  pogoda_tempMaxLabel;


private: System::Windows::Forms::Label^  pogoda_tempMinLabel;

private: System::Windows::Forms::Label^  pogoda_humLabel;

private: System::Windows::Forms::Label^  pogoda_pressureLabel;


private: System::Windows::Forms::Label^  pogoda_temp;


private: System::Windows::Forms::Label^  pogoda_windSpeedVal;
private: System::Windows::Forms::Label^  pogoda_windSpeedLabel;
private: System::Windows::Forms::ProgressBar^  progressBar1;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;
private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
private: System::Windows::Forms::Label^  czujniki_statusVal;

private: System::Windows::Forms::Label^  czujniki_statusLabel;
private: System::Windows::Forms::Timer^  timer2;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Timer^  timer3;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;















































	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Ustawienia_DialogSaveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->Ustawienia_DialogOpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pageSettings = (gcnew System::Windows::Forms::TabPage());
			this->Ustawienia_LogBox = (gcnew System::Windows::Forms::GroupBox());
			this->ustawienia_LogTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Ustawienia_GroupInternetConnection = (gcnew System::Windows::Forms::GroupBox());
			this->Ustawienia_labelStatus = (gcnew System::Windows::Forms::Label());
			this->Ustawienia_LabelStatusWeb = (gcnew System::Windows::Forms::Label());
			this->Ustawienia_buttonInternetConnection = (gcnew System::Windows::Forms::Button());
			this->Ustawienia_GroupSavingData = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Ustawienia_LabelSave = (gcnew System::Windows::Forms::Label());
			this->Ustawienia_SaveFormat = (gcnew System::Windows::Forms::Label());
			this->pageSensors = (gcnew System::Windows::Forms::TabPage());
			this->czujniki_statusVal = (gcnew System::Windows::Forms::Label());
			this->czujniki_statusLabel = (gcnew System::Windows::Forms::Label());
			this->Czujniki_PanelAkwarium = (gcnew System::Windows::Forms::Panel());
			this->Czujniki_RadioAkwariumOFF = (gcnew System::Windows::Forms::RadioButton());
			this->Czujniki_RadioAkwariumON = (gcnew System::Windows::Forms::RadioButton());
			this->Czujnik_labelLampaAkwarium = (gcnew System::Windows::Forms::Label());
			this->Czujniki_PanelRolety = (gcnew System::Windows::Forms::Panel());
			this->Czujniki_RadioRoletyON = (gcnew System::Windows::Forms::RadioButton());
			this->Czujniki_RadioRoletyOFF = (gcnew System::Windows::Forms::RadioButton());
			this->Czujnik_labelRolety = (gcnew System::Windows::Forms::Label());
			this->Czujniki_PanelKontakt = (gcnew System::Windows::Forms::Panel());
			this->Czujniki_RadioKontaktON = (gcnew System::Windows::Forms::RadioButton());
			this->Czujniki_RadioKontaktOFF = (gcnew System::Windows::Forms::RadioButton());
			this->Czujnik_labelKontakt = (gcnew System::Windows::Forms::Label());
			this->Czujniki_PanelLampa = (gcnew System::Windows::Forms::Panel());
			this->Czujniki_RadioLampaON = (gcnew System::Windows::Forms::RadioButton());
			this->Czujniki_RadioLampaOFF = (gcnew System::Windows::Forms::RadioButton());
			this->Czujnik_labelLampa = (gcnew System::Windows::Forms::Label());
			this->tabHumidity = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->HumidityChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabTemperature = (gcnew System::Windows::Forms::TabPage());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->menuBox = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TemperatureChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabData = (gcnew System::Windows::Forms::TabControl());
			this->tabWeather = (gcnew System::Windows::Forms::TabPage());
			this->pogoda_currentWeather = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pogoda_windSpeedVal = (gcnew System::Windows::Forms::Label());
			this->pogoda_windSpeedLabel = (gcnew System::Windows::Forms::Label());
			this->pogoda_humVal = (gcnew System::Windows::Forms::Label());
			this->pogoda_pressureVal = (gcnew System::Windows::Forms::Label());
			this->pogoda_tempVal = (gcnew System::Windows::Forms::Label());
			this->pogoda_tempMaxVal = (gcnew System::Windows::Forms::Label());
			this->pogoda_tempMinVal = (gcnew System::Windows::Forms::Label());
			this->pogoda_tempMaxLabel = (gcnew System::Windows::Forms::Label());
			this->pogoda_tempMinLabel = (gcnew System::Windows::Forms::Label());
			this->pogoda_humLabel = (gcnew System::Windows::Forms::Label());
			this->pogoda_pressureLabel = (gcnew System::Windows::Forms::Label());
			this->pogoda_temp = (gcnew System::Windows::Forms::Label());
			this->pogoda_generalLabel = (gcnew System::Windows::Forms::Label());
			this->pogoda_picture = (gcnew System::Windows::Forms::PictureBox());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pageSettings->SuspendLayout();
			this->Ustawienia_LogBox->SuspendLayout();
			this->Ustawienia_GroupInternetConnection->SuspendLayout();
			this->Ustawienia_GroupSavingData->SuspendLayout();
			this->pageSensors->SuspendLayout();
			this->Czujniki_PanelAkwarium->SuspendLayout();
			this->Czujniki_PanelRolety->SuspendLayout();
			this->Czujniki_PanelKontakt->SuspendLayout();
			this->Czujniki_PanelLampa->SuspendLayout();
			this->tabHumidity->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HumidityChart))->BeginInit();
			this->tabTemperature->SuspendLayout();
			this->menuBox->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TemperatureChart))->BeginInit();
			this->tabData->SuspendLayout();
			this->tabWeather->SuspendLayout();
			this->pogoda_currentWeather->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pogoda_picture))->BeginInit();
			this->SuspendLayout();
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::notifyIcon1_MouseDoubleClick);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainWindow::timer1_Tick);
			// 
			// Ustawienia_DialogOpenFile
			// 
			this->Ustawienia_DialogOpenFile->FileName = L"openFileDialog1";
			// 
			// pageSettings
			// 
			this->pageSettings->Controls->Add(this->Ustawienia_LogBox);
			this->pageSettings->Controls->Add(this->Ustawienia_GroupInternetConnection);
			this->pageSettings->Controls->Add(this->Ustawienia_GroupSavingData);
			this->pageSettings->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pageSettings->Location = System::Drawing::Point(4, 56);
			this->pageSettings->Name = L"pageSettings";
			this->pageSettings->Padding = System::Windows::Forms::Padding(3);
			this->pageSettings->Size = System::Drawing::Size(992, 440);
			this->pageSettings->TabIndex = 3;
			this->pageSettings->Text = L"Ustawienia";
			this->pageSettings->UseVisualStyleBackColor = true;
			this->pageSettings->Click += gcnew System::EventHandler(this, &MainWindow::tabPage4_Click);
			// 
			// Ustawienia_LogBox
			// 
			this->Ustawienia_LogBox->Controls->Add(this->ustawienia_LogTextBox);
			this->Ustawienia_LogBox->Location = System::Drawing::Point(308, 281);
			this->Ustawienia_LogBox->Name = L"Ustawienia_LogBox";
			this->Ustawienia_LogBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Ustawienia_LogBox->Size = System::Drawing::Size(341, 126);
			this->Ustawienia_LogBox->TabIndex = 2;
			this->Ustawienia_LogBox->TabStop = false;
			this->Ustawienia_LogBox->Text = L"Log";
			// 
			// ustawienia_LogTextBox
			// 
			this->ustawienia_LogTextBox->Cursor = System::Windows::Forms::Cursors::No;
			this->ustawienia_LogTextBox->Location = System::Drawing::Point(23, 32);
			this->ustawienia_LogTextBox->Multiline = true;
			this->ustawienia_LogTextBox->Name = L"ustawienia_LogTextBox";
			this->ustawienia_LogTextBox->ReadOnly = true;
			this->ustawienia_LogTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ustawienia_LogTextBox->Size = System::Drawing::Size(302, 76);
			this->ustawienia_LogTextBox->TabIndex = 0;
			// 
			// Ustawienia_GroupInternetConnection
			// 
			this->Ustawienia_GroupInternetConnection->Controls->Add(this->Ustawienia_labelStatus);
			this->Ustawienia_GroupInternetConnection->Controls->Add(this->Ustawienia_LabelStatusWeb);
			this->Ustawienia_GroupInternetConnection->Controls->Add(this->Ustawienia_buttonInternetConnection);
			this->Ustawienia_GroupInternetConnection->Location = System::Drawing::Point(308, 164);
			this->Ustawienia_GroupInternetConnection->Name = L"Ustawienia_GroupInternetConnection";
			this->Ustawienia_GroupInternetConnection->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Ustawienia_GroupInternetConnection->Size = System::Drawing::Size(341, 111);
			this->Ustawienia_GroupInternetConnection->TabIndex = 1;
			this->Ustawienia_GroupInternetConnection->TabStop = false;
			this->Ustawienia_GroupInternetConnection->Text = L"Po��czenie internetowe";
			// 
			// Ustawienia_labelStatus
			// 
			this->Ustawienia_labelStatus->Font = (gcnew System::Drawing::Font(L"Apolonia", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ustawienia_labelStatus->Location = System::Drawing::Point(111, 71);
			this->Ustawienia_labelStatus->Name = L"Ustawienia_labelStatus";
			this->Ustawienia_labelStatus->Size = System::Drawing::Size(190, 37);
			this->Ustawienia_labelStatus->TabIndex = 2;
			this->Ustawienia_labelStatus->Text = L"...";
			// 
			// Ustawienia_LabelStatusWeb
			// 
			this->Ustawienia_LabelStatusWeb->AutoSize = true;
			this->Ustawienia_LabelStatusWeb->Location = System::Drawing::Point(33, 71);
			this->Ustawienia_LabelStatusWeb->Name = L"Ustawienia_LabelStatusWeb";
			this->Ustawienia_LabelStatusWeb->Size = System::Drawing::Size(45, 16);
			this->Ustawienia_LabelStatusWeb->TabIndex = 1;
			this->Ustawienia_LabelStatusWeb->Text = L"Status";
			// 
			// Ustawienia_buttonInternetConnection
			// 
			this->Ustawienia_buttonInternetConnection->Location = System::Drawing::Point(36, 33);
			this->Ustawienia_buttonInternetConnection->Name = L"Ustawienia_buttonInternetConnection";
			this->Ustawienia_buttonInternetConnection->Size = System::Drawing::Size(260, 23);
			this->Ustawienia_buttonInternetConnection->TabIndex = 0;
			this->Ustawienia_buttonInternetConnection->Text = L"Sprawd� po��czenie internetowe";
			this->Ustawienia_buttonInternetConnection->UseVisualStyleBackColor = true;
			this->Ustawienia_buttonInternetConnection->Click += gcnew System::EventHandler(this, &MainWindow::Ustawienia_buttonInternetConnection_Click);
			// 
			// Ustawienia_GroupSavingData
			// 
			this->Ustawienia_GroupSavingData->Controls->Add(this->button2);
			this->Ustawienia_GroupSavingData->Controls->Add(this->comboBox1);
			this->Ustawienia_GroupSavingData->Controls->Add(this->button1);
			this->Ustawienia_GroupSavingData->Controls->Add(this->Ustawienia_LabelSave);
			this->Ustawienia_GroupSavingData->Controls->Add(this->Ustawienia_SaveFormat);
			this->Ustawienia_GroupSavingData->Location = System::Drawing::Point(308, 32);
			this->Ustawienia_GroupSavingData->Name = L"Ustawienia_GroupSavingData";
			this->Ustawienia_GroupSavingData->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Ustawienia_GroupSavingData->Size = System::Drawing::Size(341, 126);
			this->Ustawienia_GroupSavingData->TabIndex = 0;
			this->Ustawienia_GroupSavingData->TabStop = false;
			this->Ustawienia_GroupSavingData->Text = L"Zapis";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(126, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Zapisz!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click_1);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L".csv", L".txt" });
			this->comboBox1->Location = System::Drawing::Point(180, 31);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(180, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"wybierz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click_1);
			// 
			// Ustawienia_LabelSave
			// 
			this->Ustawienia_LabelSave->AutoSize = true;
			this->Ustawienia_LabelSave->Location = System::Drawing::Point(39, 68);
			this->Ustawienia_LabelSave->Name = L"Ustawienia_LabelSave";
			this->Ustawienia_LabelSave->Size = System::Drawing::Size(106, 16);
			this->Ustawienia_LabelSave->TabIndex = 1;
			this->Ustawienia_LabelSave->Text = L"Folder do zapisu";
			// 
			// Ustawienia_SaveFormat
			// 
			this->Ustawienia_SaveFormat->AutoSize = true;
			this->Ustawienia_SaveFormat->Location = System::Drawing::Point(39, 37);
			this->Ustawienia_SaveFormat->Name = L"Ustawienia_SaveFormat";
			this->Ustawienia_SaveFormat->Size = System::Drawing::Size(92, 16);
			this->Ustawienia_SaveFormat->TabIndex = 0;
			this->Ustawienia_SaveFormat->Text = L"Format zapisu";
			// 
			// pageSensors
			// 
			this->pageSensors->Controls->Add(this->czujniki_statusVal);
			this->pageSensors->Controls->Add(this->czujniki_statusLabel);
			this->pageSensors->Controls->Add(this->Czujniki_PanelAkwarium);
			this->pageSensors->Controls->Add(this->Czujniki_PanelRolety);
			this->pageSensors->Controls->Add(this->Czujniki_PanelKontakt);
			this->pageSensors->Controls->Add(this->Czujniki_PanelLampa);
			this->pageSensors->Location = System::Drawing::Point(4, 56);
			this->pageSensors->Name = L"pageSensors";
			this->pageSensors->Padding = System::Windows::Forms::Padding(3);
			this->pageSensors->Size = System::Drawing::Size(992, 440);
			this->pageSensors->TabIndex = 2;
			this->pageSensors->Text = L"Czujniki";
			this->pageSensors->UseVisualStyleBackColor = true;
			this->pageSensors->Click += gcnew System::EventHandler(this, &MainWindow::pageSensors_Click);
			// 
			// czujniki_statusVal
			// 
			this->czujniki_statusVal->AutoSize = true;
			this->czujniki_statusVal->Location = System::Drawing::Point(464, 284);
			this->czujniki_statusVal->Name = L"czujniki_statusVal";
			this->czujniki_statusVal->Size = System::Drawing::Size(27, 16);
			this->czujniki_statusVal->TabIndex = 17;
			this->czujniki_statusVal->Text = L"OK";
			this->czujniki_statusVal->Visible = false;
			// 
			// czujniki_statusLabel
			// 
			this->czujniki_statusLabel->AutoSize = true;
			this->czujniki_statusLabel->Location = System::Drawing::Point(394, 284);
			this->czujniki_statusLabel->Name = L"czujniki_statusLabel";
			this->czujniki_statusLabel->Size = System::Drawing::Size(53, 16);
			this->czujniki_statusLabel->TabIndex = 16;
			this->czujniki_statusLabel->Text = L"ERROR";
			this->czujniki_statusLabel->Visible = false;
			// 
			// Czujniki_PanelAkwarium
			// 
			this->Czujniki_PanelAkwarium->Controls->Add(this->Czujniki_RadioAkwariumOFF);
			this->Czujniki_PanelAkwarium->Controls->Add(this->Czujniki_RadioAkwariumON);
			this->Czujniki_PanelAkwarium->Controls->Add(this->Czujnik_labelLampaAkwarium);
			this->Czujniki_PanelAkwarium->Location = System::Drawing::Point(265, 224);
			this->Czujniki_PanelAkwarium->Name = L"Czujniki_PanelAkwarium";
			this->Czujniki_PanelAkwarium->Size = System::Drawing::Size(338, 40);
			this->Czujniki_PanelAkwarium->TabIndex = 15;
			// 
			// Czujniki_RadioAkwariumOFF
			// 
			this->Czujniki_RadioAkwariumOFF->AutoSize = true;
			this->Czujniki_RadioAkwariumOFF->Location = System::Drawing::Point(281, 12);
			this->Czujniki_RadioAkwariumOFF->Name = L"Czujniki_RadioAkwariumOFF";
			this->Czujniki_RadioAkwariumOFF->Size = System::Drawing::Size(50, 20);
			this->Czujniki_RadioAkwariumOFF->TabIndex = 11;
			this->Czujniki_RadioAkwariumOFF->Text = L"OFF";
			this->Czujniki_RadioAkwariumOFF->UseVisualStyleBackColor = true;
			this->Czujniki_RadioAkwariumOFF->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioAkwariumOFF_CheckedChanged);
			// 
			// Czujniki_RadioAkwariumON
			// 
			this->Czujniki_RadioAkwariumON->AutoSize = true;
			this->Czujniki_RadioAkwariumON->Checked = true;
			this->Czujniki_RadioAkwariumON->Location = System::Drawing::Point(148, 12);
			this->Czujniki_RadioAkwariumON->Name = L"Czujniki_RadioAkwariumON";
			this->Czujniki_RadioAkwariumON->Size = System::Drawing::Size(46, 20);
			this->Czujniki_RadioAkwariumON->TabIndex = 10;
			this->Czujniki_RadioAkwariumON->TabStop = true;
			this->Czujniki_RadioAkwariumON->Text = L"ON";
			this->Czujniki_RadioAkwariumON->UseVisualStyleBackColor = true;
			this->Czujniki_RadioAkwariumON->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioAkwariumON_CheckedChanged);
			// 
			// Czujnik_labelLampaAkwarium
			// 
			this->Czujnik_labelLampaAkwarium->AutoSize = true;
			this->Czujnik_labelLampaAkwarium->Location = System::Drawing::Point(13, 14);
			this->Czujnik_labelLampaAkwarium->Name = L"Czujnik_labelLampaAkwarium";
			this->Czujnik_labelLampaAkwarium->Size = System::Drawing::Size(114, 16);
			this->Czujnik_labelLampaAkwarium->TabIndex = 3;
			this->Czujnik_labelLampaAkwarium->Text = L"Lampa akwarium";
			// 
			// Czujniki_PanelRolety
			// 
			this->Czujniki_PanelRolety->Controls->Add(this->Czujniki_RadioRoletyON);
			this->Czujniki_PanelRolety->Controls->Add(this->Czujniki_RadioRoletyOFF);
			this->Czujniki_PanelRolety->Controls->Add(this->Czujnik_labelRolety);
			this->Czujniki_PanelRolety->Location = System::Drawing::Point(265, 117);
			this->Czujniki_PanelRolety->Name = L"Czujniki_PanelRolety";
			this->Czujniki_PanelRolety->Size = System::Drawing::Size(338, 40);
			this->Czujniki_PanelRolety->TabIndex = 14;
			// 
			// Czujniki_RadioRoletyON
			// 
			this->Czujniki_RadioRoletyON->AutoSize = true;
			this->Czujniki_RadioRoletyON->Checked = true;
			this->Czujniki_RadioRoletyON->Location = System::Drawing::Point(148, 11);
			this->Czujniki_RadioRoletyON->Name = L"Czujniki_RadioRoletyON";
			this->Czujniki_RadioRoletyON->Size = System::Drawing::Size(46, 20);
			this->Czujniki_RadioRoletyON->TabIndex = 6;
			this->Czujniki_RadioRoletyON->TabStop = true;
			this->Czujniki_RadioRoletyON->Text = L"ON";
			this->Czujniki_RadioRoletyON->UseVisualStyleBackColor = true;
			this->Czujniki_RadioRoletyON->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioRoletyON_CheckedChanged);
			// 
			// Czujniki_RadioRoletyOFF
			// 
			this->Czujniki_RadioRoletyOFF->AutoSize = true;
			this->Czujniki_RadioRoletyOFF->Location = System::Drawing::Point(281, 11);
			this->Czujniki_RadioRoletyOFF->Name = L"Czujniki_RadioRoletyOFF";
			this->Czujniki_RadioRoletyOFF->Size = System::Drawing::Size(50, 20);
			this->Czujniki_RadioRoletyOFF->TabIndex = 7;
			this->Czujniki_RadioRoletyOFF->Text = L"OFF";
			this->Czujniki_RadioRoletyOFF->UseVisualStyleBackColor = true;
			this->Czujniki_RadioRoletyOFF->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioRoletyOFF_CheckedChanged);
			// 
			// Czujnik_labelRolety
			// 
			this->Czujnik_labelRolety->AutoSize = true;
			this->Czujnik_labelRolety->Location = System::Drawing::Point(13, 15);
			this->Czujnik_labelRolety->Name = L"Czujnik_labelRolety";
			this->Czujnik_labelRolety->Size = System::Drawing::Size(108, 16);
			this->Czujnik_labelRolety->TabIndex = 1;
			this->Czujnik_labelRolety->Text = L"Otwieranie rolet";
			this->Czujnik_labelRolety->Click += gcnew System::EventHandler(this, &MainWindow::Czujnik_labelRolety_Click);
			// 
			// Czujniki_PanelKontakt
			// 
			this->Czujniki_PanelKontakt->BackColor = System::Drawing::Color::LightBlue;
			this->Czujniki_PanelKontakt->Controls->Add(this->Czujniki_RadioKontaktON);
			this->Czujniki_PanelKontakt->Controls->Add(this->Czujniki_RadioKontaktOFF);
			this->Czujniki_PanelKontakt->Controls->Add(this->Czujnik_labelKontakt);
			this->Czujniki_PanelKontakt->Location = System::Drawing::Point(265, 172);
			this->Czujniki_PanelKontakt->Name = L"Czujniki_PanelKontakt";
			this->Czujniki_PanelKontakt->Size = System::Drawing::Size(338, 40);
			this->Czujniki_PanelKontakt->TabIndex = 13;
			// 
			// Czujniki_RadioKontaktON
			// 
			this->Czujniki_RadioKontaktON->AutoSize = true;
			this->Czujniki_RadioKontaktON->Checked = true;
			this->Czujniki_RadioKontaktON->Location = System::Drawing::Point(148, 12);
			this->Czujniki_RadioKontaktON->Name = L"Czujniki_RadioKontaktON";
			this->Czujniki_RadioKontaktON->Size = System::Drawing::Size(46, 20);
			this->Czujniki_RadioKontaktON->TabIndex = 8;
			this->Czujniki_RadioKontaktON->TabStop = true;
			this->Czujniki_RadioKontaktON->Text = L"ON";
			this->Czujniki_RadioKontaktON->UseVisualStyleBackColor = true;
			this->Czujniki_RadioKontaktON->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioKontaktON_CheckedChanged);
			// 
			// Czujniki_RadioKontaktOFF
			// 
			this->Czujniki_RadioKontaktOFF->AutoSize = true;
			this->Czujniki_RadioKontaktOFF->Location = System::Drawing::Point(281, 12);
			this->Czujniki_RadioKontaktOFF->Name = L"Czujniki_RadioKontaktOFF";
			this->Czujniki_RadioKontaktOFF->Size = System::Drawing::Size(50, 20);
			this->Czujniki_RadioKontaktOFF->TabIndex = 9;
			this->Czujniki_RadioKontaktOFF->Text = L"OFF";
			this->Czujniki_RadioKontaktOFF->UseVisualStyleBackColor = true;
			this->Czujniki_RadioKontaktOFF->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioKontaktOFF_CheckedChanged);
			// 
			// Czujnik_labelKontakt
			// 
			this->Czujnik_labelKontakt->AutoSize = true;
			this->Czujnik_labelKontakt->Location = System::Drawing::Point(13, 14);
			this->Czujnik_labelKontakt->Name = L"Czujnik_labelKontakt";
			this->Czujnik_labelKontakt->Size = System::Drawing::Size(56, 16);
			this->Czujnik_labelKontakt->TabIndex = 2;
			this->Czujnik_labelKontakt->Text = L"Kontakt";
			// 
			// Czujniki_PanelLampa
			// 
			this->Czujniki_PanelLampa->BackColor = System::Drawing::Color::LightBlue;
			this->Czujniki_PanelLampa->Controls->Add(this->Czujniki_RadioLampaON);
			this->Czujniki_PanelLampa->Controls->Add(this->Czujniki_RadioLampaOFF);
			this->Czujniki_PanelLampa->Controls->Add(this->Czujnik_labelLampa);
			this->Czujniki_PanelLampa->Location = System::Drawing::Point(265, 62);
			this->Czujniki_PanelLampa->Name = L"Czujniki_PanelLampa";
			this->Czujniki_PanelLampa->Size = System::Drawing::Size(338, 40);
			this->Czujniki_PanelLampa->TabIndex = 12;
			// 
			// Czujniki_RadioLampaON
			// 
			this->Czujniki_RadioLampaON->AutoSize = true;
			this->Czujniki_RadioLampaON->Checked = true;
			this->Czujniki_RadioLampaON->Location = System::Drawing::Point(148, 11);
			this->Czujniki_RadioLampaON->Name = L"Czujniki_RadioLampaON";
			this->Czujniki_RadioLampaON->Size = System::Drawing::Size(46, 20);
			this->Czujniki_RadioLampaON->TabIndex = 4;
			this->Czujniki_RadioLampaON->TabStop = true;
			this->Czujniki_RadioLampaON->Text = L"ON";
			this->Czujniki_RadioLampaON->UseVisualStyleBackColor = true;
			this->Czujniki_RadioLampaON->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioLampaON_CheckedChanged);
			// 
			// Czujniki_RadioLampaOFF
			// 
			this->Czujniki_RadioLampaOFF->AutoSize = true;
			this->Czujniki_RadioLampaOFF->Location = System::Drawing::Point(281, 11);
			this->Czujniki_RadioLampaOFF->Name = L"Czujniki_RadioLampaOFF";
			this->Czujniki_RadioLampaOFF->Size = System::Drawing::Size(50, 20);
			this->Czujniki_RadioLampaOFF->TabIndex = 5;
			this->Czujniki_RadioLampaOFF->Text = L"OFF";
			this->Czujniki_RadioLampaOFF->UseVisualStyleBackColor = true;
			this->Czujniki_RadioLampaOFF->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::Czujniki_RadioLampaOFF_CheckedChanged);
			// 
			// Czujnik_labelLampa
			// 
			this->Czujnik_labelLampa->AutoSize = true;
			this->Czujnik_labelLampa->Location = System::Drawing::Point(13, 13);
			this->Czujnik_labelLampa->Name = L"Czujnik_labelLampa";
			this->Czujnik_labelLampa->Size = System::Drawing::Size(86, 16);
			this->Czujnik_labelLampa->TabIndex = 0;
			this->Czujnik_labelLampa->Text = L"Lampa pok�j";
			// 
			// tabHumidity
			// 
			this->tabHumidity->BackColor = System::Drawing::Color::LightGray;
			this->tabHumidity->Controls->Add(this->label12);
			this->tabHumidity->Controls->Add(this->label11);
			this->tabHumidity->Controls->Add(this->HumidityChart);
			this->tabHumidity->Location = System::Drawing::Point(4, 56);
			this->tabHumidity->Name = L"tabHumidity";
			this->tabHumidity->Padding = System::Windows::Forms::Padding(3);
			this->tabHumidity->Size = System::Drawing::Size(992, 440);
			this->tabHumidity->TabIndex = 1;
			this->tabHumidity->Text = L"Wilgotno��";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(774, 341);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(50, 16);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Czas [s]";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(48, 44);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(96, 16);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Wilgotno�� [%]";
			// 
			// HumidityChart
			// 
			this->HumidityChart->BackColor = System::Drawing::Color::Gainsboro;
			chartArea1->Name = L"ChartArea1";
			this->HumidityChart->ChartAreas->Add(chartArea1);
			this->HumidityChart->Location = System::Drawing::Point(33, 17);
			this->HumidityChart->Margin = System::Windows::Forms::Padding(4);
			this->HumidityChart->Name = L"HumidityChart";
			series1->BorderColor = System::Drawing::Color::Gray;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->IsValueShownAsLabel = true;
			series1->MarkerColor = System::Drawing::Color::Gray;
			series1->Name = L"humidity";
			this->HumidityChart->Series->Add(series1);
			this->HumidityChart->Size = System::Drawing::Size(825, 340);
			this->HumidityChart->TabIndex = 0;
			this->HumidityChart->Text = L"HumidityChart";
			title1->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			title1->Name = L"Title1";
			title1->Text = L"Wilgotno�� w pokoju %";
			this->HumidityChart->Titles->Add(title1);
			this->HumidityChart->Click += gcnew System::EventHandler(this, &MainWindow::HumidityChart_Click);
			// 
			// tabTemperature
			// 
			this->tabTemperature->BackColor = System::Drawing::Color::LightGray;
			this->tabTemperature->Controls->Add(this->label10);
			this->tabTemperature->Controls->Add(this->label9);
			this->tabTemperature->Controls->Add(this->menuBox);
			this->tabTemperature->Controls->Add(this->TemperatureChart);
			this->tabTemperature->Location = System::Drawing::Point(4, 59);
			this->tabTemperature->Name = L"tabTemperature";
			this->tabTemperature->Padding = System::Windows::Forms::Padding(3);
			this->tabTemperature->Size = System::Drawing::Size(992, 437);
			this->tabTemperature->TabIndex = 0;
			this->tabTemperature->Text = L"Temperatura";
			this->tabTemperature->Click += gcnew System::EventHandler(this, &MainWindow::tabTemperature_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(65, 49);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(105, 16);
			this->label10->TabIndex = 7;
			this->label10->Text = L"Temperatura [C]";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(746, 350);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(54, 16);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Czas  [s]";
			// 
			// menuBox
			// 
			this->menuBox->BackColor = System::Drawing::Color::LightGray;
			this->menuBox->Controls->Add(this->groupBox1);
			this->menuBox->Location = System::Drawing::Point(344, 391);
			this->menuBox->Name = L"menuBox";
			this->menuBox->Size = System::Drawing::Size(243, 223);
			this->menuBox->TabIndex = 5;
			this->menuBox->TabStop = false;
			this->menuBox->Text = L"Dodatkowe opcje";
			this->menuBox->Click += gcnew System::EventHandler(this, &MainWindow::mainBox_Clicked);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(17, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(211, 148);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zakres dat";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(68, 110);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Ustaw";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(55, 33);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(147, 23);
			this->dateTimePicker1->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Do";
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(55, 72);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(147, 23);
			this->dateTimePicker3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Od";
			// 
			// TemperatureChart
			// 
			this->TemperatureChart->BackColor = System::Drawing::Color::Gainsboro;
			this->TemperatureChart->BorderlineColor = System::Drawing::Color::Gray;
			chartArea2->Name = L"ChartArea";
			this->TemperatureChart->ChartAreas->Add(chartArea2);
			this->TemperatureChart->Location = System::Drawing::Point(65, 26);
			this->TemperatureChart->Margin = System::Windows::Forms::Padding(4);
			this->TemperatureChart->Name = L"TemperatureChart";
			series2->ChartArea = L"ChartArea";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Name = L"temperatura";
			this->TemperatureChart->Series->Add(series2);
			this->TemperatureChart->Size = System::Drawing::Size(765, 340);
			this->TemperatureChart->TabIndex = 1;
			this->TemperatureChart->Text = L"chart1";
			title2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			title2->Name = L"Title1";
			title2->Text = L"Temperatura w pokoju �C";
			this->TemperatureChart->Titles->Add(title2);
			this->TemperatureChart->Click += gcnew System::EventHandler(this, &MainWindow::DataChart_Click_1);
			// 
			// tabData
			// 
			this->tabData->Controls->Add(this->tabTemperature);
			this->tabData->Controls->Add(this->tabHumidity);
			this->tabData->Controls->Add(this->pageSensors);
			this->tabData->Controls->Add(this->tabWeather);
			this->tabData->Controls->Add(this->pageSettings);
			this->tabData->Location = System::Drawing::Point(0, 0);
			this->tabData->Multiline = true;
			this->tabData->Name = L"tabData";
			this->tabData->Padding = System::Drawing::Point(20, 20);
			this->tabData->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->tabData->SelectedIndex = 0;
			this->tabData->Size = System::Drawing::Size(1000, 500);
			this->tabData->TabIndex = 6;
			// 
			// tabWeather
			// 
			this->tabWeather->Controls->Add(this->pogoda_currentWeather);
			this->tabWeather->Location = System::Drawing::Point(4, 59);
			this->tabWeather->Name = L"tabWeather";
			this->tabWeather->Padding = System::Windows::Forms::Padding(3);
			this->tabWeather->Size = System::Drawing::Size(992, 437);
			this->tabWeather->TabIndex = 4;
			this->tabWeather->Text = L"Pogoda";
			this->tabWeather->UseVisualStyleBackColor = true;
			// 
			// pogoda_currentWeather
			// 
			this->pogoda_currentWeather->Controls->Add(this->label8);
			this->pogoda_currentWeather->Controls->Add(this->label7);
			this->pogoda_currentWeather->Controls->Add(this->label6);
			this->pogoda_currentWeather->Controls->Add(this->label5);
			this->pogoda_currentWeather->Controls->Add(this->label2);
			this->pogoda_currentWeather->Controls->Add(this->label1);
			this->pogoda_currentWeather->Controls->Add(this->progressBar1);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_windSpeedVal);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_windSpeedLabel);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_humVal);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_pressureVal);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_tempVal);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_tempMaxVal);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_tempMinVal);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_tempMaxLabel);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_tempMinLabel);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_humLabel);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_pressureLabel);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_temp);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_generalLabel);
			this->pogoda_currentWeather->Controls->Add(this->pogoda_picture);
			this->pogoda_currentWeather->Location = System::Drawing::Point(221, 61);
			this->pogoda_currentWeather->Name = L"pogoda_currentWeather";
			this->pogoda_currentWeather->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->pogoda_currentWeather->Size = System::Drawing::Size(456, 293);
			this->pogoda_currentWeather->TabIndex = 0;
			this->pogoda_currentWeather->TabStop = false;
			this->pogoda_currentWeather->Text = L"Aktualne warunki pogodowe";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(192, 234);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"m/s";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(192, 192);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 16);
			this->label7->TabIndex = 19;
			this->label7->Text = L"%";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(192, 152);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 16);
			this->label6->TabIndex = 18;
			this->label6->Text = L"HPa";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(428, 152);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 16);
			this->label5->TabIndex = 17;
			this->label5->Text = L"�C";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(428, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 16);
			this->label2->TabIndex = 16;
			this->label2->Text = L"�C";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(192, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 16);
			this->label1->TabIndex = 15;
			this->label1->Text = L"�C";
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->progressBar1->Location = System::Drawing::Point(0, 283);
			this->progressBar1->Maximum = 3000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->progressBar1->Size = System::Drawing::Size(456, 10);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 14;
			this->progressBar1->Value = 3000;
			// 
			// pogoda_windSpeedVal
			// 
			this->pogoda_windSpeedVal->AutoSize = true;
			this->pogoda_windSpeedVal->Location = System::Drawing::Point(159, 234);
			this->pogoda_windSpeedVal->Name = L"pogoda_windSpeedVal";
			this->pogoda_windSpeedVal->Size = System::Drawing::Size(17, 16);
			this->pogoda_windSpeedVal->TabIndex = 13;
			this->pogoda_windSpeedVal->Text = L"...";
			// 
			// pogoda_windSpeedLabel
			// 
			this->pogoda_windSpeedLabel->Location = System::Drawing::Point(50, 225);
			this->pogoda_windSpeedLabel->Name = L"pogoda_windSpeedLabel";
			this->pogoda_windSpeedLabel->Size = System::Drawing::Size(63, 43);
			this->pogoda_windSpeedLabel->TabIndex = 12;
			this->pogoda_windSpeedLabel->Text = L"Pr�dko�� wiatru";
			// 
			// pogoda_humVal
			// 
			this->pogoda_humVal->AutoSize = true;
			this->pogoda_humVal->Location = System::Drawing::Point(159, 192);
			this->pogoda_humVal->Name = L"pogoda_humVal";
			this->pogoda_humVal->Size = System::Drawing::Size(17, 16);
			this->pogoda_humVal->TabIndex = 11;
			this->pogoda_humVal->Text = L"...";
			// 
			// pogoda_pressureVal
			// 
			this->pogoda_pressureVal->AutoSize = true;
			this->pogoda_pressureVal->Location = System::Drawing::Point(159, 152);
			this->pogoda_pressureVal->Name = L"pogoda_pressureVal";
			this->pogoda_pressureVal->Size = System::Drawing::Size(17, 16);
			this->pogoda_pressureVal->TabIndex = 10;
			this->pogoda_pressureVal->Text = L"...";
			// 
			// pogoda_tempVal
			// 
			this->pogoda_tempVal->AutoSize = true;
			this->pogoda_tempVal->Location = System::Drawing::Point(159, 119);
			this->pogoda_tempVal->Name = L"pogoda_tempVal";
			this->pogoda_tempVal->Size = System::Drawing::Size(17, 16);
			this->pogoda_tempVal->TabIndex = 9;
			this->pogoda_tempVal->Text = L"...";
			// 
			// pogoda_tempMaxVal
			// 
			this->pogoda_tempMaxVal->AutoSize = true;
			this->pogoda_tempMaxVal->Location = System::Drawing::Point(396, 152);
			this->pogoda_tempMaxVal->Name = L"pogoda_tempMaxVal";
			this->pogoda_tempMaxVal->Size = System::Drawing::Size(17, 16);
			this->pogoda_tempMaxVal->TabIndex = 8;
			this->pogoda_tempMaxVal->Text = L"...";
			// 
			// pogoda_tempMinVal
			// 
			this->pogoda_tempMinVal->AutoSize = true;
			this->pogoda_tempMinVal->Location = System::Drawing::Point(396, 119);
			this->pogoda_tempMinVal->Name = L"pogoda_tempMinVal";
			this->pogoda_tempMinVal->Size = System::Drawing::Size(17, 16);
			this->pogoda_tempMinVal->TabIndex = 7;
			this->pogoda_tempMinVal->Text = L"...";
			// 
			// pogoda_tempMaxLabel
			// 
			this->pogoda_tempMaxLabel->AutoSize = true;
			this->pogoda_tempMaxLabel->Location = System::Drawing::Point(256, 152);
			this->pogoda_tempMaxLabel->Name = L"pogoda_tempMaxLabel";
			this->pogoda_tempMaxLabel->Size = System::Drawing::Size(120, 16);
			this->pogoda_tempMaxLabel->TabIndex = 6;
			this->pogoda_tempMaxLabel->Text = L"Temperatura maks";
			// 
			// pogoda_tempMinLabel
			// 
			this->pogoda_tempMinLabel->AutoSize = true;
			this->pogoda_tempMinLabel->Location = System::Drawing::Point(256, 119);
			this->pogoda_tempMinLabel->Name = L"pogoda_tempMinLabel";
			this->pogoda_tempMinLabel->Size = System::Drawing::Size(113, 16);
			this->pogoda_tempMinLabel->TabIndex = 5;
			this->pogoda_tempMinLabel->Text = L"Temperatura min";
			// 
			// pogoda_humLabel
			// 
			this->pogoda_humLabel->Location = System::Drawing::Point(50, 183);
			this->pogoda_humLabel->Name = L"pogoda_humLabel";
			this->pogoda_humLabel->Size = System::Drawing::Size(76, 42);
			this->pogoda_humLabel->TabIndex = 4;
			this->pogoda_humLabel->Text = L"Wilgotno�� powietrza";
			// 
			// pogoda_pressureLabel
			// 
			this->pogoda_pressureLabel->AutoSize = true;
			this->pogoda_pressureLabel->Location = System::Drawing::Point(50, 152);
			this->pogoda_pressureLabel->Name = L"pogoda_pressureLabel";
			this->pogoda_pressureLabel->Size = System::Drawing::Size(63, 16);
			this->pogoda_pressureLabel->TabIndex = 3;
			this->pogoda_pressureLabel->Text = L"Ci�nienie";
			// 
			// pogoda_temp
			// 
			this->pogoda_temp->AutoSize = true;
			this->pogoda_temp->Location = System::Drawing::Point(50, 119);
			this->pogoda_temp->Name = L"pogoda_temp";
			this->pogoda_temp->Size = System::Drawing::Size(85, 16);
			this->pogoda_temp->TabIndex = 2;
			this->pogoda_temp->Text = L"Temperatura";
			// 
			// pogoda_generalLabel
			// 
			this->pogoda_generalLabel->AutoSize = true;
			this->pogoda_generalLabel->Font = (gcnew System::Drawing::Font(L"Apolonia", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pogoda_generalLabel->Location = System::Drawing::Point(94, 51);
			this->pogoda_generalLabel->Name = L"pogoda_generalLabel";
			this->pogoda_generalLabel->Size = System::Drawing::Size(164, 25);
			this->pogoda_generalLabel->TabIndex = 1;
			this->pogoda_generalLabel->Text = L"Og�lne warunki";
			// 
			// pogoda_picture
			// 
			this->pogoda_picture->ImageLocation = L"..\\images\\01d.png";
			this->pogoda_picture->Location = System::Drawing::Point(285, 32);
			this->pogoda_picture->Name = L"pogoda_picture";
			this->pogoda_picture->Size = System::Drawing::Size(64, 60);
			this->pogoda_picture->TabIndex = 0;
			this->pogoda_picture->TabStop = false;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MainWindow::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MainWindow::timer3_Tick);
			// 
			// MainWindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(901, 478);
			this->Controls->Add(this->tabData);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Apolonia", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home Dashboard";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->pageSettings->ResumeLayout(false);
			this->Ustawienia_LogBox->ResumeLayout(false);
			this->Ustawienia_LogBox->PerformLayout();
			this->Ustawienia_GroupInternetConnection->ResumeLayout(false);
			this->Ustawienia_GroupInternetConnection->PerformLayout();
			this->Ustawienia_GroupSavingData->ResumeLayout(false);
			this->Ustawienia_GroupSavingData->PerformLayout();
			this->pageSensors->ResumeLayout(false);
			this->pageSensors->PerformLayout();
			this->Czujniki_PanelAkwarium->ResumeLayout(false);
			this->Czujniki_PanelAkwarium->PerformLayout();
			this->Czujniki_PanelRolety->ResumeLayout(false);
			this->Czujniki_PanelRolety->PerformLayout();
			this->Czujniki_PanelKontakt->ResumeLayout(false);
			this->Czujniki_PanelKontakt->PerformLayout();
			this->Czujniki_PanelLampa->ResumeLayout(false);
			this->Czujniki_PanelLampa->PerformLayout();
			this->tabHumidity->ResumeLayout(false);
			this->tabHumidity->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HumidityChart))->EndInit();
			this->tabTemperature->ResumeLayout(false);
			this->tabTemperature->PerformLayout();
			this->menuBox->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TemperatureChart))->EndInit();
			this->tabData->ResumeLayout(false);
			this->tabWeather->ResumeLayout(false);
			this->pogoda_currentWeather->ResumeLayout(false);
			this->pogoda_currentWeather->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pogoda_picture))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//MyProperties
		private: bool stateVisible = true;
		//myMethods
		void HomeDashboard::MainWindow::wait(unsigned timeout)
		{
			timeout += clock();
			while (clock() < timeout) continue;
		}


		//my methods
		
			private: System::Void mainBox_Clicked(System::Object^  sender, System::EventArgs^  e)
			{
				if (stateVisible)
				{
					stateVisible = false;
					int endPoint = menuBox->Location.Y-300;
					int startPoint = HomeDashboard::MainWindow::menuBox->Location.Y;
					int X = menuBox->Location.X;
					for (int i = startPoint;i > endPoint;i -= 2)
					{
						Application::DoEvents();
						HomeDashboard::MainWindow::menuBox->Update();
						HomeDashboard::MainWindow::menuBox->Location = System::Drawing::Point(X, i);
						//menuBox->BackColor = Color::FromArgb(j, 211,211,211);
						wait(10);
					}
				}
				else
				{
					stateVisible = true;
					int endPoint = menuBox->Location.Y+300;
					int startPoint = HomeDashboard::MainWindow::menuBox->Location.Y;
					int X = menuBox->Location.X;
					
					for (int i = startPoint;i < endPoint;i += 2)
					{
						Application::DoEvents();
						HomeDashboard::MainWindow::menuBox->Update();
						HomeDashboard::MainWindow::menuBox->Location = System::Drawing::Point(X, i);
						//menuBox->BackColor = Color::FromArgb(j, 211, 211, 211);
						wait(10);
						
					}
				}
			}
		void HomeDashboard::MainWindow::moveGroupox()
		{
			Point endPointA = System::Drawing::Point(0, HomeDashboard::MainWindow::Height-200);

			Point startPointA = System::Drawing::Point(0, HomeDashboard::MainWindow::Height);
			int endPoint = HomeDashboard::MainWindow::menuBox->Height-200;
			int endPoint2 = HomeDashboard::MainWindow::Height;
			////Console::WriteLine(endPoint2);

			if (stateVisible)
			{
				
				for (int i = 41; i <= endPointA.Y + 41;i += 2)
				{
					Sleep(10);
					//wait(10);
					HomeDashboard::MainWindow::menuBox->Update();
					HomeDashboard::MainWindow::menuBox->Location = System::Drawing::Point(30, i);

					Application::DoEvents();
				}
				// HomeDashboard::MainWindow::button1->Visible = true;
				stateVisible = false;
			}
			else {
				stateVisible = true;

				for (int i = endPoint + 82;i >= 82;i--)

				{

					// System::Threading::Timeout();

					Application::DoEvents();
					wait(5);Update();
					HomeDashboard::MainWindow::menuBox->Update();
					HomeDashboard::MainWindow::menuBox->Location = System::Drawing::Point(30, i);
				}

				wait(2);
			}




		}







		//GeneratedMethods
private: System::Void DataChart_Click(System::Object^  sender, System::EventArgs^  e) {

	}

private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
	//Console::WriteLine("Wszed�e� na teren grupy!\r\n");
	moveGroupox();
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	stateVisible = false;
	moveGroupox();
}




private: System::Void groupBox1_OnMouseHover(System::Object ^sender, System::EventArgs ^e)

	{
		////Console::WriteLine("group hover!");


		//	 Thread^ newThread = gcnew Thread(gcnew ThreadStart(&MainWindow::moveGroupox()));
		// newThread->Start();
		//	moveGroupox();
		////Console::WriteLine("lecimy dalej!");
	}
	/*
	System::Void groupBox1_OnMouseHover(System::Object ^sender, System::EventArgs ^e)
	{
	////Console::WriteLine("group hover!");


	//	 Thread^ newThread = gcnew Thread(gcnew ThreadStart(&MainWindow::moveGroupox()));
	// newThread->Start();
	//HomeDashboard::MainWindow::moveGroupox();
	////Console::WriteLine("lecimy dalej!");
	}
	*/




private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	stateVisible = true;
	moveGroupox();

}



	private: System::Void DataChart_Click_1(System::Object^  sender, System::EventArgs^  e) {
		try {
			//Color nowy = Color::FromArgb(127,123,123,123);
			for (int i = 0, j=0;i < 1000,j<255;i++,j++)
			{
				TemperatureChart->Series["temperatura"]->Points->AddXY(i, rand() % 100);
				TemperatureChart->BackColor = Color::FromArgb(j,123,123,123);
				wait(30);
				Application::DoEvents();
			}
		}
		catch (NullReferenceException^)
		{
			errorReport("Error while obtaing data from the Web!");
		}
	}


		/* public: System::String fetchData(String url, String file, int data=1)
		 {


		 }

*/

private: System::Void tabPage4_Click(System::Object^  sender, System::EventArgs^  e) {
	////Console::WriteLine("Started obtaining data!");
	wait(200);

	/*
		web client instructions:
		->https://msdn.microsoft.com/pl-pl/library/system.net.webclient.webclient(v=vs.110).aspx
		->https://www.youtube.com/watch?v=HCeg5WgrIE4  - visual basic
		->http://stackoverflow.com/questions/20171165/getting-libcurl-to-work-with-visual-studio-2013
	*/
	try{
	WebClient^ tempClient = gcnew WebClient();


	String ^htmlCode = tempClient->DownloadString("http://kubat.beskjaba.com/PHP_temp/");
	////Console::WriteLine(htmlCode);
	} catch (WebException^ WebEx)
	{
		errorReport(WebEx);
	}
	/*
	System::Uri^ url = gcnew Uri("http://www.kubat.besaba.com");
	tempClient->DownloadStringAsync(url);
	////Console::WriteLine(url->ToString());
	*/
	}



		 public: System::Void fetchData() {
			 /*
			 try
{
   // Download the data to a buffer.
   WebClient^ client = gcnew WebClient;

   array<Byte>^ pageData = client->DownloadData( "http://www.contoso.com" );
   String^ pageHtml = Encoding::ASCII->GetString( pageData );
   ////Console::WriteLine( pageHtml );

   // Download the data to a file.
   client->DownloadFile( "http://www.contoso.com", "page.htm" );

   // Upload some form post values.
   NameValueCollection^ form = gcnew NameValueCollection;
   form->Add( "MyName", "MyValue" );
   array<Byte>^ responseData = client->UploadValues( "http://www.contoso.com/form.aspx", form );
}
catch ( WebException^ webEx ) 
{
   ////Console::WriteLine( webEx->ToString() );
   if ( webEx->Status == WebExceptionStatus::ConnectFailure )
   {
      ////Console::WriteLine( "Are you behind a firewall?  If so, go through the proxy server." );
   }
}
			 */
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	WeatherUpdate();
	progress();
	
}
private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {

}

private: System::Void InternetConnectionChecker()
		 {
			 try{	 WebClient^ internetChecker = gcnew WebClient();
			 System::String^ status = internetChecker->DownloadString("http://kubat.besaba.com/PHP_temp/checkConnection.php");
			 if (status->IndexOf("ok") > -1)
			 {
				 Ustawienia_labelStatus->BackColor = System::Drawing::Color::ForestGreen;
				 Ustawienia_labelStatus->ForeColor = System::Drawing::Color::WhiteSmoke;
				 Ustawienia_labelStatus->Text = "OK";
			 }
			 else
			 {
				 Ustawienia_labelStatus->BackColor = System::Drawing::Color::DarkRed;
				 Ustawienia_labelStatus->ForeColor = System::Drawing::Color::WhiteSmoke;
				 Ustawienia_labelStatus->Text = "ERROR";
			 }
			 
			 }
			 catch (WebException^ WebEx)
			 {
				 
				 ////Console::WriteLine(WebEx->ToString());
				 Ustawienia_labelStatus->BackColor = System::Drawing::Color::DarkRed;
				 Ustawienia_labelStatus->ForeColor = System::Drawing::Color::WhiteSmoke;
				 Ustawienia_labelStatus->Text = L"There was an error in obtaining the data!";
				 //Ustawienia_labelStatus->Text = "ERROR - " +  WebEx->ToString();
				// HomeDashboard::MainWindow::notifyIcon1->BalloonTipShown()
			 }
		

		 }



			  //System:Runtime::Serialization::Json;

private: bool HumidityChartInitialized = false;
private: bool TemperatureChartInitialized = false;
private: System::Void HumidityChart_Click(System::Object^  sender, System::EventArgs^  e) {
	if (HumidityChartInitialized) {
		HumidityChartInitialized = true;
		try {
			WebClient^ internetChecker = gcnew WebClient();
			System::String^ status = internetChecker->DownloadString("http://kubat.besaba.com/PHP_temp/checkConnection.php");
			if (status->IndexOf("ok") > -1)
			{
				Ustawienia_labelStatus->BackColor = System::Drawing::Color::ForestGreen;
				Ustawienia_labelStatus->ForeColor = System::Drawing::Color::WhiteSmoke;
			}
		}
		catch (WebException^ WebEx)
		{

			////Console::WriteLine(WebEx->ToString());
		}
	}



}
private: System::Void Czujnik_labelRolety_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabTemperature_Click(System::Object^ sender, System::EventArgs^ e)
		 {
			 ////Console::WriteLine("Tab temperatura has been clicked!");
		 }
private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Application::DoEvents();
}

private: System::Void tabWeather_Click(System::Object^  sender, System::EventArgs^  e) {
	InitializeWeather();
}
private: System::Void InitializeWeather()
{
	weatherInfo^ weatherPoint = gcnew weatherInfo;
	try {
		WebClient^ weatherUpdate = gcnew WebClient();
		System::String^ status = weatherUpdate->DownloadString("http://www.kubat.besaba.com/PHP_temp/weather.php");
		weatherPoint->parseData(status);
		
		if (status->IndexOf("ok") > -1)
		{

		}

	}
	catch (WebException^ WebEx)
	{
		////Console::WriteLine("There was an error in obtaining data!");
		////Console::WriteLine(WebEx->ToString());
		// HomeDashboard::MainWindow::notifyIcon1->BalloonTipShown()
	}
}

private: System::Void Ustawienia_buttonInternetConnection_Click(System::Object^  sender, System::EventArgs^  e) {
	InternetConnectionChecker();
}
		private: System::Void progress()
		{
			int step = PogodaProgressMaks+1;
			while (step--)
			{
				if (!progressBar1->Value) break;
				wait(10);
				progressBar1->Value -= 1;
				Application::DoEvents();
			}
		}
				 private:   int PogodaProgressMaks = 3000;
							private: weatherInfo ^currWeather = gcnew weatherInfo();
private: System::Void WeatherUpdate(){

	progressBar1->Value = PogodaProgressMaks;
	
		
		try {
			WebClient^ weather = gcnew WebClient();
			System::String^ status = weather->DownloadString("http://www.kubat.besaba.com/PHP_temp/weather.php");
			DateTime^ ErrTime = DateTime::Now;
			
			try {
				currWeather->parseData(status);
				
				HomeDashboard::MainWindow::pogoda_tempVal->Text = currWeather->temp;
				HomeDashboard::MainWindow::pogoda_tempMinVal->Text = currWeather->tempMIN;
				HomeDashboard::MainWindow::pogoda_tempMaxVal->Text = currWeather->tempMAX;
				HomeDashboard::MainWindow::pogoda_humVal->Text = currWeather->humidity;
				HomeDashboard::MainWindow::pogoda_windSpeedVal->Text = currWeather->windSpeed;
				HomeDashboard::MainWindow::pogoda_pressureVal->Text = currWeather->pressure;
				HomeDashboard::MainWindow::pogoda_picture->ImageLocation = "..\\images\\"+currWeather->icon;
				}
			catch (Exception ^e)
			{
				errorReport(e);
			}
			HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += ErrTime->Hour.ToString()+":"+ErrTime->Minute.ToString()+":Weather updated!\n\r" + Environment::NewLine;
		}
		catch (WebException^ WebEx)
		{
			errorReport(WebEx);
		}
}







		 ///
		 ///	Filesystem
		 ///
		/* private: System::Void SaveToFile(int mode)
		 {
			 System::String^ filename = DateTime::Now.ToString()+".txt";
			 std::string file = msclr::interop::marshal_as<std::string>(filename);
			 file = "C:\\Users\\user\\Desktop\\kuba\\Home Dashboard\\Debug\\plik.txt";
			 std::ofstream plikOut(file.c_str());
			 std::string formatPliku ="" ;
			 System::String^ format = Ustawienia_SaveFormat->Text;
			 if (format == ".csc")
				 formatPliku = ".csv";
			 else
				 formatPliku = ".txt";
			 plikOut << "cos.txt";
			 plikOut.close();
			 MessageBox::Show("Zapisano!"+filename,"Informacja", MessageBoxButtons::OK,
				 MessageBoxIcon::Information);
			 
		 }
		 */
		 private: bool filenameChanged = false;

				  System::String^ filename = ".txt";

private: bool filenameChoosen = false;
		 String^ filesystemChoosen = "";

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	//HomeDashboard::MainWindow::Ustawienia_DialogSaveFile->ShowDialog();
	//filenameChoosen = true;
	folderBrowserDialog1->ShowDialog();
	filenameChoosen = true;
	filesystemChoosen = folderBrowserDialog1->SelectedPath;

	MessageBox::Show("Zmieniono plik zapisu na: "+filesystemChoosen,
	"Zmieniono pliku zapisu", MessageBoxButtons::OK,
	MessageBoxIcon::Information);
}
		 //comboBox z wyborem formatu zapisu
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	filenameChanged = true;
}
private: System::Void saveToFile(String^ type)
{

					 System::String^ fullFilename = "";
					 if (filenameChanged)
					 {
						 if (Ustawienia_SaveFormat->Text == ".csv")
						 {
							 filename = ".csv";
						 }
					 }
					 else {
						 filename = type;
					 }
					 //name of a file
					 //DateTime^ time =  DateTime::Now;

					 filename = "\\HomeDash_" + DateTime::Now.ToString() + filename;

					 //jezlei nie wybralismy sciezki do pliku
					 if (filenameChoosen)
					 {
						 filename = filesystemChoosen + filename;
						 //Console::WriteLine(filename);
					 }
					 else
					 {
						 filename = "C:" + filename;
						 //Console::WriteLine("nie zmieniony");
						 //Console::WriteLine(filename);
					 }

					 //saving a file-> filesystemChoosen+filename
					 //check if a file exist
					 try
					 {
						 if (File::Exists(filename))
						 {
							 File::Delete(filename);

						 }
						 filename = "cos1.txt";
						 StreamWriter^ fileSave = nullptr;
						 try
						 {
							 fileSave = gcnew StreamWriter(filename);
						 }
						 catch (Exception ^ex)
						 {
							 errorReport(ex);
						 }
						 
						 FileStream ^ file = File::Create(filename);
						 String^ toFile = "";
						 dumpData(toFile);
						 fileSave->WriteLine(toFile);
						 fileSave->Close();
						 
						 MessageBox::Show("Zapisano plik : " + filename,
							 "Zapis pilku si� powi�d�!", MessageBoxButtons::OK,
							 MessageBoxIcon::Information);
					 }
					 catch(IOException ^IOEx)
					 {
						 errorReport(IOEx);
					 }


}
		 private: System::Void closeApp(int timeout)
		 {
			 Application::DoEvents();
			 wait(timeout*1000);
		 }

private: System::Void errorReport(System::String ^err)
{
	DateTime^ ErrTime = DateTime::Now;
	HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += ErrTime->ToString() + ":Problem systemowy!:" + Environment::NewLine;
	HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += err += Environment::NewLine;
}
		 private: System::Void errorReport(WebException^ WebEx)
		 {
			 DateTime^ ErrTime = DateTime::Now;
			 HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += ErrTime->ToString() + ":Problem ze �ci�gni�ciem danych :" + Environment::NewLine;
			 HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += WebEx->ToString() + Environment::NewLine;
			 MessageBox::Show("Brak po��czenia z internetem, aplikacja zostanie zamkni�ta w ci�gu 10 sekund!", "Brak po��czenia internetowego!", MessageBoxButtons::OK,
				 MessageBoxIcon::Information);
			 closeApp(10);
		 }
						 private: System::Void errorReport(IOException^ IOEx)
						 {
							 DateTime^ ErrTime = DateTime::Now;
							 HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += ErrTime->ToString() + ":Problem z wej�ciem/wyj�ciem:" + Environment::NewLine;
							 HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += IOEx->ToString() + Environment::NewLine;

						 }
										 private: System::Void errorReport(Exception^ Ex)
										 {
											 DateTime^ ErrTime = DateTime::Now;
											 HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += ErrTime->ToString() + ":Problem z systemowy:" + Environment::NewLine;
											 HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += Ex->ToString() + Environment::NewLine;
											 
										 }
private: System::Void dumpData(String^ toFile)
{
	System::String^pom = "";
	toFile += "Dane o aktualnej pogodzie:\n\r";
		currWeather->ToString(pom);
		toFile += pom+"\n\r";
		toFile += "Dane o czujnikach:\n\r";


}	


		 sensor^ sensorPom = gcnew sensor;
private: System::Void Czujniki_RadioLampaON_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "lampka";
	sensorPom->state = 1;
	SensorSetStatus();

}
private: System::Void Czujniki_RadioLampaOFF_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "lampka";
	sensorPom->state = 0;
	SensorSetStatus();
}


		 private: System::Void SensorSetStatus() 
		 {
			 try {
				 ////Console::WriteLine("zmieniam stan!");
				 Application::DoEvents();
				 WebClient^ setStatus = gcnew WebClient();
				 String^ state = "0";
				 if (sensorPom->state == 1) state = "1";
				 System::String ^ pom = "http://www.kubat.besaba.com/PHP_temp/saveStatus.php?q=HomeDashboard&sensor=" + sensorPom->name + "&state=" + state;
				 System::String^ status = setStatus->DownloadString(pom);
				 
				 ////Console::WriteLine(status);
				 
				 if (status->IndexOf("ok")>1)
				 {
					 
					 czujniki_statusVal->Visible = true;
					 for (int j = 0; j < 255; j += 5)
					 {
						 czujniki_statusLabel->BackColor = Color::FromArgb(j, 26, 148, 49);
						 czujniki_statusVal->BackColor = Color::FromArgb(j, 26, 148, 49);
						 wait(10);
						 Application::DoEvents();
					 }
					 for (int j = 255; j >=0; j -= 5)
					 {
						 czujniki_statusLabel->BackColor = Color::FromArgb(j, 26, 148, 49);
						 czujniki_statusVal->BackColor = Color::FromArgb(j, 26, 148, 49);
						 wait(10);
						 Application::DoEvents();
					 }
					 czujniki_statusVal->Visible = false;
				 }
				 else
				 {czujniki_statusLabel->Visible = true;
					 for (int j = 0; j < 255; j += 5)
					 {
						 czujniki_statusLabel->BackColor = Color::FromArgb(j, 255, 28, 28);
						 czujniki_statusVal->BackColor = Color::FromArgb(j, 255, 28, 28);
						 wait(10);
						 Application::DoEvents();
					 }
					 for (int j = 255; j >= 0; j -= 5)
					 {
						 czujniki_statusLabel->BackColor = Color::FromArgb(j, 255, 28, 28);
						 czujniki_statusVal->BackColor = Color::FromArgb(j, 255, 28, 28);
						 wait(10);
						 Application::DoEvents();
					 }
				 }czujniki_statusLabel->Visible = false;
				 
				 
			 }
			 catch (WebException^ WebEx)
			 {
				 errorReport(WebEx);
			 }
		 
		 }

				  private: System::Void handleSensors()
				  {
					  sensor^ a = gcnew sensor;
					  sensor^ b = gcnew sensor;
					  sensor^ c = gcnew sensor;
					  sensor^ d = gcnew sensor;
					  try {
						  WebClient^ weather = gcnew WebClient();
						  System::String^ status = weather->DownloadString("http://www.kubat.besaba.com/PHP_temp/sensorsState.php");
						  array<String^> ^states = status->Split(':');
						  int j = 0;
						  a->name = states[0];
						  a->state = int::Parse(states[1]); 
						  if (a->state == 1)
						  { Czujniki_RadioLampaON->Checked = true;
						  Czujniki_RadioLampaOFF->Checked = false;
						  }
							  
						  else
						  {
							  Czujniki_RadioLampaON->Checked = false;
							 Czujniki_RadioLampaOFF->Checked = true;
						  }

						  b->name = states[2];
						  b->state = int::Parse(states[3]);
						  if (b->state == 1)
						  {
							  Czujniki_RadioRoletyON->Checked = true;
							  Czujniki_RadioRoletyOFF->Checked = false;
						  }

						  else
						  {
							  Czujniki_RadioRoletyON->Checked = false;
							  Czujniki_RadioRoletyOFF->Checked = true;
						  }

						  c->name = states[4];
						  c->state = int::Parse(states[5]);
						  if (c->state == 1)
						  {
							  Czujniki_RadioKontaktON->Checked = true;
							  Czujniki_RadioKontaktOFF->Checked = false;
						  }

						  else
						  {
							  Czujniki_RadioKontaktON->Checked = false;
							  Czujniki_RadioKontaktOFF->Checked = true;
						  }

						  d->name = states[6];
						  d->state = int::Parse(states[7]);
						  if (d->state == 1)
						  {
							  Czujniki_RadioAkwariumON->Checked = true;
							  Czujniki_RadioAkwariumOFF->Checked = false;
						  }

						  else
						  {
							  Czujniki_RadioAkwariumON->Checked = false;
							  Czujniki_RadioAkwariumOFF->Checked = true;
						  }

						  

						  
						  try {
						  }
						  catch (Exception ^e)
						  {
							  errorReport(e);
						  }
						 // HomeDashboard::MainWindow::ustawienia_LogTextBox->Text += ErrTime->Hour.ToString() + ":" + ErrTime->Minute.ToString() + ":Weather updated!\n\r" + Environment::NewLine;
					  }
					  catch (WebException^ WebEx)
					  {
						  errorReport(WebEx);
					  }








				  }
						   
private: System::Void pageSensors_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Czujniki_RadioRoletyON_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "rolety";
	sensorPom->state = 1;
	SensorSetStatus();
}
private: System::Void Czujniki_RadioRoletyOFF_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "rolety";
	sensorPom->state = 0;
	SensorSetStatus();
}
private: System::Void Czujniki_RadioKontaktON_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "kontakt";
	sensorPom->state = 1;
	SensorSetStatus();
}
private: System::Void Czujniki_RadioKontaktOFF_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "kontakt";
	sensorPom->state = 0;
	SensorSetStatus();
}
private: System::Void Czujniki_RadioAkwariumON_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "akwarium";
	sensorPom->state = 1;
	SensorSetStatus();
}
private: System::Void Czujniki_RadioAkwariumOFF_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	sensorPom->name = "akwarium";
	sensorPom->state = 0;
	SensorSetStatus();
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	handleSensors();
}
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	saveToFile(".txt");
}
		 private: int graphcount = 1;
		 private: System::Void drawGraph()
		 {
			 try {
				 Application::DoEvents();
				 WebClient^ setStatus = gcnew WebClient();
				 DateTime^ pom = DateTime::Now;
				// String^ x = pom->Hour.ToString()+":"+;
				 System::String ^ url = "http://www.kubat.besaba.com/PHP_temp/drawGraph.php";
				 System::String^ status = setStatus->DownloadString(url);
				 array<String^> ^states = status->Split(':');
				 TemperatureChart->Series["temperatura"]->Points->AddXY(graphcount, int::Parse(states[0]));
				 HumidityChart->Series["humidity"]->Points->AddXY(graphcount, int::Parse(states[1]));
				 graphcount++;




				 ////Console::WriteLine("temp");



			 }
			 catch (WebException^ WebEx)
			 {
				 errorReport(WebEx);
			 }

		 }
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
	drawGraph();
}
};
}
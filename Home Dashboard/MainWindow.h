#pragma once

namespace HomeDashboard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Console::WriteLine("inicjalizacja\n");
			//DataChart->Series["temperatura"]->Points->AddXY("cos", 25);
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  DataChart;
	protected:

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureSave;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
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
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->DataChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureSave = (gcnew System::Windows::Forms::PictureBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureSave))->BeginInit();
			this->SuspendLayout();
			// 
			// DataChart
			// 
			this->DataChart->BackColor = System::Drawing::Color::Transparent;
			this->DataChart->BorderlineColor = System::Drawing::Color::Gray;
			chartArea1->Name = L"ChartArea1";
			this->DataChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->DataChart->Legends->Add(legend1);
			this->DataChart->Location = System::Drawing::Point(105, 139);
			this->DataChart->Margin = System::Windows::Forms::Padding(4);
			this->DataChart->Name = L"DataChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Temperatura";
			this->DataChart->Series->Add(series1);
			this->DataChart->Size = System::Drawing::Size(736, 157);
			this->DataChart->TabIndex = 0;
			this->DataChart->Text = L"chart1";
			this->DataChart->Visible = false;
			this->DataChart->Click += gcnew System::EventHandler(this, &MainWindow::DataChart_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(226, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 39);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainWindow::pictureBox1_Click);
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &MainWindow::pictureBox1_Leave);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &MainWindow::pictureBox1_Hover);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(363, 50);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 38);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MainWindow::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(503, 50);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(50, 46);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureSave
			// 
			this->pictureSave->BackColor = System::Drawing::Color::Transparent;
			this->pictureSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureSave.Image")));
			this->pictureSave->Location = System::Drawing::Point(622, 50);
			this->pictureSave->Name = L"pictureSave";
			this->pictureSave->Size = System::Drawing::Size(50, 50);
			this->pictureSave->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureSave->TabIndex = 4;
			this->pictureSave->TabStop = false;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::backgroundWorker1_DoWork);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(884, 561);
			this->Controls->Add(this->pictureSave);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->DataChart);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Apolonia", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home Dashboard";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureSave))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DataChart_Click(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	Console::WriteLine("cos");
}
private: System::Void pictureBox1_Hover(System::Object^ sender, System::EventArgs^ e)
{
		pictureBox1->BackColor = System::Drawing::Color::White;

}
private: System::Void pictureBox1_Leave(System::Object^ sender, System::EventArgs^ e)
{
		pictureBox1->BackColor = System::Drawing::Color::Transparent;
}

private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	DataChart->Visible = "True";
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
}
};
}

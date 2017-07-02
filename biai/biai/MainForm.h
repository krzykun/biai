#pragma once
#include "Net.h"
#include "Neuron.h"
#include "TrainingData.h"
#include "Expression.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <msclr\marshal_cppstd.h>
namespace biai {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->initializeChart();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Start;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::GroupBox^  grpBoxOutput;
	private: System::Windows::Forms::GroupBox^  grpBoxChart;
	private: System::Windows::Forms::Button^  btnLaunchTest;
	private: System::Windows::Forms::GroupBox^  grpBoxInputs;
	private: System::Windows::Forms::Panel^  panel1;
	private: Net* NeuralNetwork;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox10;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Start = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpBoxOutput = (gcnew System::Windows::Forms::GroupBox());
			this->grpBoxChart = (gcnew System::Windows::Forms::GroupBox());
			this->btnLaunchTest = (gcnew System::Windows::Forms::Button());
			this->grpBoxInputs = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->grpBoxOutput->SuspendLayout();
			this->grpBoxChart->SuspendLayout();
			this->grpBoxInputs->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(12, 25);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(123, 33);
			this->Start->TabIndex = 1;
			this->Start->Text = L"Launch learning";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &MainForm::Start_Click);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(3, 16);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(953, 215);
			this->textBox1->TabIndex = 2;
			// 
			// chart1
			// 
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart1->Location = System::Drawing::Point(3, 16);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(953, 326);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// grpBoxOutput
			// 
			this->grpBoxOutput->Controls->Add(this->textBox1);
			this->grpBoxOutput->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxOutput->Location = System::Drawing::Point(0, 0);
			this->grpBoxOutput->Name = L"grpBoxOutput";
			this->grpBoxOutput->Size = System::Drawing::Size(959, 234);
			this->grpBoxOutput->TabIndex = 4;
			this->grpBoxOutput->TabStop = false;
			this->grpBoxOutput->Text = L"Output";
			// 
			// grpBoxChart
			// 
			this->grpBoxChart->Controls->Add(this->chart1);
			this->grpBoxChart->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->grpBoxChart->Location = System::Drawing::Point(0, 259);
			this->grpBoxChart->Name = L"grpBoxChart";
			this->grpBoxChart->Size = System::Drawing::Size(959, 345);
			this->grpBoxChart->TabIndex = 5;
			this->grpBoxChart->TabStop = false;
			this->grpBoxChart->Text = L"Visualization";
			// 
			// btnLaunchTest
			// 
			this->btnLaunchTest->Location = System::Drawing::Point(12, 64);
			this->btnLaunchTest->Name = L"btnLaunchTest";
			this->btnLaunchTest->Size = System::Drawing::Size(123, 34);
			this->btnLaunchTest->TabIndex = 6;
			this->btnLaunchTest->Text = L"Approximate";
			this->btnLaunchTest->UseVisualStyleBackColor = true;
			this->btnLaunchTest->Click += gcnew System::EventHandler(this, &MainForm::OnClick_btnTest);
			// 
			// grpBoxInputs
			// 
			this->grpBoxInputs->Controls->Add(this->groupBox3);
			this->grpBoxInputs->Controls->Add(this->groupBox2);
			this->grpBoxInputs->Controls->Add(this->groupBox1);
			this->grpBoxInputs->Controls->Add(this->btnLaunchTest);
			this->grpBoxInputs->Controls->Add(this->Start);
			this->grpBoxInputs->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxInputs->Location = System::Drawing::Point(0, 0);
			this->grpBoxInputs->Name = L"grpBoxInputs";
			this->grpBoxInputs->Size = System::Drawing::Size(959, 143);
			this->grpBoxInputs->TabIndex = 7;
			this->grpBoxInputs->TabStop = false;
			this->grpBoxInputs->Text = L"Inputs";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(341, 18);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(136, 125);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Test data";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 23);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(54, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Topology:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(6, 39);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(124, 20);
			this->textBox10->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 24);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Create";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Location = System::Drawing::Point(483, 18);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(258, 125);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"scale";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(136, 73);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"yInterval =";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(197, 70);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(54, 20);
			this->textBox7->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(136, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"yMax =";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(197, 43);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(54, 20);
			this->textBox8->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(135, 18);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"yMin =";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(197, 17);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(54, 20);
			this->textBox9->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(245, 24);
			this->button2->TabIndex = 6;
			this->button2->Text = L"set scale";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"xInterval =";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(67, 69);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(54, 20);
			this->textBox6->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"xMax =";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(67, 42);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(54, 20);
			this->textBox4->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"xMin =";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(67, 16);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(54, 20);
			this->textBox5->TabIndex = 4;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Location = System::Drawing::Point(141, 18);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(194, 125);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"function";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(30, 72);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(73, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Autoscale";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(168, 24);
			this->button1->TabIndex = 4;
			this->button1->Text = L"draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"y =";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(30, 46);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(148, 20);
			this->textBox3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"x =";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(30, 20);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 20);
			this->textBox2->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->grpBoxOutput);
			this->panel1->Controls->Add(this->grpBoxChart);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 149);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(959, 604);
			this->panel1->TabIndex = 8;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 753);
			this->Controls->Add(this->grpBoxInputs);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->grpBoxOutput->ResumeLayout(false);
			this->grpBoxOutput->PerformLayout();
			this->grpBoxChart->ResumeLayout(false);
			this->grpBoxInputs->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		string showVectorVals(string label, std::vector<double> &v)
		{
			string _text = "";
			_text += label;
			_text += " ";
			for (unsigned i = 0; i < v.size(); ++i) {
				_text += to_string(v[i]);
				_text += " ";
			}
			return _text;
		}

#pragma endregion

	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {
		string text = "";
		TrainingData trainData("trainingData.txt", READ);

		vector<unsigned> topology;
		trainData.getTopology(topology);

		Net myNet(topology);

		vector<double> inputVals, targetVals, resultVals;
		int trainingPass = 0;
		while (!trainData.isEof()) {
			string text2 = "";
			++trainingPass;
			text2 += "\t\t";
			text2 += "Pass";
			text2 += to_string(trainingPass);
			text2 += "\t\t";

			// Get new input data and feed it forward:
			if (trainData.getNextInputs(inputVals) != topology[0]) {
				break;
			}

			text2 += showVectorVals("Inputs:", inputVals);
			myNet.feedForward(inputVals);
			text2 += "\t\t";

			// Collect the net's actual output results:
			myNet.getResults(resultVals);
			text2 += showVectorVals("Outputs:", resultVals);
			//this->chart1->Series["data"]->Points->AddXY(trainingPass, resultVals[0]);
			text2 += "\t\t";

			// Train the net what the outputs should have been:
			trainData.getTargetOutputs(targetVals);
			text2 += showVectorVals("Targets:", targetVals);
			//assert(targetVals.size() == topology.back());
			text2 += "\t\t";

			myNet.backProp(targetVals);

			// Report how well the training is working, average over recent samples:
			text2 += "Net recent average error: ";
			double error = myNet.getRecentAverageError();
			text2 += to_string(error);
			this->chart1->Series["error"]->Points->AddXY(trainingPass, error);
			text2 += "\r\n";
			if (trainingPass % 50 == 0)
				text += text2;
		}
		System::String^ MyString = gcnew System::String(text.c_str());
		this->textBox1->Text = MyString;
	}

	private: System::Void initializeChart() {
		this->chart1->ChartAreas->Add("area");
		this->chart1->ChartAreas["area"]->AxisX->Minimum = 0;
		this->chart1->ChartAreas["area"]->AxisX->Maximum = 2000;
		this->chart1->ChartAreas["area"]->AxisX->Interval = 100;
		this->chart1->ChartAreas["area"]->AxisY->Minimum = -0.2;
		this->chart1->ChartAreas["area"]->AxisY->Interval = 0.1;
		this->chart1->ChartAreas["area"]->AxisY->Maximum = 1.2;

		this->chart1->Series->Add("function1");
		this->chart1->Series->Add("function2");
		this->chart1->Series->Add("error");
		this->chart1->Series->Add("data");
		this->chart1->Series["function1"]->Color = System::Drawing::Color::Red;
		this->chart1->Series["function2"]->Color = System::Drawing::Color::Green;
		this->chart1->Series["error"]->Color = System::Drawing::Color::YellowGreen;
		this->chart1->Series["data"]->Color = System::Drawing::Color::BurlyWood;
		this->chart1->Series["function1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["function2"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
		this->chart1->Series["error"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["data"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;

	}

	private: System::Void OnClick_btnTest(System::Object^  sender, System::EventArgs^  e) {}
			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	
		double xMin = solve(msclr::interop::marshal_as<std::string>(this->textBox2->Text), 0);
		double xMax = solve(msclr::interop::marshal_as<std::string>(this->textBox2->Text), 0);
		double yMin = solve(msclr::interop::marshal_as<std::string>(this->textBox3->Text), 0);
		double yMax = solve(msclr::interop::marshal_as<std::string>(this->textBox3->Text), 0);

		this->chart1->Series["function1"]->Points->Clear();
		for (int k = 0; k < 2001; k++) {
			double x = solve(msclr::interop::marshal_as<std::string>(this->textBox2->Text), k);
			double y = solve(msclr::interop::marshal_as<std::string>(this->textBox3->Text), k);
			this->chart1->Series["function1"]->Points->AddXY(x, y);
			if (x > xMax)
				xMax = x;
			else if (x < xMin)
				xMin = x;
			if (y > yMax)
				yMax = y;
			else if (y < yMin)
				yMin = y;
		}
		if (this->checkBox1->Checked) {
			this->chart1->ChartAreas["area"]->AxisX->Minimum = xMin;
			this->textBox5->Text = xMin.ToString();
			this->chart1->ChartAreas["area"]->AxisX->Maximum = xMax;
			this->textBox4->Text = xMax.ToString();
			this->chart1->ChartAreas["area"]->AxisX->Interval = (xMax - xMin) / 10;
			this->textBox6->Text = ((xMax - xMin) / 10).ToString();
			this->chart1->ChartAreas["area"]->AxisY->Minimum = yMin;
			this->textBox9->Text = yMin.ToString();
			this->chart1->ChartAreas["area"]->AxisY->Maximum = yMax;
			this->textBox8->Text = yMax.ToString();
			this->chart1->ChartAreas["area"]->AxisY->Interval = (yMax - yMin) / 10;
			this->textBox7->Text = ((yMax - yMin) / 10).ToString();
		}
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->chart1->ChartAreas["area"]->AxisX->Minimum = double::Parse(this->textBox5->Text);
	this->chart1->ChartAreas["area"]->AxisX->Maximum = double::Parse(this->textBox4->Text);
	this->chart1->ChartAreas["area"]->AxisX->Interval = double::Parse(this->textBox6->Text);
	this->chart1->ChartAreas["area"]->AxisY->Minimum = double::Parse(this->textBox9->Text);
	this->chart1->ChartAreas["area"]->AxisY->Maximum = double::Parse(this->textBox8->Text);
	this->chart1->ChartAreas["area"]->AxisY->Interval = double::Parse(this->textBox7->Text);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	TrainingData trainingData("trainingData.txt", WRITE);
	trainingData.generate(createTopologySchema(msclr::interop::marshal_as<std::string>(this->textBox10->Text)));
}

};
}

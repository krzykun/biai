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
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label11;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;







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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
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
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
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
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(6, 95);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(140, 24);
			this->Start->TabIndex = 1;
			this->Start->Text = L"Launch";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &MainForm::Start_Click);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(3, 16);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(1285, 215);
			this->textBox1->TabIndex = 2;
			// 
			// chart1
			// 
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart1->Location = System::Drawing::Point(3, 16);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(1285, 326);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// grpBoxOutput
			// 
			this->grpBoxOutput->Controls->Add(this->textBox1);
			this->grpBoxOutput->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxOutput->Location = System::Drawing::Point(0, 0);
			this->grpBoxOutput->Name = L"grpBoxOutput";
			this->grpBoxOutput->Size = System::Drawing::Size(1291, 234);
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
			this->grpBoxChart->Size = System::Drawing::Size(1291, 345);
			this->grpBoxChart->TabIndex = 5;
			this->grpBoxChart->TabStop = false;
			this->grpBoxChart->Text = L"Visualization";
			// 
			// btnLaunchTest
			// 
			this->btnLaunchTest->Location = System::Drawing::Point(6, 95);
			this->btnLaunchTest->Name = L"btnLaunchTest";
			this->btnLaunchTest->Size = System::Drawing::Size(140, 24);
			this->btnLaunchTest->TabIndex = 6;
			this->btnLaunchTest->Text = L"Approximate";
			this->btnLaunchTest->UseVisualStyleBackColor = true;
			this->btnLaunchTest->Click += gcnew System::EventHandler(this, &MainForm::OnClick_btnTest);
			// 
			// grpBoxInputs
			// 
			this->grpBoxInputs->Controls->Add(this->groupBox5);
			this->grpBoxInputs->Controls->Add(this->groupBox4);
			this->grpBoxInputs->Controls->Add(this->groupBox3);
			this->grpBoxInputs->Controls->Add(this->groupBox2);
			this->grpBoxInputs->Controls->Add(this->groupBox1);
			this->grpBoxInputs->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxInputs->Location = System::Drawing::Point(0, 0);
			this->grpBoxInputs->Name = L"grpBoxInputs";
			this->grpBoxInputs->Size = System::Drawing::Size(1291, 143);
			this->grpBoxInputs->TabIndex = 7;
			this->grpBoxInputs->TabStop = false;
			this->grpBoxInputs->Text = L"Inputs";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Controls->Add(this->textBox14);
			this->groupBox5->Controls->Add(this->btnLaunchTest);
			this->groupBox5->Location = System::Drawing::Point(794, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(153, 125);
			this->groupBox5->TabIndex = 12;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Approximate";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 44);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(39, 13);
			this->label13->TabIndex = 19;
			this->label13->Text = L"Points:";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(51, 41);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(95, 20);
			this->textBox14->TabIndex = 16;
			this->textBox14->Text = L"200";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->checkBox3);
			this->groupBox4->Controls->Add(this->checkBox2);
			this->groupBox4->Controls->Add(this->Start);
			this->groupBox4->Location = System::Drawing::Point(636, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(152, 125);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Learning";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Location = System::Drawing::Point(34, 48);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(72, 17);
			this->checkBox3->TabIndex = 3;
			this->checkBox3->Text = L"autoscale";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(34, 28);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(73, 17);
			this->checkBox2->TabIndex = 2;
			this->checkBox2->Text = L"draw error";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(478, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(152, 125);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Training data";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 53);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Size:";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(66, 50);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(80, 20);
			this->textBox11->TabIndex = 17;
			this->textBox11->Text = L"2000";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(54, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Topology:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(66, 28);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(80, 20);
			this->textBox10->TabIndex = 6;
			this->textBox10->Text = L"10 10 2";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 24);
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
			this->groupBox2->Location = System::Drawing::Point(226, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(246, 125);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Scale";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(126, 72);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"yInterval =";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(187, 69);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(54, 20);
			this->textBox7->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(126, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"yMax =";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(187, 47);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(54, 20);
			this->textBox8->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(125, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"yMin =";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(187, 25);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(54, 20);
			this->textBox9->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(235, 24);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Set";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 70);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"xInterval =";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(67, 67);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(54, 20);
			this->textBox6->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"xMax =";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(67, 45);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(54, 20);
			this->textBox4->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"xMin =";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(67, 23);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(54, 20);
			this->textBox5->TabIndex = 4;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->textBox13);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Location = System::Drawing::Point(6, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(214, 125);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Function";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(154, 67);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(50, 20);
			this->textBox12->TabIndex = 23;
			this->textBox12->Text = L"2001";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(114, 72);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(34, 13);
			this->label11->TabIndex = 22;
			this->label11->Text = L"t end:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(7, 70);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 13);
			this->label12->TabIndex = 20;
			this->label12->Text = L"t start:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(49, 66);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(50, 20);
			this->textBox13->TabIndex = 19;
			this->textBox13->Text = L"0";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(6, 95);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(72, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"autoscale";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 24);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"y =";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(30, 43);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(174, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"t*t-0.7*t";
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
			this->textBox2->Size = System::Drawing::Size(174, 20);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"2*t";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->grpBoxOutput);
			this->panel1->Controls->Add(this->grpBoxChart);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 149);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1291, 604);
			this->panel1->TabIndex = 8;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1291, 753);
			this->Controls->Add(this->grpBoxInputs);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->grpBoxOutput->ResumeLayout(false);
			this->grpBoxOutput->PerformLayout();
			this->grpBoxChart->ResumeLayout(false);
			this->grpBoxInputs->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {
		TrainingData trainData("trainingData.txt", READ);
		stringstream ss;
		TopologySchema topologySchema;
		trainData.getTopology(topologySchema);
		double maxError;
		Net myNet(topologySchema);
		this->chart1->Series["error"]->Points->Clear();

		vector<double> inputVals, targetVals, resultVals;
		int trainingPass = 0;
		while (!trainData.isEof()) {			
			++trainingPass;
			ss << "Pass" << trainingPass << "\t\t";

			// Get new input data and feed it forward:
			if (trainData.getNextInputs(inputVals) != topologySchema[0])
				break;

			ss << showVectorVals("Inputs:", inputVals) << "\t\t";
			myNet.feedForward(inputVals);

			// Collect the net's actual output results:
			myNet.getResults(resultVals);
			ss << showVectorVals("Outputs:", resultVals) << "\t\t";

			// Train the net what the outputs should have been:
			trainData.getTargetOutputs(targetVals);
			ss << showVectorVals("Targets:", targetVals) << "\t\t";
			assert(targetVals.size() == topologySchema.back());

			myNet.backProp(targetVals);

			// Report how well the training is working, average over recent samples:			
			double error = myNet.getRecentAverageError();
			ss << "Net recent average error: " << error << "\r\n";
			if (this->checkBox2->Checked) {
				this->chart1->Series["error"]->Points->AddXY(trainingPass, error);
				if (maxError < error)
					maxError = error;
			}
		}
		this->textBox1->Text = toSystemString(ss.str());
		if (this->checkBox3->Checked && this->checkBox2->Checked) {
			this->chart1->ChartAreas["area"]->AxisX->Minimum = 0;
			this->chart1->ChartAreas["area"]->AxisX->Maximum = trainingPass;
			this->chart1->ChartAreas["area"]->AxisX->Interval = trainingPass / 10.0;
			this->chart1->ChartAreas["area"]->AxisY->Minimum = 0;
			this->chart1->ChartAreas["area"]->AxisY->Interval = maxError / 10.0;
			this->chart1->ChartAreas["area"]->AxisY->Maximum = maxError;
		}
		myNet.save("net.txt");
	}

	private: System::Void initializeChart() {
		this->chart1->ChartAreas->Add("area");
		this->chart1->ChartAreas["area"]->AxisX->Minimum = 0;
		this->chart1->ChartAreas["area"]->AxisX->Maximum = 2000;
		this->chart1->ChartAreas["area"]->AxisX->Interval = 100;
		this->chart1->ChartAreas["area"]->AxisY->Minimum = -0.2;
		this->chart1->ChartAreas["area"]->AxisY->Interval = 0.1;
		this->chart1->ChartAreas["area"]->AxisY->Maximum = 1.2;

		this->chart1->Series->Add("function");
		this->chart1->Series->Add("error");
		this->chart1->Series->Add("approximate");
		this->chart1->Series["function"]->Color = System::Drawing::Color::Green;
		this->chart1->Series["error"]->Color = System::Drawing::Color::YellowGreen;
		this->chart1->Series["approximate"]->Color = System::Drawing::Color::BurlyWood;
		this->chart1->Series["function"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["error"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["approximate"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;

	}

	private: vector<double> getInputsForPoint(double t, Normalizer xNormalizer, Normalizer yNormalizer) {
		vector<double> inputs;
		string xFunction = toStdString(this->textBox2->Text);
		string yFunction = toStdString(this->textBox3->Text);
		TopologySchema topologySchema = createTopologySchema(toStdString(this->textBox10->Text));
		for (int i = (topologySchema[0]/2); i > 0; --i) {
			double x = xNormalizer.normalize(solve(xFunction, t - i));
			double y = yNormalizer.normalize(solve(yFunction, t - i));
			inputs.push_back(x);
			inputs.push_back(y);
		}
		return inputs;
	}

	private: System::Void OnClick_btnTest(System::Object^  sender, System::EventArgs^  e) {
		int size = int::Parse(this->textBox11->Text);
		int tStart = int::Parse(this->textBox13->Text);
		int tEnd = int::Parse(this->textBox12->Text);
		string xFunction = toStdString(this->textBox2->Text);
		string yFunction = toStdString(this->textBox3->Text);
		int points = int::Parse(this->textBox14->Text);
		Normalizer xNormalizer(minValue(xFunction, tStart, tEnd + points), maxValue(xFunction, tStart, tEnd + points));
		Normalizer yNormalizer(minValue(yFunction, tStart, tEnd + points), maxValue(yFunction, tStart, tEnd + points));
		Net myNet("net.txt");
		stringstream ss;
		this->chart1->Series["approximate"]->Points->Clear();
		double xMin = this->chart1->ChartAreas["area"]->AxisX->Minimum;
		double xMax = this->chart1->ChartAreas["area"]->AxisX->Maximum;
		double yMin = this->chart1->ChartAreas["area"]->AxisY->Minimum;
		double yMax = this->chart1->ChartAreas["area"]->AxisY->Maximum;

		vector<double> inputVals, resultVals;
		int pass = 0;
		//ss << "\r\n \r\n"; //if history present, uncomment this line 
		for (int i = tEnd; i < (tEnd + points); i++) {
			++pass;
			ss << "Pass" << pass << "\t\t";
			inputVals = getInputsForPoint(i, xNormalizer, yNormalizer);
			ss << showVectorVals("Inputs:", inputVals) << "\t\t";
			myNet.feedForward(inputVals);
			myNet.getResults(resultVals);
			ss << showVectorVals("Outputs:", resultVals) << "\r\n";
			double x = xNormalizer.realValue(resultVals[0]);
			double y = yNormalizer.realValue(resultVals[1]);
			this->chart1->Series["function"]->Points->AddXY(x, y);
			if (x > xMax)
				xMax = x;
			else if (x < xMin)
				xMin = x;
			if (y > yMax)
				yMax = y;
			else if (y < yMin)
				yMin = y;
		}
		this->textBox1->Text = toSystemString(ss.str());
		this->chart1->ChartAreas["area"]->AxisX->Minimum = xMin;
		this->chart1->ChartAreas["area"]->AxisX->Maximum = xMax;
		this->chart1->ChartAreas["area"]->AxisX->Interval = (xMax - xMin) / 10;
		this->chart1->ChartAreas["area"]->AxisY->Minimum = yMin;
		this->chart1->ChartAreas["area"]->AxisY->Maximum = yMax;
		this->chart1->ChartAreas["area"]->AxisY->Interval = (yMax - yMin) / 10;
	}
			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	
		double xMin = solve(toStdString(this->textBox2->Text), 0);
		double xMax = solve(toStdString(this->textBox2->Text), 0);
		double yMin = solve(toStdString(this->textBox3->Text), 0);
		double yMax = solve(toStdString(this->textBox3->Text), 0);
		int tStart = int::Parse(this->textBox13->Text);
		int tEnd = int::Parse(this->textBox12->Text);

		this->chart1->Series["function"]->Points->Clear();
		for (int k = tStart; k < tEnd; k++) {
			double x = solve(toStdString(this->textBox2->Text), k);
			double y = solve(toStdString(this->textBox3->Text), k);
			this->chart1->Series["function"]->Points->AddXY(x, y);
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
	int size = int::Parse(this->textBox11->Text);
	int tStart = int::Parse(this->textBox13->Text);
	int tEnd = int::Parse(this->textBox12->Text);
	string xFunction = toStdString(this->textBox2->Text);
	string yFunction = toStdString(this->textBox3->Text);
	int points = int::Parse(this->textBox14->Text);
	TopologySchema topologySchema = createTopologySchema(toStdString(this->textBox10->Text));
	TrainingData trainingData("trainingData.txt", WRITE);
	trainingData.generate(topologySchema, size, tStart, tEnd,  points, xFunction, yFunction);
}

private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->checkBox3->Enabled = this->checkBox2->Checked;
}
};
}

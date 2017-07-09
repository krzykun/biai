#pragma once
#include "neutralNetwork/neutralNetwork.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <conio.h>
#include <math.h>
#include <direct.h>
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
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::Label^  label15;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::Label^  label16;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::CheckBox^  checkBox4;


	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  textBox18;
private: System::Windows::Forms::CheckBox^  checkBox5;

	private: System::Windows::Forms::TextBox^  textBox16;

	private: System::Void initializeChart();
	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void OnClick_btnTest(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);

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
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox6->SuspendLayout();
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
			this->Start->Size = System::Drawing::Size(142, 24);
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
			this->textBox1->Size = System::Drawing::Size(1267, 215);
			this->textBox1->TabIndex = 2;
			// 
			// chart1
			// 
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart1->Location = System::Drawing::Point(3, 16);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(1267, 326);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// grpBoxOutput
			// 
			this->grpBoxOutput->Controls->Add(this->textBox1);
			this->grpBoxOutput->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxOutput->Location = System::Drawing::Point(0, 0);
			this->grpBoxOutput->Name = L"grpBoxOutput";
			this->grpBoxOutput->Size = System::Drawing::Size(1273, 234);
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
			this->grpBoxChart->Size = System::Drawing::Size(1273, 345);
			this->grpBoxChart->TabIndex = 5;
			this->grpBoxChart->TabStop = false;
			this->grpBoxChart->Text = L"Visualization";
			// 
			// btnLaunchTest
			// 
			this->btnLaunchTest->Location = System::Drawing::Point(6, 95);
			this->btnLaunchTest->Name = L"btnLaunchTest";
			this->btnLaunchTest->Size = System::Drawing::Size(108, 24);
			this->btnLaunchTest->TabIndex = 6;
			this->btnLaunchTest->Text = L"Approximate";
			this->btnLaunchTest->UseVisualStyleBackColor = true;
			this->btnLaunchTest->Click += gcnew System::EventHandler(this, &MainForm::OnClick_btnTest);
			// 
			// grpBoxInputs
			// 
			this->grpBoxInputs->Controls->Add(this->groupBox6);
			this->grpBoxInputs->Controls->Add(this->groupBox5);
			this->grpBoxInputs->Controls->Add(this->groupBox4);
			this->grpBoxInputs->Controls->Add(this->groupBox3);
			this->grpBoxInputs->Controls->Add(this->groupBox2);
			this->grpBoxInputs->Controls->Add(this->groupBox1);
			this->grpBoxInputs->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxInputs->Location = System::Drawing::Point(0, 0);
			this->grpBoxInputs->Name = L"grpBoxInputs";
			this->grpBoxInputs->Size = System::Drawing::Size(1273, 143);
			this->grpBoxInputs->TabIndex = 7;
			this->grpBoxInputs->TabStop = false;
			this->grpBoxInputs->Text = L"Inputs";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label30);
			this->groupBox6->Controls->Add(this->button4);
			this->groupBox6->Controls->Add(this->label29);
			this->groupBox6->Controls->Add(this->textBox20);
			this->groupBox6->Controls->Add(this->label25);
			this->groupBox6->Controls->Add(this->label26);
			this->groupBox6->Controls->Add(this->label27);
			this->groupBox6->Controls->Add(this->textBox22);
			this->groupBox6->Controls->Add(this->label28);
			this->groupBox6->Controls->Add(this->textBox23);
			this->groupBox6->Controls->Add(this->textBox19);
			this->groupBox6->Controls->Add(this->label23);
			this->groupBox6->Controls->Add(this->label22);
			this->groupBox6->Controls->Add(this->label24);
			this->groupBox6->Controls->Add(this->textBox21);
			this->groupBox6->Controls->Add(this->label21);
			this->groupBox6->Controls->Add(this->textBox18);
			this->groupBox6->Location = System::Drawing::Point(887, 12);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(377, 124);
			this->groupBox6->TabIndex = 13;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Autotests";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(90, 101);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(194, 13);
			this->label30->TabIndex = 35;
			this->label30->Text = L"result diagrams will be saved in png files";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(285, 94);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 24);
			this->button4->TabIndex = 34;
			this->button4->Text = L"Run tests";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(3, 87);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(74, 13);
			this->label29->TabIndex = 33;
			this->label29->Text = L"(with commas)";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(285, 71);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(80, 20);
			this->textBox20->TabIndex = 32;
			this->textBox20->Text = L"200";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(214, 77);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(66, 13);
			this->label25->TabIndex = 31;
			this->label25->Text = L"Appr. points:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(282, 13);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(83, 13);
			this->label26->TabIndex = 30;
			this->label26->Text = L"lists with spaces";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(214, 54);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(31, 13);
			this->label27->TabIndex = 29;
			this->label27->Text = L"Etas:";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(285, 50);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(80, 20);
			this->textBox22->TabIndex = 28;
			this->textBox22->Text = L"0.2";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(214, 32);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(42, 13);
			this->label28->TabIndex = 27;
			this->label28->Text = L"Alphas:";
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(285, 29);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(80, 20);
			this->textBox23->TabIndex = 26;
			this->textBox23->Text = L"0.3";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(77, 71);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(131, 20);
			this->textBox19->TabIndex = 25;
			this->textBox19->Text = L"6 4,8";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(3, 74);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(74, 13);
			this->label23->TabIndex = 24;
			this->label23->Text = L"Hidden layers:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(74, 13);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(83, 13);
			this->label22->TabIndex = 23;
			this->label22->Text = L"lists with spaces";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(3, 54);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(35, 13);
			this->label24->TabIndex = 22;
			this->label24->Text = L"Sizes:";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(77, 50);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(131, 20);
			this->textBox21->TabIndex = 21;
			this->textBox21->Text = L"20000";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(3, 30);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(65, 13);
			this->label21->TabIndex = 18;
			this->label21->Text = L"Input points:";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(77, 29);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(131, 20);
			this->textBox18->TabIndex = 17;
			this->textBox18->Text = L"2 3 4";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->checkBox5);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Controls->Add(this->textBox14);
			this->groupBox5->Controls->Add(this->btnLaunchTest);
			this->groupBox5->Location = System::Drawing::Point(762, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(119, 125);
			this->groupBox5->TabIndex = 12;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Approximate";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Checked = true;
			this->checkBox5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox5->Location = System::Drawing::Point(9, 65);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(49, 17);
			this->checkBox5->TabIndex = 20;
			this->checkBox5->Text = L"draw";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 33);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(39, 13);
			this->label13->TabIndex = 19;
			this->label13->Text = L"Points:";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(51, 30);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(49, 20);
			this->textBox14->TabIndex = 16;
			this->textBox14->Text = L"100";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label14);
			this->groupBox4->Controls->Add(this->checkBox3);
			this->groupBox4->Controls->Add(this->textBox15);
			this->groupBox4->Controls->Add(this->label15);
			this->groupBox4->Controls->Add(this->checkBox2);
			this->groupBox4->Controls->Add(this->textBox16);
			this->groupBox4->Controls->Add(this->Start);
			this->groupBox4->Location = System::Drawing::Point(601, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(155, 125);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Learning";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(8, 50);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(25, 13);
			this->label14->TabIndex = 22;
			this->label14->Text = L"eta:";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Location = System::Drawing::Point(76, 70);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(72, 17);
			this->checkBox3->TabIndex = 3;
			this->checkBox3->Text = L"autoscale";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(68, 47);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(80, 20);
			this->textBox15->TabIndex = 21;
			this->textBox15->Text = L"0,15";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(8, 29);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(36, 13);
			this->label15->TabIndex = 20;
			this->label15->Text = L"alpha:";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(6, 70);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(73, 17);
			this->checkBox2->TabIndex = 2;
			this->checkBox2->Text = L"draw error";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(68, 25);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(80, 20);
			this->textBox16->TabIndex = 19;
			this->textBox16->Text = L"0,5";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->checkBox4);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->textBox17);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(435, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(160, 125);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Training data";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(24, 106);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(43, 13);
			this->label19->TabIndex = 26;
			this->label19->Text = L"(slower)";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(6, 89);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(82, 17);
			this->checkBox4->TabIndex = 25;
			this->checkBox4->Text = L"with logging";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(295, 30);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 13);
			this->label17->TabIndex = 24;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 50);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(74, 13);
			this->label18->TabIndex = 23;
			this->label18->Text = L"Hidden layers:";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(86, 47);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(67, 20);
			this->textBox17->TabIndex = 22;
			this->textBox17->Text = L"8";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(13, 48);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 13);
			this->label16->TabIndex = 21;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 73);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Size:";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(86, 69);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(67, 20);
			this->textBox11->TabIndex = 17;
			this->textBox11->Text = L"200000";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 28);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Input points:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(86, 25);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(67, 20);
			this->textBox10->TabIndex = 6;
			this->textBox10->Text = L"2";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(94, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 24);
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
			this->groupBox2->Location = System::Drawing::Point(216, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(213, 125);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Scale";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(108, 72);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"yInt. =";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(150, 66);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(54, 20);
			this->textBox7->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(108, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"yMax =";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(150, 44);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(54, 20);
			this->textBox8->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(107, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"yMin =";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(150, 22);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(54, 20);
			this->textBox9->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(198, 24);
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
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"xInt. =";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(48, 65);
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
			this->textBox4->Location = System::Drawing::Point(48, 43);
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
			this->textBox5->Location = System::Drawing::Point(48, 21);
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
			this->groupBox1->Size = System::Drawing::Size(204, 125);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Function";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(143, 67);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(50, 20);
			this->textBox12->TabIndex = 23;
			this->textBox12->Text = L"2001";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(103, 72);
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
			this->textBox13->Size = System::Drawing::Size(36, 20);
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
			this->button1->Size = System::Drawing::Size(108, 24);
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
			this->textBox3->Location = System::Drawing::Point(30, 42);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(163, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"t*t-2000*t";
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
			this->textBox2->Size = System::Drawing::Size(163, 20);
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
			this->panel1->Size = System::Drawing::Size(1273, 604);
			this->panel1->TabIndex = 8;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1273, 753);
			this->Controls->Add(this->grpBoxInputs);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->grpBoxOutput->ResumeLayout(false);
			this->grpBoxOutput->PerformLayout();
			this->grpBoxChart->ResumeLayout(false);
			this->grpBoxInputs->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
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
};
}

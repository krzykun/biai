#pragma once
#include "Net.h"
#include "Neuron.h"
#include "TrainingData.h"
#include "TestData.h"
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

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->grpBoxOutput->SuspendLayout();
			this->grpBoxChart->SuspendLayout();
			this->grpBoxInputs->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(6, 19);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(150, 50);
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
			this->textBox1->Size = System::Drawing::Size(953, 234);
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
			this->grpBoxOutput->Size = System::Drawing::Size(959, 253);
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
			this->btnLaunchTest->Location = System::Drawing::Point(6, 75);
			this->btnLaunchTest->Name = L"btnLaunchTest";
			this->btnLaunchTest->Size = System::Drawing::Size(150, 50);
			this->btnLaunchTest->TabIndex = 6;
			this->btnLaunchTest->Text = L"Launch tests";
			this->btnLaunchTest->UseVisualStyleBackColor = true;
			this->btnLaunchTest->Click += gcnew System::EventHandler(this, &MainForm::OnClick_btnTest);
			// 
			// grpBoxInputs
			// 
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
		TrainingData trainData("trainingCoordinates.txt");
		TrainingData testData("testingCoordinates.txt");

		// e.g., { 3, 2, 1 }
		vector<unsigned> topology;
		trainData.getTopology(topology);

		Net myNet(topology);

		vector<double> inputVals, targetVals, resultVals;
		unsigned trainingPass = 0;
		unsigned testPass = 0;

		//
		//Learning
		//

		while (!trainData.isEof()) {
			if (trainingPass % 500 == 0)
				text += "aa:";
			++trainingPass;
			text += "\t\t";
			text += "Pass";
			text += to_string(trainingPass);
			text += "\t\t";

			// Get new input data and feed it forward:
			if (trainData.getNextInputs(inputVals) != topology[0]) {
				break;
			}

			text += showVectorVals("Inputs:", inputVals);
			myNet.feedForward(inputVals);
			text += "\t\t";

			// Collect the net's actual output results:
			myNet.getResults(resultVals);
			text += showVectorVals("Outputs:", resultVals);
			this->chart1->Series["NetData"]->Points->AddXY(trainingPass, resultVals[0] * 100);
			text += "\t\t";

			// Train the net what the outputs should have been:
			trainData.getTargetOutputs(targetVals);
			text += showVectorVals("Targets:", targetVals);
			//assert(targetVals.size() == topology.back());
			text += "\t\t";

			myNet.backProp(targetVals);

			// Report how well the training is working, average over recent samples:
			text += "Net recent average error: ";
			text += to_string(myNet.getRecentAverageError());
			text += "\r\n";
		}
		System::String^ MyString = gcnew System::String(text.c_str());
		this->textBox1->Text = MyString;

		//
		//Testing
		//

		string TestLogString = "";

		while (!testData.isEof())
		{
			if (testPass % 500 == 0)
				TestLogString += "aa:";
			++testPass;
			TestLogString += "\t\t";
			TestLogString += "Pass";
			TestLogString += to_string(testPass);
			TestLogString += "\t\t";

			// Get new input data and feed it forward:
			if (testData.getNextInputs(inputVals) != topology[0]) {
				break;
			}

			TestLogString += showVectorVals("Inputs:", inputVals);
			myNet.feedForward(inputVals);
			TestLogString += "\t\t";

			// Collect the net's actual output results:
			myNet.getResults(resultVals);
			TestLogString += showVectorVals("Outputs:", resultVals);
			this->chart1->Series["NetData"]->Points->AddXY(testPass, resultVals[0] * 100);
			TestLogString += "\t\t";

			// Report how well the training is working, average over recent samples:
			TestLogString += "Net recent average error: ";
			TestLogString += to_string(myNet.getRecentAverageError());
			TestLogString += "\r\n";
		}

		System::String^ TestManagedString = gcnew System::String(TestLogString.c_str());
		this->textBox1->Text = TestManagedString;

	}

	private: int function1(int x) {
		return 0.7*x;
	}
	private: int function2(int x) {
		return 6 + log(x);
	}

	private: double squareFunction(double x) {
		return 2 * x*x + 5 * x;
	}
	

	private: System::Void initializeChart() {
		this->chart1->ChartAreas->Add("area");
		this->chart1->ChartAreas["area"]->AxisX->Minimum = 0;
		this->chart1->ChartAreas["area"]->AxisX->Maximum = 100;
		this->chart1->ChartAreas["area"]->AxisX->Interval = 10;
		this->chart1->ChartAreas["area"]->AxisY->Minimum = 0;
		this->chart1->ChartAreas["area"]->AxisY->Maximum = 100;
		this->chart1->ChartAreas["area"]->AxisY->Interval = 10;

		this->chart1->Series->Add("function1");
		this->chart1->Series->Add("function2");
		this->chart1->Series->Add("kromka");
		this->chart1->Series->Add("NetData");
		this->chart1->Series["function1"]->Color = System::Drawing::Color::Red;
		this->chart1->Series["function2"]->Color = System::Drawing::Color::Green;
		this->chart1->Series["kromka"]->Color = System::Drawing::Color::YellowGreen;
		this->chart1->Series["NetData"]->Color = System::Drawing::Color::BurlyWood;
		this->chart1->Series["function1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		this->chart1->Series["function2"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
		this->chart1->Series["kromka"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
		this->chart1->Series["NetData"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;

		/*for (int i = 0; i < 20; i++) {
			this->chart1->Series["function1"]->Points->AddXY(i, function1(i));
			this->chart1->Series["function2"]->Points->AddXY(i, function2(i));
		}*/

		/*for (double dbIter = 0.0; dbIter < 20; dbIter += 1.0) {
			this->chart1->Series["kromka"]->Points->AddXY(dbIter, squareFunction(dbIter));
		}*/
	}
private: System::Void OnClick_btnTest(System::Object^  sender, System::EventArgs^  e) {

}
};
}

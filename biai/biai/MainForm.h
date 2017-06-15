#pragma once
#include "Net.h"
#include "Neuron.h"
#include "TrainingData.h"
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->grpBoxOutput->SuspendLayout();
			this->grpBoxChart->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Dock = System::Windows::Forms::DockStyle::Top;
			this->Start->Location = System::Drawing::Point(0, 0);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(918, 23);
			this->Start->TabIndex = 1;
			this->Start->Text = L"Start";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &MainForm::Start_Click);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(3, 16);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(912, 240);
			this->textBox1->TabIndex = 2;
			// 
			// chart1
			// 
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart1->Location = System::Drawing::Point(3, 16);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(912, 333);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// grpBoxOutput
			// 
			this->grpBoxOutput->Controls->Add(this->textBox1);
			this->grpBoxOutput->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBoxOutput->Location = System::Drawing::Point(0, 23);
			this->grpBoxOutput->Name = L"grpBoxOutput";
			this->grpBoxOutput->Size = System::Drawing::Size(918, 259);
			this->grpBoxOutput->TabIndex = 4;
			this->grpBoxOutput->TabStop = false;
			this->grpBoxOutput->Text = L"Output";
			// 
			// grpBoxChart
			// 
			this->grpBoxChart->Controls->Add(this->chart1);
			this->grpBoxChart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grpBoxChart->Location = System::Drawing::Point(0, 282);
			this->grpBoxChart->Name = L"grpBoxChart";
			this->grpBoxChart->Size = System::Drawing::Size(918, 352);
			this->grpBoxChart->TabIndex = 5;
			this->grpBoxChart->TabStop = false;
			this->grpBoxChart->Text = L"Visualization";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(918, 634);
			this->Controls->Add(this->grpBoxChart);
			this->Controls->Add(this->grpBoxOutput);
			this->Controls->Add(this->Start);
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->grpBoxOutput->ResumeLayout(false);
			this->grpBoxOutput->PerformLayout();
			this->grpBoxChart->ResumeLayout(false);
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
		TestData testData("testingCoordinates.txt");

		// e.g., { 3, 2, 1 }
		vector<unsigned> topology;
		trainData.getTopology(topology);

		Net myNet(topology);

		vector<double> inputVals, targetVals, resultVals;
		int trainingPass = 0;



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
			this->chart1->Series["NetData"]->Points->AddXY(trainingPass, resultVals[0]);
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

		while(!testdata.Is)

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
};
}

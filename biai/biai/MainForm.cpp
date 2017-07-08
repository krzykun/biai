#include "MainForm.h"
namespace biai {
	System::Void MainForm::Start_Click(System::Object^  sender, System::EventArgs^  e) {
		TrainingData trainData("trainingData.txt", READ);
		stringstream ss;
		TopologySchema topologySchema;
		trainData.getTopology(topologySchema);
		double maxError;
		double alpha = double::Parse(this->textBox16->Text);
		double eta = double::Parse(this->textBox15->Text);
		Net myNet(topologySchema, alpha, eta);
		this->chart1->Series["error"]->Points->Clear();

		vector<double> inputVals, targetVals, resultVals;
		int trainingPass = 0;
		while (!trainData.isEof()) {
			ss << "Pass" << ++trainingPass << "\t\t";

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

	System::Void MainForm::initializeChart() {
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

	vector<double> MainForm::getInputsForPoint(double t, Normalizer xNormalizer, Normalizer yNormalizer) {
		vector<double> inputs;
		string xFunction = toStdString(this->textBox2->Text);
		string yFunction = toStdString(this->textBox3->Text);
		TopologySchema topologySchema = createTopologySchema(int::Parse(this->textBox10->Text), toStdString(this->textBox17->Text));
		for (int i = (topologySchema[0] / 2); i > 0; --i) {
			double x = xNormalizer.normalize(solve(xFunction, t - i));
			double y = yNormalizer.normalize(solve(yFunction, t - i));
			inputs.push_back(x);
			inputs.push_back(y);
		}
		return inputs;
	}

	System::Void MainForm::OnClick_btnTest(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkBox6->Checked) {
			button3_Click(sender, e);
			Start_Click(sender, e);
		}
		if(this->checkBox5->Checked)
			button1_Click(sender, e);
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
		if (this->checkBox5->Checked)
			this->chart1->Series["approximate"]->Points->Clear();
		double xMin = this->chart1->ChartAreas["area"]->AxisX->Minimum;
		double xMax = this->chart1->ChartAreas["area"]->AxisX->Maximum;
		double yMin = this->chart1->ChartAreas["area"]->AxisY->Minimum;
		double yMax = this->chart1->ChartAreas["area"]->AxisY->Maximum;
		double xErrorSum = 0.0, yErrorSum = 0.0;
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
			ss << showVectorVals("Outputs:", resultVals) << "\t\t";
			ss << "x: " << xNormalizer.realValue(resultVals[0]) << "\t";
			ss << "y: " << yNormalizer.realValue(resultVals[1]) << "\t\t";
			double xError = xNormalizer.realValue(resultVals[0]) - solve(toStdString(this->textBox2->Text), i);
			double yError = yNormalizer.realValue(resultVals[1]) - solve(toStdString(this->textBox3->Text), i);
			xErrorSum += pow(xError, 2);
			yErrorSum += pow(yError, 2);
			ss << "x error:" << xError << "\t" << "y error:" << yError << "\r\n";
			double x = xNormalizer.realValue(resultVals[0]);
			double y = yNormalizer.realValue(resultVals[1]);
			if (this->checkBox5->Checked) {
				this->chart1->Series["approximate"]->Points->AddXY(x, y);
				if (x > xMax)
					xMax = x;
				else if (x < xMin)
					xMin = x;
				if (y > yMax)
					yMax = y;
				else if (y < yMin)
					yMin = y;
			}
		}
		ss << "x error square root: " << sqrt(xErrorSum/points) << "\r\n" << "y error square root: " << sqrt(yErrorSum/points);
		this->textBox1->Text = toSystemString(ss.str());
		if (this->checkBox5->Checked) {
			this->chart1->ChartAreas["area"]->AxisX->Minimum = xMin;
			this->chart1->ChartAreas["area"]->AxisX->Maximum = xMax;
			this->chart1->ChartAreas["area"]->AxisX->Interval = (xMax - xMin) / 10;
			this->chart1->ChartAreas["area"]->AxisY->Minimum = yMin;
			this->chart1->ChartAreas["area"]->AxisY->Maximum = yMax;
			this->chart1->ChartAreas["area"]->AxisY->Interval = (yMax - yMin) / 10;
		}
	}

	System::Void MainForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
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

	System::Void MainForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->chart1->ChartAreas["area"]->AxisX->Minimum = double::Parse(this->textBox5->Text);
		this->chart1->ChartAreas["area"]->AxisX->Maximum = double::Parse(this->textBox4->Text);
		this->chart1->ChartAreas["area"]->AxisX->Interval = double::Parse(this->textBox6->Text);
		this->chart1->ChartAreas["area"]->AxisY->Minimum = double::Parse(this->textBox9->Text);
		this->chart1->ChartAreas["area"]->AxisY->Maximum = double::Parse(this->textBox8->Text);
		this->chart1->ChartAreas["area"]->AxisY->Interval = double::Parse(this->textBox7->Text);
	}

	System::Void MainForm::button3_Click(System::Object^  sender, System::EventArgs^  e) {
		int size = int::Parse(this->textBox11->Text);
		int tStart = int::Parse(this->textBox13->Text);
		int tEnd = int::Parse(this->textBox12->Text);
		string xFunction = toStdString(this->textBox2->Text);
		string yFunction = toStdString(this->textBox3->Text);
		int points = int::Parse(this->textBox14->Text);
		TopologySchema topologySchema = createTopologySchema(int::Parse(this->textBox10->Text), toStdString(this->textBox17->Text));
		TrainingData trainingData("trainingData.txt", WRITE);
		this->textBox1->AppendText("\r\nStarting data generation\r\n");
		if (!this->checkBox4->Checked) {
			trainingData.setTopology(topologySchema);
			trainingData.generate(topologySchema, size, tStart, tEnd, points, xFunction, yFunction);
			this->textBox1->AppendText("Data generated");
		}
		else {
			this->textBox1->Text = "";
			trainingData.setTopology(topologySchema);
			do {
				stringstream ss;
				if (size > 1000) {
					ss << "Generating 1000 data... Remaining: " << size-1000 << "\r\n";
					trainingData.generate(topologySchema, 1000, tStart, tEnd, points, xFunction, yFunction);
				}
				else {
					ss << "Generating " << size << " data... Finish! :)" << "\r\n";
					trainingData.generate(topologySchema, size, tStart, tEnd, points, xFunction, yFunction);
				}
				this->textBox1->AppendText(toSystemString(ss.str()));
				this->Refresh();
				size -= 1000;
			} while (size > 0);
		}
	}

	System::Void MainForm::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->checkBox3->Enabled = this->checkBox2->Checked;
	}
}
#include "MainForm.h"
namespace biai {
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

	System::Void MainForm::Start_Click(System::Object^  sender, System::EventArgs^  e) {
		double alpha = double::Parse(this->textBox16->Text);
		double eta = double::Parse(this->textBox15->Text);
		bool draw = this->checkBox2->Checked;
		bool autoscale = this->checkBox3->Checked;
		stringstream ss;
		launchLearning(alpha, eta, ss, this->chart1->ChartAreas["area"], this->chart1->Series["error"], draw, autoscale);
		this->textBox1->Text = toSystemString(ss.str());
	}

	System::Void MainForm::OnClick_btnTest(System::Object^  sender, System::EventArgs^  e) {
		int size = int::Parse(this->textBox11->Text);
		int tStart = int::Parse(this->textBox13->Text);
		int tEnd = int::Parse(this->textBox12->Text);
		string xFunction = toStdString(this->textBox2->Text);
		string yFunction = toStdString(this->textBox3->Text);
		int points = int::Parse(this->textBox14->Text);
		bool draw = this->checkBox5->Checked;
		TopologySchema topologySchema = createTopologySchema(int::Parse(this->textBox10->Text), toStdString(this->textBox17->Text));
		stringstream ss;
		if (draw)
			button1_Click(sender, e);
		approximate(size, tStart, tEnd, ss, xFunction, yFunction, topologySchema, points, this->chart1->ChartAreas["area"], this->chart1->Series["approximate"], draw);
		this->textBox1->Text = toSystemString(ss.str());
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

		stringstream ss;
		this->textBox1->AppendText("\r\nStarting data generation\r\n");
		if (!this->checkBox4->Checked)
			createTestData(topologySchema, size, tStart, tEnd, points, xFunction, yFunction, this->textBox1, true);
		else {
			this->textBox1->Text = "";
			bool isFirst = true;
			do {
				stringstream ss;
				if (size > 1000) {
					ss << "Generating 1000 data... Remaining: " << size - 1000 << "\r\n";
					createTestData(topologySchema, 1000, tStart, tEnd, points, xFunction, yFunction, this->textBox1, isFirst);
				}
				else {
					ss << "Generating " << size << " data... Finish! :)" << "\r\n";
					createTestData(topologySchema, size, tStart, tEnd, points, xFunction, yFunction, this->textBox1, isFirst);
				}
				this->textBox1->AppendText(toSystemString(ss.str()));
				this->Refresh();
				size -= 1000;
				isFirst = false;
			} while (size > 0);
		}
		this->textBox1->AppendText("\r\ndata generation finished\r\n");
	}

	System::Void MainForm::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->checkBox3->Enabled = this->checkBox2->Checked;
	}

	System::Void MainForm::button4_Click(System::Object^  sender, System::EventArgs^  e) {
		vector<unsigned> inputs = toUnsignedIntVector(this->textBox18->Text);
		vector<string> hiddenLayers = splitByCommas(this->textBox19->Text);
		vector<TopologySchema> topologySchemas = createTopologySchemas(inputs, hiddenLayers);
		vector<unsigned> sizes = toUnsignedIntVector(this->textBox21->Text);
		vector<double> alphas = toDoubleVector(this->textBox23->Text);
		vector<double> etas = toDoubleVector(this->textBox22->Text);
		vector<unsigned> points = toUnsignedIntVector(this->textBox20->Text);
		stringstream ss;
		int tStart = int::Parse(this->textBox13->Text);
		int tEnd = int::Parse(this->textBox12->Text);
		string xFunction = toStdString(this->textBox2->Text);
		string yFunction = toStdString(this->textBox3->Text);
		string convertedXFunction = xFunction;
		string convertedYFunction = yFunction;
		replaceStrings(convertedXFunction, "*", " x "); // '*' is invalid in filename
		replaceStrings(convertedYFunction, "*", " x ");

		for (int i = 0; i < topologySchemas.size(); i++) {
			for (int j = 0; j < sizes.size(); j++) {
				for (int k = 0; k < alphas.size(); k++) {
					for (int l = 0; l < etas.size(); l++) {
						for (int m = 0; m < points.size(); m++) {
							createTestData(topologySchemas[i], sizes[j], tStart, tEnd, points[m], xFunction, yFunction, this->textBox1, true);
							launchLearning(alphas[k], etas[l], ss, this->chart1->ChartAreas["area"], this->chart1->Series["error"], false, false);
							button1_Click(sender, e);
							approximate(sizes[j], tStart, tEnd, ss, xFunction, yFunction, topologySchemas[i], points[m], this->chart1->ChartAreas["area"], this->chart1->Series["approximate"], true);
							stringstream filename;
							double a = alphas[k];
							double b = etas[l];
							filename << "xFunction " << convertedXFunction << " - yFunction " << convertedYFunction << " - topology " << toString(topologySchemas[i]);
							filename << " - Size " << sizes[j] << " - alpha " << alphas[k] << " - eta " << etas[l] << " - appr.points " << points[m];
							filename << " - tStart " << tStart << " - tEnd " << tEnd << ".png";
							string s = filename.str();
							chart1->SaveImage(toSystemString("tests results\\"+filename.str()), Imaging::ImageFormat::Png);
						}
					}
				}
			}
		}
		ss << "tests finished!";
		this->textBox1->Text = toSystemString(ss.str());
	}	
}

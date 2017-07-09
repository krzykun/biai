#include "neutralNetwork.h"

vector<double> getInputsForPoint(string xFunction, string yFunction, TopologySchema topologySchema, double t, Normalizer xNormalizer, Normalizer yNormalizer) {
	vector<double> inputs;
	for (int i = (topologySchema[0] / 2); i > 0; --i) {
		double x = xNormalizer.normalize(solve(xFunction, t - i));
		double y = yNormalizer.normalize(solve(yFunction, t - i));
		inputs.push_back(x);
		inputs.push_back(y);
	}
	return inputs;
}

void launchLearning(double alpha, double eta, stringstream& ss, System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea, System::Windows::Forms::DataVisualization::Charting::Series^ chartSeries, bool draw, bool autoscale) {
	TrainingData trainData("trainingData.txt", READ);
	TopologySchema topologySchema;
	trainData.getTopology(topologySchema);
	double maxError;
	Net myNet(topologySchema, alpha, eta);
	chartSeries->Points->Clear();

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
		if (draw) {
			chartSeries->Points->AddXY(trainingPass, error);
			if (maxError < error)
				maxError = error;
		}
	}
	if (draw && autoscale) {
		chartArea->AxisX->Minimum = 0;
		chartArea->AxisX->Maximum = trainingPass;
		chartArea->AxisX->Interval = trainingPass / 10.0;
		chartArea->AxisY->Minimum = 0;
		chartArea->AxisY->Interval = maxError / 10.0;
		chartArea->AxisY->Maximum = maxError;
	}
	myNet.save("net.txt");
}


void approximate(int size, int tStart, int tEnd, stringstream& ss, string xFunction, string yFunction, TopologySchema topologySchema, int points, System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea, System::Windows::Forms::DataVisualization::Charting::Series^ chartSeries, bool draw){
	Normalizer xNormalizer(minValue(xFunction, tStart, tEnd + points), maxValue(xFunction, tStart, tEnd + points));
	Normalizer yNormalizer(minValue(yFunction, tStart, tEnd + points), maxValue(yFunction, tStart, tEnd + points));
	Net myNet("net.txt");
	if (draw)
		chartSeries->Points->Clear();
	double xMin = chartArea->AxisX->Minimum;
	double xMax = chartArea->AxisX->Maximum;
	double yMin = chartArea->AxisY->Minimum;
	double yMax = chartArea->AxisY->Maximum;
	double xErrorSum = 0.0, yErrorSum = 0.0;
	vector<double> inputVals, resultVals;
	int pass = 0;
	//ss << "\r\n \r\n"; //if history present, uncomment this line 
	for (int i = tEnd; i < (tEnd + points); i++) {
		++pass;
		ss << "Pass" << pass << "\t\t";
		inputVals = getInputsForPoint(xFunction, yFunction, topologySchema, i, xNormalizer, yNormalizer);
		ss << showVectorVals("Inputs:", inputVals) << "\t\t";
		myNet.feedForward(inputVals);
		myNet.getResults(resultVals);
		ss << showVectorVals("Outputs:", resultVals) << "\t\t";
		ss << "x: " << xNormalizer.realValue(resultVals[0]) << "\t";
		ss << "y: " << yNormalizer.realValue(resultVals[1]) << "\t\t";
		double xError = xNormalizer.realValue(resultVals[0]) - solve(xFunction, i);
		double yError = yNormalizer.realValue(resultVals[1]) - solve(yFunction, i);
		xErrorSum += pow(xError, 2);
		yErrorSum += pow(yError, 2);
		ss << "x error:" << xError << "\t" << "y error:" << yError << "\r\n";
		double x = xNormalizer.realValue(resultVals[0]);
		double y = yNormalizer.realValue(resultVals[1]);
		if (draw) {
			chartSeries->Points->AddXY(x, y);
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
	ss << "x error square root: " << sqrt(xErrorSum / points) << "\r\n" << "y error square root: " << sqrt(yErrorSum / points);
	if (draw) {
		chartArea->AxisX->Minimum = xMin;
		chartArea->AxisX->Maximum = xMax;
		chartArea->AxisX->Interval = (xMax - xMin) / 10;
		chartArea->AxisY->Minimum = yMin;
		chartArea->AxisY->Maximum = yMax;
		chartArea->AxisY->Interval = (yMax - yMin) / 10;
	}
}

void createTestData(TopologySchema topologySchema, int size, int tStart, int tEnd, int points, string xFunction, string yFunction, System::Windows::Forms::TextBox^ textBox, bool withTopology) {
	TrainingData trainingData("trainingData.txt", WRITE);
	if(withTopology)
		trainingData.setTopology(topologySchema);
	trainingData.generate(topologySchema, size, tStart, tEnd, points, xFunction, yFunction);	
}



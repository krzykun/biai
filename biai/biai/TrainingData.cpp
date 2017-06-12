#include "TrainingData.h"

TrainingData::TrainingData(const string filename)
{
	prv_trainingDataFile.open(filename.c_str());
}

void TrainingData::getTopology(vector<unsigned> &topology)
{
	string line;
	string label;

	getline(prv_trainingDataFile, line);
	stringstream ss(line);
	ss >> label;
	if (this->isEof() || label.compare("topology:") != 0) {
		abort();
	}

	while (!ss.eof()) {
		unsigned n;
		ss >> n;
		topology.push_back(n);
	}

	return;
}

unsigned TrainingData::getNextInputs(vector<double> &inputValues)
{
	inputValues.clear();

	string line;
	getline(prv_trainingDataFile, line);
	stringstream ss(line);

	string label;
	ss >> label;
	if (label.compare("in:") == 0) {
		double oneValue;
		while (ss >> oneValue) {
			inputValues.push_back(oneValue);
		}
	}

	return inputValues.size();
}

unsigned TrainingData::getTargetOutputs(vector<double> &targetOutputValues)
{
	targetOutputValues.clear();

	string line;
	getline(prv_trainingDataFile, line);
	stringstream ss(line);

	string label;
	ss >> label;
	if (label.compare("out:") == 0) {
		double oneValue;
		while (ss >> oneValue) {
			targetOutputValues.push_back(oneValue);
		}
	}

	return targetOutputValues.size();
}
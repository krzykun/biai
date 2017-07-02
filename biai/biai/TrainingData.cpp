#include "TrainingData.h"

TrainingData::TrainingData(const string filename, OpenType opentype)
{
	if(opentype == READ)
		prv_trainingDataFile.open(filename, fstream::in);
	else if (opentype == WRITE)
		prv_trainingDataFile.open(filename, fstream::out);
	else
		abort();
}

TrainingData::~TrainingData()
{
	prv_trainingDataFile.close();
}

void TrainingData::getTopology(vector<unsigned> &topology)
{
	string line,label;
	getline(prv_trainingDataFile, line);
	stringstream ss(line);
	ss >> label;
	if (this->isEof() || label.compare("topology:") != 0)
		abort();
	while (!ss.eof()) {
		unsigned n;
		ss >> n;
		topology.push_back(n);
	}
	return;
}

void TrainingData::setTopology(TopologySchema topologySchema)
{
	prv_trainingDataFile << "topology:";
	for (int i = 0; i < topologySchema.size(); ++i)
		prv_trainingDataFile << " " << topologySchema.at(i);
	prv_trainingDataFile << endl;
}

unsigned TrainingData::getNextInputs(vector<double> &inputValues)
{
	inputValues.clear();
	string line, label;
	getline(prv_trainingDataFile, line);
	stringstream ss(line);
	ss >> label;
	if (label.compare("in:") == 0) {
		double oneValue;
		while (ss >> oneValue)
			inputValues.push_back(oneValue);
	}
	return inputValues.size();
}

unsigned TrainingData::getTargetOutputs(vector<double> &targetOutputValues)
{
	targetOutputValues.clear();
	string line, label;
	getline(prv_trainingDataFile, line);
	stringstream ss(line);
	ss >> label;
	if (label.compare("out:") == 0) {
		double oneValue;
		while (ss >> oneValue) {
			targetOutputValues.push_back(oneValue);
		}
	}
	return targetOutputValues.size();
}

void TrainingData::generate(TopologySchema topologySchema, int size, int tStart, int tEnd, string xFunction, string yFunction)
{
	Normalizer xNormalizer(minValue(xFunction, tStart, tEnd), maxValue(xFunction, tStart, tEnd));
	Normalizer yNormalizer(minValue(yFunction, tStart, tEnd), maxValue(yFunction, tStart, tEnd));
	setTopology(topologySchema);
	for (int i = 0; i < size; ++i) {
		double t = tStart + ((rand() / double(RAND_MAX)) * (tEnd - tStart));
		double delta_t = rand() / double(RAND_MAX) / 10;
		prv_trainingDataFile << "in:";
		for (int j = 0; j < (topologySchema.front() / 2); ++j) {
			prv_trainingDataFile << " " << xNormalizer.normalize(solve(xFunction, (t + j * delta_t)));
			prv_trainingDataFile << " " << yNormalizer.normalize(solve(yFunction, (t + j * delta_t)));
		}
		prv_trainingDataFile << endl << "out:";
		for (int j = 0; j < (topologySchema.back() / 2); ++j) {
			prv_trainingDataFile << " " << xNormalizer.normalize(solve(xFunction, (t + ((topologySchema.front() / 2) + j) * delta_t)));
			prv_trainingDataFile << " " << yNormalizer.normalize(solve(yFunction, (t + ((topologySchema.front() / 2) + j) * delta_t)));
		}
		prv_trainingDataFile << endl;
	};
}
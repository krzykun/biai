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

void TrainingData::generate(TopologySchema topologySchema)
{	// TODO: Create data depending on topologySchema
	setTopology(topologySchema);
	double a = rand() / double(RAND_MAX);
	double b = rand() / double(RAND_MAX);
	for (int i = 2000; i >= 0; --i) {
		double t = rand() / double(RAND_MAX);
		double delta_t = rand() / double(RAND_MAX) / 10;
		prv_trainingDataFile << "in:" << " " << a*t << " " << b*t << " " << a*(t + delta_t) << " " << b*(t + delta_t) << " " << a*(t + 2 * delta_t) << " " << b*(t + 2 * delta_t);
		prv_trainingDataFile << " " << a*(t + 3 * delta_t) << " " << b*(t + 3 * delta_t) << " " << a*(t + 4 * delta_t) << " " << b*(t + 4 * delta_t);
		prv_trainingDataFile << endl << "out: " << a*(t + 5 * delta_t) << " " << b*(t + 5 * delta_t) << "" << endl;
	};
}
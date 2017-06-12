#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class TrainingData
{
	ifstream prv_trainingDataFile;
public:
	TrainingData(const string filename);
	bool isEof(void) { return prv_trainingDataFile.eof(); }
	void getTopology(vector<unsigned> &topology);
	unsigned getNextInputs(vector<double> &inputValues);
	unsigned getTargetOutputs(vector<double> &targetOutputValues);
};
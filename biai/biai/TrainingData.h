#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

enum OpenType{READ, WRITE};

class TrainingData
{
	fstream  prv_trainingDataFile;
public:
	TrainingData(const string filename, OpenType openType);
	~TrainingData();
	bool isEof(void) { return prv_trainingDataFile.eof(); }
	void getTopology(vector<unsigned> &topology);
	void setTopology(string topology);
	unsigned getNextInputs(vector<double> &inputValues);
	unsigned getTargetOutputs(vector<double> &targetOutputValues);
	void generate();
};
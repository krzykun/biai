#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class TestData
{
	ifstream prv_trainingDataFile;
public:
	TestData(const string filename);
	bool isEof(void) { return prv_trainingDataFile.eof(); }

};


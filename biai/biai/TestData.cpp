#include "TestData.h"

TestData::TestData(const string filename)
{
	prv_trainingDataFile.open(filename.c_str());
}
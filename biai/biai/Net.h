#pragma once
#include <cassert>
#include <fstream>
#include "Topology.h"

using namespace std;

class Net
{
public:
	Net(const TopologySchema &topologySchema, double alpha, double eta);
	Net(string fileName);
	~Net();
	void feedForward(const vector<double> &inputValues);
	void backProp(const vector<double> &targetValues);
	void getResults(vector<double> &resultValues) const;
	double getRecentAverageError(void) const { return prv_recentAverageError; }
	void save(string filename);
private:
	Topology topology;
	double prv_error;
	double prv_recentAverageError;
	double prv_recentAverageSmoothingFactor;
};
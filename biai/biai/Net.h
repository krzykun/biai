#pragma once
#include <cassert>
#include "Topology.h"

using std::vector;

class Net
{
public:
	Net(const TopologySchema &topologySchema);
	~Net();
	void feedForward(const vector<double> &inputValues);
	void backProp(const vector<double> &targetValues);
	void getResults(vector<double> &resultValues) const;
	double getRecentAverageError(void) const { return prv_recentAverageError; }
private:
	Topology topology;
	double prv_error;
	double prv_recentAverageError;
	double prv_recentAverageSmoothingFactor;
};


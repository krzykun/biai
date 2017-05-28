#pragma once
#include <Vector>
#include <cassert>
#include "Neuron.h"

using std::vector;

typedef vector<Neuron> Layer;

class Net
{
public:
	Net(const vector<unsigned> &topology);
	~Net();
	void feedForward(const vector<double> &inputValues);
	void backProp(const vector<double> &targetValues);
	void getResults(vector<double> resultValues) const;
	double getRecentAverageError(void) const { return prv_recentAverageError; }
private:
	vector<Layer> prv_layers;
	double prv_error;
	double prv_recentAverageError;
	double prv_recentAverageSmoothingFactor;
};


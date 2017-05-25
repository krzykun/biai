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
private:
	vector<Layer> prv_layers;
};


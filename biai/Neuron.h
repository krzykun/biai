#pragma once
#include <iostream>
#include <vector>
#include <cmath>

#include "Connection.h"

using std::vector;
using std::cout;
using std::endl;

extern const bool isDebug;

class Neuron;

typedef vector<Neuron> Layer;

class Neuron
{
	const unsigned prv_myIndex;
	double prv_outputValue;
	vector<Connection> prv_outputWeights;
	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
public:
	Neuron(unsigned howManyOutputs, const unsigned _myIndex);
	~Neuron();
	void setOutputValue(double outValue) { prv_outputValue = outValue; }
	double getOutputValue(void) const { return prv_outputValue; }
	void feedForward(const Layer &previousLayer);

};


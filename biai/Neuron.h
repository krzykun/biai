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
	double prv_gradient;
public:
	Neuron(unsigned howManyOutputs, const unsigned _myIndex);
	~Neuron();
	void setOutputValue(double outValue) { prv_outputValue = outValue; }
	double getOutputValue(void) const { return prv_outputValue; }
	void feedForward(const Layer &previousLayer);
	void calcOutputGradients(double targetValue);
	void calcHiddenGradients(const Layer &nextLayer);
	double sumDOW(const Layer &nextLayer) const;
	void updateInputWeights(Layer &prevLayer);
	//all neurons use the same value:
	static double alpha;	//0.0 - n multiplier of the last weight change (momentum)
	static double eta; //0.0 - 1.0 training rate
	static double randomWeight(void) { return rand() / double(RAND_MAX); }
};
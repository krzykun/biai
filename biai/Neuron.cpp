#include "Neuron.h"

Neuron::Neuron(unsigned howManyOutputs, const unsigned _myIndex) : prv_myIndex(_myIndex)
{
	for (unsigned con = 0; con < howManyOutputs; ++con)
	{
		prv_outputWeights.push_back(Connection());
	}
	if (isDebug)
	{
		cout << "Made a neuron with weight: " << prv_outputValue << endl;
	}
	
}


Neuron::~Neuron()
{
}


void Neuron::feedForward(const Layer &prevLayer)
{
	double sum = 0.0;

	for (unsigned whichNeuron = 0; whichNeuron < prevLayer.size(); ++whichNeuron)
	{
		sum += prevLayer[whichNeuron].getOutputValue() * prevLayer[whichNeuron].prv_outputWeights[prv_myIndex].weight;
	}

	prv_outputValue = Neuron::transferFunction(sum);
}


double Neuron::transferFunction(double x)
{
	//TODO Check other transfer functions
	return tanh(x);
}


double Neuron::transferFunctionDerivative(double x)
{
	return 1.0 - x*x;
}
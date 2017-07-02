#include "Neuron.h"

Neuron::Neuron(unsigned howManyOutputs, const unsigned _myIndex) : prv_myIndex(_myIndex)
{
	for (unsigned con = 0; con < howManyOutputs; ++con)
	{
		prv_outputWeights.push_back(Connection());
		prv_outputWeights.back().weight = randomWeight();
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
	//TODO: Check other transfer functions
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	return 1.0 - x*x;
}

void Neuron::calcOutputGradients(double targetValue)
{
	double delta = targetValue - prv_outputValue;
	prv_gradient = delta * Neuron::transferFunctionDerivative(prv_outputValue);
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
	double dow = sumDOW(nextLayer);
	prv_gradient = dow * Neuron::transferFunctionDerivative(prv_outputValue);
}

double Neuron::sumDOW(const Layer &nextLayer) const
{
	double sum = 0.0;

	//sum our contributions of the errors at the nodes we feed

	for (unsigned whichNeuron = 0; whichNeuron < nextLayer.size() - 1; ++whichNeuron)
	{
		sum += prv_outputWeights[whichNeuron].weight * nextLayer[whichNeuron].prv_gradient;
	}

	return sum;
}

void Neuron::updateInputWeights(Layer &prevLayer)
{
	// The weights to be updated are in the Connection container
	// in the neurons in the preceding layer

	for (unsigned whichNeuron = 0; whichNeuron < prevLayer.size(); ++whichNeuron)
	{
		Neuron &neuron = prevLayer[whichNeuron];
		double oldDeltaWeight = neuron.prv_outputWeights[prv_myIndex].deltaWeight;

		double newDeltaWeight =
			eta //train rate
			* neuron.getOutputValue() //individual input
			* prv_gradient
			//a fraction of the previous delta weight
			+ alpha //momentum
			* oldDeltaWeight;

		neuron.prv_outputWeights[prv_myIndex].deltaWeight = newDeltaWeight;
		neuron.prv_outputWeights[prv_myIndex].weight += newDeltaWeight;
	}
}

double Neuron::alpha = 0.5;
double Neuron::eta = 0.15;

string Neuron::toString() {
	stringstream ss;
	ss << prv_myIndex << " " << prv_outputValue << " " << prv_gradient;
	for (int i = 0; i < prv_outputWeights.size(); i++)
		ss << " " << prv_outputWeights[i].weight << " " << prv_outputWeights[i].deltaWeight;
	ss << endl;
	return ss.str();
}
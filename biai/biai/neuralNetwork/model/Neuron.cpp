#include "Neuron.h"

Neuron::Neuron(unsigned howManyOutputs, const unsigned _myIndex, double _alpha, double _eta) : prv_myIndex(_myIndex), alpha(_alpha), eta(_eta)
{
	for (unsigned con = 0; con < howManyOutputs; ++con)	{
		prv_outputWeights.push_back(Connection());
		prv_outputWeights.back().weight = randomWeight();
	}
	if (isDebug)
		cout << "Made a neuron with weight: " << prv_outputValue << endl;
}

Neuron::~Neuron()
{
}


void Neuron::feedForward(const Layer &prevLayer)
{
	double sum = 0.0;
	for (unsigned whichNeuron = 0; whichNeuron < prevLayer.size(); ++whichNeuron)
		sum += prevLayer[whichNeuron].getOutputValue() * prevLayer[whichNeuron].prv_outputWeights[prv_myIndex].weight;
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
	double sum = 0.0;	//sum our contributions of the errors at the nodes we feed
	for (unsigned whichNeuron = 0; whichNeuron < nextLayer.size() - 1; ++whichNeuron)
		sum += prv_outputWeights[whichNeuron].weight * nextLayer[whichNeuron].prv_gradient;
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

string Neuron::toString() {
	stringstream ss;
	ss << prv_myIndex << " " << prv_outputValue << " " << prv_gradient;
	for (int i = 0; i < prv_outputWeights.size(); i++)
		ss << " " << prv_outputWeights[i].weight << " " << prv_outputWeights[i].deltaWeight;
	ss << endl;
	return ss.str();
}

void Neuron::update(vector<double> values) {
	if (prv_myIndex != values[0])
		abort();
	prv_outputValue = values[1];
	prv_gradient = values[2];
	for (int i = 0; i < prv_outputWeights.size(); ++i) {
		int a = values.size();
		int b = 2 * i + 4;
		int c = prv_outputWeights.size();
		prv_outputWeights[i].weight = values[2*i+3];
		prv_outputWeights[i].deltaWeight = values[2*i+4];
	}
}
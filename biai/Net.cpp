#include "Net.h"

Net::Net(const vector<unsigned> &topology)
{
	unsigned howManyLayers = topology.size();
	for (unsigned layerIter = 0; layerIter < howManyLayers; ++layerIter)
	{
		prv_layers.push_back(Layer());
		unsigned howManyOutputs = layerIter == topology.size() - 1 ? 0 : topology[layerIter + 1];
		for (unsigned neuronIter = 0; neuronIter <= topology[layerIter]; ++neuronIter)
		{
//			if ((layerIter != howManyLayers - 1) || (neuronIter != topology[layerIter]))
//			{
				prv_layers.back().push_back(Neuron(howManyOutputs, neuronIter));
//			}
//			else
//				cout << "I'm not creating useless neurons.\n";
		}
		prv_layers.back().back().setOutputValue(1.0);
	}
}


Net::~Net()
{
}

void Net::feedForward(const vector<double> &inputValues)
{
	assert(inputValues.size() == prv_layers[0].size() - 1);

	for (unsigned whichInput = 0; whichInput < inputValues.size(); ++whichInput)
	{
		prv_layers[0][whichInput].setOutputValue(inputValues[whichInput]);
	}

	for (unsigned whichLayer = 1; whichLayer < prv_layers.size(); ++whichLayer)
	{
		Layer &previousLayer = prv_layers[whichLayer - 1];
		for (unsigned whichNeuron = 0; whichNeuron < prv_layers[whichLayer].size() - 1; ++whichNeuron)
		{
			prv_layers[whichLayer][whichNeuron].feedForward(previousLayer);
		}
	}
}

void Net::backProp(const vector<double> &targetValues)
{
	//TODO try different backProp schemas
	Layer &outputLayer = prv_layers.back();
	prv_error = 0.0;

	for (unsigned whichNeuron = 0; whichNeuron < outputLayer.size() - 1; ++whichNeuron)
	{
		double delta = targetValues[whichNeuron] - outputLayer[whichNeuron].getOutputValue();
		prv_error += delta*delta;
	}
	prv_error /= outputLayer.size() - 1; //average error squared
	prv_error = sqrt(prv_error);

	// Implement a recent average measurement

	prv_recentAverageError = (prv_recentAverageError * prv_recentAverageSmoothingFactor + prv_error) / (prv_recentAverageSmoothingFactor + 1.0);

	//calculate output layer gradients

	for (unsigned whichNeuron = 0; whichNeuron < outputLayer.size() - 1; ++whichNeuron)
	{
		outputLayer[whichNeuron].calcOutputGradients(targetValues[whichNeuron]);
	}
	
	//Calculate gradients on hidden layers

	for (unsigned whichLayer = prv_layers.size() - 2; whichLayer > 0; --whichLayer)
	{
		Layer &hiddenLayer = prv_layers[whichLayer];
		Layer &nextLayer = prv_layers[whichLayer + 1];	//convenience vars for debug later

		for (unsigned whichNeuron = 0; whichNeuron < hiddenLayer.size(); ++whichNeuron)
		{
			hiddenLayer[whichNeuron].calcHiddenGradients(nextLayer);
		}
	}

	//For all layers from outputs to first hidden layer
	// update connection weights

	for (unsigned whichLayer = prv_layers.size() - 1; whichLayer > 0; --whichLayer)
	{
		Layer &layer = prv_layers[whichLayer];
		Layer &prevLayer = prv_layers[whichLayer - 1];

		for (unsigned whichNeuron = 0; whichNeuron < layer.size() - 1; ++whichNeuron)
		{
			layer[whichNeuron].updateInputWeights(prevLayer);
		}
	}
}

void Net::getResults(vector<double> resultValues) const
{
	resultValues.clear();

	for (unsigned whichNeuron = 0; whichNeuron < prv_layers.back().size() - 1; ++whichNeuron)
	{
		resultValues.push_back(prv_layers.back()[whichNeuron].getOutputValue());
	}
}
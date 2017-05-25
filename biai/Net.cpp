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
			if ((layerIter != howManyLayers - 1) || (neuronIter != topology[layerIter]))
			{
				prv_layers.back().push_back(Neuron(howManyOutputs, neuronIter));
			}
			else
				cout << "I'm not creating useless neurons.\n";
		}
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

}

void Net::getResults(vector<double> resultValues) const
{

}
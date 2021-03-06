#include "Net.h"

Net::Net(const TopologySchema &topologySchema, double alpha, double eta)
{
	topology = createTopology(topologySchema, alpha, eta);
}

Net::Net(string filename)
{
	fstream file;
	file.open(filename, fstream::in);
	topology = createTopology(getTopologySchemaFromFile(file));
	for (int i = 0; i < topology.size(); ++i)
		for (int j = 0; j < topology[i].size(); ++j) {
			string line;
			getline(file, line);
			topology[i][j].update(toDoubleVector(line));
		}
	file.close();
}

Net::~Net()
{
}

void Net::feedForward(const vector<double> &inputValues)
{
	assert(inputValues.size() == topology[0].size() - 1);
	for (unsigned whichInput = 0; whichInput < inputValues.size(); ++whichInput)
		topology[0][whichInput].setOutputValue(inputValues[whichInput]);
	for (unsigned whichLayer = 1; whichLayer < topology.size(); ++whichLayer)
	{
		Layer &previousLayer = topology[whichLayer - 1];
		for (unsigned whichNeuron = 0; whichNeuron < topology[whichLayer].size() - 1; ++whichNeuron)
			topology[whichLayer][whichNeuron].feedForward(previousLayer);
	}
}

void Net::backProp(const vector<double> &targetValues)
{
	//TODO try different backProp schemas
	Layer &outputLayer = topology.back();
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
		outputLayer[whichNeuron].calcOutputGradients(targetValues[whichNeuron]);
	
	//Calculate gradients on hidden layers

	for (unsigned whichLayer = topology.size() - 2; whichLayer > 0; --whichLayer)
	{
		Layer &hiddenLayer = topology[whichLayer];
		Layer &nextLayer = topology[whichLayer + 1];	//convenience vars for debug later
		for (unsigned whichNeuron = 0; whichNeuron < hiddenLayer.size(); ++whichNeuron)
			hiddenLayer[whichNeuron].calcHiddenGradients(nextLayer);
	}

	//For all layers from outputs to first hidden layer
	// update connection weights

	for (unsigned whichLayer = topology.size() - 1; whichLayer > 0; --whichLayer)
	{
		Layer &layer = topology[whichLayer];
		Layer &prevLayer = topology[whichLayer - 1];
		for (unsigned whichNeuron = 0; whichNeuron < layer.size() - 1; ++whichNeuron)
			layer[whichNeuron].updateInputWeights(prevLayer);
	}
}

void Net::getResults(vector<double> &resultValues) const
{
	resultValues.clear();
	for (unsigned whichNeuron = 0; whichNeuron < topology.back().size() - 1; ++whichNeuron)
		resultValues.push_back(topology.back()[whichNeuron].getOutputValue());
}

void Net::save(string filename) {
	fstream file;
	file.open(filename, fstream::out);	
	file << toString(toTopologySchema(topology)) << endl;
	for (int i = 0; i < topology.size(); ++i)
		for (int j = 0; j < topology[i].size(); ++j)
			file << topology[i][j].toString(); // print every neuron
	file.close();
}
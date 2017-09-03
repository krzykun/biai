#include "Topology.h"

Topology createTopology(TopologySchema topologySchema, double alpha, double eta) {
	Topology topology;
	unsigned howManyLayers = topologySchema.size();
	for (unsigned layerIter = 0; layerIter < howManyLayers; ++layerIter)
	{
		topology.push_back(Layer());
		unsigned howManyOutputs = layerIter == topologySchema.size() - 1 ? 0 : topologySchema[layerIter + 1];
		for (unsigned neuronIter = 0; neuronIter <= topologySchema[layerIter]; ++neuronIter)
			topology.back().push_back(Neuron(howManyOutputs, neuronIter, alpha, eta));
		topology.back().back().setOutputValue(1.0);
	}
	return topology;
}

Topology createTopology(TopologySchema topologySchema) {
	double alpha = 0.5;
	double eta = 0.15;
	return createTopology(topologySchema, alpha, eta);
}

TopologySchema createTopologySchema(string topologySchemaString) {
	string s = topologySchemaString;
	vector<string> layers = splitBySpaces(topologySchemaString);
	TopologySchema topologySchema;
	for (int i = 0; i < layers.size(); ++i) {
		int a = atoi(layers.at(i).c_str());
		topologySchema.push_back(a);
	}
	return topologySchema;
}

TopologySchema createTopologySchema(int inputPoints, string hiddenLayers) {
	stringstream ss;
	ss << inputPoints*2 << " " << hiddenLayers << " 2";
	return createTopologySchema(ss.str());
}

vector<TopologySchema> createTopologySchemas(vector<unsigned> inputs, vector<string> hiddenLayers) {
	vector<TopologySchema> topologySchemas;
	for (int i = 0; i < inputs.size(); i++)
		for (int j = 0; j < hiddenLayers.size(); j++)
			topologySchemas.push_back(createTopologySchema(inputs[i], hiddenLayers[j]));
	return topologySchemas;
}

TopologySchema getTopologySchemaFromFile(fstream &file) {
	string line;
	getline(file, line);
	return toUnsignedIntVector(line);
}

string toString(TopologySchema topologySchema) {
	stringstream ss;
	auto a = topologySchema.size();
	if (topologySchema.size() == 0)
		abort();
	ss << topologySchema[0];
	for (int i = 1; i < topologySchema.size(); ++i) {
		ss << " " << topologySchema[i];
	}
	return ss.str();
}

TopologySchema toTopologySchema(Topology topology) {
	TopologySchema topologySchema;
	for (int i = 0; i < topology.size(); i++)
		topologySchema.push_back(topology[i].size()-1);
	return topologySchema;
}
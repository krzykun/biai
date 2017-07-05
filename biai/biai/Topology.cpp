#include "Topology.h"

Topology createTopology(TopologySchema topologySchema, double alpha, double eta) {
	Topology topology;
	unsigned howManyLayers = topologySchema.size();
	for (unsigned layerIter = 0; layerIter < howManyLayers; ++layerIter)
	{
		topology.push_back(Layer());
		unsigned howManyOutputs = layerIter == topologySchema.size() - 1 ? 0 : topologySchema[layerIter + 1];
		auto a = topologySchema[layerIter];
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
	vector<string> layers = splitString(topologySchemaString);
	TopologySchema topologySchema;
	for (int i = 0; i < layers.size(); ++i) {
		int a = atoi(layers.at(i).c_str());
		topologySchema.push_back(a);
	}
	return topologySchema;
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
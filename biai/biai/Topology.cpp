#include "Topology.h"

Topology createTopology(TopologySchema topologySchema) {
	Topology topology;
	unsigned howManyLayers = topologySchema.size();
	for (unsigned layerIter = 0; layerIter < howManyLayers; ++layerIter)
	{
		topology.push_back(Layer());
		unsigned howManyOutputs = layerIter == topologySchema.size() - 1 ? 0 : topologySchema[layerIter + 1];
		for (unsigned neuronIter = 0; neuronIter <= topologySchema[layerIter]; ++neuronIter)
			topology.back().push_back(Neuron(howManyOutputs, neuronIter));
		topology.back().back().setOutputValue(1.0);
	}
	return topology;
}

TopologySchema createTopologySchema(string topologySchemaString) {
	string s = topologySchemaString;
	vector<std::string> layers;
	splitString(topologySchemaString, layers);	
	TopologySchema topologySchema;
	for (int i = 0; i < layers.size(); ++i){
		int a = atoi(layers.at(i).c_str());
		topologySchema.push_back(a);
	}
	return topologySchema;
}

#pragma once
#include "Neuron.h"
#include "../../common/StringHelper.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

typedef vector<unsigned> TopologySchema;
typedef vector<Neuron> Layer;
typedef vector<Layer> Topology;

Topology createTopology(TopologySchema topologySchema, double alpha, double eta);
Topology createTopology(TopologySchema topologySchema);
TopologySchema createTopologySchema(string topologySchemaString);
TopologySchema createTopologySchema(int inputPoints, string hiddenLayers);
TopologySchema getTopologySchemaFromFile(fstream &file);
vector<TopologySchema> createTopologySchemas(vector<unsigned> inputs, vector<string> hiddenLayers);
string toString(TopologySchema);
TopologySchema toTopologySchema(Topology topology);
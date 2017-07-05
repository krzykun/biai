#pragma once
#include "Neuron.h"
#include "StringHelper.h"
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
TopologySchema getTopologySchemaFromFile(fstream &file);
string toString(TopologySchema);
TopologySchema toTopologySchema(Topology topology);
#pragma once
#include "Neuron.h"
#include "StringHelper.h"
#include <vector>
#include <string>
using namespace std;

typedef vector<unsigned> TopologySchema;
typedef vector<Neuron> Layer;
typedef vector<Layer> Topology;

Topology createTopology(TopologySchema topologySchema);
TopologySchema createTopologySchema(string topologySchemaString);
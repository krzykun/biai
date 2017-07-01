#pragma once
#include "Neuron.h"
#include <Vector>
using std::vector;

typedef vector<unsigned> TopologySchema;
typedef vector<Neuron> Layer;
typedef vector<Layer> Topology;

Topology createTopology(TopologySchema topologySchema);
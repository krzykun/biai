// biai.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <conio.h>

#include "stdafx.h"
#include "Net.h"
#include "Neuron.h"

using std::vector;
using std::cout;
using std::cin;

const bool isDebug = 1;
typedef vector<Neuron> Layer;

int main()
{
	vector<unsigned> topology;

	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);

	Net net = Net(topology);
	_getch();
    return 0;
}


#include <stdio.h>
#include <iostream>
#include <vector>
#include <conio.h>

#include "stdafx.h"
#include "Net.h"
#include "Neuron.h"
#include "TrainingData.h"

using std::vector;
using std::cout;
using std::cin;

const bool isDebug = 1;

void showVectorVals(string label, vector<double> &v)
{
	cout << label << " ";
	for (unsigned i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}

	cout << endl;
}

int main()
{
	TrainingData trainData("trainingData.txt");

	// e.g., { 3, 2, 1 }
	vector<unsigned> topology;
	trainData.getTopology(topology);

	Net myNet(topology);

	vector<double> inputVals, targetVals, resultVals;
	int trainingPass = 0;

	while (!trainData.isEof()) {
		if (trainingPass % 500 ==0)
			cout << "aa:";
		++trainingPass;
		cout << endl << "Pass " << trainingPass;

		// Get new input data and feed it forward:
		if (trainData.getNextInputs(inputVals) != topology[0]) {
			break;
		}
		showVectorVals(": Inputs:", inputVals);
		myNet.feedForward(inputVals);

		// Collect the net's actual output results:
		myNet.getResults(resultVals);
		showVectorVals("Outputs:", resultVals);

		// Train the net what the outputs should have been:
		trainData.getTargetOutputs(targetVals);
		showVectorVals("Targets:", targetVals);
		assert(targetVals.size() == topology.back());

		myNet.backProp(targetVals);

		// Report how well the training is working, average over recent samples:
		cout << "Net recent average error: "
			<< myNet.getRecentAverageError() << endl;
	}

	cout << endl << "Done" << endl;
	_getch();
}
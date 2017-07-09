#pragma once
#include "model/Net.h"
#include "model/Neuron.h"
#include "model/TrainingData.h"
#include "../common/expression/Expression.h"


vector<double> getInputsForPoint(string xFunction, string yFunction, int inputPoints, string hiddenLayers, double t, Normalizer xNormalizer, Normalizer yNormalizer);
void approximate(int size, int tStart, int tEnd, stringstream& ss, string xFunction, string yFunction, TopologySchema topologySchema, int points, System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea, System::Windows::Forms::DataVisualization::Charting::Series^ chartSeries, bool draw);
void launchLearning(double alpha, double eta, stringstream& ss, System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea, System::Windows::Forms::DataVisualization::Charting::Series^ chartSeries, bool draw, bool autoscale);
void createTestData(TopologySchema topologySchema, int size, int tStart, int tEnd, int points, string xFunction, string yFunction, System::Windows::Forms::TextBox^ textBox, bool withTopology);
// TrainingDataGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	ofstream file;
	file.open("trainingData.txt");

	// XOR for tests
	
	file << "topology: 2 4 1" << endl;
	for (int i = 2000; i >= 0; --i) {
		int a = (int)(2.0* rand() / double(RAND_MAX));
		int b = (int)(2.0* rand() / double(RAND_MAX));
		int c = a ^ b;
		file << "in: " << a << ".0 " << b << ".0" << endl;
		file << "out: " << c << ".0" << endl;
	}

	file.close();	
	return 0;
}


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

	enum generateData { XOR, XYcoordinates, Ycoordinate	};
	ofstream file;
	file.open("trainingData.txt");

	generateData whatShouldIGenerate = Ycoordinate;


	if (whatShouldIGenerate == XOR) {
		file << "topology: 2 4 1" << endl;
		for (int i = 2000; i >= 0; --i) {
			int a = (int)(2.0* rand() / double(RAND_MAX));
			int b = (int)(2.0* rand() / double(RAND_MAX));
			int c = a ^ b;
			file << "in: " << a << ".0 " << b << ".0" << endl;
			file << "out: " << c << ".0" << endl;
		}
	}
	else if (whatShouldIGenerate == XYcoordinates) {

	}
	else if (whatShouldIGenerate == Ycoordinate) {
		file << "topology: 5 4 4 1" << endl;
		double a = rand() / double(RAND_MAX) / 10;
		for (int i = 2000; i >= 0; --i) {
			double y1 = rand() / double(RAND_MAX);
			file << "in: " << y1 << " " << (y1 + a) << " " << (y1 + 2 * a) << " " << (y1 + 3 * a) << " " << (y1 + 4 * a) << "" << endl;
			file << "out: " << (y1 + 5 * a) << "" << endl;
		}
	}


	file.close();
	return 0;
}


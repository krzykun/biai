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

	generateData whatShouldIGenerate = XYcoordinates;


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
		file << "topology: 8 8 8 2" << endl;
		double a = rand() / double(RAND_MAX);
		double b = rand() / double(RAND_MAX);
		for (int i = 2000; i >= 0; --i) {
			double t = rand() / double(RAND_MAX);
			double delta_t = rand() / double(RAND_MAX) / 10;
			file << "in:" << " " << a*t << " " << b*t << " " << a*(t+delta_t) << " " << b*(t + delta_t) << " " << a*(t + 2*delta_t) << " " << b*(t + 2*delta_t);
			file << " " << a*(t + 3*delta_t) << " " << b*(t + 3 * delta_t) << " " << a*(t + 4 * delta_t) << " " << b*(t + 4 * delta_t);
			file << endl << "out: " << a*(t + 5 * delta_t) << " " << b*(t + 5 * delta_t) << "" << endl;
		}
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


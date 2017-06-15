// TrainingDataGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double normalize(double x, double range)
{
	return x / range;
}

int main()
{

	enum generateData { XOR, XYcoordinates };
	ofstream datafile;
	ofstream testfile;
	datafile.open("trainingCoordinates.txt");

	generateData whatShouldIGenerate = XYcoordinates;

	datafile << "topology: 2 4 1" << endl;

	if (whatShouldIGenerate == XOR) {
		// XOR for tests

		for (int i = 2000; i >= 0; --i) {
			int a = (int)(2.0* rand() / double(RAND_MAX));
			int b = (int)(2.0* rand() / double(RAND_MAX));
			int c = a ^ b;
			datafile << "in: " << a << ".0 " << b << ".0" << endl;
			datafile << "out: " << c << ".0" << endl;
		}
	}
	else
		if (whatShouldIGenerate == XYcoordinates) {
			// Lets assume that we are doing our calcultaions in 100x100 unit space.
			//http://www.cplusplus.com/reference/random/ might be a good idea to implement here
			// for now lets also assume, that the speed is 1 unit for a measurement period

			int a = 0;
			int range_x = 100;
			int range_y = 100;

			for (a = 0; a < 100; a++)
			{
				double new_x = a;
				double new_y = a;
				double next_y = a + 1;
				//double new_x = (static_cast<double> (rand() % 10001)) / 100; //0 - 100 is our range, and we assume 2 decimal places

				if ((a % 5) == 0) // 20 tearning, 80 test
				{
					datafile << "in: " << normalize(new_x, range_x) << " " << normalize(new_y, range_y) << endl;
					datafile << "out: " << normalize(a + 1, range_x) << " " << normalize(next_y, range_y) << endl;
					cout << "in: " << normalize(new_x, range_x) << " " << normalize(new_y, range_y) << endl;
					cout << "out: " << normalize(a + 1, range_x) << " " << normalize(next_y, range_y) << endl;
				}
				else
				{
					testfile << "in: " << normalize(new_x, range_x) << " " << normalize(new_y, range_y) << endl;
					testfile << "out: " << normalize(a + 1, range_x) << " " << normalize(next_y, range_y) << endl;
					cout << "in: " << normalize(new_x, range_x) << " " << normalize(new_y, range_y) << endl;
					cout << "out: " << normalize(a + 1, range_x) << " " << normalize(next_y, range_y) << endl;
				}
			}
		}

	char wait;
	cin >> wait;
	datafile.close();	
	return 0;
}


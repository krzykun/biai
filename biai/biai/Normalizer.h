#pragma once

using namespace std;

class Normalizer
{
	double scale;
	double minValue;
public:
	Normalizer(double minValue, double maxValue);
	Normalizer(double scale);
	double normalize(double realValue);
	double realValue(double normalizedValue);
};
#include "Normalizer.h"

Normalizer::Normalizer(double scale) : scale(scale), minValue(0) {}

Normalizer::Normalizer(double minValue, double maxValue) : scale(maxValue - minValue), minValue(minValue) {}

double Normalizer::normalize(double realValue) {
	double normalizedValue = (realValue - minValue) / scale;
	if (normalizedValue < 0 || normalizedValue > 1)
		return -1;
	return normalizedValue;
}

double Normalizer::realValue(double normalizedValue) {
	if (normalizedValue < 0 || normalizedValue > 1)
		return -1;
	return (normalizedValue * scale) + minValue;
}
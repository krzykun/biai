#include "Expression.h"

string replaceParameterT(Function expression, double parameter) {
	stringstream ss;
	ss << parameter;
	replaceStrings(expression, "t", ss.str());
	return expression;
}

double solve(Function expression, double parameterT) {
	expression = replaceParameterT(expression, parameterT);
	ostringstream ss;
	Parser prs;
	ss << prs.parse(expression.c_str());
	string str = ss.str();
	str.erase(0, 6); // Parser returns " Ans = "
	return atof(str.c_str());
}

double maxValue(Function function, int tStart, int tEnd) {
	double maxValue = solve(function, tStart);
	for (int i = tStart + 1; i < tEnd; i++)
		if (maxValue < solve(function, i))
			maxValue = solve(function, i);
	return maxValue;
}

double minValue(Function function, int tStart, int tEnd) {
	double minValue = solve(function, tStart);
	for (int i = tStart + 1; i < tEnd; i++)
		if (minValue > solve(function, i))
			minValue = solve(function, i);
	return minValue;
}
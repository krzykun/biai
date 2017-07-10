#include "Expression.h"

string replaceParameterT(Function expression, double parameter) {
	stringstream ss;
	ss << parameter;
	replaceStrings(expression, "t", ss.str());
	return expression;
}

string solveBrackets(Function expression) {
	size_t firstPos = expression.find('(');
	size_t lastPos = expression.find_last_of(')');
	string front = expression, inner = expression, end = expression;
	front.erase(firstPos, expression.length() - firstPos);
	inner.erase(lastPos, expression.length() - lastPos);
	inner.erase(0, firstPos+1);
	end.erase(0, lastPos+1);
	double innerResult = solve(inner);
	stringstream ss;
	ss << front << innerResult << end;
	return ss.str();
}

double solve(Function expression) {
	if(expression.find('(')!= string::npos)
		expression = solveBrackets(expression);
	ostringstream ss;
	Parser prs;
	ss << prs.parse(expression.c_str());
	string str = ss.str();
	str.erase(0, 6); // Parser returns " Ans = "
	return atof(str.c_str());
}

double solve(Function expression, double parameterT) {
	expression = replaceParameterT(expression, parameterT);
	return solve(expression);
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
#include "Expression.h"

Function replaceParameterT(Function expression, double parameter) {
	stringstream ss;
	ss << parameter;
	replaceStrings(expression, "t", ss.str());
	return expression;
}

Function commonFunctions(Function expression) {
	int positions[5];
	positions[0] = expression.find('s');
	positions[1] = expression.find('c');
	positions[2] = expression.find('a');
	positions[3] = expression.find('l');
	positions[4] = expression.find('t');
	int start = 999999;
	for (int i = i; i < (sizeof(positions)/sizeof(*positions)); i++)
		if (start > positions[i] && positions[i] >= 0) // position==-1 for not matched
			start = positions[i];
	size_t finish = expression.find_last_of(')');
	string front = expression, inner = expression, end = expression;
	front.erase(start, expression.length() - start);
	inner.erase(finish, expression.length() - finish);
	inner.erase(0, start + 4);
	end.erase(0, finish + 1);
	double innerResult = solve(inner);
	if(start == positions[0])
		innerResult = sin(innerResult);
	if (start == positions[1])
		innerResult = cos(innerResult);
	if (start == positions[2])
		innerResult = abs(innerResult);
	if (start == positions[3])
		innerResult = log(innerResult);
	if (start == positions[4])
		innerResult = tan(innerResult);
	stringstream ss;
	ss << front << innerResult << end;
	return ss.str();
}

Function solveBrackets(Function expression) {
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
	if ((expression.find('s') != string::npos) || (expression.find('c') != string::npos) || (expression.find('a') != string::npos) || (expression.find('l') != string::npos) || (expression.find('t') != string::npos))
		expression = commonFunctions(expression);
	if(expression.find('(') != string::npos)
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
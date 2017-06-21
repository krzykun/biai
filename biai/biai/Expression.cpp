#include "Expression.h"

void replaceStrings(std::string& str, const std::string& toReplace, const std::string& replacer) {
	std::string::size_type n = 0;
	while ((n = str.find(toReplace, n)) != std::string::npos)
	{
		str.replace(n, toReplace.size(), replacer);
		n += replacer.size();
	}
}

string replaceParameterT(string expression, double parameter) {
	stringstream ss;
	ss << parameter;
	replaceStrings(expression, "t", ss.str());
	return expression;
}

double solve(string expression, double parameterT) {
	expression = replaceParameterT(expression, parameterT);
	ostringstream ss;
	Parser prs;
	ss << prs.parse(expression.c_str());
	string str = ss.str();
	str.erase(0, 6); // Parser returns " Ans = "
	return atof(str.c_str());
}


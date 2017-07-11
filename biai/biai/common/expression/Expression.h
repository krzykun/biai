#pragma once
#include "expression_parser_cpp/parser.h"
#include "../StringHelper.h"
#include <sstream>  
#include <string>
#include <algorithm>

using namespace::std;
typedef string Function;

void replaceStrings(const std::string& str, const std::string& toReplace, const std::string& replacer);
Function replaceParameterT(Function expression, double parameter);
Function commonFunctions(Function expression); // sin, cos, abs, tan, log - valid: sin(cos(tan(log(abs(x))) - invalid: sin(x) + cos(y)
Function solveBrackets(Function expression);
double solve(Function expression);
double solve(Function expression, double parameterT);
double maxValue(Function function, int tStart, int tEnd);
double minValue(Function function, int tStart, int tEnd);
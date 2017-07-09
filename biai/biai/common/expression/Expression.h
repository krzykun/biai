#pragma once
#include "expression_parser_cpp/parser.h"
#include "../StringHelper.h"
#include <sstream>  
#include <string>
#include <algorithm>

using namespace::std;
typedef string Function;

void replaceStrings(const std::string& str, const std::string& toReplace, const std::string& replacer);
string replaceParameterT(Function expression, double parameter);
double solve(Function expression, double parameterT);
double maxValue(Function function, int tStart, int tEnd);
double minValue(Function function, int tStart, int tEnd);
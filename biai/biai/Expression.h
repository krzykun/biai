#pragma once
#include <sstream>  
#include <string>
#include <algorithm>
#include "expression_parser_cpp/parser.h"
using namespace::std;

void replaceStrings(const std::string& str, const std::string& toReplace, const std::string& replacer);
string replaceParameterT(string expression, double parameter);
double solve(string expression, double parameterT);
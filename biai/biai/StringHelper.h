#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <msclr\marshal_cppstd.h>

using namespace std;

void replaceStrings(std::string& str, const std::string& toReplace, const std::string& replacer);
void splitString(const string& str, vector<string>& v);
string toStdString(System::String^ systemString);
System::String^ toSystemString(string s);
string showVectorVals(string label, std::vector<double> &v);

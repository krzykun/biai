#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <msclr\marshal_cppstd.h>

using namespace std;

void replaceStrings(std::string& str, const std::string& toReplace, const std::string& replacer);
vector<string> splitByChar(const string str, const char c);
vector<string> splitBySpaces(const string& str);
vector<string> splitBySpaces(System::String^ systemString);
vector<string> splitByCommas(const string str);
vector<string> splitByCommas(System::String^ systemString);
vector<unsigned> toUnsignedIntVector(string line);
vector<unsigned> toUnsignedIntVector(System::String^ systemString);
vector<double> toDoubleVector(string line);
vector<double> toDoubleVector(System::String^ systemString);
string toStdString(System::String^ systemString);
System::String^ toSystemString(string s);
string showVectorVals(string label, std::vector<double> &v);
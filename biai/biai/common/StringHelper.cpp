#include "StringHelper.h"

void replaceStrings(std::string& str, const std::string& toReplace, const std::string& replacer) {
	std::string::size_type n = 0;
	while ((n = str.find(toReplace, n)) != std::string::npos)
	{
		str.replace(n, toReplace.size(), replacer);
		n += replacer.size();
	}
}

vector<string> splitByChar(const string str, const char c) {
	std::stringstream ss(str);
	std::string segment;
	std::vector<std::string> seglist;
	while (std::getline(ss, segment, c))
		seglist.push_back(segment);
	return seglist;
}

vector<string> splitBySpaces(const string& str) {
	return splitByChar(str, ' ');
}

vector<string> splitBySpaces(System::String^ systemString) {
	return splitBySpaces(toStdString(systemString));
}

vector<string> splitByCommas(const string str) {
	return splitByChar(str, ',');
}

vector<string> splitByCommas(System::String^ systemString) {
	return splitByCommas(toStdString(systemString));
}

vector<unsigned> toUnsignedIntVector(string line) {
	vector<string> tokens = splitBySpaces(line);
	vector<unsigned> unsignedIntVector;
	for (int i = 0; i < tokens.size(); ++i)
		unsignedIntVector.push_back(atoll(tokens[i].c_str()));
	return unsignedIntVector;
}

vector<unsigned> toUnsignedIntVector(System::String^ systemString) {
	return toUnsignedIntVector(toStdString(systemString));
}

vector<double> toDoubleVector(string line) {
	vector<string> tokens = splitBySpaces(line);
	vector<double> doubleVector;
	for (int i = 0; i < tokens.size(); ++i) {
		string str = tokens[i];
		double t = stod(tokens[i]);
		doubleVector.push_back(stod(tokens[i]));
	}
	return doubleVector;
}

vector<double> toDoubleVector(System::String^ systemString) {
	return toDoubleVector(toStdString(systemString));
}

string toStdString(System::String^ systemString) {
	return msclr::interop::marshal_as<std::string>(systemString);
}

System::String^ toSystemString(string s) {
	return gcnew System::String(s.c_str());
}

string showVectorVals(string label, std::vector<double> &v){
	string _text = "";
	_text += label;
	_text += " ";
	for (unsigned i = 0; i < v.size(); ++i) {
		_text += to_string(v[i]);
		_text += " ";
	}
	return _text;
}
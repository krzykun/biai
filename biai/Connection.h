#pragma once

#include <cstdlib>

class Connection
{
	static double randomWeight(void) { return rand() / double(RAND_MAX); }
public:
	Connection();
	~Connection();
	double weight;
	double deltaweight;
};


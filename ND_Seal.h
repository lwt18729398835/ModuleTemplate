#pragma once
#include <math.h>
#include <fstream>

#include "..\Common\tinyxml2.h"
using namespace tinyxml2;
using namespace std;

#include"..\Common\FileInstantiation.h"

class CND_Seal
{
private:
	double d;
	double Dia;
	double dmin, dmax, d0;
	string message;

	int inputFromXML(const char* xmlPath);
	int outputToXML(const char* xmlPath);
public:
	int design(const char* xmlPath);
};
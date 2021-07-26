#include "ModuleRealize.h"
int main(int argc, char* argv[])
{
	int result;
	ModuleRealize *mr=new ModuleRealize();
	result = mr->startAlgorithm(argv);
	delete mr;
	return result;
}
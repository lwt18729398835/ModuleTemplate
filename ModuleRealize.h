#pragma once
#include "ModuleBase.h"
class ModuleRealize :
	protected ModuleBase
{
private:
	/*需要读的变量*/
	double x1;
	double x2;
	/*需要写的变量*/
	double y;
	/*从数据字典读取数据*/
	virtual void inputFromXML();
	/*将结果写入数据字典*/
	virtual void outputFromXML();
public:
	/*开始计算：完成返回0，失败返回-1，数据字典参数不全返回1*/
	virtual int startAlgorithm(char* argv[]);
};


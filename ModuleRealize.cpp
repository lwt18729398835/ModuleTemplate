/*
本文件是算法模块的实现部分
已经自动添加GSL(GNU Scientific Library)算法库以供科学计算 http://www.gnu.org/software/gsl/
务必设置系统环境变量GSL_DIR为GSL库的安装路径
务必设置平台类型为X64平台
*/
#include "ModuleRealize.h"
#include <gsl/gsl_sf_bessel.h>

void ModuleRealize::inputFromXML()
{
	/*第一步：加载数据字典*/
	loadXML();
	/*第二步：访问节点并读入数据*/
	accessNode("in");
	accessNode("class1");
	read(x1, "x1");
	leaveNode();
	accessNode("class2"); 
	read(x2, "x2");
	leaveNode();
}

int ModuleRealize::startAlgorithm(char* argv[])
{
	try
	{
		/*第一步：设置数据字典文件名称*/
		setXmlPath(argv);
		/*第二步：读数据*/
		inputFromXML();
		/*第三步：
		在此处填写算法代码
		可以启动已有的可执行文件(.exe)
		如果出现错误可以抛出throw(...)
		如果出现警告可以使用addMessage(...)添加警告信息
		*/
		y = gsl_sf_bessel_J0(x1) + gsl_sf_bessel_J0(x2);
		/*第四步：写数据*/
		outputFromXML();
		return 0;
	}
	catch (const char* exp)
	{
		/*如果出错，根据具体情况返回-1或1*/
		return exceptionHandler(exp);
	}
}

void ModuleRealize::outputFromXML()
{
	/*第一步：加载数据字典*/
	loadXML();
	/*第二步：添加计算完成的消息和状态*/
	addMessage("\n消息！完成计算\n");
	write("message", getMessage());
	write("status", "Finish");
	/*第三步：访问节点并写数据*/
	accessNode("out");
	accessNode("class3");
	write("y", y);
	leaveNode();
	/*第四步：保存数据字典*/
	saveXML();
}

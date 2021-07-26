#pragma once
#include "tinyxml2.h"
#include <vector>
class ModuleBase
{
private:
	string message="";						//消息、警告和错误信息
	string xmlPath = "";					//数据字典文件名称
	tinyxml2::XMLDocument doc;				//数据字典文件
	tinyxml2::XMLElement* currentNode;		//当前访问的节点
	//分割字符串
	vector <string> split(const string& str, const string& pattern);
protected:
	//根据main()的传入参数得到数据字典文件名称
	void setXmlPath(char* argv[]);
	//纯虚函数，派生类必须实现
	virtual void inputFromXML() = 0;
	virtual int startAlgorithm(char* argv[]) = 0;
	virtual void outputFromXML() = 0;
	//加载数据字典
	void loadXML();
	//保存数据字典
	void saveXML();
	//将当前节点设置为名称为nodeName的节点，nodeName必须为当前节点的子节点
	void accessNode(const char* nodeName);
	//离开当前节点，返回到当前节点的父节点
	void leaveNode();
	//从数据字典读取整数
	void read(int& target, const char* source);
	//从数据字典读取浮点数
	void read(double& target, const char* source);
	//从数据字典读取C字符串
	void read(char* target, const char* source);
	//从数据字典读取C++字符串
	void read(string& target, const char* source);
	//向数据字典写整数
	void write(const char* target, int& source);
	//向数据字典写浮点数
	void write(const char* target, double& source);
	//向数据字典写C字符串（变量）
	void write(const char* target, char* source);
	//向数据字典写C字符串（常量）
	void write(const char* target, const char* source);
	//向数据字典写C++字符串
	void write(const char* target, string& source);
	//用于处理错误信息的函数，返回-1表示错误，返回1表示输入参数不全
	int exceptionHandler(const char* exp);
	//追加一条信息
	void addMessage(string newMessage);
	//返回所有信息
	const char* getMessage();
};


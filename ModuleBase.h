#pragma once
#include "tinyxml2.h"
#include <vector>
class ModuleBase
{
private:
	string message="";						//��Ϣ������ʹ�����Ϣ
	string xmlPath = "";					//�����ֵ��ļ�����
	tinyxml2::XMLDocument doc;				//�����ֵ��ļ�
	tinyxml2::XMLElement* currentNode;		//��ǰ���ʵĽڵ�
	//�ָ��ַ���
	vector <string> split(const string& str, const string& pattern);
protected:
	//����main()�Ĵ�������õ������ֵ��ļ�����
	void setXmlPath(char* argv[]);
	//���麯�������������ʵ��
	virtual void inputFromXML() = 0;
	virtual int startAlgorithm(char* argv[]) = 0;
	virtual void outputFromXML() = 0;
	//���������ֵ�
	void loadXML();
	//���������ֵ�
	void saveXML();
	//����ǰ�ڵ�����Ϊ����ΪnodeName�Ľڵ㣬nodeName����Ϊ��ǰ�ڵ���ӽڵ�
	void accessNode(const char* nodeName);
	//�뿪��ǰ�ڵ㣬���ص���ǰ�ڵ�ĸ��ڵ�
	void leaveNode();
	//�������ֵ��ȡ����
	void read(int& target, const char* source);
	//�������ֵ��ȡ������
	void read(double& target, const char* source);
	//�������ֵ��ȡC�ַ���
	void read(char* target, const char* source);
	//�������ֵ��ȡC++�ַ���
	void read(string& target, const char* source);
	//�������ֵ�д����
	void write(const char* target, int& source);
	//�������ֵ�д������
	void write(const char* target, double& source);
	//�������ֵ�дC�ַ�����������
	void write(const char* target, char* source);
	//�������ֵ�дC�ַ�����������
	void write(const char* target, const char* source);
	//�������ֵ�дC++�ַ���
	void write(const char* target, string& source);
	//���ڴ��������Ϣ�ĺ���������-1��ʾ���󣬷���1��ʾ���������ȫ
	int exceptionHandler(const char* exp);
	//׷��һ����Ϣ
	void addMessage(string newMessage);
	//����������Ϣ
	const char* getMessage();
};


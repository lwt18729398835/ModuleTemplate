#pragma once
#include "ModuleBase.h"
class ModuleRealize :
	protected ModuleBase
{
private:
	/*��Ҫ���ı���*/
	double x1;
	double x2;
	/*��Ҫд�ı���*/
	double y;
	/*�������ֵ��ȡ����*/
	virtual void inputFromXML();
	/*�����д�������ֵ�*/
	virtual void outputFromXML();
public:
	/*��ʼ���㣺��ɷ���0��ʧ�ܷ���-1�������ֵ������ȫ����1*/
	virtual int startAlgorithm(char* argv[]);
};


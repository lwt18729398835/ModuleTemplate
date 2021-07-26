/*
���ļ����㷨ģ���ʵ�ֲ���
�Ѿ��Զ����GSL(GNU Scientific Library)�㷨���Թ���ѧ���� http://www.gnu.org/software/gsl/
�������ϵͳ��������GSL_DIRΪGSL��İ�װ·��
�������ƽ̨����ΪX64ƽ̨
*/
#include "ModuleRealize.h"
#include <gsl/gsl_sf_bessel.h>

void ModuleRealize::inputFromXML()
{
	/*��һ�������������ֵ�*/
	loadXML();
	/*�ڶ��������ʽڵ㲢��������*/
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
		/*��һ�������������ֵ��ļ�����*/
		setXmlPath(argv);
		/*�ڶ�����������*/
		inputFromXML();
		/*��������
		�ڴ˴���д�㷨����
		�����������еĿ�ִ���ļ�(.exe)
		������ִ�������׳�throw(...)
		������־������ʹ��addMessage(...)��Ӿ�����Ϣ
		*/
		y = gsl_sf_bessel_J0(x1) + gsl_sf_bessel_J0(x2);
		/*���Ĳ���д����*/
		outputFromXML();
		return 0;
	}
	catch (const char* exp)
	{
		/*����������ݾ����������-1��1*/
		return exceptionHandler(exp);
	}
}

void ModuleRealize::outputFromXML()
{
	/*��һ�������������ֵ�*/
	loadXML();
	/*�ڶ�������Ӽ�����ɵ���Ϣ��״̬*/
	addMessage("\n��Ϣ����ɼ���\n");
	write("message", getMessage());
	write("status", "Finish");
	/*�����������ʽڵ㲢д����*/
	accessNode("out");
	accessNode("class3");
	write("y", y);
	leaveNode();
	/*���Ĳ������������ֵ�*/
	saveXML();
}

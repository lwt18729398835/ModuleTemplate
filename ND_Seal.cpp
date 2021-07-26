#include "ND_Seal.h"

int CND_Seal::design(const char* xmlPath)
{
	try
	{
		inputFromXML(xmlPath);

		d0 = d - 0.5;
		if (d0 <= 50)
		{
			dmin = 2.0;
			dmax = 2.5;
		}
		else if (d0 <= 250)
		{
			dmin = 2.5;
			dmax = 3.0;
		}
		else if (d0 <= 300)
		{
			dmin = 3.0;
			dmax = 5.0;
		}
		else if (d0 <= 700)
		{
			dmin = 5.0;
			dmax = 7.0;
		}
		else if (d0 <= 1100)
		{
			dmin = 7.0;
			dmax = 9.0;
		}
		else
		{
			message += "���棺����ֱ��̫��";
		}
		Dia = dmax;

		outputToXML(xmlPath);
		return 0;
	}
	catch (const char* exp)
	{
		return exceptionHandler(xmlPath, exp, message);
	}
}

//����
int CND_Seal::inputFromXML(const char* xmlPath)
{
	XMLDocument doc;
	int res = doc.LoadFile(xmlPath);
	if (res != 0)
	{
		throw("\n���󣡲��ܼ���XML�ļ�\n");
		return res;
	}
	XMLElement* root = doc.RootElement();
	XMLElement* node, * nodeIO, * nodeClassify;
	nodeIO = queryNodeByName(root, "in");

	nodeClassify = queryNodeByName(nodeIO, "size");
	node = queryNodeByName(nodeClassify, "d"); stringToData(&d, node->GetText());

	return doc.SaveFile(xmlPath);
}


//�����XML�ļ���
int CND_Seal::outputToXML(const char* xmlPath)
{
	XMLDocument doc;
	int res = doc.LoadFile(xmlPath);
	if (res != 0)
	{
		throw( "\n���󣡲��ܼ���XML�ļ�\n");
		return res;
	}
	message += "\n��Ϣ����ɼ���\n";
	XMLElement* root = doc.RootElement();
	XMLElement* node, * nodeIO, * nodeClassify;
	nodeIO = queryNodeByName(root, "message"); nodeIO->SetText(message.c_str());
	nodeIO = queryNodeByName(root, "status"); nodeIO->SetText("Finish");

	nodeIO = queryNodeByName(root, "out");

	nodeClassify = queryNodeByName(nodeIO, "size");
	node = queryNodeByName(nodeClassify, "dmin");  node->SetText(dmin);
	node = queryNodeByName(nodeClassify, "dmax");  node->SetText(dmax);
	node = queryNodeByName(nodeClassify, "d0");  node->SetText(d0);
	return doc.SaveFile(xmlPath);
}
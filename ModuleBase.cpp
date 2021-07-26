#include "ModuleBase.h"

void ModuleBase::loadXML()
{
    if (doc.LoadFile(xmlPath.c_str()) != 0)
        throw("\n错误！不能加载XML文件\n");
    currentNode = doc.RootElement();
}

void ModuleBase::saveXML()
{
    if (doc.SaveFile(xmlPath.c_str()) != 0)
        throw("\n错误！不能保存XML文件\n");
}

void ModuleBase::accessNode(const char* nodeName)
{
    currentNode = tinyxml2::queryNodeByName(currentNode, nodeName);
}

void ModuleBase::leaveNode()
{
    currentNode = currentNode->Parent()->ToElement();
}

void ModuleBase::read(int& target,const char* source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, source);
    tinyxml2::stringToData(target, node->GetText());
}

void ModuleBase::read(double& target, const char* source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, source);
    tinyxml2::stringToData(target, node->GetText());
}

void ModuleBase::read(char* target, const char* source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, source);
    tinyxml2::stringToData(target, node->GetText());
}

void ModuleBase::read(string& target, const char* source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, source);
    tinyxml2::stringToData(target, node->GetText());
}

void ModuleBase::write(const char* target, int& source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, target);
    node->SetText(source);
}

void ModuleBase::write(const char* target, double& source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, target);
    node->SetText(source);
}

void ModuleBase::write(const char* target, char* source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, target);
    node->SetText(source);
}

void ModuleBase::write(const char* target, const char* source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, target);
    node->SetText(source);
}

void ModuleBase::write(const char* target, string& source)
{
    tinyxml2::XMLElement* node = tinyxml2::queryNodeByName(currentNode, target);
    node->SetText(source.c_str());
}

int ModuleBase::exceptionHandler(const char* exp)
{
    return tinyxml2::exceptionHandler(xmlPath.c_str(), exp, this->message);
}

void ModuleBase::addMessage(string newMessage)
{
	message += newMessage;
}

const char* ModuleBase::getMessage()
{
    return message.c_str();
}

void ModuleBase::setXmlPath(char* argv[])
{
    vector<string> splitOfPath = split(argv[0], "\\");
    splitOfPath.size();
    string exeName = splitOfPath[splitOfPath.size() - 1];
    vector<string> splitOfExeName = split(exeName, ".");
    string rawName = splitOfExeName[0];
    this->xmlPath = rawName + ".xml";
}

vector <string>  ModuleBase::split(const string& str, const string& pattern)
{
    vector<string> ret;
    if (pattern.empty()) return ret;
    size_t start = 0, index = str.find_first_of(pattern, 0);
    while (index != str.npos)
    {
        if (start != index)
            ret.push_back(str.substr(start, index - start));
        start = index + 1;
        index = str.find_first_of(pattern, start);
    }
    if (!str.substr(start).empty())
        ret.push_back(str.substr(start));
    return ret;
}

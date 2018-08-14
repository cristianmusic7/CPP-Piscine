#include "OSInfoModule.hpp"
#include <vector>
#include <iostream>
#include <limits.h>
#include <unistd.h>

OSInfoModule::OSInfoModule(): AModule(0,0,20,3,"OS Info"){
    std::string str = getOsName();
    info.push_back("OS      : " + str.substr(str.find("\t") + 1, str.find("\n") - str.find("\t")));
    str = str.substr(str.find("\n") + 1);
    info.push_back("Product : " + str.substr(str.find("\t") + 1, str.find("\n") - str.find("\t")));
    str = str.substr(str.find("\n") + 1);
    info.push_back("Build   : " + str.substr(str.find("\t") + 1, str.find("\n") - str.find("\t")));
}

OSInfoModule::OSInfoModule(const OSInfoModule&) : AModule(0,0,20,3,"OS Info"){
    info.push_back("OS : " + getOsName());
}
        
OSInfoModule::~OSInfoModule(){
    info.push_back("OS : " + getOsName());
}

const OSInfoModule& OSInfoModule::operator=(const OSInfoModule&){
    return *this;
}

OSInfoModule::OSInfoModule(int x, int y) : AModule(x,y,20,3,"OS Info"){
    info.push_back("OS : " + getOsName());

}

std::string OSInfoModule::getOsName()
{
    char buf[1024];
    unsigned buflen = 0;
    char line[256];
    FILE *sw_vers = popen("sw_vers", "r");
    while (fgets(line, sizeof(line), sw_vers) != NULL) {
        int l = snprintf(buf + buflen, sizeof(buf) - buflen, "%s", line);
        buflen += l;
    }
    pclose(sw_vers);
    return std::string (buf);
}     

std::vector<std::string> OSInfoModule::getInfo(){
    return info;
}

std::deque<float> OSInfoModule::getGraphValues(){
    return _graphValues;
}
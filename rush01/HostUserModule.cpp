#include "HostUserModule.hpp"
#include <vector>
#include <iostream>
#include <limits.h>
#include <unistd.h>

HostUserModule::HostUserModule(): AModule(0,0,20,4,"Host/User"){
    char host[_POSIX_HOST_NAME_MAX];
    char usr[_POSIX_LOGIN_NAME_MAX];
    gethostname(host, _POSIX_HOST_NAME_MAX);
    getlogin_r(usr, _POSIX_LOGIN_NAME_MAX);
    info.push_back("Host : " + std::string(host));
    info.push_back("User : " + std::string(usr));
}

HostUserModule::HostUserModule(const HostUserModule&) : AModule(0,0,20,4,"Host/User"){
    char host[_POSIX_HOST_NAME_MAX];
    char usr[_POSIX_LOGIN_NAME_MAX];
    gethostname(host, _POSIX_HOST_NAME_MAX);
    getlogin_r(usr, _POSIX_LOGIN_NAME_MAX);
    info.push_back("Host : " + std::string(host));
    info.push_back("User : " + std::string(usr));
}
        
HostUserModule::~HostUserModule(){

}

const HostUserModule& HostUserModule::operator=(const HostUserModule&){
    return *this;
}

HostUserModule::HostUserModule(int x, int y) : AModule(x,y,20,4,"Host/User"){
    char host[_POSIX_HOST_NAME_MAX];
    char usr[_POSIX_LOGIN_NAME_MAX];
    gethostname(host, _POSIX_HOST_NAME_MAX);
    getlogin_r(usr, _POSIX_LOGIN_NAME_MAX);
    info.push_back("Host : " + std::string(host));
    info.push_back("User : " + std::string(usr));
}

std::vector<std::string> HostUserModule::getInfo(){
    return info;
}

std::deque<float> HostUserModule::getGraphValues(){
    return _graphValues;
}
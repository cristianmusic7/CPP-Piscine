#include "CPUInfoModule.hpp"
#include <vector>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sysctl.h>
#include <stdio.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <sys/resource.h>

CPUInfoModule::CPUInfoModule(): AModule(0,0,20,4,"CPU"){
}

CPUInfoModule::CPUInfoModule(const CPUInfoModule&) : AModule(0,0,20,4,"CPU"){
}
        
CPUInfoModule::~CPUInfoModule(){
}

void CPUInfoModule::update(){
    info.clear();
   
    char buffer[128];
    size_t bufferlen = 128;
    std::string str;

    sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
    str = buffer;
    info.push_back("CPU : " + str.substr(0, str.find(" ", str.find(" ") + 1)));
    str = str.substr(str.find(" ") + 1);
    str = str.substr(str.find(" ") + 1);
    info.push_back("CPU Type  : " + str.substr(0, str.find(" ")));
    str = str.substr(str.find(" ") + 1);
    str = str.substr(str.find(" ") + 1);
    str = str.substr(str.find(" ") + 1);
    info.push_back("CPU clock : " + str.substr(0, str.find(" ")));
    int numCPU = sysconf(_SC_NPROCESSORS_ONLN);
    info.push_back("CPU cores : " + std::to_string(numCPU));
}

const CPUInfoModule& CPUInfoModule::operator=(const CPUInfoModule&){
    return *this;
}

CPUInfoModule::CPUInfoModule(int x, int y) : AModule(x,y,20,30,"CPU"){
}

std::vector<std::string> CPUInfoModule::getInfo(){
    return info;
}

std::deque<float> CPUInfoModule::getGraphValues(){
    return _graphValues;
}
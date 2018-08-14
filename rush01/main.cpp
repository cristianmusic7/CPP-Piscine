#include <unistd.h>
#include <limits.h>
#include <iostream>
#include "HostUserModule.hpp"
#include "OSInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "RamModule.hpp"
#include "CPUInfoModule.hpp"
#include "CPUUsageModule.hpp"
#include "NetworkModule.hpp"
#include "TextDisplay.hpp"
#include "GraphicsDisplay.hpp"
#include <map>
#include <vector>


IMonitorModule* newOSModule(){
    return new OSInfoModule;
}
IMonitorModule* newHostModule(){
    return new HostUserModule;
}
IMonitorModule* newTimeModule(){
    return new DateTimeModule;
}
IMonitorModule* newRamModule(){
    return new RamModule;
}
IMonitorModule* newCPUInfoModule(){
    return new CPUInfoModule;
}
IMonitorModule* newCPUUseModule(){
    return new CPUUsageModule;
}
IMonitorModule* newNetworkModule(){
    return new NetworkModule;
}

IMonitorModule* newModule(std::string name){
    std::map<const std::string, IMonitorModule* (*)(void)> map;
    map["OS"] = newOSModule;
    map["Host"] = newHostModule;
    map["Time"] = newTimeModule;
    map["Ram"] = newRamModule;
    map["CPUInfo"] = newCPUInfoModule;
    map["CPUUse"] = newCPUUseModule;
    map["Network"] = newNetworkModule;
    if (map.count(name))
    {
        return map[name]();
    }
    return map["Host"]();
}

int main(int argc, char **argv){
    if (argc == 2)
    {
        std::string display_mode(argv[1]);
        if (!display_mode.compare("terminal"))
        {
            TextDisplay txt;
            txt.addWindow(newModule("OS"));
            txt.addWindow(newModule("Network"));
            txt.addWindow(newModule("Host"));
            txt.addWindow(newModule("CPUInfo"));
            txt.addWindow(newModule("Ram"));
            txt.addWindow(newModule("CPUUse"));
            txt.addWindow(newModule("Time"));
            
    
            while (txt.running){
                txt.update();
                usleep(1000000);
            }
            txt.freeModules();
        }
        else if (!display_mode.compare("visual"))
        {            
            GraphicsDisplay g;

            g.addWindow(newModule("OS"));
            g.addWindow(newModule("Host"));
            g.addWindow(newModule("CPUInfo"));
            g.addWindow(newModule("Ram"));
            g.addWindow(newModule("CPUUse"));
            g.addWindow(newModule("Time"));
            g.addWindow(newModule("Network"));
            while (!g.getCloseState())
            {
                g.update();
                usleep(1000);
            }
            g.freeModules();
        }
        else
            std::cout << "usage: " << argv[0] << " [terminal] | [visual]" << std::endl;
        return (0);
    }
    std::cout << "usage: " << argv[0] << " [terminal] | [visual]" << std::endl;
}

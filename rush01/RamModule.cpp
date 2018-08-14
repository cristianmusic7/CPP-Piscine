#include "RamModule.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>


RamModule::RamModule(): AModule(0,0,20,5,"RAM"){
    this->_numGV = 10;
}

RamModule::RamModule(const RamModule&) : AModule(0,0,20,5,"RAM"){
    this->_numGV = 10;
}
        
RamModule::~RamModule(){
}

void RamModule::update(){
    info.clear();
    
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;
    int mib[2];
    int64_t physical_memory;
    size_t length;

    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    length = sizeof(int64_t);
    sysctl(mib, 2, &physical_memory, &length, NULL, 0);
    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count) *  (int64_t)page_size;
        long long free_memory = physical_memory - used_memory;
        int pm = physical_memory /1000000;
        int fm = free_memory /1000000;
        int um = used_memory /1000000;
        float pmf = pm / 1000.0f;
        float fmf = fm / 1000.0f;
        float umf = um / 1000.0f;
        std::ostringstream ss;
        ss << pmf;
        info.push_back("total memory : " + ss.str() + " GB ");
        ss.str("");
        ss << fmf;
        info.push_back("free memory  : " + ss.str() + " GB ");
        ss.str("");
        ss << umf;
        info.push_back("used memory  : " +ss.str() + " GB ");
        if (static_cast<int>(this->_graphValues.size()) > this->_numGV - 1)
            this->_graphValues.pop_front();
        this->_graphValues.push_back(umf);    
        graphMax = pmf;
    }
}

const RamModule& RamModule::operator=(const RamModule&){
    return *this;
}

RamModule::RamModule(int x, int y) : AModule(x,y,20,5,"RAM"){
    this->_numGV = 10;
}

std::vector<std::string> RamModule::getInfo(){
    return info;
}

std::deque<float> RamModule::getGraphValues(){
    return _graphValues;
}

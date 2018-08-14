#include "CPUUsageModule.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

CPUUsageModule::CPUUsageModule(): AModule(0,0,20,4,"CPU Activity")
{
  this->_numGV = 30;
}

CPUUsageModule::CPUUsageModule(const CPUUsageModule&) : AModule(0,0,20,4,"CPU Activity"){
    this->_numGV = 30;
}
        
CPUUsageModule::~CPUUsageModule(){
}

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;


float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}


float GetCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}


void CPUUsageModule::update(){
    info.clear();
    int cpu = GetCPULoad() * 10000;
    float cpuf = cpu / 100.0;
    if (static_cast<int>(this->_graphValues.size()) > this->_numGV - 1)
      this->_graphValues.pop_front();
    this->_graphValues.push_back(cpuf);    
    graphMax = 100;
    std::ostringstream ss;
    ss << cpuf;
    info.push_back("CPU Usage : " + ss.str() + " %%    ");
    ss.str("");
    ss << 100 - cpuf;
    info.push_back("CPU Left  : " + ss.str() + " %%    ");
}

const CPUUsageModule& CPUUsageModule::operator=(const CPUUsageModule&){
    return *this;
}

CPUUsageModule::CPUUsageModule(int x, int y) : AModule(x,y,20,30,"CPU Activity"){
    this->_numGV = 10;
}

std::vector<std::string> CPUUsageModule::getInfo(){
    return info;
}

std::deque<float> CPUUsageModule::getGraphValues(){
    return _graphValues;
}

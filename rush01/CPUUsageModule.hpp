#ifndef CPU_USAGE_MODULE_HPP
#define CPU_USAGE_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class CPUUsageModule : public AModule{
    private:
        CPUUsageModule(const CPUUsageModule&);
        const CPUUsageModule& operator=(const CPUUsageModule&);

    public:
        CPUUsageModule();
        ~CPUUsageModule();
        CPUUsageModule(int x, int y);
        void update();
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
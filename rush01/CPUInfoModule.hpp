#ifndef CPU_MODULE_HPP
#define CPU_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class CPUInfoModule : public AModule{
    private:
        CPUInfoModule(const CPUInfoModule&);
        const CPUInfoModule& operator=(const CPUInfoModule&);

    public:
        CPUInfoModule();
        ~CPUInfoModule();
        CPUInfoModule(int x, int y);
        void update();
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
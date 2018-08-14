#ifndef HOST_USER_MODULE_HPP
#define HOST_USER_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class HostUserModule : public AModule{
    private:
        HostUserModule(const HostUserModule&);
        const HostUserModule& operator=(const HostUserModule&);

    public:
        HostUserModule();
        ~HostUserModule();
        HostUserModule(int x, int y);
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
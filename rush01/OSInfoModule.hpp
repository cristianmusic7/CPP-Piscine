#ifndef OS_INFO_MODULE_HPP
#define OS_INFO_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class OSInfoModule : public AModule{
    private:
        OSInfoModule(const OSInfoModule&);
        const OSInfoModule& operator=(const OSInfoModule&);

    public:
        OSInfoModule();
        ~OSInfoModule();
        std::string getOsName();
        OSInfoModule(int x, int y);
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
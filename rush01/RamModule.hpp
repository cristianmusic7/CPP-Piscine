#ifndef RAM_MODULE_HPP
#define RAM_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class RamModule : public AModule{
    private:
        RamModule(const RamModule&);
        const RamModule& operator=(const RamModule&);

    public:
        RamModule();
        ~RamModule();
        RamModule(int x, int y);
        void update();
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
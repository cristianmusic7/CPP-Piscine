#ifndef NETWORK_MODULE_HPP
#define NETWORK_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class NetworkModule : public AModule{
    private:
        NetworkModule(const NetworkModule&);
        const NetworkModule& operator=(const NetworkModule&);

    public:
        NetworkModule();
        ~NetworkModule();
        NetworkModule(int x, int y);
        void update();
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
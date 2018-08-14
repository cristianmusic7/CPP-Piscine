#ifndef DATE_TIME_MODULE_HPP
#define DATE_TIME_MODULE_HPP

#include <vector>
#include "AModule.hpp"
#include <iostream>

class DateTimeModule : public AModule{
    private:
        DateTimeModule(const DateTimeModule&);
        const DateTimeModule& operator=(const DateTimeModule&);

    public:
        DateTimeModule();
        ~DateTimeModule();
        DateTimeModule(int x, int y);
        void update();
        virtual std::vector<std::string> getInfo();
        virtual std::deque<float> getGraphValues();
};

#endif
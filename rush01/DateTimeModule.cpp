#include "DateTimeModule.hpp"
#include <vector>
#include <iostream>
#include <limits.h>
#include <unistd.h>
#include <ctime>

DateTimeModule::DateTimeModule(): AModule(0,0,20,4,"Date/Time"){
}

DateTimeModule::DateTimeModule(const DateTimeModule&) : AModule(0,0,20,4,"Date/Time"){
}
        
DateTimeModule::~DateTimeModule(){
}

void DateTimeModule::update(){
    info.clear();
    time_t raw;
    time (&raw);
    info.push_back("year : " +std::string(ctime(&raw)).substr(20, 4 ));
    info.push_back("day  : " + std::string(ctime(&raw)).substr(0,11));
    info.push_back("hour : " +std::string(ctime(&raw)).substr(11, 9 ));
   
    
}

const DateTimeModule& DateTimeModule::operator=(const DateTimeModule&){
    return *this;
}

DateTimeModule::DateTimeModule(int x, int y) : AModule(x,y,20,4,"Date/Time"){
}

std::vector<std::string> DateTimeModule::getInfo(){
    return info;
}

std::deque<float> DateTimeModule::getGraphValues(){
    return _graphValues;
}
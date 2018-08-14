#include "NetworkModule.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

NetworkModule::NetworkModule(): AModule(0,0,20,4,"Network"){
}

NetworkModule::NetworkModule(const NetworkModule&) : AModule(0,0,20,4,"Network"){
}
        
NetworkModule::~NetworkModule(){
}

void NetworkModule::update(){
    static long long lasti = 0;
    static long long lasto = 0;
    std::system("nettop -J bytes_in,bytes_out -x -l1 | grep -E 'tcp|udp' | awk 'NF>3' > network");
    long long in = 0;
    long long out = 0;
    std::string word;
    std::ifstream file("network");
    int num = 0;
    
    while (file >> word)
    {
        if (num % 5 == 3)
            in += std::stoll(word);
        else if (num % 5 == 4)
            out += std::stoll(word);
        num++;

    }
    file.close();
    if (in > lasti && out > lasto)
    {
        info.clear();
        info.push_back("Bytes in  : " + std::to_string(in));
        info.push_back("Bytes out : " + std::to_string(out));
        info.push_back("Bytes in/Sec  : " + std::to_string(in - lasti) + "       ");
        info.push_back("Bytes out/Sec : " + std::to_string(out - lasto) + "      ");
        lasti = in;
        lasto = out;
    }
}

const NetworkModule& NetworkModule::operator=(const NetworkModule&){
    return *this;
}

NetworkModule::NetworkModule(int x, int y) : AModule(x,y,20,30,"Network"){
}

std::vector<std::string> NetworkModule::getInfo(){
    return info;
}

std::deque<float> NetworkModule::getGraphValues(){
    return _graphValues;
}
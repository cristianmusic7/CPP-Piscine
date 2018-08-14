#include "AModule.hpp"
#include <iostream>
#include <list>

AModule::AModule(int x, int y, int w, int h, std::string t)
:xPos(x), yPos(y), width(w), height(h), _graphType(false), title(t)
{ }
        
int AModule::getX(){
    return xPos;
}
        
void AModule::update(){
    return;
}

int AModule::getY(){
    return yPos;
}

void AModule::setX(int val){
    xPos = val;
}

void AModule::setY(int val){
    yPos = val;
}
        
int AModule::getWidth(){
    return width;
}   

int AModule::getHeight(){
    return height;
}

float AModule::getGraphMax(){
    return graphMax;
}

int AModule::getNumGraphValues(){
    return this->_numGV;
}

bool AModule::getTypeGraph()
{
    return this->_graphType;
}

void AModule::changeGraph()
{
    this->_graphType = !this->_graphType;
}

std::string AModule::getTitle(){
    return title;
}

AModule::AModule(const AModule&){
    return;
}

const AModule& AModule::operator=(const AModule&){
    return *this;
}

AModule::AModule(){

}

AModule::~AModule(){

}
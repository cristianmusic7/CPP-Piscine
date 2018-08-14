#ifndef A_MODULE_HPP
#define A_MODULE_HPP

#include <vector>
#include <deque>
#include "IMonitorModule.hpp"
#include <iostream>

class AModule : public IMonitorModule{

    private:
        int xPos;
        int yPos;
        int width;
        int height; 
        bool _graphType;      
        std::string title;
        AModule(const AModule&);
        const AModule& operator=(const AModule&);
        AModule();

    protected:
        std::vector<std::string> info;
        std::deque<float> _graphValues;
        float graphMax;
        int _numGV;        

    public:
        virtual ~AModule();
        AModule(int x, int y, int w, int h, std::string t);
        virtual void update();
        virtual int getX();
        virtual int getY();
        virtual void setX(int);
        virtual void setY(int);
        virtual int getWidth();
        virtual int getHeight();
        virtual int getNumGraphValues();
        virtual void changeGraph();
        virtual bool getTypeGraph();
        virtual std::vector<std::string> getInfo() = 0;
        virtual std::deque<float> getGraphValues() = 0;
        virtual float getGraphMax();
        virtual std::string getTitle();
};

#endif
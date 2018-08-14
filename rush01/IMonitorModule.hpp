#ifndef I_MONITOR_MODULE_HPP
#define I_MONITOR_MODULE_HPP

#include <vector>
#include <deque>

class IMonitorModule {

    public:
        virtual void update() = 0;
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual void setX(int) = 0;
        virtual void setY(int) = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual int getNumGraphValues() = 0;
        virtual bool getTypeGraph() = 0;
        virtual void changeGraph() = 0;
        virtual std::string getTitle() = 0;
        virtual std::vector<std::string> getInfo() = 0;
        virtual std::deque<float> getGraphValues() = 0;
        virtual float getGraphMax() = 0;
};
#endif
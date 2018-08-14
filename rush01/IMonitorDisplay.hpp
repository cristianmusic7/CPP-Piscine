#ifndef I_MONITOR_DISPLAY_HPP
#define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay{

    public:
        virtual void update() = 0;
        virtual void addWindow(IMonitorModule*) = 0;
        virtual void freeModules() = 0;
};

#endif
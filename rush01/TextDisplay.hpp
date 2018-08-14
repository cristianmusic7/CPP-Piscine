#ifndef TEXT_DISPLAY_HPP
#define TEXT_DISPLAY_HPP

#include <vector>
#include <ncurses.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"


class TextDisplay : public IMonitorDisplay{

    private:
        std::vector<IMonitorModule*> modules;
        int maxX;
        int maxY;
        int x;
        int y;
        WINDOW* win;
        TextDisplay(const TextDisplay&);
        const TextDisplay& operator=(const TextDisplay&);

    public:
        bool running;
        virtual ~TextDisplay();
        TextDisplay();
        void update();
        void addWindow(IMonitorModule*);
        void freeModules();
};

#endif
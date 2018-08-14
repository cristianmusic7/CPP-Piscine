#include "IMonitorModule.hpp"
#include "TextDisplay.hpp"
#include <vector>
#include <ncurses.h>
#include <iostream>

TextDisplay::TextDisplay(){
    initscr();
    x = 2; 
    running = true;
    y = 2;
    getmaxyx(stdscr, maxY, maxX);
    win = newwin(maxY - 2,maxX - 2,1,1);
    nodelay(stdscr, true);
}

void TextDisplay::update(){
    if (getch() == 'q')
        running = false;
    std::vector<IMonitorModule*>::iterator iter;
    for (iter = modules.begin(); iter < modules.end(); iter++){
        (*iter)->update();
        mvwprintw(win, (*iter)->getY(), (*iter)->getX(),(*iter)->getTitle().c_str());
        for (unsigned int i = 0; i < (*iter)->getInfo().size(); i++)
            mvwprintw(win, (*iter)->getY()+i + 1, (*iter)->getX(),((*iter)->getInfo()[i]).c_str());
        box(win,0,0);
    }
    wrefresh(win);
}
        
void TextDisplay::addWindow(IMonitorModule* mod){
    modules.push_back(mod);
    mod->setX(x);
    mod->setY(y);
    if (y + 12> maxY){
        x += 30;
        y = 2;
    }
    else{
        y += 6;
    }
   
}

TextDisplay::TextDisplay(const TextDisplay&){

}

const TextDisplay& TextDisplay::operator=(const TextDisplay&){
    return *this;
}

TextDisplay::~TextDisplay(){

}

void TextDisplay::freeModules(){
    std::vector<IMonitorModule*>().swap(modules);
}


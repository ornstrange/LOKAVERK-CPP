#include <iostream>
#include <string>
#include <curses.h>
#include <vmime/vmime.hpp>

using namespace std;

int main() {
    // Init
    int h, w;
    initscr();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, h, w);
    refresh();
    
    // Window
    int winW, winH;
    winW = 50;
    winH = winW/4;
    WINDOW *win; 
    win = newwin(winH, winW, (h/2) - (winH/2), (w/2) - (winW/2));
    box(win, 0, 0);
    string strs[3];
    wattron(win, A_DIM);
    strs[0] = "Use previous email";
    strs[1] = "Set up new email";
    strs[2] = "Quit";
    mvwprintw(win, winH/2 - 1, winW/2 - (strs[0].size()/2), strs[0].c_str());
    wmove(win, winH/2 - 1, winW/2 - (strs[0].size()/2) - 1);
    wchgat(win, strs[0].size() + 2, A_NORMAL, 0, NULL);
    mvwprintw(win, winH/2, winW/2 - (strs[1].size()/2), strs[1].c_str());
    mvwprintw(win, winH/2 + 1, winW/2 - (strs[2].size()/2), strs[2].c_str());
    curs_set(0);
    wrefresh(win);
    
    getch();

    // End
    endwin();
    return 0;
}

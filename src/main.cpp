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
    winW = 100;
    winH = winW/3;
    WINDOW *win; 
    win = newwin(winH, winW, (h/2) - (winH/2), (w/2) - (winW/2));
    box(win, 0, 0);
    wmove(win, winH/2, winW/2);
    waddch(win, 'd');
    wmove(win, 0, 0);
    wchgat(win, -1, COLOR_PAIR(1), 0, NULL);
    wrefresh(win);
    
    getch();

    // End
    endwin();
    return 0;
}

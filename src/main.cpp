#include <iostream>
#include <string>
#include <ncurses.h>
#include <vmime/vmime.hpp>
#include "strings.hpp"
using namespace std;

// Macros
#define asize(x) sizeof((x))/sizeof(*(x))

// Helper declerations
WINDOW * createWindow(int x, int y, int w, int h);
int wMenuText(WINDOW *win, string *strings, int len);

int main() {
    // Init
    int h, w, mPos;
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, h, w);
    refresh();

    // Windows
    WINDOW *loginWin;
    loginWin = createWindow(0,0,50,21);
    mPos = wMenuText(loginWin, sendMenu, asize(sendMenu));

    /*
    
    Window
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
   */ 
    
    getch();

    endwin();
    return 0;
}

// Curses helpers
WINDOW * createWindow(int x, int y, int w, int h) {
    WINDOW *_win;
    _win = newwin(h,w,y,x);
    box(_win, 0, 0);
    wrefresh(_win);
    return _win;
}

int wMenuText(WINDOW *win, string *strings, int len) {
    int w, h, offset;
    getmaxyx(win, h, w);
    offset = len/2;
    wattron(win, A_DIM);
    for (int i = 0; i < len; i++) {
        mvwprintw(win, (h/2) + i - offset, (w/2) - (strings[i].size()/2), strings[i].c_str());
        if (i == 0) {
            wmove(win , (h/2) - offset, (w/2) - (strings[i].size()/2) - 1);
            wchgat(win, strings[i].size() + 2, A_NORMAL, 0, NULL);
        }
    }
    wrefresh(win);
    return (h/2) - offset;
}

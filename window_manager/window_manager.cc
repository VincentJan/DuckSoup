#include <locale.h>
#include <ncurses.h>
#include "window_manager.h"

WindowManager::WindowManager()
{
    setlocale(LC_ALL, "");
    initscr();
    raw();
    noecho();
}

WindowManager::~WindowManager()
{
    endwin();
}

int WindowManager::exec()
{
    char c = getch();
    int x = 0;
    int y = 0;
    move(y, x);
    while(c != 'q')
    {
        switch(c)
        {
            case 'w':
                y -= 1;
                break;
            case 's':
                y += 1;
                break;
            case 'a':
                x -= 1;
                break;
            case 'd':
                x += 1;
                break;
            case ' ':
                addch('*');
                break;
            case '\n':
                addch(' ');
                break;
            default:
                break;
        } //switch(c)
        refresh();
        move(y, x);
        c = getch();
    }//while
    return 0;
}
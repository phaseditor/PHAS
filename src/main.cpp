#include <cstdio>
#include <iostream>
#include <ncurses.h>
#include "readFile.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file-path>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(1);

    std::string file_content = readFile(file_path);
    Rope rope(file_content, 32);

    int max_X = getmaxx(stdscr);
    int max_Y = getmaxy(stdscr);
    refresh();

    WINDOW *win = newwin(max_Y, max_X, 0, 0);
    if (win == nullptr) {
        endwin();
        std::cerr << "Failed to create window" << std::endl;
        return 1;
    }

    int top_border = (max_X/2) - 5;

    wborder(win, ' ', ' ', ACS_HLINE, ' ', 0, 0, 0, 0);
    mvwprintw(win, 0, top_border, "Phase");
    wrefresh(win);

    mvwprintw(win, 2, 0, "%.100s", file_content.c_str());


    wrefresh(win);
    
    char key = getchar();

    wrefresh(win);
    endwin();

    return 0;
}

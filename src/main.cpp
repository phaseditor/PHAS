#include <cstdio>
#include <iostream>
#include <ncurses.h>
#include "readFile.h"

void DisplayNcurses(const std::string& file_content) {
    initscr(); // start ncurses
    clear();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    int max_X, max_Y; // Y = Row && X = Col
    getmaxyx(stdscr, max_Y, max_X);
    refresh();

    WINDOW *win = newwin(max_Y, max_X, 0, 0); // intialize window
    wborder(win, ' ', ' ', ACS_HLINE, ACS_HLINE, 0, 0, 0, 0);
    int top_border = (max_X / 2) - 4;
    mvwprintw(win, 0, top_border, "[PHASE]");
    wrefresh(win);

    int pad_height = file_content.size() / (max_X - 2) + 1; 
    if (pad_height < max_Y - 2) pad_height = max_Y - 2;

    WINDOW *pad = newpad(pad_height, max_X - 2); // initialize pad (for scrolling)
    if (!pad) {
        endwin();
        std::cerr << "Failed to create pad" << std::endl;
        return;
    }

    wprintw(pad, "%s", file_content.c_str()); // print file_content in pad

    int vertical_offset = 0; // position for scroll (horizontal scrolling not implemented yet)
    int visible_lines = max_Y - 2;

    prefresh(pad, vertical_offset, 0, 1, 1, max_Y - 2, max_X - 2);

    while (true) {
        int key = wgetch(stdscr);
        if (key == 'q') break;
        if (key == KEY_DOWN && vertical_offset < pad_height - visible_lines) vertical_offset++;
        if (key == KEY_UP && vertical_offset > 0) vertical_offset--;

        prefresh(pad, vertical_offset, 0, 1, 1, max_Y - 2, max_X - 2);
    }

    endwin();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file-path>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];
    std::string file_content = readFile(file_path);

    DisplayNcurses(file_content);

    return 0;
}

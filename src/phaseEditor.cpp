#include "phaseEditor.h"

void EditFile(Editor& phase) {
    phase.InitEditor();
    phase.InitWindows();
    phase.RefreshPad();
    phase.HandleScrolling();
    phase.Terminate();
}

Editor::Editor(const std::string& fileContent) : fileContent(fileContent),win(nullptr),pad(nullptr){} 

void Editor::InitEditor() {
    initscr();
    clear();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, max_Y, max_X);
    vertical_offset = 0; // position for scroll (horizontal scrolling not implemented yet)
    refresh();
}
void Editor::InitWindows() {

    win = newwin(max_Y, max_X, 0, 0); // intialize window
    wborder(win, ' ', ' ', ACS_HLINE, ACS_HLINE, 0, 0, 0, 0);
    top_border = (max_X / 2) - 3;
    mvwprintw(win, 0, top_border, "[PHASE]");
    wrefresh(win);

    pad_height = std::count(fileContent.begin(), fileContent.end(), '\n') + 1;
    if (pad_height < max_Y - 2) pad_height = max_Y - 2;

    pad = newpad(pad_height, max_X - 2); // initialize pad (for scrolling)
    if (!pad) {
        endwin();
        std::cerr << "Failed to create pad" << std::endl;
        return;
    }

    wprintw(pad, "%s", fileContent.c_str()); // print file_content in pad
    
    visible_lines = max_Y - 2;
}
void  Editor::RefreshPad() { //RefreshPad();
    prefresh(pad, vertical_offset, 0, 1, 1, max_Y - 2, max_X - 2);
}
void Editor::HandleScrolling() {
    while (true) {
        int key = wgetch(stdscr);
        if (key == 'q') break;
        if (key == KEY_DOWN && vertical_offset < pad_height - visible_lines) vertical_offset++;
        if (key == KEY_UP && vertical_offset > 0) vertical_offset--;

        RefreshPad();
    }
}
void Editor::Terminate() {
    endwin();
}
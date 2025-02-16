#include "phaseEditor.h"

void EditFile(Editor& phase) {
    phase.InitEditor();
    phase.InitWindows();
    phase.RefreshPad();
    phase.HandleScrolling();
    phase.Terminate();
}

Editor::Editor(const std::string& fileContent) : fileContent(fileContent), win(nullptr), pad(nullptr) {}

void Editor::InitEditor() {
    initscr();
    clear();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(1);
    getmaxyx(stdscr, max_Y, max_X);
    vertical_offset = 0; // position for scroll (horizontal scrolling not implemented yet)
    cursor_Y = 0;
    cursor_X = 0;
    refresh();
}

void Editor::InitWindows() {
    win = newwin(max_Y, max_X, 0, 0); // initialize window
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

void Editor::RefreshPad() {
    // Move the cursor to the correct position in the pad
    wmove(pad, cursor_Y, cursor_X);

    // Refresh the visible portion of the pad
    prefresh(pad, vertical_offset, 0, 1, 0, max_Y - 2, max_X - 2);
}

void Editor::HandleScrolling() {
    while (true) {
        int key = wgetch(stdscr);
        if (key == 'q') break;

        // Handle scrolling
        if (key == KEY_DOWN) {
            if (cursor_Y < pad_height - 1) {
                cursor_Y++; // Move cursor down in the pad
            }
            if (cursor_Y >= vertical_offset + visible_lines) {
                vertical_offset++; // Scroll down
            }
        }
        if (key == KEY_UP) {
            if (cursor_Y > 0) {
                cursor_Y--; // Move cursor up in the pad
            }
            if (cursor_Y < vertical_offset) {
                vertical_offset--; // Scroll up
            }
        }

        if (key == KEY_LEFT && cursor_X > 0) { // left movement of the cursor
            cursor_X--;
        }
        if (key == KEY_RIGHT && cursor_X < max_X - 3) { // right movement of the cursor
            cursor_X++;
        }

        RefreshPad();
    }
}

void Editor::Terminate() {
    delwin(pad);
    delwin(win);
    endwin();
}
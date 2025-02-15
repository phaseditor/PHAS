#ifndef PHASEEDITOR_H
#define PHASEEDITOR_H

#include <iostream>
#include "readFile.h"
#include <algorithm>
#include <ncurses.h>


class Editor {

    public :
        Editor(const std::string& fileContent);
        void InitEditor();
        void InitWindows();
        void RefreshPad();
        void HandleScrolling();
        void Terminate();

    private :
        int max_X, max_Y; // Y = Row && X = Col
        int pad_height;
        int top_border;
        int vertical_offset;
        int visible_lines;

        std::string fileContent;

        WINDOW* win;
        WINDOW* pad;
};

void EditFile(Editor& phase);

#endif
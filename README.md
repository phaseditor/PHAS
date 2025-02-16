# Phase Text Editor

Welcome to **PHASE**, a lightweight and intuitive text editor designed with simplicity and functionality in mind. Created by a group of passionate classmates—**Hossein Hossein Nasab**, **Amirreza Saadi**, **Sobhan Azari**, and **Pedram Rahimi**—Phase is a project born out of curiosity and a desire to learn and create something meaningful together.

Phase is built to provide a clean and efficient text-editing experience, with a focus on usability and aesthetics. Whether you're a developer, writer, or just someone who loves working with text, Phase aims to be your go-to tool for quick and easy text manipulation.

---

## Features

### ✅ **Added Features**
- **Reading and Displaying File Content**: Phase can open and display the content of text files seamlessly.
- **Ncurses Integration**: The interface is powered by Ncurses, making it visually appealing and user-friendly.

### 🚧 **Planned Features**
- **Text Editing**: The ability to modify and manipulate text directly within the editor.
- **Saving Text**: Save your changes to the file with ease.
- **Text Highlighting**: Syntax highlighting for better readability and organization of code or text.

---

## Getting Started

### Prerequisites
- **Ncurses Library**: Ensure you have the Ncurses library installed on your system. You can install it using your package manager:
  - **Debian/Ubuntu**: `sudo apt-get install libncurses5-dev libncursesw5-dev`
  - **Arch**: `sudo pacman -S ncurses`
  - **Fedora**: `sudo dnf install ncurses-devel`
  - **macOS**: `brew install ncurses`

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/phaseditor/PHASE.git
2. Navigate to the project build directory (make one if there isn't any):
   ```bash
   cd PHASE/build
3. Build the project:
   ```bash
   cmake .. && make
4. Run the text editor:
   ```bash
   ./phase [File you want to view]
  
---

## License
Phase is open-source software licensed under the **MIT License**. Feel free to use, modify, and distribute it as per the terms of the license.

---

Thank you for checking out Phase! We hope you enjoy using it as much as we enjoyed building it. If you have any questions, suggestions, or feedback, feel free to open an issue or reach out to us. Happy coding! 🚀

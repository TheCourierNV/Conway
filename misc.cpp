#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

#include "misc.h"

#ifdef __linux__
#include "include/conio/conio.h" // Linux implementation of conio.h
#endif

#ifdef ISWINDOWS
#include <conio.h> // For the getch() function
#endif

// Function that prints text in a given Color. The actual implementation differs
// massively depending on the operating system.
void printInColor(const char *toPrint, Color color) {
// Windows version:
#ifdef ISWINDOWS

    // WinAPI boilerplate
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    // Get the exact console settings (including color) we were using before
    // printing so that we can restore them after we are done.
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    // Set a new color for the text
    switch (color) {
    case Color::red:
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
        break;

    case Color::green:
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        break;

    case Color::yellow:
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED |
                                       FOREGROUND_GREEN);
    default:

        break;
    }

    std::cout << toPrint;

    // Restore previous settings
    SetConsoleTextAttribute(h, wOldColorAttrs);

// Linux version:
//  In Linux changing the color of text in a console is very easy: you just need
//  to print an ANSI color code beforehand.
#elif __linux__
    std::string unixColorString;

    switch (color) {
    case Color::red:
        unixColorString = "\033[31;1m"; // Red
        break;

    case Color::green:
        unixColorString = "\033[32;1m"; // Green
        break;

    case Color::yellow:
        unixColorString = "\033[33;1m"; // Yellow
        break;

    default:
        unixColorString = ""; // Don't change color
        break;
    }

    std::cout
        << unixColorString << toPrint
        << "\033[0m"; // Print the desired string and reset the color afterwards
#endif
}

// Windows and linux use slightly different commands to clear the screen, so we
// use a wrapper function
void clearScreen() {
    std::string command;

#ifdef ISWINDOWS
    command = "cls";
#elif __linux__
    command = "clear";
#endif

    int garbageReturn = std::system(command.c_str());
    (void)garbageReturn;
}

// Pauses execution for a given amount of time (in ms)
void sleepFor(unsigned long long milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Print text in a way similar to the "less" command on Unix systems: one "page"
// at a time
void printPagedText(const char *toPrint) {
    std::cout << std::endl << toPrint << std::endl << std::endl;
    printInColor("Press any key to continue\n", Color::yellow);
    getch();
}

// Here to avoid a linker error with the replacement conio.h
int getInput() { return getch(); }

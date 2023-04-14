#pragma once

// Detects if we want to compile to Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

#define ISWINDOWS // Used as a shorthand for the above
#include <Windows.h>

#endif

#ifdef __linux__

#include <curses.h> // Included only for their getch() implementation
#include <term.h>   // Included only for acces to ca-mode
#endif

#ifdef ISWINDOWS
#include <conio.h> // For the getch() function
#endif

// Represents all colors currently implemented
enum class Color{
    red,
    green,
    yellow,
};

void printInColor (const char* toPrint, Color color);
void clearScreen();
void sleepFor(unsigned long long milliseconds);
void printPagedText(const char* toPrint);

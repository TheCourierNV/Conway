#pragma once

// Detects if we want to compile to Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

#define ISWINDOWS // Used as a shorthand for the above
#include <Windows.h>

#endif

// Represents all colors currently implemented
enum class Color {
    red,
    green,
    yellow,
};

void printInColor(const char *toPrint, Color color);
void clearScreen();
void sleepFor(unsigned long long milliseconds);
void printPagedText(const char *toPrint);
int getInput();

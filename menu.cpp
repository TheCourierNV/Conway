#include <iostream>
#include "menu.h"
#include "misc.h"

void printMenu(){
    clearScreen();

    std::cout << "\nConway's game of life beta 0.6.9" << std::endl;

    std::cout << "\nMade by ";
    printInColor("Andrea Scartazza", Color::red);
    std::cout << " & ";
    printInColor("Christian Canossa", Color::green);

    // Logo in ascii art
    printInColor("\n\n ________   ________   ________    ___       __    ________       ___    ___  ________                                    \n|\\   ____\\ |\\   __  \\ |\\   ___  \\ |\\  \\     |\\  \\ |\\   __  \\     |\\  \\  /  /||\\   ____\\                                   \n\\ \\  \\___| \\ \\  \\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\    \\ \\  \\\\ \\  \\_\\  \\    \\ \\  \\/  / /\\ \\  \\___|_                                  \n \\ \\  \\     \\ \\  \\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\  __\\ \\  \\\\ \\   __  \\    \\ \\    / /  \\ \\_____  \\                                 \n  \\ \\  \\____ \\ \\  \\_\\  \\\\ \\  \\\\ \\  \\\\ \\  \\_\\  \\_\\  \\\\ \\  \\ \\  \\    \\/  /  /    \\|____|\\  \\                                \n   \\ \\_______\\\\ \\_______\\\\ \\__\\\\ \\__\\\\ \\____________\\\\ \\__\\ \\__\\ __/  / /        ____\\_\\  \\                               \n    \\|_______| \\|_______| \\|__| \\|__| \\|____________| \\|__|\\|__||\\___/ /        |\\_________\\                              \n                                                                \\|___|/         \\|_________|                              \n                                                                                                                          \n                                                                                                                          \n ________   ________   _____ ______    _______           ________   ________      ___        ___   ________  _______      \n|\\   ____\\ |\\   __  \\ |\\   _    _   \\ |\\  ____\\         |\\   __  \\ |\\  _____\\    |\\  \\      |\\  \\ |\\  _____\\|\\  ____\\     \n\\ \\  \\___| \\ \\  \\_\\  \\\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ _          \\ \\  \\ \\  \\\\ \\  \\__/     \\ \\  \\     \\ \\  \\\\ \\  \\__/ \\ \\  \\ _    \n \\ \\  \\  ___\\ \\   __  \\\\ \\  \\\\|__| \\  \\\\ \\   _| __       \\ \\  \\ \\  \\\\ \\   __\\     \\ \\  \\     \\ \\  \\\\ \\   __\\ \\ \\   _| __  \n  \\ \\  \\|\\  \\\\ \\  \\ \\  \\\\ \\  \\    \\ \\  \\\\ \\  \\__\\ \\       \\ \\  \\_\\  \\\\ \\  \\_|      \\ \\  \\____ \\ \\  \\\\ \\  \\_|  \\ \\  \\__\\ \\ \n   \\ \\_______\\\\ \\__\\ \\__\\\\ \\__\\    \\ \\__\\\\ \\_______\\       \\ \\_______\\\\ \\__\\        \\ \\_______\\\\ \\__\\\\ \\__\\    \\ \\_______\\\n    \\|_______| \\|__|\\|__| \\|__|     \\|__| \\|_______|        \\|_______| \\|__|         \\|_______| \\|__| \\|__|     \\|_______|\n\n", Color::yellow);
}



void printOptions(){


    std::cout << "1) Play" << std::endl;
    std::cout << "2) Rules" << std::endl;
    std::cout << "3) Options" << std::endl;
    std::cout << "4) Quit\n" << std::endl;

    printInColor("Select: ", Color::green);

}



void printRules(){
    clearScreen();
    printPagedText("Conway's Game of Life isn't really a game: there are no players and no concept of winning or losing.\nConway's \"simulation\" is a cellular automaton that demonstrates how, from a few simple rules, life-like behaviour can be simulated.\n\nThis idea was then expanded upon and explored in different contexts like, for example:\n\n1) In 3D\n2) Using different kinds of \"cells\"\n3) Using a different set of rules");

    clearScreen();
    printPagedText("The game updates one \"step\" at a time. To determine the state of a cell in the next step you must know:\n\n1) Its current state\n2) The state of neighbouring cells.\n\nThis game relies on the execution of the following three rules:\n\n1) A 'dead' cell surrounded by exactly 3 'living' cells will turn alive. (Rule of birth);\n2) A 'living' cell surrouned by 2 or 3 other 'living' cells will stay alive (Rule of survival);\n3) In all other cases, the cell will die (Rule of isolation and Rule of overpopulation).");

    clearScreen();
    printInColor("\nControls:", Color::green);
    printPagedText("Use the arrow keys to select a cell\nUse the space bar to flip the state of the currently selected cell\nPress any other key to start the simulation!");

}



void editOptions(OptionsStruct& options){
    unsigned short selection;

    while(true){
        clearScreen();

        printMenu();

        std::cout << "1) Grid dimensions"     << std::endl;
        std::cout << "2) Update rate"    << std::endl;
        std::cout << "3) Close this menu\n" << std::endl;


        printInColor("Select: ", Color::green);
        std::cin >> selection;

        std::cout << std::endl;

        switch(selection){
            case 1:
                std::cout << "Input desired grid dimensions (default: 100 50): ";
                std::cin >> options.sizeX;
                std::cin >> options.sizeY;

                if(options.sizeX < 1)
                    options.sizeX = 1;

                if(options.sizeY < 1)
                    options.sizeY = 1;
            break;

            case 2:
                std::cout << "Input how many milliseconds the game should wait before printing a new frame (default: 30): ";
                std::cin >> options.frameWait;
            break;

            case 3:
                return;
            break;


        }


    }

}

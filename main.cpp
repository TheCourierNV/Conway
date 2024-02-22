#include <iostream>
#include <limits>

#include "Conway.h"
#include "menu.h"
#include "misc.h"
#include "myMatrix.h"

int main(int argc, char **argv) {
    OptionsStruct conwayOptions;

    int selection;

    while (true) {
        printMenu();
        printOptions();

        std::cin >> selection;

        switch (selection) {
        case 1: {
            Conway game(conwayOptions);
            game.run();
        } break;
        case 2:
            printRules();
            break;

        case 3:
            editOptions(conwayOptions);
            break;

        case 4:
            return 0;
            break;

        default:
            printInColor("Invalid input!\n", Color::red);

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            sleepFor(1000);
            break;
        }
    }
}

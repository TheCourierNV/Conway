#include <iostream>
#include <limits>

#include "myMatrix.h"
#include "Conway.h"
#include "menu.h"
#include "misc.h"

int main(int argc, char** argv){
	#ifdef __linux__

	// Initialise ncurses
    filter();
	initscr();
	filter();
	noecho();
	
	enter_ca_mode = 0; // ncurses switches the displayed output to an empty screen after using refresh() by defalt. By overwriting these variables with a 0 we disable this behaviour
	exit_ca_mode  = 0;

	endwin();
	
	#endif

	OptionsStruct conwayOptions;

	int selection;

	while(true){
		printMenu();
		printOptions();

		std::cin >> selection;
		

		switch(selection){
			case 1:{
				Conway game(conwayOptions);
				game.run();
			}
			break;
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
#include <iostream>

#include "Conway.h"
#include "misc.h"

Conway::Conway(OptionsStruct options){

    m_selectedOffsetX = 0;
    m_selectedOffsetY = 0;

    m_Board.allocateMatrix(options.sizeX, options.sizeY);
    m_minimumFrameDelta = options.frameWait;
}

void Conway::run(){

    // Windows and Linux represent the arrow keys using a series of different values. 
    // Here we define the exact values to expect in each platform

    #ifdef ISWINDOWS

    #define OS_ARROW_INIT  224
    #define OS_ARROW_UP    72
    #define OS_ARROW_DOWN  80
    #define OS_ARROW_LEFT  75
    #define OS_ARROW_RIGHT 77

    #elif __linux__

    #define OS_ARROW_INIT  27
    #define OS_ARROW_UP    65
    #define OS_ARROW_DOWN  66
    #define OS_ARROW_LEFT  68
    #define OS_ARROW_RIGHT 67

    #endif

    // Starting input

    do{

        #ifdef __linux__
        endwin(); // Here endwin() is used to exit 'ncurses mode' so that we can use regular iostream functions.
        #endif

        printNewBoard();

        #ifdef __linux__

        refresh(); // Here refresh() is used to enter into 'ncurses mode' again, so that we regain acces to the getch() function.

        #endif

        unsigned char firstChar = 0, extraLinuxChar = 0, lastKey = 0;

        firstChar = getch();

        if(firstChar != OS_ARROW_INIT){

            if(firstChar == ' '){
                flip_cell(m_selectedOffsetY, m_selectedOffsetX);
                continue;
            } else if(firstChar == '\n'){
                continue;
            }

            // If firstChar doesn't match any 'special key', we stop waiting for input and start the simulation
            break;

        }

        #ifdef __linux__

        // On Linux the arrow key sequence contains an extra byte
        extraLinuxChar = getch();
        if(extraLinuxChar != 91)
            break; // 91 is the only possible valid input in this case

        #endif

        #ifdef ISWINDOWS
        (void)extraLinuxChar; // Since this variable is completely unused on Windows, we do this to avoid triggering "unused variable" warnings
        #endif

        lastKey = getch();

        if       (lastKey == OS_ARROW_UP    && m_selectedOffsetY > 0){                      // Pressed "up" 
            m_selectedOffsetY--;
        }else if (lastKey == OS_ARROW_DOWN  && m_selectedOffsetY < m_Board.getSizeY() - 1){ // Pressed "down" 
            m_selectedOffsetY++;
        }else if (lastKey == OS_ARROW_RIGHT && m_selectedOffsetX < m_Board.getSizeX() - 1){ // Pressed "right" 
            m_selectedOffsetX++;
        }else if (lastKey == OS_ARROW_LEFT  && m_selectedOffsetX > 0){                      // Pressed "down" 
            m_selectedOffsetX--;
        }

    }while(true);


    #ifdef __linux__
    endwin();
    #endif

   // Start the simulation

    while(true){

        update();

        printNewBoard();

        sleepFor(m_minimumFrameDelta); // We pause execution for a few milliseconds to prevent flickering.

    }
}



void Conway::printNewBoard(){
    clearScreen();
    std::cout << std::endl;

    // We print one cell at a time
    for(unsigned int y = 0; y < m_Board.getSizeY(); y++){
        for(unsigned int x = 0; x < m_Board.getSizeX(); x++){

            Color color;
            std::string marker;

            // A living cell is represented by a green 'O'. while a dead cell is represented by a red 'X'
            if(m_Board[y][x].isAlive){
                color = Color::green;
                marker = "O";
            } else {
                color = Color::red;
                marker = "X";
            }

            // We change the color of the selected cell to yellow
            if ((x == m_selectedOffsetX)&&(y == m_selectedOffsetY))
                color = Color::yellow;

            printInColor(marker.c_str(), color);

            std::cout << " ";

        }
        // We reached the end of a line
        std::cout << std::endl;
    }
}



void Conway::update(){
    myMatrix<bool> tmpCopy;
    int sizeX = m_Board.getSizeX();
    int sizeY = m_Board.getSizeY();

    tmpCopy.allocateMatrix(sizeX, sizeY);

    for (int x = 0; x < sizeX; x++){
        for (int y = 0; y < sizeY; y++){
            int livingNeighbours = 0;

            for (int offset1 = -1; offset1 <= 1; offset1++){
                for (int offset2 = -1; offset2 <= 1; offset2++){
                    int totalOff1 = y + offset1;
                    int totalOff2 = x + offset2;

                    bool isOffsetNotInBounds = (offset1 == 0 && offset2 == 0) || (totalOff1 < 0) || (totalOff2 < 0) || ((unsigned)totalOff1 >= m_Board.getSizeY()) || (unsigned)totalOff2 >= m_Board.getSizeX();
                    if (isOffsetNotInBounds){
                        continue;
                    }
                    else if (m_Board[totalOff1][totalOff2].isAlive){
                        livingNeighbours++;
                    }
                }
            }

            switch (livingNeighbours){
                case 3:
                    tmpCopy[y][x] = true;
                break;
                case 2:
                    tmpCopy[y][x] = m_Board[y][x].isAlive; // Keep the previous state
                break;
                default:
                    tmpCopy[y][x] = false;
                break;
            }
        }
    }

    for (int x = 0; x < sizeX; x++){
        for (int y = 0; y < sizeY; y++){
            m_Board[y][x].isAlive = tmpCopy[y][x];
        }
    }
}

void Conway::flip_cell(unsigned int indexX, unsigned int indexY){
    m_Board[indexX][indexY].isAlive = !m_Board[indexX][indexY].isAlive;
}

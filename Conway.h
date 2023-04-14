#pragma once

#include "myMatrix.h"

// Struct that contains all game options and their default value
typedef struct{
	unsigned int sizeX = 100, sizeY = 50;
	unsigned int frameWait = 30;
}OptionsStruct;

// Representation of a "cell" in the simulation
typedef struct{
	bool isAlive = false;
	unsigned int livingNeighborCounter;
} cell;

// The main class, where the game is implemented
class Conway{
    private:
        
        myMatrix<cell> m_Board; // The grid that contains all of the cells

        // Functions related to the updating of the simulation
        
        void update();
        // Function used to display the state of the game to the user
        void printNewBoard(); 

        // Values that keep track of the selected cell
        unsigned int m_selectedOffsetX, m_selectedOffsetY;

        // Value that defines exactly how many milliseconds the game should wait between frames
        unsigned int m_minimumFrameDelta;

    public:
        Conway(OptionsStruct options);

        void flip_cell(unsigned int indexX, unsigned int indexY);

        // Entry point of the class
        void run();
};
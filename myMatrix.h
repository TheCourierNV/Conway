#pragma once
#include <iostream>

// Class that emulates a 2-dimensional array
template <typename T>
class myMatrix{
    private:
        class matrixRow{
            public:
                matrixRow(); // Why? Because new only uses 0 parameter constructors.
                T& operator[] (unsigned int index);

                bool setSize(unsigned int newSize);
                
            private:
                void allocate(unsigned int size);

                unsigned int m_size = 0;
                T* m_array;
        };

        matrixRow* m_matrix;
        unsigned int m_rowSize, m_rowAmount;

    public:
        myMatrix(unsigned int dimensionX, unsigned int dimensionY);
        myMatrix(unsigned int dimensionXY);
        myMatrix();

        void allocateMatrix(unsigned int dimensionX, unsigned int dimensionY);

        unsigned int getSizeX();
        unsigned int getSizeY();

        matrixRow& operator[] (unsigned int index);

};

// Template definitions (included here because linkers can't connect a template declaration and a definition if they are in different files)
#include "myMatrix.hpp"
// Create a 2d matrix of given size
template <typename T>
myMatrix<T>::myMatrix(unsigned int dimensionX, unsigned int dimensionY){
    allocateMatrix(dimensionX, dimensionY);
}

//Create a square matrix
template <typename T>
myMatrix<T>::myMatrix(unsigned int dimensionXY) : myMatrix(dimensionXY, dimensionXY){};

template <typename T>
myMatrix<T>::myMatrix(){
    m_rowSize = 0;
    m_rowAmount = 0;
}

template <typename T>
void myMatrix<T>::allocateMatrix(unsigned int dimensionX, unsigned int dimensionY){
    m_rowSize   = dimensionX;
    m_rowAmount = dimensionY;

    // TODO: check that m_rowSize e m_rowAmount siano == 0


    m_matrix = new matrixRow[m_rowAmount];

    for(unsigned int i = 0; i < m_rowAmount; i++) {
        m_matrix[i].setSize(m_rowSize);
    }
}

template <typename T>
typename myMatrix<T>::matrixRow& myMatrix<T>::operator[] (unsigned int index){
    if(index < m_rowAmount){
        return m_matrix[index];
    }else{
        throw std::out_of_range("Invalid index");
    }

}


// Getter per la dimensione X
template <typename T>
unsigned int myMatrix<T>::getSizeX(){
    return m_rowSize;
}

//Getter per la dimensione Y
template <typename T>
unsigned int myMatrix<T>::getSizeY(){
    return m_rowAmount;
}



template <typename T>
void myMatrix<T>::matrixRow::allocate(unsigned int size){
    m_array = new T[m_size];
}

template <typename T>
myMatrix<T>::matrixRow::matrixRow(){
    m_size = 0;
}

template <typename T>
bool myMatrix<T>::matrixRow::setSize(unsigned int newSize){
    if(m_size == 0){
        m_size = newSize;
        allocate(m_size);
        return true;

    }else{
        std::cout << "SIZE CAN ONLY BE DEFINED ONCE!" << std::endl;
        return false;
    }
}

template <typename T>
T& myMatrix<T>::matrixRow::operator[] (unsigned int index){
    if(index < m_size){
        return m_array[index];
    }else{
        throw std::out_of_range("Invalid index");
    }
}

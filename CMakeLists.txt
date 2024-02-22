cmake_minimum_required(VERSION 3.16)
project(Conway)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Conway)

target_sources(Conway
PRIVATE
    main.cpp
    Conway.cpp Conway.h
    menu.cpp menu.h
    misc.cpp misc.h
    myMatrix.hpp myMatrix.h
    include/conio/conio.h
)

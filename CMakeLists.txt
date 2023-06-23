cmake_minimum_required(VERSION 3.25)
project(anwar_mikou_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(anwar_mikou_cpp main.cpp Company.h Company.cpp Borrower.h Borrower.cpp Lender.h Lender.cpp Deal.h Deal.cpp Facility.cpp Part.cpp Portfolio.h Portfolio.cpp)

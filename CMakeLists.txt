cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessEngine main.cpp ChessEngine.cpp Board.cpp) 
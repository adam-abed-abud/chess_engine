#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

struct Square {
    Piece piece;
    bool isWhite;
};


class Move {
public:
    int startRow, startCol, endRow, endCol;
    Move(int sR, int sC, int eR, int eC);
    void display();
};


class Board {
public:
    Square board[8][8];
    Board();
    void display();
    void makeMove(const Move& move);
    void undoMove(const Move& move);
};


#endif // BOARD_HPP

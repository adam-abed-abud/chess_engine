#include "colors.h"
#include "Board.hpp"


Move::Move(int sR, int sC, int eR, int eC) : startRow(sR), startCol(sC), endRow(eR), endCol(eC) {}

void Move::display() {
    std::cout << "Move from (" << startRow << ", " << startCol << ") to ("
                  << endRow << ", " << endCol << ")\n";
}

Board::Board() {
    // Initialize board with the default chess starting position
    // Place rooks
    board[0][0] = { ROOK, true };
    board[0][7] = { ROOK, true };
    board[7][0] = { ROOK, false };
    board[7][7] = { ROOK, false };

    // Place knights
    board[0][1] = { KNIGHT, true };
    board[0][6] = { KNIGHT, true };
    board[7][1] = { KNIGHT, false };
    board[7][6] = { KNIGHT, false };

    // Place bishops
    board[0][2] = { BISHOP, true };
    board[0][5] = { BISHOP, true };
    board[7][2] = { BISHOP, false };
    board[7][5] = { BISHOP, false };

    // Place queens
    board[0][3] = { QUEEN, true };
    board[7][3] = { QUEEN, false };

    // Place kings
    board[0][4] = { KING, true };
    board[7][4] = { KING, false };

    // Place pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = { PAWN, true };
        board[6][i] = { PAWN, false };
    }

    // Initialize the rest of the board to empty
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = { EMPTY, false };
        }
    }


}

void Board::display() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j].isWhite) {
              switch (board[i][j].piece) {
                  case EMPTY: std::cout << "."; break;
                  case PAWN: std::cout << FBLU("P"); break;
                  case KNIGHT: std::cout << FBLU("N"); break;
                  case BISHOP: std::cout << FBLU("B"); break;
                  case ROOK: std::cout << FBLU("R"); break;
                  case QUEEN: std::cout << FBLU("Q"); break;
                  case KING: std::cout << FBLU("K"); break;
              }
            } else {
              switch (board[i][j].piece) {
                  case EMPTY: std::cout << "."; break;
                  case PAWN: std::cout << FRED("P"); break;
                  case KNIGHT: std::cout << FRED("N"); break;
                  case BISHOP: std::cout << FRED("B"); break;
                  case ROOK: std::cout << FRED("R"); break;
                  case QUEEN: std::cout << FRED("Q"); break;
                  case KING: std::cout << FRED("K"); break;

              }                
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}



void Board::makeMove(const Move& move) {
    board[move.endRow][move.endCol] = board[move.startRow][move.startCol];
    board[move.startRow][move.startCol] = { EMPTY, false };
}

void Board::undoMove(const Move& move) {
    board[move.startRow][move.startCol] = board[move.endRow][move.endCol];
    board[move.endRow][move.endCol] = { EMPTY, false };
}

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
            switch (board[i][j].piece) {
                case EMPTY: std::cout << "."; break;
                case PAWN: std::cout << "P"; break;
                case KNIGHT: std::cout << "N"; break;
                case BISHOP: std::cout << "B"; break;
                case ROOK: std::cout << "R"; break;
                case QUEEN: std::cout << "Q"; break;
                case KING: std::cout << "K"; break;
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
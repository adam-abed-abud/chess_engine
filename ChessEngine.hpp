#ifndef CHESSENGINE_HPP
#define CHESSENGINE_HPP

#include <vector>
#include "Board.hpp"

class ChessEngine {
public:
    
    std::vector<Move> generateMoves(bool isWhiteTurn);
    void updateBoard(Board newBoard);
    int evaluateBoard(Board board);
    int minimax(int depth, bool isMaximizingPlayer, int alpha, int beta, Move& bestMove_white, Move& bestMove_black);


private: 
    Board m_board;

};


#endif // CHESSENGINE_HPP

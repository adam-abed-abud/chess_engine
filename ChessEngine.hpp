#ifndef CHESSENGINE_HPP
#define CHESSENGINE_HPP

#include <vector>
#include "Board.hpp"

class ChessEngine {
public:
    Board board;
    std::vector<Move> generateMoves(bool isWhiteTurn);
};


#endif // CHESSENGINE_HPP

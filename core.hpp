#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include "Board.hpp"

int evaluateBoard(const Board& board);
int minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta);

#endif // CORE_HPP

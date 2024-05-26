
#include "Board.hpp"
#include "ChessEngine.hpp"

int evaluateBoard(const Board& board) {
    int score = 0;
    // Simple evaluation: material count
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board.board[i][j].piece != EMPTY) {
                int pieceValue = 0;
                switch (board.board[i][j].piece) {
                    case PAWN: pieceValue = 10; break;
                    case KNIGHT: case BISHOP: pieceValue = 30; break;
                    case ROOK: pieceValue = 50; break;
                    case QUEEN: pieceValue = 90; break;
                    case KING: pieceValue = 900; break;
                }
                score += (board.board[i][j].isWhite ? pieceValue : -pieceValue);
            }
        }
    }
    return score;
}

int minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta) {
    if (depth == 0) {
        int minum_score = evaluateBoard(board);
        std::cout << "BENZINA!!!" << std::endl;
        return minum_score;

    }


    ChessEngine engine;
    std::vector<Move> moves = engine.generateMoves(isMaximizingPlayer);

    Move bestMove(0,0,0,0);

    if (isMaximizingPlayer) {
        int maxEval = -10000; // Initialize to negative infinity
        for (const Move& move : moves) {
            std::cout << "Considering this move: ";
            Move theMove = move;
            theMove.display();

            board.makeMove(move); // Make the move
            auto eval = minimax(board, depth - 1, false, alpha, beta); // Recur with decreased depth
            board.undoMove(move); // Undo the move
            if (eval > maxEval) {
                maxEval = eval ; // Update maximum evaluation
                Move bestMove = move; // Update best move
                std::cout << " BEST MOVE: ";
                bestMove.display();
                std::cout << "Best score: " << maxEval << std::endl;
            }            
            alpha = std::max(alpha, eval); // Update alpha
            if (beta <= alpha) { // Beta cut-off
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = 10000; // Initialize to positive infinity
        for (const Move& move : moves) {
            board.makeMove(move); // Make the move
            auto eval = minimax(board, depth - 1, true, alpha, beta); // Recur with decreased depth
            board.undoMove(move); // Undo the move
            if (eval < minEval) {
                minEval = eval; // Update minimum evaluation
                bestMove = move; // Update best move
            }            
            beta = std::min(beta, eval); // Update beta
            if (beta <= alpha) { // Alpha cut-off
                break;
            }
        }
        return minEval;
    }
}

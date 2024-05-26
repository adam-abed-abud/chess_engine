# A Simple Chess Engine written in C++ 

This is a purely algorithmic implementation of a chess engine (no fancy ML/DL methods are applied). In order to choose the best move, a recursive `minimax` function is applied to the given board setup. This algorithm evaluates each move for a given player with the goal of finding the move that leads to the best outcome. The minimax algorithm considers both maximizing the player's score and minimizing the opponent's score. The `minimax` algorithm also uses an `alpha-beta pruning` in order to reduce the number of moves to be evaluated at each board position. The main idea is to eliminate branches in the tree that cannot possibly influence the final decision. Here is how it works:
* Alpha represents the minimum score that the maximizing player is assured of. Initially, it is set to a very low value (-infinity).
* Beta represents the maximum score that the minimizing player is assured of. Initially, it is set to a very high value (infinity).

During the minimax search means two operations:
* Maximizing player tries to maximize the score. It updates alpha with the maximum value found so far.
* Minimizing player tries to minimize the score. It updates beta with the minimum value found so far.

If at any point, alpha becomes greater than or equal to beta, it means that the current branch cannot affect the outcome, and further exploration of this branch is unnecessary. This is called a beta cut-off (if minimizing player cuts off) or an alpha cut-off (if maximizing player cuts off).

Here is the code that implements the `minimax algorithm` with the `alpha-beta pruning` technique:
```
int ChessEngine::minimax(int depth, bool isMaximizingPlayer, int alpha, int beta, Move& bestMove_white, Move& bestMove_black) {
    Board board = m_board;

    if (depth == 0) {
        int minum_score = evaluateBoard(board);
        return minum_score;
    }

    std::vector<Move> moves = generateMoves(isMaximizingPlayer);
   
    if (isMaximizingPlayer) {
        int maxEval = -10000; // Initialize to negative infinity
        for (const Move& move : moves) {
            //std::cout << "Considering this move: ";
            //Move theMove = move;
            //theMove.display();

            board.makeMove(move); // Make the move
            auto eval = minimax(depth - 1, false, alpha, beta, bestMove_white, bestMove_black); // Recur with decreased depth
            board.undoMove(move); // Undo the move
            if (eval > maxEval) {
                maxEval = eval ; // Update maximum evaluation
                bestMove_white = move; // Update best move          
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
            auto eval = minimax(depth - 1, true, alpha, beta, bestMove_white, bestMove_black); // Recur with decreased depth
            board.undoMove(move); // Undo the move
            if (eval < minEval) {
                minEval = eval; // Update minimum evaluation
                bestMove_black = move; // Update best move
            }            
            beta = std::min(beta, eval); // Update beta
            if (beta <= alpha) { // Alpha cut-off
                break;
            }
        }
        return minEval;
    }
}
```


##  How to build 
```
mkdir build; cd build
cmake ../
make -j
./ChessEngine
```

# To DO
* add castling logic to the king's allowed movements

#include <iostream>
#include "ChessEngine.hpp"  
#include "Board.hpp"

int main() {
    // Initialize the board
    Board board;
    
    // Display the initial board setup
    std::cout << "Initial Board Setup:\n";
    board.display();

    // Create a ChessEngine instance
    ChessEngine engine;

    // Generate moves for white
    //std::cout << "\nGenerating moves for White:\n";
    //std::vector<Move> whiteMoves = engine.generateMoves(true);
    //for (const Move& move : whiteMoves) {
    //    std::cout << "Move from (" << move.startRow << ", " << move.startCol << ") to ("
    //              << move.endRow << ", " << move.endCol << ")\n";
    //}
  
    //// Generate moves for black
    //std::cout << "\nGenerating moves for Black:\n";
    //std::vector<Move> blackMoves = engine.generateMoves(false);
    //for (const Move& move : blackMoves) {
    //    std::cout << "Move from (" << move.startRow << ", " << move.startCol << ") to ("
    //              << move.endRow << ", " << move.endCol << ")\n";
    //}


    // Perform a minimax search to determine the best move for white
    std::cout << "\nPerforming minimax search for White (depth 3):\n";

    Move bestMove_white(0,0,0,0);
    Move bestMove_black(0,0,0,0);

    bool isWhiteTurn = true;

    for (int i=0; i<10; ++i) {
      auto score = engine.minimax(3, isWhiteTurn, -10000, 10000, bestMove_white, bestMove_black);
      //std::cout << "Minimax score: " << score << "\n";
      if (isWhiteTurn) {
        board.makeMove(bestMove_white);
        isWhiteTurn = false;
        std::cout << "BEST MOVE FOR WHITE: ";
        bestMove_white.display();            
      } else {
        board.makeMove(bestMove_black);
        isWhiteTurn = true;
        std::cout << "BEST MOVE FOR BLACK: ";
        bestMove_black.display();            
      }
      engine.updateBoard(board);

      board.display();
      std::cout << "==================== \n\n\n";
    }

    return 0;
}

#include <iostream>
#include "ChessEngine.hpp"  
#include "Board.hpp"
#include "core.hpp"

int main() {
    // Initialize the board
    Board board;
    
    // Display the initial board setup
    std::cout << "Initial Board Setup:\n";
    board.display();

    // Create a ChessEngine instance
    ChessEngine engine;

    // Generate moves for white
    std::cout << "\nGenerating moves for White:\n";
    std::vector<Move> whiteMoves = engine.generateMoves(true);
    for (const Move& move : whiteMoves) {
        std::cout << "Move from (" << move.startRow << ", " << move.startCol << ") to ("
                  << move.endRow << ", " << move.endCol << ")\n";
    }

    // Generate moves for black
    std::cout << "\nGenerating moves for Black:\n";
    std::vector<Move> blackMoves = engine.generateMoves(false);
    for (const Move& move : blackMoves) {
        std::cout << "Move from (" << move.startRow << ", " << move.startCol << ") to ("
                  << move.endRow << ", " << move.endCol << ")\n";
    }

    // Perform a minimax search to determine the best move for white
    std::cout << "\nPerforming minimax search for White (depth 3):\n";
    auto score = minimax(board, 3, true, -10000, 10000);
    std::cout << "Minimax score: " << score << "\n";

    return 0;
}

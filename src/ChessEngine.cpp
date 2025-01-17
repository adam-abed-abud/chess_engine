#include <iostream>
#include <vector>
#include "ChessEngine.hpp"
#include "Board.hpp"

void ChessEngine::updateBoard(Board newBoard) {
    m_board = newBoard;
}


int ChessEngine::evaluateBoard(Board board) {
    int score = 0;
    // Simple evaluation: material count
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (m_board.board[i][j].piece != EMPTY) {
                int pieceValue = 0;
                switch (m_board.board[i][j].piece) {
                    case PAWN: pieceValue = 10; break;
                    case KNIGHT: case BISHOP: pieceValue = 30; break;
                    case ROOK: pieceValue = 50; break;
                    case QUEEN: pieceValue = 90; break;
                    case KING: pieceValue = 900; break;
                }
                score += (m_board.board[i][j].isWhite ? pieceValue : -pieceValue);
            }
        }
    }
    return score;
}

int ChessEngine::minimax(int depth, bool isMaximizingPlayer, int alpha, int beta, Move& bestMove_white, Move& bestMove_black) {
    Board board = m_board;

    if (depth == 0) {
        int minum_score = evaluateBoard(board);
        return minum_score;
    }

    //if (isMaximizingPlayer) {
    //  std::cout << "BEST MOVE SO FAR FOR WHITE: ";
    //  bestMove_white.display();    
    //} else {
    //  std::cout << "BEST MOVE SO FAR FOR BLACK: ";
    //  bestMove_black.display();    
    //}
      

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




std::vector<Move> ChessEngine::generateMoves(bool isWhiteTurn) {
    std::vector<Move> moves;
    // Implement move generation for all pieces
    // Example for pawns:
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Check if the piece at current position belongs to the current player
            if (m_board.board[i][j].isWhite == isWhiteTurn) {
                // Depending on the piece type, generate moves
                switch (m_board.board[i][j].piece) {            
                    case PAWN:
                        // Add pawn moves
                        if (isWhiteTurn && i < 7 && m_board.board[i + 1][j].piece == EMPTY) {
                            moves.push_back(Move(i, j, i + 1, j));
                        } else if (!isWhiteTurn && i > 0 && m_board.board[i - 1][j].piece == EMPTY) {
                            moves.push_back(Move(i, j, i - 1, j));
                        }
                        // Add capture moves for pawns
                        if (isWhiteTurn && i < 7 && j > 0 && m_board.board[i + 1][j - 1].isWhite != isWhiteTurn) {
                            moves.push_back(Move(i, j, i + 1, j - 1));
                        } else if (!isWhiteTurn && i > 0 && j > 0 && m_board.board[i - 1][j - 1].isWhite != isWhiteTurn) {
                            moves.push_back(Move(i, j, i - 1, j - 1));
                        }
                        if (isWhiteTurn && i < 7 && j < 7 && m_board.board[i + 1][j + 1].isWhite != isWhiteTurn) {
                            moves.push_back(Move(i, j, i + 1, j + 1));
                        } else if (!isWhiteTurn && i > 0 && j < 7 && m_board.board[i - 1][j + 1].isWhite != isWhiteTurn) {
                            moves.push_back(Move(i, j, i - 1, j + 1));
                        }
                        break;

                    case KNIGHT:
                        // Add knight moves
                        // Example: Move 2 squares vertically and 1 square horizontally
                        if (i + 2 < 8) {
                            if (j + 1 < 8 && (m_board.board[i + 2][j + 1].piece == EMPTY || m_board.board[i + 2][j + 1].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i + 2, j + 1));
                            }
                            if (j - 1 >= 0 && (m_board.board[i + 2][j - 1].piece == EMPTY || m_board.board[i + 2][j - 1].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i + 2, j - 1));
                            }
                        }
                        if (i - 2 >= 0) {
                            if (j + 1 < 8 && (m_board.board[i - 2][j + 1].piece == EMPTY || m_board.board[i - 2][j + 1].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i - 2, j + 1));
                            }
                            if (j - 1 >= 0 && (m_board.board[i - 2][j - 1].piece == EMPTY || m_board.board[i - 2][j - 1].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i - 2, j - 1));
                            }
                        }
                        if (j + 2 < 8) {
                            if (i + 1 < 8 && (m_board.board[i + 1][j + 2].piece == EMPTY || m_board.board[i + 1][j + 2].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i + 1, j + 2));
                            }
                            if (i - 1 >= 0 && (m_board.board[i - 1][j + 2].piece == EMPTY || m_board.board[i - 1][j + 2].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i - 1, j + 2));
                            }
                        }
                        if (j - 2 >= 0) {
                            if (i + 1 < 8 && (m_board.board[i + 1][j - 2].piece == EMPTY || m_board.board[i + 1][j - 2].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i + 1, j - 2));
                            }
                            if (i - 1 >= 0 && (m_board.board[i - 1][j - 2].piece == EMPTY || m_board.board[i - 1][j - 2].isWhite != isWhiteTurn)) {
                                moves.push_back(Move(i, j, i - 1, j - 2));
                            }
                        }
                        break;
                    case BISHOP:
                        // Add bishop moves
                        // Example: Diagonal moves
                        // Add moves along the top-left diagonal
                        for (int k = 1; i + k < 8 && j + k < 8; ++k) {
                            if (m_board.board[i + k][j + k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i + k, j + k));
                            } else if (m_board.board[i + k][j + k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i + k, j + k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the top-right diagonal
                        for (int k = 1; i + k < 8 && j - k >= 0; ++k) {
                            if (m_board.board[i + k][j - k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i + k, j - k));
                            } else if (m_board.board[i + k][j - k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i + k, j - k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the bottom-left diagonal
                        for (int k = 1; i - k >= 0 && j + k < 8; ++k) {
                            if (m_board.board[i - k][j + k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i - k, j + k));
                            } else if (m_board.board[i - k][j + k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i - k, j + k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the bottom-right diagonal
                        for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
                            if (m_board.board[i - k][j - k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i - k, j - k));
                            } else if (m_board.board[i - k][j - k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i - k, j - k));
                                break;
                            } else {
                                break;
                            }
                        }
                        break;

                    case ROOK:
                        // Add rook moves
                        // Example: Horizontal and vertical moves
                        // Add moves along the same row to the right
                        for (int k = j + 1; k < 8; ++k) {
                            if (m_board.board[i][k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i, k));
                            } else if (m_board.board[i][k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i, k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the same row to the left
                        for (int k = j - 1; k >= 0; --k) {
                            if (m_board.board[i][k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i, k));
                            } else if (m_board.board[i][k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i, k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the same column downwards
                        for (int k = i + 1; k < 8; ++k) {
                            if (m_board.board[k][j].piece == EMPTY) {
                                moves.push_back(Move(i, j, k, j));
                            } else if (m_board.board[k][j].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, k, j));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the same column upwards
                        for (int k = i - 1; k >= 0; --k) {
                            if (m_board.board[k][j].piece == EMPTY) {
                                moves.push_back(Move(i, j, k, j));
                            } else if (m_board.board[k][j].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, k, j));
                                break;
                            } else {
                                break;
                            }
                        }
                        break;

                    case QUEEN:
                        // Add queen moves
                        // Example: Moves combining rook and bishop moves
                                                
                        // Right along the same row
                        for (int k = j + 1; k < 8; ++k) {
                            if (m_board.board[i][k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i, k));
                            } else if (m_board.board[i][k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i, k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Left along the same row
                        for (int k = j - 1; k >= 0; --k) {
                            if (m_board.board[i][k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i, k));
                            } else if (m_board.board[i][k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i, k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Down along the same column
                        for (int k = i + 1; k < 8; ++k) {
                            if (m_board.board[k][j].piece == EMPTY) {
                                moves.push_back(Move(i, j, k, j));
                            } else if (m_board.board[k][j].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, k, j));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Up along the same column
                        for (int k = i - 1; k >= 0; --k) {
                            if (m_board.board[k][j].piece == EMPTY) {
                                moves.push_back(Move(i, j, k, j));
                            } else if (m_board.board[k][j].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, k, j));
                                break;
                            } else {
                                break;
                            }
                        }
                    
                        // Add moves along diagonal directions (like a bishop)
                        // Add moves along the top-left diagonal
                        for (int k = 1; i + k < 8 && j + k < 8; ++k) {
                            if (m_board.board[i + k][j + k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i + k, j + k));
                            } else if (m_board.board[i + k][j + k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i + k, j + k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the top-right diagonal
                        for (int k = 1; i + k < 8 && j - k >= 0; ++k) {
                            if (m_board.board[i + k][j - k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i + k, j - k));
                            } else if (m_board.board[i + k][j - k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i + k, j - k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the bottom-left diagonal
                        for (int k = 1; i - k >= 0 && j + k < 8; ++k) {
                            if (m_board.board[i - k][j + k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i - k, j + k));
                            } else if (m_board.board[i - k][j + k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i - k, j + k));
                                break;
                            } else {
                                break;
                            }
                        }
                        // Add moves along the bottom-right diagonal
                        for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
                            if (m_board.board[i - k][j - k].piece == EMPTY) {
                                moves.push_back(Move(i, j, i - k, j - k));
                            } else if (m_board.board[i - k][j - k].isWhite != isWhiteTurn) {
                                moves.push_back(Move(i, j, i - k, j - k));
                                break;
                            } else {
                                break;
                            }
                        }
                        break;

                    case KING:
                        // Add king moves
                        // Example: Moves one square in any direction
                        // Add moves to adjacent squares in all directions
                        for (int dx = -1; dx <= 1; ++dx) {
                            for (int dy = -1; dy <= 1; ++dy) {
                                if (i + dx >= 0 && i + dx < 8 && j + dy >= 0 && j + dy < 8 && (dx != 0 || dy != 0)) {
                                    if (m_board.board[i + dx][j + dy].piece == EMPTY || m_board.board[i + dx][j + dy].isWhite != isWhiteTurn) {
                                        moves.push_back(Move(i, j, i + dx, j + dy));
                                    }
                                }
                            }
                        }
                        // Add castling moves
                        // Note: Implement castling logic separately
                        break;

                    default:
                        break;



                }
            }    
        }
    }
    return moves;
}


#include <iostream>
#include <vector>


enum Piece {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};


struct Square {
    Piece piece;
    bool isWhite;
};



// Class of the chess board
class Board {
public:
  Square board[8][8];

  // Default starting position of the chess
  board() {
    board[0][0] = {ROOCK, true};
    board[0][7] = {ROOCK, true};
    board[7][0] = {ROOCK, false};
    board[7][7] = {ROOCK, false};

  }

  // Method to visualize thge board
  void display() {
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            switch (boar[i][j].piece) {
            case EMPTY: std::cout << "."; break;
            case PAWN: std::cout << "P"; break;
            case KNIGHT: std::cout << "N"; break;
            case BISHOP: std::cout << "B"; break;
            case ROOK: std::cout << "R"; break;
            case QUEEN: std::cout << "Q"; break;
            case KING: std::cout << "K"; break;

            }
            std::cout << " " ;
        }
        std::cout << std::endl;
    }
  } 



};


class Move {

public: 
   int startRow, startCol, endRow, endCol; 
   Move(int sR, int sC, int eR, int eC) : startRow(sR), startCol(sC), endRow(eR), endCol(eC) {}
};


class ChessEngine {
public:
   Board board;

   std::vector<Move> generateMoves(bool isWhiteTurn) {
    std::vector<Move> moves ;
    // Implement move generation for all pieces 
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            if (board.board[i][j].piece == PAWN && board.board[i][j].isWhite == isWhiteTurn) {
                // Add pawn moves 
                if (isWhiteTurn && i<7 && board.board[i+1][j].piece == EMPTY) {
                    moves.push_back(Move(i,j, i+1, j));
                } else if  (!isWhiteTurn && i>0 && board.board[i-1][j].piece == EMPTY) {
                    moves.push_back(Move(i,j, i-1, j));

                }

            }

        }
    }


   return moves;
   }


};


// Define a score to the given board
int evaluateBord(const Board& board) {
    int score = 0;

    // Material count of all the pieces 
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {

            if (board.board[i][j].piece != EMPTY) {
                int pieceValue = 0; 
                switch (board.board[i][j].piece) {
                case PAWN: pieceValue = 10; break;
                case KNIGHT: pieceValue = 30; break;
                case BISHOP: pieceValue = 30; break;

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

// Implement a search algorithm for the best move (Minimax with Alpha Beta pruning)
int minimax(Board& board, int depth, bool isMaximingPlayer, int alpha, int beta) {

    if (depth == 0) {
        return evaluateBord(board);
    }

    ChessEngine engine;
    std::vector<Move> moves = engine.generateMoves(isMaximingPlayer);

    if (isMaximingPlayer) {
        int maxEval = -10000;
        for (const Move& move: moves) {
            Board newBoard = board; // make a copy of the board

            // Apply the move and evalueate the new score
            int eval = minimax(newBoard, depth-1, false, alpha, beta);
            max_eval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);

            if (beta <= alpha) {
                break;
            }
        }
        return maxEval;

    } else {
        int minEval = 10000;
        for (const Move& move: moves) {
            Board newBoard = board;
            int eval = minimax(newBoard, depth-1, true, alpha, beta);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);

            if(beta <= alpha) {
                break;
            }

        }

        return minEval;
    }




}
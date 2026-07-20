#include "backend/gameSolvers/tango/src/tangoBoard.h"
// NOTE: it is assumed that the board will be solvable as an input. 
/*
solve(board):
    find the next Empty cell
    if none left → board is full and valid → SOLVED

    for each symbol in [Moon, Sun]:
        place symbol in that cell
        if board still valid:
            if solve(board):     # recurse into the rest
                return true
        remove symbol (set back to Empty)   # backtrack

    return false   # neither worked, dead end
*/

class TangoSolver {
    private:
        TangoBoard board;
    
    public:
        explicit TangoSolver(TangoBoard board) 
            : board(std::move(board)) {}

        bool solve() {
            /* 
                Main solve function for Tango
            */
            int row = -1;
            int col = -1;
            for (int r = 0; r < board.getRows(); r++) {
                for (int c = 0; c < board.getCols(); c++) {
                    if (board.at(r, c) == Cell::Empty) {
                        row = r;
                        col = c;
                        break;
                    }
                }
            }

            // all squares finished
            if (row == -1 and col == -1) {
                return true;
            }

            for (Cell cell : {Cell::Moon, Cell::Sun}) {
                board.setCell(row, col, cell);
            }
        }

        bool isValid() {

        }

        bool threeConsecutive() {

        }

        bool checkRelations() {

        }
};
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


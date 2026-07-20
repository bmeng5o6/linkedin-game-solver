#ifndef TANGOSOLVER_H
#define TANGOSOLVER_H

#include "backend/gameSolvers/tango/src/tangoBoard.h"

class TangoSolver {
    private:
        TangoBoard board;

        bool isValid(int row, int col) const;
        bool threeConsecutive(int row, int col) const;
        bool checkRelations (int row, int col) const;
    
    public:
        explicit TangoSolver(TangoBoard board);
        bool solve();
        const TangoBoard& result() const { return board; }
};

#endif
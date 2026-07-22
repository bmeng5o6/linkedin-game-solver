#ifndef TANGOSOLVER_H
#define TANGOSOLVER_H

#include "backend/gameSolvers/tango/src/tangoBoard.h"
#include <map>
#include <utility>

class TangoSolver {
    private:
        TangoBoard board;

        using CellPos = std::pair<int, int>;
        using CellPair = std::pair<CellPos, CellPos>;
        std::map<CellPair, Rel> relationMap;

        void buildRelationMap();

        bool isValid(int row, int col) const;
        bool noThreeConsecutive(int row, int col) const;
        bool checkRelations (int row, int col) const;
    
    public:
        explicit TangoSolver(TangoBoard board);
        bool solve();
        const TangoBoard& result() const { return board; }
};

#endif
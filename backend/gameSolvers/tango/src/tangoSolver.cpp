#include "backend/gameSolvers/tango/src/tangoSolver.h"

// NOTE: it is assumed that the board will be solvable as an input. 

TangoSolver::TangoSolver(TangoBoard board) 
    : board(std::move(board)) {
        buildRelationMap();
    }

void TangoSolver::buildRelationMap() {
    for (const Relation& rel : board.getRelations()) {
        CellPos a = {rel.r1, rel.c1};
        CellPos b = {rel.r2, rel.c2};
        relationMap[{a, b}] = rel.relation;
        relationMap[{b, a}] = rel.relation;
    }
}

bool TangoSolver::solve() {
    /* 
        Main solve function for Tango
    */
    int row = -1;
    int col = -1;
    bool found = false;
    for (int r = 0; r < board.getRows() && !found; r++) {
        for (int c = 0; c < board.getCols(); c++) {
            if (board.at(r, c) == Cell::Empty) {
                row = r;
                col = c;
                found = true;
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
        if (isValid(row, col)) {
            if (solve()) {
                return true;
            }
        } 
        board.setCell(row, col, Cell::Empty);
    }

    return false;
}

bool TangoSolver::isValid(int row, int col) const {
    return (noThreeConsecutive(row, col) && checkRelations(row, col));
}

bool TangoSolver::noThreeConsecutive(int row, int col) const {
    Cell curr = board.at(row, col);

    // Horizontal first
    for (int start = col - 2; start <= col; start++) {
        if (start < 0 || start + 2 >= board.getCols()) {
            continue;
        }

        if (board.at(row, start) == curr && 
            board.at(row, start + 1) == curr && 
            board.at(row, start + 2) == curr) {
                return false;
        }
    }      
    
    // Vertical
    for (int start = row - 2; start <= row; start++) {
        if (start < 0 || start + 2 >= board.getRows()) {
            continue;
        }

        if (board.at(start, col) == curr && 
            board.at(start + 1, col) == curr && 
            board.at(start + 2, col) == curr) {
                return false;
        }
    } 

    return true;
}

bool TangoSolver::checkRelations(int row, int col) const {
    Cell curr = board.at(row, col);
    if (curr == Cell::Empty) {
        return true;
    }

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int nr = row + directions[i][0];
        int nc = col + directions[i][1];

        if (nr < 0 || nr >= board.getRows() || nc < 0 || nc >= board.getCols()) {
            continue;
        }

        CellPair key = {{row, col}, {nr, nc}};
        auto nxt = relationMap.find(key);
        if (nxt == relationMap.end()) {
            continue;
        }

        Rel rel = nxt->second;
        Cell neighbor = board.at(nr, nc);

        if (neighbor == Cell::Empty) {
            continue;
        } 

        if (rel == Rel::Equal && curr != neighbor) {
            return false;
        } else if (rel == Rel::Cross && curr == neighbor) {
            return false;
        }
    }

    return true;
}
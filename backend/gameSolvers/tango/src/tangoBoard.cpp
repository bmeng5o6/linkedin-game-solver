#include <vector>
#include <string>
#include "tangoBoard.h"

TangoBoard::TangoBoard(int numRows = 6, int numCols = 6) 
    : rows(numRows), cols(numCols), board(numRows, std::vector<Cell>(numCols, Cell::Empty)) {}

void TangoBoard::applyFilled(std::vector<Filled> filled) {
    for (const Filled& f : filled) {
        board[f.r1][f.c1] = f.cell;
    }
}

Cell TangoBoard::at(int row, int col) const {
    return this->board[row][col];
}

void TangoBoard::setRelations(const std::vector<Relation>& relations) {
    this->relations = relations;
}

void TangoBoard::setCell(int row, int col, Cell cell) {
    this->board[row][col] = cell;
}

std::string TangoBoard::toString() const {
    std::string curr = "";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Cell cell = board[r][c];
            char ch = (cell == Cell::Empty) ? '_'
                    : (cell == Cell::Moon) ? 'M' : 'S';
            curr += ch;
            curr += (c != cols - 1) ? " " : "";
        }
        curr += "\n";
    }
    return curr;
};
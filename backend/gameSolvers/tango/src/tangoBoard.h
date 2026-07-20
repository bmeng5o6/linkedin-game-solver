#ifndef TANGOBOARD_H
#define TANGOBOARD_H

#include <iostream>
#include <vector>
#include <string>

// Enums
enum class Cell { Empty, Moon, Sun };
enum class Rel { None, Cross, Equal };

struct Relation {
    int r1, c1; // first cell
    int r2, c2; // second cell
    Rel relation;
};

struct Filled {
    int r1, c1; // target cell location
    Cell cell;
};

class TangoBoard {
    private:
        int rows;
        int cols;
        std::vector<std::vector<Cell>> board; // current board
        std::vector<Relation> relations;
        
    public:
        TangoBoard(int numRows = 6, int numCols = 6);
        
        void applyFilled(std::vector<Filled> filled);

        int getRows() const { return rows; }
        int getCols() const { return cols; }
        const std::vector<Relation>& getRelations() const { return relations; }
        
        Cell at(int row, int col) const;
        void setRelations(const std::vector<Relation>& relations);
        void setCell(int row, int col, Cell cell);

        std::string toString() const;
};

#endif
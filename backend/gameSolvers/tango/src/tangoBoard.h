#pragma once
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
        TangoBoard(int numRows = 6, int numCols = 6) 
            : rows(numRows), cols(numCols), board(numRows, std::vector<Cell>(numCols, Cell::Empty)) {}
        
        void applyFilled(std::vector<Filled> filled) {
            for (const Filled& f : filled) {
                board[f.r1][f.c1] = f.cell;
            }
        }
        
        void setRelations(const std::vector<Relation>& relations) {
            this->relations = relations;
        }

        int getRows() {
            return rows;
        }

        int getCols() {
            return cols;
        }
        
        Cell at(int row, int col) const {
            return this->board[row][col];
        }

        std::string toString() {
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
        }


};
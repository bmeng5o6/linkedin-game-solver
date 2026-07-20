#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "backend/gameSolvers/lib/doctest.h"
#include "backend/gameSolvers/tango/src/tangoBoard.h"

TEST_CASE("Board creation") {
    TangoBoard tb;
    CHECK(tb.getRows() == 6);
    CHECK(tb.getCols() == 6);

    bool allEmpty = true;
    for (int r = 0; r < tb.getRows(); r++) {
        for (int c = 0; c < tb.getCols(); c++) {
            if (tb.at(r, c) != Cell::Empty) {
                allEmpty = false;
                break;
            }
        }
    }
    CHECK(allEmpty);
}

TEST_CASE("Set and get board cells") {
    TangoBoard tb;
    tb.setCell(1, 1, Cell::Moon);
    CHECK(tb.at(1, 1) == Cell::Moon);

    tb.setCell(1, 1, Cell::Empty);
    CHECK(tb.at(1, 1) == Cell::Empty);
}


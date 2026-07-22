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

TEST_CASE("Set board cells via filled") {
    TangoBoard tb;
    std::vector<Filled> filled {
        Filled{0, 0, Cell::Moon},
        Filled{3, 2, Cell::Sun}
    };

    tb.applyFilled(filled);
    CHECK(tb.at(0, 0) == Cell::Moon);
    CHECK(tb.at(3, 2) == Cell::Sun);
    for (int r = 0; r < tb.getRows(); r++) {
        for (int c = 0; c < tb.getCols(); c++) {
            if ((r != 0 || c != 0) && (r != 3 || c != 2)) {
                CHECK(tb.at(r, c) == Cell::Empty);
            }
        }
    }
}

#include "backend/gameSolvers/lib/doctest.h"
#include "backend/gameSolvers/tango/src/tangoBoard.h"
#include "backend/gameSolvers/tango/src/tangoSolver.h"

TEST_CASE("Empty board solver, can be completed") {
    TangoBoard tb;
    TangoSolver ts(tb);

    CHECK(ts.solve());
}

TEST_CASE("Empty board, with relations") {
    TangoBoard tb;
    std::vector<Relation> relations{
        {0, 0, 0, 1, Rel::Cross},
        {4, 4, 4, 3, Rel::Equal}
    };

    tb.setRelations(relations);
    TangoSolver ts(tb);
    
    CHECK(ts.solve());
}

TEST_CASE("Empty board, impossible with relations") {
    TangoBoard tb;
    std::vector<Relation> relations{
        {0, 0, 0, 1, Rel::Equal},
        {0, 1, 0, 2, Rel::Equal},
        {0, 2, 0, 3, Rel::Equal}
    };

    tb.setRelations(relations);
    TangoSolver ts(tb);

    CHECK(!ts.solve());
}

TEST_CASE("Actual puzzle, with filled") {
    TangoBoard tb;
    std::vector<Filled> filled {
        {0, 0, Cell::Sun}, 
        {0, 2, Cell::Moon},
        {2, 4, Cell::Sun},
        {5, 1, Cell::Sun}
    };
    tb.applyFilled(filled);

    std::vector<Relation> relations{
        {0, 0, 0, 1, Rel::Equal},
        {0, 1, 0, 2, Rel::Cross},
        {1, 2, 1, 3, Rel::Equal}
    };

    tb.setRelations(relations);
    TangoSolver ts(tb);

    CHECK(ts.solve());
}
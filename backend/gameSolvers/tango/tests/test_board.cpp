#include <cassert>
#include <iostream>
#include "../src/tangoBoard.h"

void testBoardCreation() {
    TangoBoard tb;
    assert(tb.getRows() == 6);
    assert(tb.getCols() == 6);

    bool allEmpty = true;
    for (int r = 0; r < tb.getRows(); r++) {
        for (int c = 0; c < tb.getCols(); c++) {
            if (tb.at(r, c) != Cell::Empty) {
                allEmpty = false;
                break;
            }
        }
    }
    assert(allEmpty);
}
int main() {

}
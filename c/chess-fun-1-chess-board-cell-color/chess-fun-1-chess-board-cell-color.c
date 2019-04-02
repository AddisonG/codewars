#include <stdbool.h>

bool isMatching(int x, int y) {
  return x % 2 == y % 2;
}

bool chess_board_cell_color(const char* cell1, const char *cell2) {
  if (isMatching(cell1[0], cell2[0])) {
    // Matching column
    return isMatching(cell1[1], cell2[1]);
  } else {
    // Alternate column
    return !isMatching(cell1[1], cell2[1]);
  }
}

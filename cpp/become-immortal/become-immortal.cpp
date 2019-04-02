using namespace std;

/*
Here is an illustration of my solution.

We want to find X, which has size ROW * COL

<---- Square ---->
<--- Row ---><-a->

+------------+---+   ^    ^
|            |   |   |    |
|            |   |   |    |
|      X     | A |  Col   |
|            |   |   |  Square
|            |   |   v    |
+------------+---+   ^    |
|      B     | Y |   b    |
+------------+---+   v    v

We can easily find the sum of a single row or column in a 2^N square.
(It's got every number from 0 - square exactly once).
The formula is just (square - 1) * (square / 2). I call this linesum.

So we can easily find the value of (see diagram):
 (1) = X+A (linesum * col)
 (2) = X+B (linesum * row)
 (3) = X+A+B+Y (linesum * square)

I simply add (1) and (2) together to get 2X+A+B, and then subtract (3) to get X-Y.

This means to find X, all I have to do is find Y and add it.

And funnily enough, Y is actually just a smaller version of X.
The sides are (square - row) and (square - col).
Recurse, solve.

==EDGE CASES==
 1)
 The sides must BOTH be within the 2^N square, and neither must fit within the square that is half that amount (2^(N-1)).
 If this happens, I solve it by splitting into the rectangle of linesums from the 2^(N-1) square, and the other part, which recurses as normal.
*/

#define bigint __int128_t

/**
 * Given a 2^N square, calculate the sum of the digits in a single line of that square.
 */
bigint getLineSum(bigint square, bigint tloss, bigint mod) {
  if (tloss >= square) {
    return 0;
  }
  bigint rowValue = (square - 1) * square / 2;
  bigint triangularNumber = tloss * (tloss + 1) / 2;
  return (rowValue - tloss * square + triangularNumber) % mod;
}

uint64_t elder_age(bigint cols, bigint rows, bigint tloss, bigint mod) {
  bigint res;
  if (!cols || !rows) {
    return 0;
  } else if (cols == 1 || rows == 1) {
    bigint single = rows * cols;
    if (single <= tloss) {
      return 0;
    }
    bigint triangularNumber = tloss * (tloss + 1) / 2;
    if (single & 1) {
      res = (single * (single - 1) / 2) % mod;
    } else {
      res = (single / 2 * (single - 1)) % mod;
    }
    return (triangularNumber > res) ? mod - triangularNumber + res : res - triangularNumber;
  }
  
  // Find a 2^N square which can fit the bounds inside it.
  bigint square = 1;
  while ((square < rows || square < cols)) {
    square <<= 1;
  }
  
  bigint halfSquare = square / 2;
  bigint largest = max(rows, cols);
  bigint smallest = min(rows, cols);
  if (smallest < halfSquare && largest != square) {
    // The smaller of the two sides is better suited to a smaller square.
    // The problem will need to be split in two.
    bigint lineSum = getLineSum(halfSquare, tloss, mod);
    if (halfSquare > tloss) {
      bigint evenGrid = ((smallest * (largest - halfSquare)) % mod * (halfSquare - tloss)) % mod;
      return (elder_age(smallest, largest - halfSquare, 0, mod) + evenGrid + lineSum * smallest) % mod;
    }
    return (elder_age(smallest, largest - halfSquare, tloss - halfSquare, mod) + lineSum * smallest) % mod;
  }
  
  // Both sides were well suited to the size of the square. Find the size of the square, the subtract the
  // two rectangles at the edges (linesum * rows and linesum * cols), and the square on the opposite (recurse).

  bigint lineSum = getLineSum(square, tloss, mod);
  res = (lineSum * (rows + cols - square)) % mod + elder_age(square - cols, square - rows, tloss, mod);
  return res % mod;
}

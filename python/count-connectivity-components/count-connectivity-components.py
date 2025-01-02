#!/usr/bin/env python3.11

from typing import List, Set, Tuple


class Cell():
    def __init__(self, col: int, row: int, left = None, above = None) -> None:
        self.col = col
        self.row = row
        self.left = left
        self.above = above
        self.right = None
        self.below = None

        # Link the other ones to us as well
        if left:
            left.right = self
        if above:
            above.below = self

    def get_family(self) -> Set:
        """Used to be recursive. Not a good idea."""
        family = {self}
        neighbours = [self.left, self.right, self.above, self.below]

        while neighbours:
            candidate = neighbours[0]
            if (candidate is not None) and (candidate not in family):
                family.add(candidate)
                neighbours.append(candidate.left)
                neighbours.append(candidate.right)
                neighbours.append(candidate.above)
                neighbours.append(candidate.below)
            del neighbours[0]

        return family


    def __repr__(self) -> str:
        # For debugging
        links = ""
        if self.left:
            links += "+LEFT"
        if self.above:
            links += "+UP"
        if self.right:
            links += "+RIGHT"
        if self.below:
            links += "+DOWN"
        return f"<Cell {self.row}x{self.col}{links}>"


def convert_to_graph(grid: str) -> Cell:
    lines = grid.split("\n")

    height = (len(lines) - 1) // 2
    width = (len(lines[0]) - 1) // 3

    cells = {}
    col_links = []  # for linking one column to another: |
    row_links = []  # for linking one row to another: --

    # Find col: |
    for row in range(height):
        col_links.append([])
        for col in range(width + 1):
            symbol = lines[row * 2 + 1][col * 3]
            col_links[-1].append(symbol)

    # Find row: --
    for row in range(height + 1):
        row_links.append([])
        for col in range(width):
            symbol = lines[row * 2][col * 3 + 1]
            row_links[-1].append(symbol)

    # Create the cells
    for row in range(height):
        cells[row] = {}
        for col in range(width):
            left = None
            above = None
            if col_links[row][col] != "|":
                left = cells[row][col - 1]
            if row_links[row][col] != "-":
                above = cells[row - 1][col]
            new = Cell(col, row, left=left, above=above)
            cells[row][col] = new

    return set([cell for row in cells.values() for cell in row.values()])


def components(grid: str) -> List[Tuple[int, int]]:
    res = {}
    cells = convert_to_graph(grid)
    processed = set()

    while True:
        # Janky - just get the next thing that hasn't been processed
        starter = next(iter(cells - processed), None)
        if starter is None:
            break
        next_family = starter.get_family()
        size = len(next_family)
        processed.update(next_family)

        res[size] = res.get(size, 0) + 1

    # Dunno why they want it in this garbage format lol
    weird_tuple_list_thing_that_should_have_been_a_dict = []
    for x in sorted(res.keys(), reverse=True):
        weird_tuple_list_thing_that_should_have_been_a_dict.append((x, res[x]))

    return weird_tuple_list_thing_that_should_have_been_a_dict

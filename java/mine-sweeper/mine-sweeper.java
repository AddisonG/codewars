import java.util.*;

/**
  * Terminology:
  *  - To "OPEN" is to activate a cell that is unknown
  *  - A cell can be one of 3 states: "UNKNOWN", "SAFE" or "MINE"
  * 
  * ROW = Y = HEIGHT
  * COL = X = WIDTH
  */
class MineSweeper {
  public static final char MINE = 'x';
  public static final char UNKNOWN = '?';
  
  private final Set<Cell> cells, unresolvedCells;
  private final int rows, cols;
  private int remainingMines;
  
  public MineSweeper(String grid, int nMines) {
    System.out.println("--------START--------");
    this.cols = grid.indexOf('\n') / 2 + 1;
    this.cells = readBoard(grid);
    this.unresolvedCells = new TreeSet<>(cells);
    this.rows = cells.size() / cols; // not used (yet?)
    this.remainingMines = nMines;
  }
  
  public String solve() {
    while (true) {
      if (opener() || complexOpener()) {
        continue;
      }
      break; // No progress is being made.
    }
    System.out.println("---------END---------");
    return writeBoard();
  }
  
  // If a cell can only have mines around it, flag them all
  // If a cell already has enough mines around it, open all remaining
  private boolean opener() {
    boolean result = false;
    Iterator<Cell> iter = unresolvedCells.iterator();
    while (iter.hasNext()) {
      Cell cell = iter.next();
      if (cell.getState() >= '0' && cell.getState() < '9') {
        List<Cell> unknowns = cell.getSurroundingUnknown();
        int missingMineCount = cell.missingMineCount();
//         System.out.println("Found " + cell + " " + mines + " " + unknowns);
        if (missingMineCount == unknowns.size()) {
          unknowns.forEach(unknown -> unknown.setState(MINE));
          remainingMines -= unknowns.size();
          iter.remove();
          result = true;
        } else if (missingMineCount == 0) {
          unknowns.forEach(surrounding -> surrounding.open());
          iter.remove();
          result = true;
        }
      } else if (cell.getState() == MINE) {
        iter.remove();
      }
    }
    return result;
  }
  
  private boolean complexOpener() {
    List<Set<Cell>> groups = new ArrayList<>();
    for (Cell cell : unresolvedCells) {
      if (cell.getState() == UNKNOWN && (groups.stream().filter(group -> group.contains(cell)) == null || groups.isEmpty())) {
        Set<Cell> group = new TreeSet<>();
        groups.add(group);
        handleUnknownGroup(group, cell);
      }
    }
    System.out.println(groups);
    return false;
  }
  
  private void handleUnknownGroup(Set<Cell> set, Cell seed) {
    for (Cell cell : seed.getSurroundingUnknown()) {
      if (!set.contains(cell)) {
        set.add(cell);
        handleUnknownGroup(set, cell);
      }
    }
  }
  
  private Set<Cell> readBoard(String grid) {
    Set<Cell> cells = new TreeSet<>();
    Cell previous = null;
    List<Cell> previousRow = null;
    
    int row = 0, col;
    for (String line : grid.split("\n")) {
      col = 0;
      List<Cell> thisRow = new ArrayList<>();
      previous = null;
      
      for (char c : line.toCharArray()) {
        if (c == ' ') {
          continue;
        }
        Cell cell = new Cell(c, row, col, previous, previousRow);
        cells.add(cell);
        thisRow.add(cell);
        previous = cell;
        col++;
      }
      row++;
      previousRow = thisRow;
    }
    return cells;
  }
  
  private String writeBoard() {
    boolean failFlag = false;
    StringBuilder sb = new StringBuilder();
    for (Cell cell : cells) {
      if (cell.getState() == UNKNOWN) {
        failFlag = true;
      }
      sb.append(cell.getState()).append(' ');
      if (cell.getSurroundingCell(1, 0) == null) {
        sb.setLength(sb.length() - 1);
        sb.append('\n');
      }
    }
    sb.setLength(sb.length() - 1);
    if (failFlag) {
      System.out.println("ACTUAL: \r\n" + sb);
      return "?";
    }
    return sb.toString();
  }
  
  private class Cell implements Comparable<Cell> {
    private final List<Cell> surrounding = new ArrayList<>(); // Stored Left->Right, Top->Bottom (like a book)
    private final int row, col;
    private char state;
    
    public Cell(char state, int row, int col, Cell previous, List<Cell> previousRow) {
      this.state = state;
      this.row = row;
      this.col = col;
      
      if (previousRow != null) {
        linkCells(col > 0 ? previousRow.get(col - 1) : null);
        linkCells(previousRow.get(col));
        linkCells(col + 1 < cols ? previousRow.get(col + 1) : null);
      }
      linkCells(previous);
    }
    
    private void linkCells(Cell other) {
      if (other != null) {
        other.surrounding.add(this);
        this.surrounding.add(other);
      }
    }
    
    public int missingMineCount() {
      return state - '0' - getSurroundingMines().size();
    }
    
    public char getState() {
      return state;
    }
    
    public void setState(char state) {
      this.state = state;
    }
    
    public List<Cell> getSurrounding() {
      return surrounding;
    }
    
    public Cell getSurroundingCell(int x, int y) {
      for (Cell cell : surrounding) {
        if (cell.row == this.row + y && cell.col == this.col + x) {
          return cell;
        }
      }
      return null;
    }
    
    public List<Cell> getSurroundingUnknown() {
      List<Cell> list = new ArrayList<>(surrounding);
      list.removeIf(cell -> cell.getState() != UNKNOWN);
      return list;
    }
    
    public List<Cell> getSurroundingMines() {
      List<Cell> list = new ArrayList<>(surrounding);
      list.removeIf(cell -> cell.getState() != MINE);
      return list;
    }
    
    public int open() {
      int result = Game.open(row, col);
      setState((char) (result + '0'));
      return result;
    }
    
    @Override
    public int compareTo(Cell other) {
      if (this.row - other.row != 0) {
        return this.row - other.row;
      }
      return this.col - other.col;
    }
    
    public String toString() {
      return "(" + col + "," + row + "=" + state + ")";
    }
  }
}

using namespace std;

bool path_finder(string maze) {
  int n = maze.find("\n"); // Maze dimensions
  maze[0] = 'S'; // Set "Search" location to (0,0)
  // Add wall above and below, for safety
  maze = (ostringstream() << string(n, 'W') << '\n' << maze << '\n' << string(n, 'W')).str();
  
  while (maze.find("S") != string::npos) {
    char& c = maze[maze.find("S")]; // "Search"
    c = 'X'; // "Explored"
    
    char& left = *(&c - 1);
    char& right = *(&c + 1);
    char& above = *(&c - n - 1);
    char& below = *(&c + n + 1);
    left = (left == '.' ? 'S' : left);
    right = (right == '.' ? 'S' : right);
    above = (above == '.' ? 'S' : above);
    below = (below == '.' ? 'S' : below);
  }
  return maze[maze.length() - n - 1 - 1] == 'X';
}

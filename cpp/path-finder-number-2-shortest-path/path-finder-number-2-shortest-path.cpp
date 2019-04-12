using namespace std;

bool update_adjacent(char& status, int& thisDistance, int& otherDistance) {
  if (status == 'S' || status == 'X') {
    if (otherDistance >= 0 && (thisDistance < 0 || otherDistance + 1 < thisDistance)) {
      thisDistance = otherDistance + 1; // Other is 2+ less than this - update this
      return true;
    } else if (thisDistance + 1 < otherDistance) {
      otherDistance = thisDistance + 1; // This is 2+ less than other - update other
      status = 'S';
    }
  }
  status = (status == '.' ? 'S' : status);
  return false;
}

int path_finder(string maze) {
  if (maze.length() == 1) {
    return 0;
  }
  int n = maze.find("\n"); // Maze dimensions
  maze[0] = 'S'; // Set "Search" location to (0,0)
  // Add wall above and below, for safety
  maze = (ostringstream() << string(n, 'W') << '\n' << maze << '\n' << string(n, 'W')).str();
  
  // Init distances array
  vector<int> distances((n + 1) * (n + 2), -1);
  distances[n + 1] = 0;
  
  while (maze.find("S") != string::npos) {
    int index = maze.find("S"); // "Search"
    char& c = maze[index];
    int& d = distances[index];
    c = 'X';
    
    for (bool changes = true; changes;) {
      changes = update_adjacent(*(&c - 1), d, *(&d - 1));
      changes |= update_adjacent(*(&c + 1), d, *(&d + 1));
      changes |= update_adjacent(*(&c - n - 1), d, *(&d - n - 1));
      changes |= update_adjacent(*(&c + n + 1), d, *(&d + n + 1));
    }
  }
  return distances[maze.length() - n - 1 - 1];
}

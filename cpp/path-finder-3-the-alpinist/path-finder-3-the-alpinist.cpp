using namespace std;

bool update_adjacent(char thisHeight, char otherHeight, int& thisDistance, int& otherDistance) {
  if (otherHeight > '9' || otherHeight < '0') {
    return false;
  }
  int difference = abs(otherHeight - thisHeight);
  if (otherDistance >= 0 && (thisDistance < 0 || otherDistance + difference < thisDistance)) {
    thisDistance = otherDistance + difference;
    return true;
  } else if (thisDistance + difference < otherDistance) {
    otherDistance = thisDistance + difference;
  }
  return false;
}

int path_finder(string maze) {
  if (maze.length() == 1) {
    return 0;
  }
  int n = maze.find("\n"); // Maze dimensions
  
  // Add wall above and below, for safety
  maze = (ostringstream() << string(n, 'X') << '\n' << maze << '\n' << string(n, 'X')).str();
  
  // Init distances array
  vector<int> distances((n + 1) * (n + 2), -1);
  distances[n + 1] = 0;
  
  for (bool loopChanges = true; loopChanges;) {
    loopChanges = false;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        int index = (y + 1) * (n + 1) + x;
        char& height = maze[index];
        int& distance = distances[index];
        
        for (bool changes = true; changes; loopChanges |= changes) {
          changes = update_adjacent(height, *(&height - 1), distance, *(&distance - 1));
          changes |= update_adjacent(height, *(&height + 1), distance, *(&distance + 1));
          changes |= update_adjacent(height, *(&height - n - 1), distance, *(&distance - n - 1));
          changes |= update_adjacent(height, *(&height + n + 1), distance, *(&distance + n + 1));
        }
      }
    }
  }
  
  return distances[maze.length() - n - 1 - 1];
}

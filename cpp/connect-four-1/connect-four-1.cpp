using namespace std;

bool checkBoard(int column, string board[7]) {
  int row = board[column].length() - 1;
  char player = board[column][row];
  
  int count = 0;
  for (int i = 0; i < 7; i++) { // Horizontal ( - )
    count -= board[i][row] == player ? -1 : count;
    if (count >= 4) {
      return true;
    }
  }
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 4; x++) { // Diagonal ( / )
      if (board[x][y] == board[x + 1][y + 1] &&
          board[x][y] == board[x + 2][y + 2] &&
          board[x][y] == board[x + 3][y + 3] &&
          board[x][y] == player) {
        return true;
      }
    }
    for (int x = 3; x < 7; x++) { // Diagonal ( \ )
      if (board[x][y] == board[x - 1][y + 1] &&
          board[x][y] == board[x - 2][y + 2] &&
          board[x][y] == board[x - 3][y + 3] &&
          board[x][y] == player) {
        return true;
      }
    }
  }
  return board[column].find(string(4, player)) != string::npos; // Vertical ( | )
}

string who_is_winner(vector<string> moves) {
  char player = moves[0][2];
  string board[7];
  
  for (string move : moves) {
    board[move[0] - 'A'].append(string(1, player));
    cout << board[0] << endl << board[1] << endl << board[2] << endl << board[3] << endl << board[4] << endl << board[5] << endl << board[6] << endl << "-------" << endl;
    if (checkBoard(move[0] - 'A', board)) {
      cout << (player == 'R' ? "Red" : "Yellow") << " wins!" << endl;
      return player == 'R' ? "Red" : "Yellow";
    }
    player = player == 'R' ? 'Y' : 'R';
  }
  return "Draw";
}

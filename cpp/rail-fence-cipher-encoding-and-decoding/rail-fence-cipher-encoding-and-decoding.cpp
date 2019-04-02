using namespace std;

string encode_rail_fence_cipher(string str, int n) {
  string result = "";
  int maxJump = (n - 1) * 2, jump = maxJump;
  for (int i = 0; i < n; i++) {
    int pointer = i;
    while (pointer < str.length()) {
      result += str[pointer];
      pointer += jump;
      jump = maxJump == jump ? maxJump : maxJump - jump;
    }
    jump = maxJump - 2 * (i + 1) ? maxJump - 2 * (i + 1) : maxJump;
  }
  return result;
}

string decode_rail_fence_cipher(string str, int n) {
  string result(str.length(), '\0');
  int maxJump = n * 2 - 2, jump = maxJump;
  int src = 0;
  for (int i = 0; i < n; i++) {
    for (int dest = i; dest < str.length(); src++) {
      result[dest] = str[src];
      dest += jump;
      jump = maxJump == jump ? maxJump : maxJump - jump;
    }
    jump = maxJump - 2 * (i + 1) ? maxJump - 2 * (i + 1) : maxJump;
  }
  return result;
}

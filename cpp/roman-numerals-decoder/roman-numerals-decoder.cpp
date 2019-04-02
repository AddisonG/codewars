using namespace std;

map<char, int> num {
  {'M', 1000},
  {'D', 500},
  {'C', 100},
  {'L', 50},
  {'X', 10},
  {'V', 5},
  {'I', 1}
};

int solution(string roman) {
  int value = 0, prev = 0;
  for (char c : roman) {
    if (prev != 0 && num[c] > num[prev]) {
      value -= 2 * num[prev];
    }
    value += num[c];
    prev = c;
  }
  return value;
}

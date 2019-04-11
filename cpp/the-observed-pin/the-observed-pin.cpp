using namespace std;

string adjacent[10] = {"08","124","2135","326","4157","52468","6359","748","85790","968"};

vector<string> get_pins(string observed) {
  vector<string> result;
  if (observed.size() == 1) {
    for (char c : adjacent[observed[0] - '0']) {
      result.push_back(string(1, c));
    }
    return result;
  }
  for (string s : get_pins(observed.substr(1))) {
    for (char c : adjacent[observed[0] - '0']) {
      result.push_back(c + s);
    }
  }
  return result;
}

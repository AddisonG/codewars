#include <iostream>

string to_alternating_case(const string& str) {
  std::string altStr;
  for (char c : str) {
    if (isupper(c)) {
      altStr += tolower(c);
    } else {
      altStr += toupper(c);
    }
  }
  return altStr;
}

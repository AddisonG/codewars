using namespace std;

map<char, int> decode {
  {'M', 1000},
  {'D', 500},
  {'C', 100},
  {'L', 50},
  {'X', 10},
  {'V', 5},
  {'I', 1}
};

map<int, char> encode {
  {1000, 'M'},
  {500, 'D'},
  {100, 'C'},
  {50, 'L'},
  {10, 'X'},
  {5, 'V'},
  {1, 'I'}
};

class FUCK_THIS_KATA_AND_ITS_BULLSHIT_LACK_OF_TESTS {

  public: static int from_roman(string roman) {
    int value = 0, prev = 0;
    for (char c : roman) {
      if (prev != 0 && decode[c] > decode[prev]) {
        value -= 2 * decode[prev];
      }
      value += decode[c];
      prev = c;
    }
    return value;
  }
  
  public: static string to_roman(int number) {
    string roman;
    int div = 1000;
    while (div > 0) {
      int digit = (number % (div * 10)) / div;
      if (digit == 9) {
        roman += encode[div];
        roman += encode[div * 10];
      } else if (digit == 4) {
        roman += encode[div];
        roman += encode[div * 5];
      } else if (digit > 0) {
        if (digit > 4) {
          roman += encode[div * 5];
        }
        while (digit-- % 5 > 0) {
          roman += encode[div];
        }
      }
      div /= 10;
    }
    return roman;
  }
};

// WHY THE FUCK DO I NEED THIS LINE? IT TOOK ME AN HOUR TO FIGURE THIS SHIT OUT
FUCK_THIS_KATA_AND_ITS_BULLSHIT_LACK_OF_TESTS RomanNumerals;

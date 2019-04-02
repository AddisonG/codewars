using namespace std;

#include <unordered_map>

static void mov(unordered_map<string, int>& regs, string x, string y) {
  if (isalpha(y[0])) {
    regs[x] = regs[y];
  } else {
    regs[x] = stoi(y);
  }
}

static void inc(unordered_map<string, int>& regs, string x) {
  regs[x]++;
}

static void dec(unordered_map<string, int>& regs, string x) {
  regs[x]--;
}

static void jnz(unordered_map<string, int>& regs, int& instruction, string x, string y) {
  if (x == "0" || (regs.find(x) != regs.end() && regs[x] == 0)) {
    return;
  }
  --instruction += stoi(y);
}

unordered_map<string, int> assembler(const vector<string>& program) {
  unordered_map<string, int> regs = {};
  int instruction = -1;
  
  while (++instruction < program.size()) {
    string line = program[instruction];
    int splitIndex = line.find(" ", 4);
    switch (line[0]) {
        case 'm':
          mov(regs, line.substr(4, splitIndex - 4), line.substr(splitIndex + 1));
          break;
        case 'i':
          inc(regs, line.substr(4));
          break;
        case 'd':
          dec(regs, line.substr(4));
          break;
        case 'j':
          jnz(regs, instruction, line.substr(4, splitIndex - 4), line.substr(splitIndex + 1));
          break;
    }
  }
  
  return regs;
}

using namespace std;

class Accumul {
    public: static string accum(const string &s) {
        string str = "";
        int i = -1;
        while (++i < s.length()) {
            str += "-";
            str += toupper(s[i]);
            for (int j = 0; j < i; ++j) {
                str += tolower(s[i]);
            }
        }
        return str = str.substr(1, str.size() - 1);
    }
};

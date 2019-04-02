using namespace std;

#include <algorithm>
#include <climits>

class MaxDiffLength {
public:
    static int mxdiflg(vector<string> &a1, vector<string> &a2) {
        unsigned long max1 = 0, min1 = LONG_MAX, max2 = 0, min2 = LONG_MAX;
        if (! a1.size() || ! a2.size()) {
            return -1;
        }
        for (string s : a1) {
            max1 = max(max1, s.length());
            min1 = min(min1, s.length());
        }
        for (string s : a2) {
            max2 = max(max2, s.length());
            min2 = min(min2, s.length());
        }
        return max(max1 - min2, max2 - min1);
    }
};


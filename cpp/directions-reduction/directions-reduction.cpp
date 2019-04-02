using namespace std;

class DirReduction {
public:
    static vector<string> dirReduc(vector<string> &arr) {
        int size = 0;
        while (size != arr.size()) {
            size = arr.size();
            for (int i = 1; i < arr.size(); ++i) {
                if (arr[i - 1] != arr[i] && arr[i - 1].length() == arr[i].length()) {
                    arr.erase(arr.begin() + i - 1, arr.begin() + i + 1);
                    i -= 2;
                }
            }
        }
        return arr;
    }
};


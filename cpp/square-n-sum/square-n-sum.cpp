using namespace std;

#include <vector>

int square_sum(const vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
      sum += number * number;
    }
    return sum;
}

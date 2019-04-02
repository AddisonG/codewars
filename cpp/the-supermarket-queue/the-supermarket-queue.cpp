using namespace std;

long queueTime(vector<int> customers, int n) {
    int total = 0;
    while (!customers.empty()) {
        int fastest = customers[0];
        for (int i = 1; i < min(n, int(customers.size())); ++i) {
            fastest = min(fastest, customers[i]);
        }
        int gone = 0;
        for (int i = 0; i < min(n - gone, int(customers.size())); ++i) {
            customers[i] -= fastest;
            if (!customers[i]) {
                customers.erase(customers.begin() + i);
                gone++;
                i--;
            }
        }
        total += fastest;
    }
    return total;
}

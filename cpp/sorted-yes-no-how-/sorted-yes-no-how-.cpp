using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>

string is_sorted_and_how(vector<int> array) {
    vector<int> asc = array;
    vector<int> desc = array;
    sort(asc.begin(), asc.end());
    sort(desc.begin(), desc.end(), greater<int>());
    
    if (array == asc) {
        return "yes, ascending";
    } else if (array == desc) {
        return "yes, descending";
    }
    return "no";
}

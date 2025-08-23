#include <iostream>
#include <vector>
using namespace std;

vector<int> duplicateTwosExpand(const vector<int>& arr) {
    vector<int> result;
    for (int val : arr) {
        result.push_back(val);
        if (val == 2) {
            result.push_back(2);  // duplicate each 2
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5, 2};

    vector<int> expanded = duplicateTwosExpand(arr);

    for (int val : expanded)
        cout << val << " ";
    cout << endl;

    return 0;
}

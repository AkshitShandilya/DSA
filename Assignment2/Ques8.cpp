#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found) count++;
    }
    return count;
}

int main() {
    int n = 8;
    int arr[1000] = {5, 1, 2, 2, 3, 5, 4, 1};
    int distinctCount = countDistinct(arr, n);
    cout << "Number of distinct elements: " << distinctCount << endl;
    return 0;
}

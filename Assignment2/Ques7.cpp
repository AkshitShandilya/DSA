#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int invCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }
    }
    return invCount;
}

int main() {
    int n = 6;
    int arr[n] = {2, 4, 1, 3, 5, 0}; 

    int invCount = countInversions(arr, n);
    cout << "Number of inversions: " << invCount << endl;

    return 0;
}

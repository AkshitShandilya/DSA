#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]) ;

    int missing = findMissingBinary(arr, n);
    cout << "Missing number (Binary Search): " << missing << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k) {
    sort(arr, arr + n);  
    int count = 0;
    int i = 0, j = 1;

    while (j < n && i < n) {
        int diff = arr[j] - arr[i];
        if (diff == k && i < j) {
            count++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
            if (i == j)
                j++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int totalPairs = countPairsWithDiffK(arr, n, k);
    cout << "Number of pairs with difference " << k << " is: " << totalPairs << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, k = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) if (arr[i] == arr[j]) break;
        if (j == k) arr[k++] = arr[i];
    }
    n = k;
    cout << "Array after removing duplicates: ";
    for (i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

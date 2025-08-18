#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]) ;

    int missing = findMissingLinear(arr, n);
    cout << "Missing number: " << missing << endl;
    return 0;
}

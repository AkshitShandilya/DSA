#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int mi = i;
        for (int j = i+1; j < n; j++) if (a[j] < a[mi]) mi = j;
        int t = a[i]; a[i] = a[mi]; a[mi] = t;
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int t = a[i], j = i-1;
        while (j >= 0 && a[j] > t) { a[j+1] = a[j]; j--; }
        a[j+1] = t;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
}

int main() {
    int a[100], n, ch;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> ch; // 1=Selection, 2=Insertion, 3=Bubble
    if (ch == 1) selectionSort(a,n);
    if (ch == 2) insertionSort(a,n);
    if (ch == 3) bubbleSort(a,n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}

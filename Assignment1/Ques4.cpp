#include <iostream>
using namespace std;

int main() {
    int choice;
    while (1) {
        cout << "1.REVERSE ARRAY\n2.MATRIX MULTIPLICATION\n3.TRANSPOSE MATRIX\n4.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            int arr[100], n;
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            for (int i = 0, j = n - 1; i < j; i++, j--) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            cout << "Reversed array: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
        }
        else if (choice == 2) {
            int a[10][10], b[10][10], c[10][10], n1, m1, n2, m2;
            cout << "Enter rows and columns of first matrix: ";
            cin >> n1 >> m1;
            cout << "Enter elements of first matrix:\n";
            for (int i = 0; i < n1; i++) 
                for (int j = 0; j < m1; j++) cin >> a[i][j];
            cout << "Enter rows and columns of second matrix: ";
            cin >> n2 >> m2;
            cout << "Enter elements of second matrix:\n";
            for (int i = 0; i < n2; i++) 
                for (int j = 0; j < m2; j++) cin >> b[i][j];
            if (m1 != n2) { cout << "Invalid dimensions for multiplication\n"; continue; }
            for (int i = 0; i < n1; i++) 
                for (int j = 0; j < m2; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < m1; k++) c[i][j] += a[i][k] * b[k][j];
                }
            cout << "Resultant matrix:\n";
            for (int i = 0; i < n1; i++) {
                for (int j = 0; j < m2; j++) cout << c[i][j] << " ";
                cout << "\n";
            }
        }
        else if (choice == 3) {
            int a[10][10], t[10][10], n, m;
            cout << "Enter rows and columns of matrix: ";
            cin >> n >> m;
            cout << "Enter elements of matrix:\n";
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < m; j++) cin >> a[i][j];
            for (int i = 0; i < m; i++) 
                for (int j = 0; j < n; j++) t[i][j] = a[j][i];
            cout << "Transpose of matrix:\n";
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) cout << t[i][j] << " ";
                cout << "\n";
            }
        }
        else if (choice == 4) break;
        else cout << "Invalid choice\n";
    }
}

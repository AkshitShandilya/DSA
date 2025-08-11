#include <iostream>
using namespace std;

int main() {
    
  int a[10][10] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int n = 3; 
int m = 3; 


    cout << "Sum of each row:\n";
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < m; j++)
            rowSum += a[i][j];
        cout << "Row " << i + 1 << ": " << rowSum << "\n";
    }

    cout << "Sum of each column:\n";
    for (int j = 0; j < m; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++)
            colSum += a[i][j];
        cout << "Column " << j + 1 << ": " << colSum << "\n";
    }
    return 0;
}


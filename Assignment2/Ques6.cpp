#include <iostream>
using namespace std;

void printSparse(int sparse[][3], int n) {
    for (int i = 0; i < n; i++)
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
}

void transposeSparse(int sparse[][3], int n, int result[][3], int& res_n) {
    res_n = n;
    for (int i = 0; i < n; i++) {
        result[i][0] = sparse[i][1];
        result[i][1] = sparse[i][0];
        result[i][2] = sparse[i][2];
    }
    for (int i = 0; i < res_n - 1; i++) {
        for (int j = 0; j < res_n - 1 - i; j++) {
            if (result[j][0] > result[j+1][0] || (result[j][0] == result[j+1][0] && result[j][1] > result[j+1][1])) {
                int t0 = result[j][0], t1 = result[j][1], t2 = result[j][2];
                result[j][0] = result[j+1][0]; result[j][1] = result[j+1][1]; result[j][2] = result[j+1][2];
                result[j+1][0] = t0;           result[j+1][1] = t1;           result[j+1][2] = t2;
            }
        }
    }
}

void addSparse(int a[][3], int na, int b[][3], int nb, int result[][3], int& nr) {
    nr = 0;
    int i = 0, j = 0;
    while (i < na && j < nb) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[nr][0] = a[i][0];
            result[nr][1] = a[i][1];
            result[nr][2] = a[i][2];
            nr++; i++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[nr][0] = b[j][0];
            result[nr][1] = b[j][1];
            result[nr][2] = b[j][2];
            nr++; j++;
        } else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                result[nr][0] = a[i][0];
                result[nr][1] = a[i][1];
                result[nr][2] = sum;
                nr++;
            }
            i++; j++;
        }
    }
    while (i < na) {
        result[nr][0] = a[i][0];
        result[nr][1] = a[i][1];
        result[nr][2] = a[i][2];
        nr++; i++;
    }
    while (j < nb) {
        result[nr][0] = b[j][0];
        result[nr][1] = b[j][1];
        result[nr][2] = b[j][2];
        nr++; j++;
    }
}

void multiplySparse(int a[][3], int na, int a_cols, int b[][3], int nb, int result[][3], int& nr) {
    nr = 0;
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            if (a[i][1] == b[j][0]) {
                int row = a[i][0];
                int col = b[j][1];
                int val = a[i][2] * b[j][2];
                bool found = false;
                for (int k = 0; k < nr; k++) {
                    if (result[k][0] == row && result[k][1] == col) {
                        result[k][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found && val != 0) {
                    result[nr][0] = row;
                    result[nr][1] = col;
                    result[nr][2] = val;
                    nr++;
                }
            }
        }
    }
    
    for (int i = 0; i < nr - 1; i++) {
        for (int j = 0; j < nr - 1 - i; j++) {
            if (result[j][0] > result[j+1][0] || (result[j][0] == result[j+1][0] && result[j][1] > result[j+1][1])) {
                int t0 = result[j][0], t1 = result[j][1], t2 = result[j][2];
                result[j][0] = result[j+1][0]; result[j][1] = result[j+1][1]; result[j][2] = result[j+1][2];
                result[j+1][0] = t0;           result[j+1][1] = t1;           result[j+1][2] = t2;
            }
        }
    }
}

int main() {
    int A[5][3] = {
        {0, 2, 10},
        {1, 0, 5},
        {2, 1, 8},
        {2, 2, 15},
        {3, 0, 6}
    };
    int B[5][3] = {
        {0, 1, 7},
        {1, 2, 6},
        {2, 0, 4},
        {3, 2, 3},
        {3, 0, 2}
    };
    int nA = 5, nB = 5;
    int T[10][3] = {0}, C[20][3] = {0};
    int tn, cn;

    cout << "Original Sparse Matrix A (triplets):" << endl;
    printSparse(A, nA);

    transposeSparse(A, nA, T, tn);
    cout << "\nTranspose of A (sorted):" << endl;
    printSparse(T, tn);

    cout << "\nOriginal Sparse Matrix B (triplets):" << endl;
    printSparse(B, nB);

    addSparse(A, nA, B, nB, C, cn);
    cout << "\nAddition (A + B):" << endl;
    printSparse(C, cn);

    multiplySparse(A, nA, 4, B, nB, C, cn);
    cout << "\nMultiplication (A * B):" << endl;
    printSparse(C, cn);

    return 0;
}

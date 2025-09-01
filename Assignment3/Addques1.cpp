#include <iostream>
#include <stack>
using namespace std;

void nearestSmallerToLeft(int A[], int n, int result[]) {
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        result[i] = (st.empty()) ? -1 : st.top();
        st.push(A[i]);
    }
}

int main() {
    int A[] = {4, 5, 2, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int result[n];
    nearestSmallerToLeft(A, n, result);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

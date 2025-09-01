#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n, int result[]) {
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];
    nextGreaterElement(arr, n, result);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

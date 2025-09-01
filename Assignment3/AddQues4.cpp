#include <iostream>
#include <stack>
using namespace std;

void dailyTemperatures(int temperatures[], int n, int answer[]) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx;
        }
        st.push(i);
    }

}

int main() {
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temps) / sizeof(temps[0]);
    int result[n] = {0};

    dailyTemperatures(temps, n, result);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

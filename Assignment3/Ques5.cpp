#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evalPostfix(const string& expr) {
    stack<int> st;
    int n = expr.size();
    int i = 0;
    while (i < n) {
        while (i < n && expr[i] == ' ') ++i;
        if (i >= n) break;
        if ((expr[i] >= '0' && expr[i] <= '9') || (expr[i] == '-' && i+1 < n && expr[i+1] >= '0' && expr[i+1] <= '9')) {
            int sign = 1, num = 0;
            if (expr[i] == '-') { sign = -1; ++i; }
            while (i < n && expr[i] >= '0' && expr[i] <= '9') { num = num * 10 + (expr[i] - '0'); ++i; }
            st.push(sign * num);
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (expr[i]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
            ++i;
        }
    }
    return st.top();
}

int main() {
    string expr = "3 4 + 2 * 7 /";
    cout << evalPostfix(expr) << endl;
    return 0;
}

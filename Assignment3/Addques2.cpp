#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    int minEle;

public:
    MinStack() {}

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minEle = x;
        } else if (x >= minEle) {
            st.push(x);
        } else {
            st.push(2 * x - minEle);
            minEle = x;
        }
    }

    void pop() {
        if (st.empty()) return;

        int t = st.top();
        st.pop();

        if (t < minEle) {
            minEle = 2 * minEle - t;
        }
    }

    int top() {
        int t = st.top();
        if (t >= minEle) return t;
        else return minEle;
    }

    int getMin() {
        return minEle;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MinStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << "\n"; 
    s.push(2);
    s.push(1);
    cout << s.getMin() << "\n"; 
    s.pop();
    cout << s.getMin() << "\n"; 
    s.pop();
    cout << s.top() << "\n";    
    cout << s.getMin() << "\n"; 
    return 0;
}

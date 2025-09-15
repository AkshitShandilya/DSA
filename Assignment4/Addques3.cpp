#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canSortQueue(queue<int> q) {
    stack<int> s;
    int expected = 1;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        while (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
        if (curr == expected) expected++;
        else {
            if (!s.empty() && s.top() < curr)
                return false;
            s.push(curr);
        }
    }
    while (!s.empty() && s.top() == expected) {
        s.pop();
        expected++;
    }
    return expected == s.size() + q.size() + expected;
}

int main() {
    queue<int> q;
    q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);
    cout << (canSortQueue(q) ? "Yes\n" : "No\n");
    return 0;
}

#include <iostream>
#include <queue>
#include<climits>
using namespace std;

void sortQueue(queue<int>& q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int min_val = INT_MAX;
        int size = q.size();
        for (int j = 0; j < size; j++) {
            int val = q.front(); q.pop();
            if (val < min_val && j < size - i)
                min_val = val;
            q.push(val);
        }
        bool removed = false;
        size = q.size();
        for (int j = 0; j < size; j++) {
            int val = q.front(); q.pop();
            if (val == min_val && !removed) {
                removed = true;
                continue;
            }
            q.push(val);
        }
        q.push(min_val);
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);
    sortQueue(q);
    printQueue(q);
    return 0;
}

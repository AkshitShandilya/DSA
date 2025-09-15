#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();
        cout << s;
        if (i != n - 1) cout << ", ";
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << "\n";
}

int main() {
    generateBinaryNumbers(5);
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int countStudentsUnableToEat(int students[], int sandwiches[], int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(students[i]);
    int i = 0, rotations = 0;
    while (!q.empty() && rotations < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            rotations = 0;
        } else {
            q.push(q.front());
            q.pop();
            rotations++;
        }
    }
    return q.size();
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;
    cout << countStudentsUnableToEat(students, sandwiches, n) << "\n";
    return 0;
}

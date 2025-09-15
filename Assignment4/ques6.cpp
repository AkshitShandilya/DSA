#include <iostream>
using namespace std;

class StackUsingOneQueue {
    int q[100];
    int front, rear;
public:
    StackUsingOneQueue() { front = 0; rear = -1; }
    void enqueue(int x) { q[++rear] = x; }
    int dequeue() { if(front <= rear) return q[front++]; return -1; }
    int size() { return rear - front + 1; }
    void push(int x) {
        enqueue(x);
        int sz = size() - 1;
        while(sz--) enqueue(dequeue());
    }
    int pop() {
        return dequeue();
    }
};

int main() {
    StackUsingOneQueue s;
    s.push(10);
    s.push(20);
    cout << s.pop() << "\n";
    s.push(30);
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    return 0;
}

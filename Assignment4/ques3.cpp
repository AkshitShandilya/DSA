#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    bool enqueue(int x) { if(rear < 99) { arr[++rear] = x; return true; } return false; }
    int dequeue() { if(front <= rear) return arr[front++]; return -1; }
    int size() { return rear - front + 1; }
    bool isEmpty() { return front > rear; }
    void display() {
        for(int i=front; i<=rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    void interleave() {
        int n = size();
        int half = n / 2;
        int first[50], second[50];
        for(int i=0; i<half; i++) first[i] = dequeue();
        for(int i=0; i<n-half; i++) second[i] = dequeue();
        for(int i=0; i<half; i++) {
            enqueue(first[i]);
            if(i < n-half) enqueue(second[i]);
        }
    }
};

int main() {
    Queue q;
    q.enqueue(4); q.enqueue(7); q.enqueue(11);
    q.enqueue(20); q.enqueue(5); q.enqueue(9);
    q.interleave();
    q.display();
    return 0;
}

#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear, size;
public:
    Queue(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }
    void enqueue(int x) {
        if (rear == size - 1) cout << "Queue Full\n";
        else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) cout << "Queue Empty\n";
        else front++;
    }
    void display() {
        if (front == -1 || front > rear) cout << "Queue Empty\n";
        else {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
    void peek() {
        if (front == -1 || front > rear) cout << "Queue Empty\n";
        else cout << arr[front] << endl;
    }
    void isEmpty() {
        if (front == -1 || front > rear) cout << "Yes\n";
        else cout << "No\n";
    }
    void isFull() {
        if (rear == size - 1) cout << "Yes\n";
        else cout << "No\n";
    }
};

int main() {
    Queue q;
    int choice, val;
    while (1) {
        cin >> choice;
        if (choice == 1) { cin >> val; q.enqueue(val); }
        else if (choice == 2) q.dequeue();
        else if (choice == 3) q.isEmpty();
        else if (choice == 4) q.isFull();
        else if (choice == 5) q.display();
        else if (choice == 6) q.peek();
        else break;
    }
    return 0;
}

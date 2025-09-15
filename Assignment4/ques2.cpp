#include <iostream>
using namespace std;
class CircularQueue {
    int arr[100];
    int front, rear, size;
public:
    CircularQueue(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }
    void enqueue(int x) {
        if ((rear + 1) % size == front) cout << "Queue Full\n";
        else {
            if (front == -1) { front = rear = 0; }
            else rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (front == -1) cout << "Queue Empty\n";
        else if (front == rear) { front = rear = -1; }
        else front = (front + 1) % size;
    }
    void display() {
        if (front == -1) cout << "Queue Empty\n";
        else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
    void peek() {
        if (front == -1) cout << "Queue Empty\n";
        else cout << arr[front] << endl;
    }
    void isEmpty() {
        if (front == -1) cout << "Yes\n";
        else cout << "No\n";
    }
    void isFull() {
        if ((rear + 1) % size == front) cout << "Yes\n";
        else cout << "No\n";
    }
};

int main() {
    CircularQueue q;
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

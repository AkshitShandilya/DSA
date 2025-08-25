#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;

public:
    Stack(int size) {
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }

    void push(int x, int size) {
        if (top == size - 1) {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull(int size) {
        return top == size - 1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    Stack stack(size);

    while (true) {
        cout << "\n1. Push  2. Pop  3. isEmpty  4. isFull  5. Display  6. Peek  7. Exit\nChoose option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to push: ";
            cin >> val;
            stack.push(val, size);
        }
        else if (choice == 2) {
            stack.pop();
        }
        else if (choice == 3) {
            cout << (stack.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
        }
        else if (choice == 4) {
            cout << (stack.isFull(size) ? "Stack is full\n" : "Stack is not full\n");
        }
        else if (choice == 5) {
            stack.display();
        }
        else if (choice == 6) {
            stack.peek();
        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

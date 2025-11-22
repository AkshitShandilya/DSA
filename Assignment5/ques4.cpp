#include <iostream>
using namespace std;
struct Node { int data; Node* next; };
Node* head = 0;
void insert_end(int x) {
    Node* p = new Node;
    p->data = x; p->next = 0;
    if (!head) head = p;
    else {
        Node* q = head;
        while (q->next) q = q->next;
        q->next = p;
    }
}
void reverse() {
    Node* prev = 0; Node* curr = head; Node* next = 0;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void display() {
    Node* q = head;
    while (q) { cout << q->data << " "; q = q->next; }
    cout << endl;
}
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert_end(x); }
    reverse();
    display();
    return 0;
}

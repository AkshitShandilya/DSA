#include <iostream>
using namespace std;
struct Node { int data; Node* next; };
Node* head = 0;
void insert_end(int x) {
    Node* p = new Node; p->data = x; p->next = 0;
    if (!head) { head = p; p->next = head; }
    else {
        Node* q = head;
        while (q->next != head) q = q->next;
        q->next = p; p->next = head;
    }
}
void display() {
    if (!head) return;
    Node* q = head;
    do { cout << q->data << " "; q = q->next; } while (q != head);
    cout << head->data << endl;
}
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert_end(x); }
    display();
    return 0;
}

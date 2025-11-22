#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node* prev; };
Node* head = 0;
void insert_end(int x) {
    Node* p = new Node; p->data = x; p->next = 0; p->prev = 0;
    if (!head) head = p;
    else {
        Node* q = head;
        while (q->next) q = q->next;
        q->next = p; p->prev = q;
    }
}
int size_dll() {
    int s = 0; Node* q = head;
    while (q) { s++; q = q->next; }
    return s;
}
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert_end(x); }
    cout << size_dll() << endl;
    return 0;
}

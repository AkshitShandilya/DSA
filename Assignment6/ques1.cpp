#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node* prev; };
Node* head = 0;
void insert_anywhere(int x, int pos) {
    Node* p = new Node; p->data = x;
    if (!head) {
        p->next = p->prev = p; head = p;
    } else if (pos == 0) {
        p->next = head; p->prev = head->prev;
        head->prev->next = p; head->prev = p; head = p;
    } else {
        Node* q = head;
        for (int i = 0; i < pos - 1 && q->next != head; i++) q = q->next;
        p->next = q->next; p->prev = q;
        q->next->prev = p; q->next = p;
    }
}
void delete_node(int x) {
    if (!head) return;
    Node* q = head;
    do {
        if (q->data == x) {
            if (q == head && q->next == head) { delete q; head = 0; return; }
            q->prev->next = q->next; q->next->prev = q->prev;
            if (q == head) head = q->next;
            delete q; return;
        }
        q = q->next;
    } while (q != head);
}
void search(int x) {
    if (!head) { cout << "-1\n"; return; }
    Node* q = head; int pos = 1;
    do {
        if (q->data == x) { cout << pos << endl; return; }
        q = q->next; pos++;
    } while (q != head);
    cout << "-1\n";
}
int main() {
    int ch, x, pos;
    while (1) {
        cin >> ch;
        if (ch == 1) { cin >> x >> pos; insert_anywhere(x, pos); }
        else if (ch == 2) { cin >> x; delete_node(x); }
        else if (ch == 3) { cin >> x; search(x); }
        else if (ch == 4) break;
    }
    return 0;
}

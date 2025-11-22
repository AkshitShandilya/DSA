#include <iostream>
using namespace std;
struct Node { int data; Node* next; };
Node* head = 0;
void insert_beg(int x) {
    Node* p = new Node;
    p->data = x; p->next = head; head = p;
}
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
void insert_before(int val, int x) {
    if (!head) return;
    if (head->data == val) { insert_beg(x); return; }
    Node* q = head;
    while (q->next && q->next->data != val) q = q->next;
    if (q->next) {
        Node* p = new Node;
        p->data = x; p->next = q->next; q->next = p;
    }
}
void insert_after(int val, int x) {
    Node* q = head;
    while (q && q->data != val) q = q->next;
    if (q) {
        Node* p = new Node;
        p->data = x; p->next = q->next; q->next = p;
    }
}
void delete_beg() {
    if (!head) return;
    Node* p = head; head = head->next; delete p;
}
void delete_end() {
    if (!head) return;
    if (!head->next) { delete head; head = 0; return; }
    Node* q = head;
    while (q->next->next) q = q->next;
    delete q->next; q->next = 0;
}
void delete_val(int x) {
    if (!head) return;
    if (head->data == x) { Node* p = head; head = head->next; delete p; return; }
    Node* q = head;
    while (q->next && q->next->data != x) q = q->next;
    if (q->next) {
        Node* p = q->next; q->next = p->next; delete p;
    }
}
void search(int x) {
    Node* q = head; int pos = 1;
    while (q) {
        if (q->data == x) { cout << pos << endl; return; }
        q = q->next; pos++;
    }
    cout << "-1\n";
}
void display() {
    Node* q = head;
    while (q) { cout << q->data << " "; q = q->next; }
    cout << endl;
}
int main() {
    int ch, x, y;
    while (1) {
        cin >> ch;
        if (ch == 1) { cin >> x; insert_beg(x); }
        else if (ch == 2) { cin >> x; insert_end(x); }
        else if (ch == 3) { cin >> x >> y; insert_before(x, y); }
        else if (ch == 4) { cin >> x >> y; insert_after(x, y); }
        else if (ch == 5) { delete_beg(); }
        else if (ch == 6) { delete_end(); }
        else if (ch == 7) { cin >> x; delete_val(x); }
        else if (ch == 8) { cin >> x; search(x); }
        else if (ch == 9) { display(); }
        else if (ch == 10) { break; }
    }
    return 0;
}

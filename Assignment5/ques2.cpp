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
int count_key(int key) {
    Node* q = head; int cnt = 0;
    while (q) { if (q->data == key) cnt++; q = q->next; }
    return cnt;
}
void delete_key(int key) {
    while (head && head->data == key) {
        Node* p = head;
        head = head->next;
        delete p;
    }
    Node* q = head;
    while (q && q->next) {
        if (q->next->data == key) {
            Node* p = q->next;
            q->next = p->next;
            delete p;
        } else q = q->next;
    }
}
void display() {
    Node* q = head;
    while (q) { cout << q->data << " "; q = q->next; }
    cout << endl;
}
int main() {
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert_end(x); }
    cin >> key;
    int c = count_key(key);
    cout << "Count: " << c << endl;
    delete_key(key);
    display();
    return 0;
}

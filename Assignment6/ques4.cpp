#include <iostream>
using namespace std;
struct Node { char data; Node* next; Node* prev; };
Node* head = 0;
void insert_end(char x) {
    Node* p = new Node; p->data = x; p->next = 0; p->prev = 0;
    if (!head) head = p;
    else {
        Node* q = head;
        while (q->next) q = q->next;
        q->next = p; p->prev = q;
    }
}
bool is_palindrome() {
    if (!head) return true;
    Node* left = head;
    Node* right = head;
    while (right->next) right = right->next;
    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next; right = right->prev;
    }
    return true;
}
int main() {
    int n; char x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert_end(x); }
    cout << (is_palindrome() ? "Yes" : "No") << endl;
    return 0;
}

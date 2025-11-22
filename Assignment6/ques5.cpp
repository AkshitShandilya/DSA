#include <iostream>
using namespace std;
struct Node { int data; Node* next; };
Node* head = 0;
void insert_end(int x) {
    Node* p = new Node; p->data = x; p->next = 0;
    if (!head) head = p;
    else {
        Node* q = head;
        while (q->next) q = q->next;
        q->next = p;
    }
}
bool is_circular() {
    if (!head) return false;
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert_end(x); }
    cout << (is_circular() ? "Yes" : "No") << endl;
    return 0;
}

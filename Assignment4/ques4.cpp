#include <iostream>
using namespace std;

class Queue {
    char arr[100];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    void enqueue(char c) { arr[++rear] = c; }
    void dequeue() { if(front <= rear) front++; }
    bool isEmpty() { return front > rear; }
    char peek() { if(!isEmpty()) return arr[front]; return 0; }
};

void firstNonRepeating(string s) {
    int freq[256] = {0};
    Queue q;
    for(int i=0; i<(int)s.size(); i++) {
        char c = s[i];
        freq[c]++;
        q.enqueue(c);
        while(!q.isEmpty() && freq[q.peek()] > 1) q.dequeue();
        if(q.isEmpty()) cout << "-1 ";
        else cout << q.peek() << " ";
    }
    cout << "\n";
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
    return 0;
}

#include <iostream>
using namespace std;

class StackUsingTwoQueues {
    int q1[100], q2[100], f1, r1, f2, r2;
public:
    StackUsingTwoQueues() { f1=0; r1=-1; f2=0; r2=-1; }
    void enqueue1(int x) { q1[++r1] = x; }
    int dequeue1() { if(f1<=r1) return q1[f1++]; return -1; }
    void enqueue2(int x) { q2[++r2] = x; }
    int dequeue2() { if(f2<=r2) return q2[f2++]; return -1; }
    void push(int x) {
        enqueue2(x);
        while(f1 <= r1) enqueue2(dequeue1());
        swap(q1, q2);
        swap(f1, f2);
        swap(r1, r2);
    }
    int pop() {
        if(f1 > r1) return -1;
        return dequeue1();
    }
};

int main() {
    StackUsingTwoQueues s;
    s.push(10);
    s.push(20);
    cout << s.pop() << "\n";
    s.push(30);
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    return 0;
}

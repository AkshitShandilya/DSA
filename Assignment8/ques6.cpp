#include <iostream>
using namespace std;

struct PriorityQueue {
    int a[100];
    int size;
    PriorityQueue():size(0){}
    void heapifyUp(int i) {
        while(i != 0 && a[(i-1)/2] < a[i]) {
            int t = a[i]; a[i] = a[(i-1)/2]; a[(i-1)/2] = t;
            i = (i-1)/2;
        }
    }
    void heapifyDown(int i) {
        int left = 2*i + 1, right = 2*i + 2, largest = i;
        if (left < size && a[left] > a[largest]) largest = left;
        if (right < size && a[right] > a[largest]) largest = right;
        if (largest != i) {
            int t = a[i]; a[i] = a[largest]; a[largest] = t;
            heapifyDown(largest);
        }
    }
    void insert(int x) {
        a[size] = x; size++;
        heapifyUp(size-1);
    }
    int extractMax() {
        if (size <= 0) return -1;
        int root = a[0];
        a[0] = a[size-1];
        size--;
        heapifyDown(0);
        return root;
    }
};

int main() {
    PriorityQueue pq;
    int n,x;
    cin >> n;
    for(int i=0; i<n; i++) { cin >> x; pq.insert(x); }
    while(pq.size > 0) cout << pq.extractMax() << " ";
    return 0;
}

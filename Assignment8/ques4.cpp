#include <iostream>
#include <climits>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x), left(0), right(0){}
};
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data < minVal || root->data > maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data-1) &&
           isBSTUtil(root->right, root->data+1, maxVal);
}
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    cout << (isBST(root) ? "Yes\n" : "No\n");
    root->right->left = new Node(4); // Violates BST
    cout << (isBST(root) ? "Yes\n" : "No\n");
    return 0;
}

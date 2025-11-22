#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x), left(0), right(0){}
};
Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}
Node* searchRec(Node* root, int x) {
    if (!root || root->data == x) return root;
    if (x < root->data) return searchRec(root->left, x);
    return searchRec(root->right, x);
}
Node* searchNonRec(Node* root, int x) {
    while (root && root->data != x) {
        if (x < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}
Node* maxNode(Node* root) {
    if (!root) return 0;
    while (root->right) root = root->right;
    return root;
}
Node* minNode(Node* root) {
    if (!root) return 0;
    while (root->left) root = root->left;
    return root;
}
Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return minNode(x->right);
    Node* succ = 0;
    while (root) {
        if (x->data < root->data) { succ = root; root = root->left; }
        else if (x->data > root->data) root = root->right;
        else break;
    }
    return succ;
}
Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return maxNode(x->left);
    Node* pred = 0;
    while (root) {
        if (x->data > root->data) { pred = root; root = root->right; }
        else if (x->data < root->data) root = root->left;
        else break;
    }
    return pred;
}
int main() {
    Node* root = 0;
    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for(int x : arr) root = insert(root, x);
    Node* n = searchRec(root, 15);
    cout << (n ? n->data : -1) << "\n";
    n = searchNonRec(root, 100);
    cout << (n ? n->data : -1) << "\n";
    cout << maxNode(root)->data << "\n";
    cout << minNode(root)->data << "\n";
    n = inorderSuccessor(root, root->left); // successor of 10
    cout << (n ? n->data : -1) << "\n";
    n = inorderPredecessor(root, root->left->right); // predecessor of 15
    cout << (n ? n->data : -1) << "\n";
    return 0;
}

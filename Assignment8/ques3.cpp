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
Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}
Node* delNode(Node* root, int x) {
    if (!root) return root;
    if (x < root->data) root->left = delNode(root->left, x);
    else if (x > root->data) root->right = delNode(root->right, x);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = delNode(root->right, temp->data);
    }
    return root;
}
int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}
int minDepth(Node* root) {
    if (!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (!root->left) return 1 + r;
    if (!root->right) return 1 + l;
    return 1 + (l < r ? l : r);
}
int main() {
    Node* root = 0;
    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int x : arr) root = insert(root, x);
    root = delNode(root, 10);
    cout << maxDepth(root) << "\n";
    cout << minDepth(root) << "\n";
    return 0;
}

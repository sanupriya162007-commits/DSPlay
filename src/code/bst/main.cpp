// Binary Search Tree: insert, search, inorder
// Rule: smaller values go LEFT, larger values go RIGHT
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int value) {
    Node *n = new Node;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node *insert(Node *root, int value) {
    if (root == nullptr) return newNode(value);       // found an empty spot
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

bool search(Node *root, int value) {
    if (root == nullptr) return false;                // not found
    if (value == root->data) return true;             // found
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

void inorder(Node *root) {                            // left, root, right
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout << "Inorder: ";
    inorder(root);                                    // 20 30 40 50 70
    cout << endl;
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not found") << endl;
    cout << "Search 99: " << (search(root, 99) ? "Found" : "Not found") << endl;
    return 0;
}

// Binary Search Tree: insert, search, inorder
// Rule: smaller values go LEFT, larger values go RIGHT
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) return newNode(value);          // found an empty spot
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

int search(struct Node *root, int value) {
    if (root == NULL) return 0;                       // not found
    if (value == root->data) return 1;                // found
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

void inorder(struct Node *root) {                     // left, root, right
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    printf("Inorder: ");
    inorder(root);                                    // 20 30 40 50 70
    printf("\n");
    printf("Search 40: %s\n", search(root, 40) ? "Found" : "Not found");
    printf("Search 99: %s\n", search(root, 99) ? "Found" : "Not found");
    return 0;
}

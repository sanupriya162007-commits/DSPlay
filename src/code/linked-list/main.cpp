// Singly linked list: insert at head, delete first node, print
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;   // link to the next node
};

Node *head = nullptr;   // nullptr means the list is empty

void insertAtHead(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;   // new node points to the old first node
    head = newNode;         // new node becomes the first node
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;      // move head to the second node
    delete temp;
}

void printList() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;   // follow the link
    }
    cout << "NULL" << endl;
}

int main() {
    insertAtHead(30);
    insertAtHead(20);
    insertAtHead(10);
    printList();     // 10 -> 20 -> 30 -> NULL
    deleteFirst();
    printList();     // 20 -> 30 -> NULL
    return 0;
}

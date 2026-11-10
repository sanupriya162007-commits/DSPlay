// Singly linked list: insert at head, delete first node, print
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;   // link to the next node
};

struct Node *head = NULL;   // NULL means the list is empty

void insertAtHead(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;   // new node points to the old first node
    head = newNode;         // new node becomes the first node
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;      // move head to the second node
    free(temp);
}

void printList() {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;   // follow the link
    }
    printf("NULL\n");
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

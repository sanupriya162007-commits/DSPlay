// Hashing with separate chaining: each table slot holds a linked list
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Node {
    int key;
    struct Node *next;
};

struct Node *table[SIZE];          // every slot starts as NULL (empty)

int hash(int key) {
    return key % SIZE;             // hash function: remainder
}

void insert(int key) {
    int index = hash(key);
    struct Node *n = malloc(sizeof(struct Node));
    n->key = key;
    n->next = table[index];        // collision? just join the list
    table[index] = n;
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        struct Node *current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(10);   // 10 % 5 = 0
    insert(15);   // 15 % 5 = 0 -> collision, joins the list at slot 0
    insert(20);   // 20 % 5 = 0 -> collision again
    insert(7);    // 7 % 5 = 2
    insert(12);   // 12 % 5 = 2 -> collision at slot 2
    printTable();
    return 0;
}

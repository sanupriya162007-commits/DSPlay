// Hashing with linear probing: on a collision, check the next slot
#include <stdio.h>

#define SIZE 7

int table[SIZE];   // -1 means the slot is empty

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    for (int i = 0; i < SIZE; i++) {
        int slot = (index + i) % SIZE;      // try index, index+1, index+2 ... (wraps around)
        if (table[slot] == -1) {
            table[slot] = key;
            printf("Inserted %d at slot %d\n", key, slot);
            return;
        }
    }
    printf("Table is full\n");
}

int main() {
    for (int i = 0; i < SIZE; i++) table[i] = -1;

    insert(10);   // 10 % 7 = 3
    insert(17);   // 17 % 7 = 3 -> collision, goes to slot 4
    insert(24);   // 24 % 7 = 3 -> collision, goes to slot 5
    insert(31);   // 31 % 7 = 3 -> collision, goes to slot 6
    return 0;
}

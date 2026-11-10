// Hashing with linear probing: on a collision, check the next slot
#include <iostream>
using namespace std;

const int SIZE = 7;
int table[SIZE];   // -1 means the slot is empty

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    for (int i = 0; i < SIZE; i++) {
        int slot = (index + i) % SIZE;      // try index, index+1, index+2 ... (wraps around)
        if (table[slot] == -1) {
            table[slot] = key;
            cout << "Inserted " << key << " at slot " << slot << endl;
            return;
        }
    }
    cout << "Table is full" << endl;
}

int main() {
    for (int i = 0; i < SIZE; i++) table[i] = -1;

    insert(10);   // 10 % 7 = 3
    insert(17);   // 17 % 7 = 3 -> collision, goes to slot 4
    insert(24);   // 24 % 7 = 3 -> collision, goes to slot 5
    insert(31);   // 31 % 7 = 3 -> collision, goes to slot 6
    return 0;
}

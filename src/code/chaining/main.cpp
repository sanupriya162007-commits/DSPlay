// Hashing with separate chaining: each table slot holds a list
#include <iostream>
#include <list>
using namespace std;

const int SIZE = 5;
list<int> table[SIZE];             // an array of lists

int hashFunction(int key) {
    return key % SIZE;             // hash function: remainder
}

void insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);   // collision? just join the list
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "]: ";
        for (int key : table[i]) cout << key << " -> ";
        cout << "NULL" << endl;
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

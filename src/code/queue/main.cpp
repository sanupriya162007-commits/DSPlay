// Queue using an array (FIFO: First In, First Out)
#include <iostream>
using namespace std;

const int SIZE = 5;
int queueArr[SIZE];
int front = 0;   // where we remove from
int rear = -1;   // where we add to
int cnt = 0;     // how many items are inside

void enqueue(int value) {
    if (cnt == SIZE) {
        cout << "Queue is full" << endl;
        return;
    }
    rear++;
    queueArr[rear] = value;   // add at the back
    cnt++;
}

void dequeue() {
    if (cnt == 0) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Removed: " << queueArr[front] << endl;
    front++;                  // the next item becomes the front
    cnt--;
}

void peek() {
    if (cnt == 0) cout << "Queue is empty" << endl;
    else cout << "Front value: " << queueArr[front] << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();      // 10
    dequeue();   // 10
    dequeue();   // 20
    peek();      // 30
    return 0;
}

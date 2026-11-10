// Queue using an array (FIFO: First In, First Out)
#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;   // where we remove from
int rear = -1;   // where we add to
int count = 0;   // how many items are inside

void enqueue(int value) {
    if (count == SIZE) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    queue[rear] = value;   // add at the back
    count++;
}

void dequeue() {
    if (count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Removed: %d\n", queue[front]);
    front++;               // the next item becomes the front
    count--;
}

void peek() {
    if (count == 0) printf("Queue is empty\n");
    else printf("Front value: %d\n", queue[front]);
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

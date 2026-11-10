// Stack using an array (LIFO: Last In, First Out)
#include <stdio.h>

#define SIZE 5

int stack[SIZE];   // the box that holds our values
int top = -1;      // -1 means the stack is empty

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;                // move top up
    stack[top] = value;   // put the value on top
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped: %d\n", stack[top]);
    top--;                // move top down
}

void peek() {
    if (top == -1) printf("Stack is empty\n");
    else printf("Top value: %d\n", stack[top]);
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();   // 30
    pop();    // 30
    pop();    // 20
    peek();   // 10
    return 0;
}

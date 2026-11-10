// Stack using an array (LIFO: Last In, First Out)
#include <iostream>
using namespace std;

const int SIZE = 5;
int stackArr[SIZE];   // the box that holds our values
int top = -1;         // -1 means the stack is empty

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack is full" << endl;
        return;
    }
    top++;                  // move top up
    stackArr[top] = value;  // put the value on top
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Popped: " << stackArr[top] << endl;
    top--;                  // move top down
}

void peek() {
    if (top == -1) cout << "Stack is empty" << endl;
    else cout << "Top value: " << stackArr[top] << endl;
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

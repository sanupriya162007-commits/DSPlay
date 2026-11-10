// Stack using an array (LIFO: Last In, First Out)
public class Main {
    static final int SIZE = 5;
    static int[] stack = new int[SIZE];   // the box that holds our values
    static int top = -1;                  // -1 means the stack is empty

    static void push(int value) {
        if (top == SIZE - 1) {
            System.out.println("Stack is full");
            return;
        }
        top++;                // move top up
        stack[top] = value;   // put the value on top
    }

    static void pop() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.println("Popped: " + stack[top]);
        top--;                // move top down
    }

    static void peek() {
        if (top == -1) System.out.println("Stack is empty");
        else System.out.println("Top value: " + stack[top]);
    }

    public static void main(String[] args) {
        push(10);
        push(20);
        push(30);
        peek();   // 30
        pop();    // 30
        pop();    // 20
        peek();   // 10
    }
}

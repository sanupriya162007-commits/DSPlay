// Queue using an array (FIFO: First In, First Out)
public class Main {
    static final int SIZE = 5;
    static int[] queue = new int[SIZE];
    static int front = 0;   // where we remove from
    static int rear = -1;   // where we add to
    static int count = 0;   // how many items are inside

    static void enqueue(int value) {
        if (count == SIZE) {
            System.out.println("Queue is full");
            return;
        }
        rear++;
        queue[rear] = value;   // add at the back
        count++;
    }

    static void dequeue() {
        if (count == 0) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.println("Removed: " + queue[front]);
        front++;               // the next item becomes the front
        count--;
    }

    static void peek() {
        if (count == 0) System.out.println("Queue is empty");
        else System.out.println("Front value: " + queue[front]);
    }

    public static void main(String[] args) {
        enqueue(10);
        enqueue(20);
        enqueue(30);
        peek();      // 10
        dequeue();   // 10
        dequeue();   // 20
        peek();      // 30
    }
}

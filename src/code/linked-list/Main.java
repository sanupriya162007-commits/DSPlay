// Singly linked list: insert at head, delete first node, print
public class Main {
    static class Node {
        int data;
        Node next;          // link to the next node
        Node(int data) { this.data = data; }
    }

    static Node head = null;   // null means the list is empty

    static void insertAtHead(int value) {
        Node newNode = new Node(value);
        newNode.next = head;   // new node points to the old first node
        head = newNode;        // new node becomes the first node
    }

    static void deleteFirst() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        head = head.next;      // move head to the second node
    }

    static void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;   // follow the link
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        insertAtHead(30);
        insertAtHead(20);
        insertAtHead(10);
        printList();     // 10 -> 20 -> 30 -> null
        deleteFirst();
        printList();     // 20 -> 30 -> null
    }
}

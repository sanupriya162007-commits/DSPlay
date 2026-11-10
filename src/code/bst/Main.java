// Binary Search Tree: insert, search, inorder
// Rule: smaller values go LEFT, larger values go RIGHT
public class Main {
    static class Node {
        int data;
        Node left, right;
        Node(int data) { this.data = data; }
    }

    static Node insert(Node root, int value) {
        if (root == null) return new Node(value);         // found an empty spot
        if (value < root.data) root.left = insert(root.left, value);
        else if (value > root.data) root.right = insert(root.right, value);
        return root;
    }

    static boolean search(Node root, int value) {
        if (root == null) return false;                   // not found
        if (value == root.data) return true;              // found
        if (value < root.data) return search(root.left, value);
        return search(root.right, value);
    }

    static void inorder(Node root) {                      // left, root, right
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Node root = null;
        int[] numbers = {50, 30, 70, 20, 40};
        for (int n : numbers) root = insert(root, n);

        System.out.print("Inorder: ");
        inorder(root);                                    // 20 30 40 50 70
        System.out.println();
        System.out.println("Search 40: " + (search(root, 40) ? "Found" : "Not found"));
        System.out.println("Search 99: " + (search(root, 99) ? "Found" : "Not found"));
    }
}

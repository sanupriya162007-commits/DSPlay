// Hashing with separate chaining: each table slot holds a list
import java.util.ArrayList;

public class Main {
    static final int SIZE = 5;
    static ArrayList<Integer>[] table = new ArrayList[SIZE];   // an array of lists

    static int hash(int key) {
        return key % SIZE;               // hash function: remainder
    }

    static void insert(int key) {
        int index = hash(key);
        table[index].add(key);           // collision? just join the list
    }

    public static void main(String[] args) {
        for (int i = 0; i < SIZE; i++) table[i] = new ArrayList<>();

        insert(10);   // 10 % 5 = 0
        insert(15);   // 15 % 5 = 0 -> collision, joins the list at slot 0
        insert(20);   // 20 % 5 = 0 -> collision again
        insert(7);    // 7 % 5 = 2
        insert(12);   // 12 % 5 = 2 -> collision at slot 2

        for (int i = 0; i < SIZE; i++) {
            System.out.println("[" + i + "]: " + table[i]);
        }
    }
}

// Hashing with linear probing: on a collision, check the next slot
public class Main {
    static final int SIZE = 7;
    static int[] table = new int[SIZE];   // -1 means the slot is empty

    static int hash(int key) {
        return key % SIZE;
    }

    static void insert(int key) {
        int index = hash(key);
        for (int i = 0; i < SIZE; i++) {
            int slot = (index + i) % SIZE;      // try index, index+1, index+2 ... (wraps around)
            if (table[slot] == -1) {
                table[slot] = key;
                System.out.println("Inserted " + key + " at slot " + slot);
                return;
            }
        }
        System.out.println("Table is full");
    }

    public static void main(String[] args) {
        for (int i = 0; i < SIZE; i++) table[i] = -1;

        insert(10);   // 10 % 7 = 3
        insert(17);   // 17 % 7 = 3 -> collision, goes to slot 4
        insert(24);   // 24 % 7 = 3 -> collision, goes to slot 5
        insert(31);   // 31 % 7 = 3 -> collision, goes to slot 6
    }
}

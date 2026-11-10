// Tower of Hanoi (recursion)
// Move n disks from rod "from" to rod "to" using rod "helper"
public class Main {
    static void hanoi(int n, char from, char to, char helper) {
        if (n == 0) return;                      // nothing to move

        hanoi(n - 1, from, helper, to);          // 1. move n-1 disks out of the way
        System.out.println("Move disk " + n + " from " + from + " to " + to);   // 2. biggest disk
        hanoi(n - 1, helper, to, from);          // 3. move n-1 disks on top of it
    }

    public static void main(String[] args) {
        hanoi(3, 'A', 'C', 'B');
    }
}

// Linear search: check every value one by one
public class Main {
    public static void main(String[] args) {
        int[] numbers = {8, 3, 6, 1, 5};
        int target = 6;
        int found = -1;                      // -1 means "not found yet"

        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == target) {      // compare each value with the target
                found = i;
                break;
            }
        }

        if (found != -1) System.out.println("Found " + target + " at index " + found);
        else System.out.println(target + " not found");
    }
}

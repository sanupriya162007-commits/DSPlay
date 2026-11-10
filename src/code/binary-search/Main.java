// Binary search: the list MUST be sorted
public class Main {
    public static void main(String[] args) {
        int[] numbers = {1, 3, 6, 8, 10};
        int target = 8;

        int low = 0;                      // start of the search range
        int high = numbers.length - 1;    // end of the search range
        int found = -1;

        while (low <= high) {
            int mid = (low + high) / 2;          // look at the middle value
            if (numbers[mid] == target) {
                found = mid;
                break;
            } else if (numbers[mid] < target) {
                low = mid + 1;                   // target is in the right half
            } else {
                high = mid - 1;                  // target is in the left half
            }
        }

        if (found != -1) System.out.println("Found " + target + " at index " + found);
        else System.out.println(target + " not found");
    }
}

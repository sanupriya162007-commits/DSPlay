// Shell sort: insertion sort that starts by comparing values far apart (the "gap")
public class Main {
    public static void main(String[] args) {
        int[] numbers = {8, 3, 6, 1, 5};
        int size = numbers.length;

        for (int gap = size / 2; gap > 0; gap = gap / 2) {     // shrink the gap each round
            for (int i = gap; i < size; i++) {
                int current = numbers[i];
                int j = i;
                while (j >= gap && numbers[j - gap] > current) {
                    numbers[j] = numbers[j - gap];             // shift the bigger value right
                    j = j - gap;
                }
                numbers[j] = current;                          // drop the value in its place
            }
        }

        System.out.print("Sorted: ");
        for (int n : numbers) System.out.print(n + " ");
        System.out.println();
    }
}

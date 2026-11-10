// Bubble sort: compare neighbours and swap if they are in the wrong order
public class Main {
    public static void main(String[] args) {
        int[] numbers = {8, 3, 6, 1, 5};
        int size = numbers.length;

        for (int pass = 0; pass < size - 1; pass++) {
            for (int i = 0; i < size - 1 - pass; i++) {
                if (numbers[i] > numbers[i + 1]) {     // wrong order?
                    int temp = numbers[i];             // swap the two values
                    numbers[i] = numbers[i + 1];
                    numbers[i + 1] = temp;
                }
            }
        }

        System.out.print("Sorted: ");
        for (int n : numbers) System.out.print(n + " ");
        System.out.println();
    }
}

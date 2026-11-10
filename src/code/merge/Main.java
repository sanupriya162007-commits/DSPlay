// Merge two sorted runs into one sorted list
// (Multiway / polyphase merge repeat this idea with more runs)
public class Main {
    public static void main(String[] args) {
        int[] a = {1, 4, 7};
        int[] b = {2, 5, 6};
        int[] result = new int[6];
        int i = 0, j = 0, k = 0;

        while (i < a.length && j < b.length) {     // pick the smaller front value
            if (a[i] <= b[j]) result[k++] = a[i++];
            else result[k++] = b[j++];
        }
        while (i < a.length) result[k++] = a[i++]; // copy what is left in a
        while (j < b.length) result[k++] = b[j++]; // copy what is left in b

        System.out.print("Merged: ");
        for (int x : result) System.out.print(x + " ");
        System.out.println();
    }
}

// Shell sort: insertion sort that starts by comparing values far apart (the "gap")
#include <stdio.h>

int main() {
    int numbers[] = {8, 3, 6, 1, 5};
    int size = 5;

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

    printf("Sorted: ");
    for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}

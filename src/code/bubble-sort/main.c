// Bubble sort: compare neighbours and swap if they are in the wrong order
#include <stdio.h>

int main() {
    int numbers[] = {8, 3, 6, 1, 5};
    int size = 5;

    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (numbers[i] > numbers[i + 1]) {     // wrong order?
                int temp = numbers[i];             // swap the two values
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
            }
        }
    }

    printf("Sorted: ");
    for (int i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}

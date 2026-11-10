// Merge two sorted runs into one sorted list
// (Multiway / polyphase merge repeat this idea with more runs)
#include <stdio.h>

int main() {
    int a[] = {1, 4, 7};
    int b[] = {2, 5, 6};
    int result[6];
    int i = 0, j = 0, k = 0;

    while (i < 3 && j < 3) {              // pick the smaller front value
        if (a[i] <= b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while (i < 3) result[k++] = a[i++];   // copy what is left in a
    while (j < 3) result[k++] = b[j++];   // copy what is left in b

    printf("Merged: ");
    for (int x = 0; x < 6; x++) printf("%d ", result[x]);
    printf("\n");
    return 0;
}

// Linear search: check every value one by one
#include <stdio.h>

int main() {
    int numbers[] = {8, 3, 6, 1, 5};
    int size = 5;
    int target = 6;
    int found = -1;                      // -1 means "not found yet"

    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {      // compare each value with the target
            found = i;
            break;
        }
    }

    if (found != -1) printf("Found %d at index %d\n", target, found);
    else printf("%d not found\n", target);
    return 0;
}

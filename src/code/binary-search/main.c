// Binary search: the list MUST be sorted
#include <stdio.h>

int main() {
    int numbers[] = {1, 3, 6, 8, 10};
    int size = 5;
    int target = 8;

    int low = 0;                 // start of the search range
    int high = size - 1;         // end of the search range
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

    if (found != -1) printf("Found %d at index %d\n", target, found);
    else printf("%d not found\n", target);
    return 0;
}

// Linear search: check every value one by one
#include <iostream>
using namespace std;

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

    if (found != -1) cout << "Found " << target << " at index " << found << endl;
    else cout << target << " not found" << endl;
    return 0;
}

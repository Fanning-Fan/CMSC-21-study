#include <stdio.h>
#include <string.h>

// Helper function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate all permutations
// str   = the string we are permuting
// start = the current index we are fixing
// len   = total length of the string
void permute(char *str, int start, int len) {

    // Base case: when start reaches the last character,
    // we have a complete permutation — print it
    if (start == len - 1) {
        printf("%s\n", str);
        return;
    }

    // Outer loop: try placing each remaining character at position 'start'
    for (int i = start; i < len; i++) {
        // Swap character at 'start' with character at 'i'
        // This places str[i] at the current position
        swap(&str[start], &str[i]);

        // Recurse: fix the next position (start + 1)
        permute(str, start + 1, len);

        // Backtrack: swap back to restore original order
        // This undoes the swap so we can try the next character
        swap(&str[start], &str[i]);
    }
}

int main() {
    char str[] = "ABC";
    int len = strlen(str);

    printf("All permutations of \"%s\":\n", str);
    permute(str, 0, len);

    return 0;
}
```
**Output:**
```
All permutations of "ABC":
ABC
ACB
BAC
BCA
CAB
CBA
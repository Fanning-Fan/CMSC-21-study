#include <stdio.h>
#include <string.h>

int main() {
    char pattern[] = "ABC"; // Pattern string to cycle through
    int patternLen = strlen(pattern);
    int n = 5; // Size of the matrix (n x n)

    printf("Pattern: '%s' | Matrix size: %dx%d\n\n", pattern, n, n);

    // Outer loop: controls the row index i
    for (int i = 0; i < n; i++) {

        // Inner loop: controls the column index j
        for (int j = 0; j < n; j++) {
            // (i + j) % patternLen gives the index into the pattern string
            // This creates a diagonal cycling effect across the matrix
            int index = (i + j) % patternLen;
            printf("%c ", pattern[index]);
        }

        printf("\n"); // Move to the next row
    }

    return 0;
}
```
**Output:**
```
Pattern: 'ABC' | Matrix size: 5x5

A B C A B 
B C A B C 
C A B C A 
A B C A B 
B C A B C
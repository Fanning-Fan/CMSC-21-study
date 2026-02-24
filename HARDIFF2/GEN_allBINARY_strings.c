#include <stdio.h>
#include <string.h>

int main() {
    int n = 3; // Length of binary strings to generate
    int total = 1;

    // Calculate 2^n (total number of binary strings)
    // We do this manually using a loop instead of pow()
    for (int i = 0; i < n; i++) total *= 2;

    printf("All binary strings of length %d:\n", n);

    // Outer loop: go through all numbers from 0 to 2^n - 1
    // Each number represents one binary string
    for (int i = 0; i < total; i++) {
        char binary[10]; // Buffer to store the binary string
        binary[n] = '\0'; // Null-terminate in advance

        // Inner loop: extract each bit from right to left
        for (int j = n - 1; j >= 0; j--) {
            // i >> j shifts i right by j positions, then & 1 extracts the last bit
            // This gives us 1 or 0 for each bit position
            binary[j] = ((i >> (n - 1 - j)) & 1) ? '1' : '0';
        }

        printf("%s\n", binary);
    }

    return 0;
}
```
**Output:**
```
All binary strings of length 3:
000
001
010
011
100
101
110
111
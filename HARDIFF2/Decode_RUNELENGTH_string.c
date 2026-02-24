#include <stdio.h>
#include <string.h>

int main() {
    // Encoded strings to decode
    char encoded[][20] = {"3a2b1c", "4x1y1z", "2a2b2c2d", "4a", "1a1b1c1d"};
    int numStrings = sizeof(encoded) / sizeof(encoded[0]);

    // Outer loop: go through each encoded string
    for (int s = 0; s < numStrings; s++) {
        int len = strlen(encoded[s]);
        char decoded[100]; // Buffer to hold the decoded result
        int dIndex = 0;    // Write index for decoded[]
        int i = 0;         // Read index for encoded string

        // Inner loop: process encoded string two characters at a time
        // Each pair is: [digit][character] e.g., '3' and 'a'
        while (i < len) {
            int count = encoded[s][i] - '0'; // Convert digit char to integer
            char c = encoded[s][i + 1];      // The character to repeat

            // Repeat the character 'count' times
            for (int j = 0; j < count; j++) {
                decoded[dIndex++] = c;
            }

            i += 2; // Move past the digit and character pair
        }

        decoded[dIndex] = '\0'; // Null-terminate

        printf("Encoded: \"%s\" -> Decoded: \"%s\"\n", encoded[s], decoded);
    }

    return 0;
}
```
**Output:**
```
Encoded: "3a2b1c" -> Decoded: "aaabbc"
Encoded: "4x1y1z" -> Decoded: "xxxxyz"
Encoded: "2a2b2c2d" -> Decoded: "aabbccdd"
Encoded: "4a" -> Decoded: "aaaa"
Encoded: "1a1b1c1d" -> Decoded: "abcd"
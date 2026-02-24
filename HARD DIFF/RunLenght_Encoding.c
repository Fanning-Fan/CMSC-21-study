#include <stdio.h>
#include <string.h>

int main() {
    // Array of strings to encode using Run-Length Encoding
    char strings[][20] = {"aaabbc", "xxxxyz", "aabbccdd", "aaaa", "abcd"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    // Outer loop: go through each string
    for (int s = 0; s < numStrings; s++) {
        int len = strlen(strings[s]);
        char encoded[100]; // Buffer to hold the encoded result
        int eIndex = 0;    // Index to write into encoded[]
        int i = 0;         // Index to traverse the input string

        // Inner loop: traverse the string manually
        while (i < len) {
            char currentChar = strings[s][i]; // Current character to count
            int count = 1;                     // It appears at least once

            // Look ahead: count how many times the character repeats
            while (i + count < len && strings[s][i + count] == currentChar) {
                count++; // Same character, keep counting
            }

            // Write the count as a character digit into encoded[]
            // We handle single digit counts (1-9) for simplicity
            encoded[eIndex++] = '0' + count;  // Convert int count to char digit
            encoded[eIndex++] = currentChar;  // Write the character itself

            // Move index forward past all the repeated characters we just counted
            i += count;
        }

        encoded[eIndex] = '\0'; // Null-terminate the encoded string

        printf("Original: \"%s\" -> Encoded: \"%s\"\n", strings[s], encoded);
    }

    return 0;
}
```
**Output:**
```
Original: "aaabbc" -> Encoded: "3a2b1c"
Original: "xxxxyz" -> Encoded: "4x1y1z"
Original: "aabbccdd" -> Encoded: "2a2b2c2d"
Original: "aaaa" -> Encoded: "4a"
Original: "abcd" -> Encoded: "1a1b1c1d"
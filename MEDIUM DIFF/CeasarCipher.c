#include <stdio.h>
#include <string.h>

int main() {
    // Array of messages to encode
    char messages[][20] = {"hello", "world", "python"};
    int numMessages = sizeof(messages) / sizeof(messages[0]);
    int shift = 3; // Number of positions to shift each character

    // Outer loop: go through each message
    for (int i = 0; i < numMessages; i++) {
        int len = strlen(messages[i]);
        char encoded[20]; // Array to store the encoded message

        // Inner loop: go through each character of the current message
        for (int j = 0; j < len; j++) {
            char c = messages[i][j];

            if (c >= 'a' && c <= 'z') {
                // Lowercase letter:
                // Subtract 'a' to get 0-25 range, add shift, wrap with % 26, add 'a' back
                encoded[j] = (c - 'a' + shift) % 26 + 'a';

            } else if (c >= 'A' && c <= 'Z') {
                // Uppercase letter: same logic but with 'A'
                encoded[j] = (c - 'A' + shift) % 26 + 'A';

            } else {
                // Not a letter (space, punctuation), keep as is
                encoded[j] = c;
            }
        }

        encoded[len] = '\0'; // Null-terminate the encoded string

        printf("Original: \"%s\" -> Encoded: \"%s\"\n", messages[i], encoded);
    }

    return 0;
}
```
**Output:**
```
Original: "hello" -> Encoded: "khoor"
Original: "world" -> Encoded: "zruog"
Original: "python" -> Encoded: "sbwkrq"
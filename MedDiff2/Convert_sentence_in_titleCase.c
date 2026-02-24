#include <stdio.h>
#include <string.h>

int main() {
    char sentences[][100] = {
        "hello world from c",
        "nested loops and strings",
        "the quick brown fox"
    };

    int numSentences = sizeof(sentences) / sizeof(sentences[0]);

    // Outer loop: process each sentence
    for (int s = 0; s < numSentences; s++) {
        int len = strlen(sentences[s]);
        char result[100]; // Buffer to hold the title-cased result
        int newWord = 1;  // Flag: 1 means the next letter should be uppercase

        // Inner loop: go through each character
        for (int i = 0; i < len; i++) {
            char c = sentences[s][i];

            if (c == ' ') {
                // Space found — next character starts a new word
                result[i] = ' ';
                newWord = 1; // Set flag so next letter becomes uppercase
            } else if (newWord && c >= 'a' && c <= 'z') {
                // First letter of a word — convert to uppercase
                // In ASCII, subtracting 32 from a lowercase letter gives uppercase
                result[i] = c - 32;
                newWord = 0; // Reset flag, we are now inside a word
            } else {
                // Middle of a word — keep character as is
                result[i] = c;
            }
        }

        result[len] = '\0'; // Null-terminate

        printf("Original  : \"%s\"\nTitle Case: \"%s\"\n\n", sentences[s], result);
    }

    return 0;
}
```
**Output:**
```
Original  : "hello world from c"
Title Case: "Hello World From C"

Original  : "nested loops and strings"
Title Case: "Nested Loops And Strings"

Original  : "the quick brown fox"
Title Case: "The Quick Brown Fox"
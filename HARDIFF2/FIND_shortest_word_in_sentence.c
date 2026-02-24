#include <stdio.h>
#include <string.h>

int main() {
    char sentences[][100] = {
        "the quick brown fox jumps",
        "I love programming in C",
        "nested loops are really powerful tools"
    };

    int numSentences = sizeof(sentences) / sizeof(sentences[0]);

    // Outer loop: process each sentence
    for (int s = 0; s < numSentences; s++) {
        int len = strlen(sentences[s]);

        char shortestWord[50] = "";  // Store the shortest word found
        int shortestLen = 9999;      // Start with a very large number

        char currentWord[50] = "";   // Buffer for the word being built
        int wIndex = 0;              // Write index for currentWord

        // Inner loop: go through each character including a final pass for last word
        for (int i = 0; i <= len; i++) {
            char c = sentences[s][i];

            if (c != ' ' && c != '\0') {
                // Still inside a word — add character to currentWord
                currentWord[wIndex++] = c;
            } else {
                // Space or end of string — the word is complete
                if (wIndex > 0) {
                    currentWord[wIndex] = '\0'; // Null-terminate the word

                    // Check if this word is shorter than the current shortest
                    if (wIndex < shortestLen) {
                        shortestLen = wIndex;
                        strcpy(shortestWord, currentWord); // Save this word
                    }

                    wIndex = 0; // Reset for the next word
                }
            }
        }

        printf("Sentence : \"%s\"\nShortest : \"%s\" (length %d)\n\n",
               sentences[s], shortestWord, shortestLen);
    }

    return 0;
}
```
**Output:**
```
Sentence : "the quick brown fox jumps"
Shortest : "the" (length 3)

Sentence : "I love programming in C"
Shortest : "I" (length 1)

Sentence : "nested loops are really powerful tools"
Shortest : "are" (length 3)
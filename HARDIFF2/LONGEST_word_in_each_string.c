#include <stdio.h>
#include <string.h>

int main() {
    char sentences[][100] = {
        "the quick brown fox",
        "I enjoy solving difficult programming challenges",
        "nested loops help with string problems"
    };

    int numSentences = sizeof(sentences) / sizeof(sentences[0]);

    // Outer loop: process each sentence
    for (int s = 0; s < numSentences; s++) {
        int len = strlen(sentences[s]);

        char longestWord[50] = "";  // Stores the longest word found so far
        int longestLen = 0;         // Length of the longest word

        char currentWord[50] = "";  // Buffer to build the current word
        int wIndex = 0;             // Write index for currentWord

        // Inner loop: go through each character including the final position
        for (int i = 0; i <= len; i++) {
            char c = sentences[s][i];

            if (c != ' ' && c != '\0') {
                // Inside a word — keep building it
                currentWord[wIndex++] = c;
            } else {
                // Word boundary — check if it's the longest so far
                if (wIndex > longestLen) {
                    currentWord[wIndex] = '\0'; // Null-terminate
                    strcpy(longestWord, currentWord); // Save as longest
                    longestLen = wIndex;
                }
                wIndex = 0; // Reset for next word
            }
        }

        printf("Sentence : \"%s\"\nLongest  : \"%s\" (length %d)\n\n",
               sentences[s], longestWord, longestLen);
    }

    return 0;
}
```
**Output:**
```
Sentence : "the quick brown fox"
Longest  : "quick" (length 5)

Sentence : "I enjoy solving difficult programming challenges"
Longest  : "programming" (length 11)

Sentence : "nested loops help with string problems"
Longest  : "problems" (length 8)
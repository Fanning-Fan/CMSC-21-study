#include <stdio.h>
#include <string.h>

int main() {
    // List of sentences to count words in
    char sentences[][100] = {
        "the quick brown fox",
        "nested loops are fun to learn",
        "C programming is powerful"
    };

    int numSentences = sizeof(sentences) / sizeof(sentences[0]);

    // Outer loop: go through each sentence
    for (int s = 0; s < numSentences; s++) {
        int len = strlen(sentences[s]);
        int wordCount = 0;     // Total word count
        int inWord = 0;        // Flag: are we currently inside a word?

        // Inner loop: go through each character in the sentence
        for (int i = 0; i < len; i++) {
            if (sentences[s][i] != ' ') {
                // Non-space character — we are inside a word
                if (!inWord) {
                    wordCount++; // Only count it once when we first enter the word
                    inWord = 1;  // Mark that we are now inside a word
                }
            } else {
                // Space character — we are no longer inside a word
                inWord = 0;
            }
        }

        printf("Sentence: \"%s\"\nWord count: %d\n\n", sentences[s], wordCount);
    }

    return 0;
}
```
**Output:**
```
Sentence: "the quick brown fox"
Word count: 4

Sentence: "nested loops are fun to learn"
Word count: 6

Sentence: "C programming is powerful"
Word count: 4
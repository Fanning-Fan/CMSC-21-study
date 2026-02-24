#include <stdio.h>
#include <string.h>

int main() {
    // The sentence split into individual words
    char sentence[][20] = {"the", "cat", "sat", "on", "the", "mat", 
                           "and", "the", "cat", "wore", "a", "hat"};
    int sentenceLen = sizeof(sentence) / sizeof(sentence[0]);

    // Target words we want to count
    char targets[][20] = {"the", "cat", "hat", "dog"};
    int targetLen = sizeof(targets) / sizeof(targets[0]);

    // Outer loop: go through each target word
    for (int i = 0; i < targetLen; i++) {
        int count = 0; // Reset count for each target

        // Inner loop: go through every word in the sentence
        for (int j = 0; j < sentenceLen; j++) {
            // strcmp returns 0 if two strings are equal
            if (strcmp(targets[i], sentence[j]) == 0) {
                count++; // Match found, increment count
            }
        }

        printf("\"%s\" appears %d time(s)\n", targets[i], count);
    }

    return 0;
}
```
**Output:**
```
"the" appears 3 time(s)
"cat" appears 2 time(s)
"hat" appears 1 time(s)
"dog" appears 0 time(s)
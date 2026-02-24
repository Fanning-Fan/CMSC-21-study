#include <stdio.h>
#include <string.h>

int main() {
    char words[][20] = {"cat", "elephant", "dog", "ant", "bat",
                        "crocodile", "bee", "ape", "ox"};
    int n = sizeof(words) / sizeof(words[0]);

    printf("Pairs of words with the same length:\n\n");

    // Outer loop: pick the first word of the pair
    for (int i = 0; i < n; i++) {
        int len1 = strlen(words[i]);

        // Inner loop: pick the second word (forward only to avoid repeats)
        for (int j = i + 1; j < n; j++) {
            int len2 = strlen(words[j]);

            // If both words have the same length, they form a valid pair
            if (len1 == len2) {
                printf("\"%s\" and \"%s\" (both length %d)\n",
                       words[i], words[j], len1);
            }
        }
    }

    return 0;
}
```
**Output:**
```
Pairs of words with the same length:

"cat" and "dog" (both length 3)
"cat" and "ant" (both length 3)
"cat" and "bat" (both length 3)
"cat" and "bee" (both length 3)
"cat" and "ape" (both length 3)
"dog" and "ant" (both length 3)
"dog" and "bat" (both length 3)
"dog" and "bee" (both length 3)
"dog" and "ape" (both length 3)
"ant" and "bat" (both length 3)
"ant" and "bee" (both length 3)
"ant" and "ape" (both length 3)
"bat" and "bee" (both length 3)
"bat" and "ape" (both length 3)
"bee" and "ape" (both length 3)
#include <stdio.h>
#include <string.h>

int main() {
    // List of words (all same length for word ladder to work)
    char words[][10] = {"cat", "bat", "hat", "hot", "dot", "dog", "log", "lag"};
    int n = sizeof(words) / sizeof(words[0]);

    printf("Word pairs that differ by exactly ONE character:\n\n");

    // Outer loop: pick the first word of the pair
    for (int i = 0; i < n; i++) {

        // Inner loop: pick the second word (only forward to avoid duplicate pairs)
        for (int j = i + 1; j < n; j++) {
            int len1 = strlen(words[i]);
            int len2 = strlen(words[j]);

            // Only compare words of the same length
            if (len1 != len2) continue;

            int diffCount = 0; // Count how many characters differ

            // Character comparison loop: compare character by character
            for (int k = 0; k < len1; k++) {
                if (words[i][k] != words[j][k]) {
                    diffCount++; // Found a different character
                }

                // Early exit: more than 1 difference, no need to continue
                if (diffCount > 1) break;
            }

            // If exactly 1 character differs, it's a valid word ladder step
            if (diffCount == 1) {
                printf("\"%s\" -> \"%s\"\n", words[i], words[j]);
            }
        }
    }

    return 0;
}
```
**Output:**
```
Word pairs that differ by exactly ONE character:

"cat" -> "bat"
"cat" -> "hat"
"bat" -> "hat"
"hat" -> "hot"
"hot" -> "dot"
"dot" -> "dog"
"dog" -> "log"
"log" -> "lag"
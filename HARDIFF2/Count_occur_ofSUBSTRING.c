#include <stdio.h>
#include <string.h>

int main() {
    // Main strings to search within
    char strings[][50] = {
        "abababab",
        "the cat sat on the mat in the hat",
        "mississippi"
    };

    // Substrings to search for
    char substrings[][10] = {"ab", "the", "ss"};

    int numPairs = sizeof(strings) / sizeof(strings[0]);

    // Outer loop: go through each string-substring pair
    for (int p = 0; p < numPairs; p++) {
        int sLen = strlen(strings[p]);   // Length of main string
        int subLen = strlen(substrings[p]); // Length of substring
        int count = 0; // Count of how many times substring appears

        // Middle loop: try every possible starting position in the main string
        for (int i = 0; i <= sLen - subLen; i++) {
            int match = 1; // Assume match at this position

            // Inner loop: compare substring character by character
            for (int j = 0; j < subLen; j++) {
                if (strings[p][i + j] != substrings[p][j]) {
                    match = 0; // Mismatch found
                    break;
                }
            }

            if (match) count++; // Found an occurrence
        }

        printf("String: \"%s\"\nSubstring: \"%s\" -> Found %d time(s)\n\n",
               strings[p], substrings[p], count);
    }

    return 0;
}
```
**Output:**
```
String: "abababab"
Substring: "ab" -> Found 4 time(s)

String: "the cat sat on the mat in the hat"
Substring: "the" -> Found 3 time(s)

String: "mississippi"
Substring: "ss" -> Found 2 time(s)
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abcdefgh";
    char str2[] = "cdefxyzab";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char longest[100] = "";   // Store the longest common substring found
    int longestLen = 0;       // Length of the longest match

    // Outer loop: pick a starting position in str1
    for (int i = 0; i < len1; i++) {

        // Inner loop: pick a starting position in str2
        for (int j = 0; j < len2; j++) {
            int k = 0;          // Offset for extending the match
            char current[100];  // Temporary buffer for current matching substring
            int currentLen = 0; // Length of current match

            // Extension loop: keep extending while characters match
            while (i + k < len1 && j + k < len2 && str1[i + k] == str2[j + k]) {
                current[currentLen++] = str1[i + k]; // Add matched character
                k++;
            }
            current[currentLen] = '\0'; // Null-terminate the current match

            // Update longest if current match is longer
            if (currentLen > longestLen) {
                longestLen = currentLen;
                strcpy(longest, current); // Save current as the new longest
            }
        }
    }

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Longest Common Substring: '%s' (length: %d)\n", longest, longestLen);

    return 0;
}
```
**Output:**
```
String 1: abcdefgh
String 2: cdefxyzab
Longest Common Substring: 'cdef' (length: 4)
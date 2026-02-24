#include <stdio.h>
#include <string.h>

int main() {
    char str1[][20] = {"listen", "hello", "triangle"};
    char str2[][20] = {"silent", "world", "integral"};

    int numPairs = sizeof(str1) / sizeof(str1[0]);

    // Outer loop: go through each pair of strings
    for (int p = 0; p < numPairs; p++) {
        int len1 = strlen(str1[p]);
        int len2 = strlen(str2[p]);

        // Permutations must have the same length
        if (len1 != len2) {
            printf("\"%s\" and \"%s\": NOT permutations (different length)\n",
                   str1[p], str2[p]);
            continue;
        }

        // freq[] counts character occurrences
        // Positive means str1 has more, negative means str2 has more
        int freq[128] = {0};

        // First inner loop: increment for each char in str1
        for (int i = 0; i < len1; i++) {
            freq[(int)str1[p][i]]++;
        }

        // Second inner loop: decrement for each char in str2
        for (int i = 0; i < len2; i++) {
            freq[(int)str2[p][i]]--;
        }

        // Third inner loop: if all freq values are 0, they are permutations
        int isPerm = 1;
        for (int i = 0; i < 128; i++) {
            if (freq[i] != 0) {
                isPerm = 0; // Some character count doesn't balance
                break;
            }
        }

        printf("\"%s\" and \"%s\": %s\n",
               str1[p], str2[p],
               isPerm ? "ARE permutations" : "are NOT permutations");
    }

    return 0;
}
```
**Output:**
```
"listen" and "silent": ARE permutations
"hello" and "world": are NOT permutations
"triangle" and "integral": ARE permutations
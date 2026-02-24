#include <stdio.h>
#include <string.h>

int main() {
    char strings[][30] = {"mississippi", "programming", "banana"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    // Outer loop: process each string
    for (int s = 0; s < numStrings; s++) {
        int len = strlen(strings[s]);

        // freq[] stores how many times each character appears
        // Index is the ASCII value of the character
        int freq[128] = {0};

        // First inner loop: count frequency of each character
        for (int i = 0; i < len; i++) {
            freq[(int)strings[s][i]]++; // Increment count for this character
        }

        // Second inner loop: find the character with the highest frequency
        char maxChar = strings[s][0]; // Assume first character is the most frequent
        int maxCount = 0;

        for (int i = 0; i < len; i++) {
            char c = strings[s][i];
            if (freq[(int)c] > maxCount) {
                maxCount = freq[(int)c]; // Update max count
                maxChar = c;            // Update most frequent character
            }
        }

        printf("String: \"%s\" -> Most frequent: '%c' (%d times)\n",
               strings[s], maxChar, maxCount);
    }

    return 0;
}
```
**Output:**
```
String: "mississippi" -> Most frequent: 's' (4 times)
String: "programming" -> Most frequent: 'r' (2 times)
String: "banana" -> Most frequent: 'a' (3 times)
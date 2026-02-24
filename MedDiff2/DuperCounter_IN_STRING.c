#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "programming";
    int len = strlen(str);

    // Array to track which characters we already reported
    // Using ASCII size (128), initialized to 0 = not yet reported
    int reported[128] = {0};

    printf("Duplicate characters in \"%s\":\n", str);

    // Outer loop: pick each character as the one we are checking
    for (int i = 0; i < len; i++) {
        char c = str[i];

        // Skip if we already reported this character before
        if (reported[(int)c]) continue;

        int count = 1; // Start count at 1 (the character itself)

        // Inner loop: compare with every character after it
        for (int j = i + 1; j < len; j++) {
            if (str[j] == c) {
                count++; // Found another occurrence
            }
        }

        // Only report if the character appeared more than once
        if (count > 1) {
            printf("'%c' appears %d times\n", c, count);
            reported[(int)c] = 1; // Mark as reported to avoid duplicates
        }
    }

    return 0;
}
```
**Output:**
```
Duplicate characters in "programming":
'r' appears 2 times
'g' appears 2 times
'm' appears 2 times
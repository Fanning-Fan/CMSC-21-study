#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "programming";
    char str2[] = "gaming";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Array to track which characters have already been recorded
    // We use ASCII values (128 possible characters), initialized to 0 (not found)
    int found[128] = {0};

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Common characters: ");

    // Outer loop: go through each character in str1
    for (int i = 0; i < len1; i++) {
        char c = str1[i];

        // Skip if we already printed this character (avoid duplicates)
        if (found[(int)c]) continue;

        // Inner loop: go through each character in str2
        for (int j = 0; j < len2; j++) {
            if (c == str2[j]) {
                // Match found — print it and mark as found
                printf("%c ", c);
                found[(int)c] = 1; // Mark this character as already printed
                break;             // No need to keep checking str2
            }
        }
    }

    printf("\n");
    return 0;
}
```
**Output:**
```
String 1: programming
String 2: gaming
Common characters: r a g m i n
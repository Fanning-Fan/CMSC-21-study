#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "abcd";
    int len = strlen(str);

    printf("All substrings of \"%s\":\n", str);

    // Outer loop: pick the starting index of the substring
    for (int i = 0; i < len; i++) {

        // Inner loop: pick the ending index of the substring
        for (int j = i + 1; j <= len; j++) {

            // Print characters from index i up to j (not including j)
            for (int k = i; k < j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }

    return 0;
}
```
**Output:**
```
All substrings of "abcd":
a
ab
abc
abcd
b
bc
bcd
c
cd
d
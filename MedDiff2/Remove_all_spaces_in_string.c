#include <stdio.h>
#include <string.h>

int main() {
    // List of strings with spaces to remove
    char strings[][50] = {
        "hello world",
        "C is   great",
        "nested   loops   are   cool"
    };

    int numStrings = sizeof(strings) / sizeof(strings[0]);

    // Outer loop: process each string
    for (int s = 0; s < numStrings; s++) {
        int len = strlen(strings[s]);
        char result[50]; // Buffer to store the string without spaces
        int rIndex = 0;  // Write index for result

        // Inner loop: go through each character
        for (int i = 0; i < len; i++) {
            // Only copy the character if it is NOT a space
            if (strings[s][i] != ' ') {
                result[rIndex++] = strings[s][i];
            }
            // If it IS a space, we simply skip it (don't copy)
        }

        result[rIndex] = '\0'; // Null-terminate the result string

        printf("Original : \"%s\"\nNo spaces: \"%s\"\n\n", strings[s], result);
    }

    return 0;
}
```
**Output:**
```
Original : "hello world"
No spaces: "helloworld"

Original : "C is   great"
No spaces: "Cisgreat"

Original : "nested   loops   are   cool"
No spaces: "nestedloopsarecool"
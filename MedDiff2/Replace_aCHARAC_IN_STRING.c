#include <stdio.h>
#include <string.h>

int main() {
    char strings[][30] = {"hello world", "banana split", "loop the loop"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    char oldChar = 'l'; // Character to find and replace
    char newChar = '*'; // Character to replace it with

    printf("Replacing '%c' with '%c':\n\n", oldChar, newChar);

    // Outer loop: go through each string
    for (int s = 0; s < numStrings; s++) {
        int len = strlen(strings[s]);
        char result[30];

        // Inner loop: go through each character in the string
        for (int i = 0; i < len; i++) {
            if (strings[s][i] == oldChar) {
                result[i] = newChar; // Replace with new character
            } else {
                result[i] = strings[s][i]; // Keep original character
            }
        }

        result[len] = '\0'; // Null-terminate

        printf("Original : \"%s\"\nReplaced : \"%s\"\n\n", strings[s], result);
    }

    return 0;
}
```
**Output:**
```
Replacing 'l' with '*':

Original : "hello world"
Replaced : "he**o wor*d"

Original : "banana split"
Replaced : "banana sp*it"

Original : "loop the loop"
Replaced : "*oop the *oop"
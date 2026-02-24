#include <stdio.h>
#include <string.h>

int main() {
    char words[][20] = {"banana", "apple", "mango", "cherry", "date", "elderberry"};
    int n = sizeof(words) / sizeof(words[0]);

    printf("Before sorting:\n");

    // Print original order
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    // Bubble Sort using nested loops
    // Outer loop: controls the number of passes needed
    for (int i = 0; i < n - 1; i++) {

        // Inner loop: compare adjacent strings in each pass
        for (int j = 0; j < n - 1 - i; j++) {

            // strcmp returns positive if words[j] comes AFTER words[j+1]
            // meaning they are out of order and need to be swapped
            if (strcmp(words[j], words[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, words[j]);          // Save words[j]
                strcpy(words[j], words[j + 1]);  // Move words[j+1] to words[j]
                strcpy(words[j + 1], temp);      // Put saved word in words[j+1]
            }
        }
    }

    printf("\nAfter sorting:\n");

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
```
**Output:**
```
Before sorting:
banana
apple
mango
cherry
date
elderberry

After sorting:
apple
banana
cherry
date
elderberry
mango
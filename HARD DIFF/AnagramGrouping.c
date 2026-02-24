#include <stdio.h>
#include <string.h>

// Helper function: sorts the characters of a string alphabetically
// This is used to check if two words are anagrams (same sorted chars)
void sortString(char *str, char *result) {
    int len = strlen(str);
    
    // Copy str into result so we don't modify the original
    for (int i = 0; i < len; i++) result[i] = str[i];
    result[len] = '\0';

    // Simple bubble sort to sort the characters
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                // Swap characters
                char temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
}

int main() {
    char words[][10] = {"eat", "tea", "tan", "ate", "nat", "bat", "tab", "arc", "car"};
    int n = sizeof(words) / sizeof(words[0]);

    // Track which words have already been grouped (1 = used, 0 = not used)
    int used[9] = {0};

    printf("Anagram Groups:\n");

    // Outer loop: pick each word as a potential group anchor
    for (int i = 0; i < n; i++) {
        if (used[i]) continue; // Skip if already grouped

        char sorted_i[10];
        sortString(words[i], sorted_i); // Get sorted version of anchor word

        printf("[ %s", words[i]); // Start printing the group
        used[i] = 1;              // Mark anchor as used

        // Inner loop: find all other words that are anagrams of the anchor
        for (int j = i + 1; j < n; j++) {
            if (used[j]) continue; // Skip if already grouped

            char sorted_j[10];
            sortString(words[j], sorted_j); // Get sorted version of candidate word

            // If sorted versions match, they are anagrams
            if (strcmp(sorted_i, sorted_j) == 0) {
                printf(", %s", words[j]); // Add to group
                used[j] = 1;              // Mark as used
            }
        }

        printf(" ]\n"); // Close the group
    }

    return 0;
}
```
**Output:**
```
Anagram Groups:
[ eat, tea, ate ]
[ tan, nat ]
[ bat, tab ]
[ arc, car ]
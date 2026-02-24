#include <stdio.h>
#include <string.h>

int main() {
    // Array of strings to check
    char words[][20] = {"racecar", "hello", "level", "world", "madam"};
    
    // Get the number of words by dividing total size by size of one element
    int numWords = sizeof(words) / sizeof(words[0]);

    // Outer loop: go through each word
    for (int i = 0; i < numWords; i++) {
        int length = strlen(words[i]); // Get length of current word
        int isPalindrome = 1;          // Assume true (1 = true, 0 = false)

        // Inner loop: compare characters from both ends toward the center
        for (int j = 0; j < length / 2; j++) {
            // Compare front character [j] with back character [length - 1 - j]
            if (words[i][j] != words[i][length - 1 - j]) {
                isPalindrome = 0; // Mismatch found, not a palindrome
                break;            // Stop checking
            }
        }

        // Print result
        if (isPalindrome)
            printf("\"%s\" is a palindrome\n", words[i]);
        else
            printf("\"%s\" is NOT a palindrome\n", words[i]);
    }

    return 0;
}
```
**Output:**
```
"racecar" is a palindrome
"hello" is NOT a palindrome
"level" is a palindrome
"world" is NOT a palindrome
"madam" is a palindrome


#include <stdio.h>
#include <string.h>

int main() {
    char strings[][30] = {"babad", "racecar", "abcbad"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    // Outer loop: process each string
    for (int s = 0; s < numStrings; s++) {
        int len = strlen(strings[s]);
        int bestStart = 0;  // Start index of the longest palindrome found
        int bestLen = 1;    // Length of the longest palindrome found

        // Middle loop: pick each character as the center of a palindrome
        for (int center = 0; center < len; center++) {

            // --- Check ODD length palindromes (single center character) ---
            int left = center;
            int right = center;

            // Inner loop: expand outward as long as characters match
            while (left >= 0 && right < len &&
                   strings[s][left] == strings[s][right]) {
                int currentLen = right - left + 1;
                if (currentLen > bestLen) {
                    bestLen = currentLen;   // Update best length
                    bestStart = left;       // Update best start index
                }
                left--;  // Expand left
                right++; // Expand right
            }

            // --- Check EVEN length palindromes (center between two characters) ---
            left = center;
            right = center + 1;

            while (left >= 0 && right < len &&
                   strings[s][left] == strings[s][right]) {
                int currentLen = right - left + 1;
                if (currentLen > bestLen) {
                    bestLen = currentLen;
                    bestStart = left;
                }
                left--;
                right++;
            }
        }

        // Print the longest palindromic substring
        printf("String: \"%s\" -> Longest palindrome: \"", strings[s]);
        for (int i = bestStart; i < bestStart + bestLen; i++) {
            printf("%c", strings[s][i]);
        }
        printf("\" (length %d)\n", bestLen);
    }

    return 0;
}
```
**Output:**
```
String: "babad" -> Longest palindrome: "bab" (length 3)
String: "racecar" -> Longest palindrome: "racecar" (length 7)
String: "abcbad" -> Longest palindrome: "abcba" (length 5)
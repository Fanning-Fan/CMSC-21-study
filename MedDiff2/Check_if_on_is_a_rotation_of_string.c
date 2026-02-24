#include <stdio.h>
#include <string.h>

int main() {
    // Pairs of strings to test for rotation
    char str1[][20] = {"abcdef", "hello", "rotate"};
    char str2[][20] = {"defabc", "llohe", "taterox"};

    int numPairs = sizeof(str1) / sizeof(str1[0]);

    // Outer loop: go through each pair
    for (int p = 0; p < numPairs; p++) {
        int len1 = strlen(str1[p]);
        int len2 = strlen(str2[p]);
        int isRotation = 0; // Assume not a rotation

        // A rotation is only possible if both strings have the same length
        if (len1 == len2) {

            // Outer loop: try every possible rotation offset (0 to len1-1)
            for (int offset = 0; offset < len1; offset++) {
                int match = 1; // Assume this offset is a match

                // Inner loop: compare each character with the rotation applied
                for (int i = 0; i < len1; i++) {
                    // (i + offset) % len1 wraps around to simulate rotation
                    if (str1[p][i] != str2[p][(i + offset) % len1]) {
                        match = 0; // Mismatch at this offset
                        break;
                    }
                }

                if (match) {
                    isRotation = 1; // Found a valid rotation
                    break;
                }
            }
        }

        printf("\"%s\" and \"%s\": %s\n",
               str1[p], str2[p],
               isRotation ? "IS a rotation" : "is NOT a rotation");
    }

    return 0;
}
```
**Output:**
```
"abcdef" and "defabc": IS a rotation
"hello" and "llohe": IS a rotation
"rotate" and "taterox": is NOT a rotation
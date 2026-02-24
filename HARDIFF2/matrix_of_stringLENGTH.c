#include <stdio.h>
#include <string.h>

int main() {
    // 2D array of strings (3 rows, 4 columns)
    char grid[3][4][20] = {
        {"apple", "hi", "banana", "cat"},
        {"dog", "elephant", "fig", "go"},
        {"hello", "i", "jazz", "kite"}
    };

    int rows = 3;
    int cols = 4;

    printf("String Grid:\n");

    // Outer loop: go through each row
    for (int i = 0; i < rows; i++) {

        // Inner loop: go through each column
        for (int j = 0; j < cols; j++) {
            // Print each string padded to 10 characters for alignment
            printf("%-10s ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\nLength Grid:\n");

    // Outer loop: go through each row again for lengths
    for (int i = 0; i < rows; i++) {

        // Inner loop: get and print the length of each string
        for (int j = 0; j < cols; j++) {
            int len = strlen(grid[i][j]);

            // Print the length padded to match the string column width
            printf("%-11d", len);
        }
        printf("\n");
    }

    return 0;
}
```
**Output:**
```
String Grid:
apple      hi         banana     cat        
dog        elephant   fig        go         
hello      i          jazz       kite       

Length Grid:
5          2          6          3          
3          8          3          2          
5          1          4          4
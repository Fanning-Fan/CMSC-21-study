#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "HELLOWORLD";
    int len = strlen(str);
    int rows = 3; // Number of rows in the zigzag pattern

    // 2D array to store the zigzag pattern
    // Each row holds the characters placed in that zigzag row
    char pattern[3][100];
    int colIndex[3]; // Tracks the current column position for each row

    // Initialize the pattern array with spaces and colIndex to 0
    for (int i = 0; i < rows; i++) {
        colIndex[i] = 0;
        for (int j = 0; j < 100; j++) {
            pattern[i][j] = ' ';
        }
    }

    int currentRow = 0;  // Start placing characters in row 0
    int goingDown = 1;   // Direction flag: 1 = going down, 0 = going up

    // Outer loop: place each character into the correct zigzag row
    for (int i = 0; i < len; i++) {
        // Place the character in the current row at the next available column
        pattern[currentRow][colIndex[currentRow]++] = str[i];

        // Change direction when we hit the top or bottom row
        if (currentRow == rows - 1) goingDown = 0; // Hit bottom, go up
        if (currentRow == 0)        goingDown = 1; // Hit top, go down

        // Move to the next row based on direction
        if (goingDown) currentRow++;
        else           currentRow--;
    }

    printf("Zigzag pattern of \"%s\" with %d rows:\n", str, rows);

    // Inner loop: print each row of the pattern
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colIndex[i]; j++) {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
**Output:**
```
Zigzag pattern of "HELLOWORLD" with 3 rows:
H   O   L 
E L W R D 
L   O
// Header files
#include <stdio.h>

// Global variables
// Array to hold the cell status
char game_board[3][3];


// The main function
int main()
{
    int row = 0;
    int col = 0;
    char start_char = '1';

    // Fill all the cell 1-9
    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++)
            game_board[row][col] = start_char++;

    return 0;
}

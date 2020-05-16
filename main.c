// Header files
#include <stdio.h>

// Global variables
// Array to hold the cell status
char game_board[3][3];

// Function prototypes
void draw_board();
void get_row_col(int cell, int *row, int *col);

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

    // Draw board with current data
    draw_board();


// Function to calculate row & column number from selected cell
void get_row_col(int cell, int *row, int *col)
{
    *row = (cell - 1) / 3;
    *col = (cell - 1) % 3;
}
    return 0;
}

void draw_board()
{
    int i;
    int j;

    printf("TIC TAC TOE\n");
    printf("\nDigits (1-9) indicates valid cell number\n\n");

    printf(" %c | %c | %c \n", game_board[0][0], game_board[0][1], game_board[0][2]);
    printf("---|---|---\n");

    printf(" %c | %c | %c \n", game_board[1][0], game_board[1][1], game_board[1][2]);
    printf("---|---|---\n");

    printf(" %c | %c | %c \n", game_board[2][0], game_board[2][1], game_board[2][2]);
    printf("---|---|---\n");
}
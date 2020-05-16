// Header files
#include <stdio.h>

// Global variables
// Array to hold the cell status
char game_board[3][3];

// Function prototypes
void draw_board();
void turn_player_x(int *cell);
void turn_player_o(int *cell);
void get_row_col(int cell, int *row, int *col);
int validate_input(int cell);
int show_result(char ch);

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



// Function to make player x's move
void turn_player_x(int *p_cell)
{
    int cell;

    do
    {
        printf("Player X:\nSelect valid cell number: ");
        scanf("%d", &cell);
    } while (0 != validate_input(cell));

    *p_cell = cell;
}

// Function to make player o's move
void turn_player_o(int *p_cell)
{
    int cell;

    do
    {
        printf("Player O:\nSelect valid cell number: ");
        scanf("%d", &cell);
    } while (0 != validate_input(cell));

    *p_cell = cell;
}

// Function to calculate row & column number from selected cell
void get_row_col(int cell, int *row, int *col)
{
    *row = (cell - 1) / 3;
    *col = (cell - 1) % 3;
}

// Function to check whether the selected cell is invalid or not
int validate_input(int cell)
{
    int row, col;

    // If cell is less than 1 or greater than 9; invalid
    if (cell < 1 || cell > 9)
        return 1;

    // If cell is already occupied, invalid
    get_row_col(cell, &row, &col);

    if ('o' == game_board[row][col] || 'x' == game_board[row][col])
        return 2;

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

// Function to show the winner
int show_result(char ch)
{
    int status = 1;

    // Check diagonal
    if (game_board[0][0] == ch && game_board[1][1] == ch && game_board[2][2] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check diagonal
    else if (game_board[0][2] == ch && game_board[1][1] == ch && game_board[2][0] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check first column
    else if (game_board[0][0] == ch && game_board[1][0] == ch && game_board[2][0] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check second column
    else if (game_board[0][1] == ch && game_board[1][1] == ch && game_board[2][1] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check third column
    else if (game_board[0][2] == ch && game_board[1][2] == ch && game_board[2][2] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check first row
    else if (game_board[0][0] == ch && game_board[0][1] == ch && game_board[0][2] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check second row
    else if (game_board[1][0] == ch && game_board[1][1] == ch && game_board[1][2] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    // Check third row
    else if (game_board[2][0] == ch && game_board[2][1] == ch && game_board[2][2] == ch)
    {
        printf("Player %c is winner\n", ch);
        status = 0;
    }

    return status;
}
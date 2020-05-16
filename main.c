// Header files
#include <stdio.h>
#include <stdlib.h>

// Global variables
// Array to hold the cell status
char game_board[3][3];

// Function prototypes
void draw_board();
void turn_player_x(int *cell);
void turn_player_o(int *cell);
void get_row_col(int cell, int *row, int *col);
int validate_input(int cell);
int evaluate_winner(char player);

// The main function
int main()
{
    int x = 0;
    int y = 0;
    int row = 0;
    int col = 0;
    int available_cells = 9;
    int selected_cell = 0;
    char start_char = '1';

    // Fill all the cell 1-9
    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++)
            game_board[row][col] = start_char++;

    // Draw board with current data
    draw_board();

    // Loop until we've played all the cell
    while (available_cells >= 0)
    {
        // Assume first player is player x
        turn_player_x(&selected_cell);
        // get row and column from the selected cell
        get_row_col(selected_cell, &x, &y);
        // Update the array
        game_board[x][y] = 'x';
        // Decrease available cells
        --available_cells;
        // Redraw board
        system("clear"); // Clear the screen
        draw_board();

        // Check whether first player is winner or not
        if (evaluate_winner('x') == 0)
        {
            break;
        }

        // If no available cells left
        else if (available_cells == 0)
        {
            printf("Game drawn!\n");
            break;
        }

        // Assume second player is player o
        turn_player_o(&selected_cell);
        // get row and column from the selected cell
        get_row_col(selected_cell, &x, &y);
        // Update the array
        game_board[x][y] = 'o';
        // Decrease available cells
        --available_cells;
        // Redraw board
        system("clear"); // Clear the screen
        draw_board();

        // Check whether first player is winner or not
        if (evaluate_winner('o') == 0)
        {
            break;
        }

        // If no available cells left
        else if (available_cells == 0)
        {
            printf("Game drawn!\n");
            break;
        }
    }

    return 0;
}

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

// Function to draw board with current data
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
int evaluate_winner(char player)
{
    int status = 1;

    // Check diagonal
    if (game_board[0][0] == player && game_board[1][1] == player && game_board[2][2] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check diagonal
    else if (game_board[0][2] == player && game_board[1][1] == player && game_board[2][0] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check first column
    else if (game_board[0][0] == player && game_board[1][0] == player && game_board[2][0] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check second column
    else if (game_board[0][1] == player && game_board[1][1] == player && game_board[2][1] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check third column
    else if (game_board[0][2] == player && game_board[1][2] == player && game_board[2][2] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check first row
    else if (game_board[0][0] == player && game_board[0][1] == player && game_board[0][2] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check second row
    else if (game_board[1][0] == player && game_board[1][1] == player && game_board[1][2] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    // Check third row
    else if (game_board[2][0] == player && game_board[2][1] == player && game_board[2][2] == player)
    {
        printf("Player %c is winner\n", player);
        status = 0;
    }

    return status;
}
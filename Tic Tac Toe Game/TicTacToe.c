#include "TicTacToe.h"
#include <stdio.h>

char Game_Board[3][3]; // Tic Tac Toe Game Board

void initialize_Game_Board(){
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            Game_Board[i][j] = ' '; // to initialize game board with blank spaces
        }
    }
}

void update_Game_Board(int row, int column, char sign) {
    if (row < 0 || row > 2 || column < 0 || column > 2) {
        printf("Please enter row and column between 1 and 3: "); // if the input is not in the specified range
        scanf("%d %d", &row, &column);
        update_Game_Board(row-1, column-1, sign); // minus 1 because array is between 0 and 2 but input is between 1 and 3
    }
    else if (Game_Board[row][column] != ' ') { //if the player chooses a place that has already been filled
        printf("Please select an unfilled cell: ");
        scanf("%d %d", &row, &column);
        update_Game_Board(row-1, column-1, sign); // minus 1 because array is between 0 and 2 but input is between 1 and 3
    }
    else{
        Game_Board[row][column] = sign;
    }
}

void show_Game_Board(){
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", Game_Board[i][j]);
            if (j < 2){ //puts "|"" only after first and second cell
                printf("|"); // to separate columns
            }
        }
        printf("\n");
        if (i < 2){ //print to seperate lines only after first and second row
            printf("-----------\n"); // to separate rows
        }
    }
    printf("\n");
}

int check_for_Win(char sign){
    int i, j;
    // checks each row
    for (i = 0; i < 3; i++) {
        if (Game_Board[i][0] == sign && Game_Board[i][1] == sign && Game_Board[i][2] == sign) {
            return 1;
        }
    }
    // checks each columns
    for (j = 0; j < 3; j++) {
        if (Game_Board[0][j] == sign && Game_Board[1][j] == sign && Game_Board[2][j] == sign) {
            return 1;
        }
    }
    // checks both diagonals
    if (Game_Board[0][0] == sign && Game_Board[1][1] == sign && Game_Board[2][2] == sign) {
        return 1;
    }
    if (Game_Board[0][2] == sign && Game_Board[1][1] == sign && Game_Board[2][0] == sign) {
        return 1;
    }
    return 0; // no winner
}

void start_Game(){
    char sign = 'O'; // to make sign O start
    int row, column;
    printf("Player O goes first.\n");
    initialize_Game_Board(); // to initialize game board
    int count = 0; //counts to 9
    while (1){ 
        count++;
        printf("Player %c, enter row and column both between 1 and 3 separated by a space: ", sign);
        scanf("%d %d", &row, &column);
        update_Game_Board(row-1, column-1, sign); // minus 1 because array is between 0 and 2 but input is between 1 and 3
        show_Game_Board(); // prints game board after every play of each player
        if (check_for_Win(sign)) { // if check_for_Win returns 0 that means there is no winner so passes this statement
            printf("Player %c wins!\n", sign);
            return;
        }
        if (sign == 'X') { // to change the player
            sign = 'O';
        } else {
            sign = 'X';
        }
        if(count==9){ //if all of the cells are filled and no one win
            printf("All cells are filled, no one wins.\n");
            return;
        }
    }
}

void show_Game_Rules(){
    printf("\n");
    printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("2. First player is O , and second sign is X. Players take turns putting their marks in empty squares.\n");
    printf("3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n");
    printf("\n");
}

void Menu(){
    int choice;
    printf("MENU\n");
    printf("1 Show Game Rules\n");
    printf("2 Start the Game\n");
    printf("3 Exit Game\n");
    printf("Please enter your choice:");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        show_Game_Rules();
        Menu(); //shows menu after showing game rules
        break;
    case 2:
        printf("\n");
        start_Game(); 
        printf("\n");
        Menu(); //shows menu after game finishes
    case 3:
        printf("You are out of the game.\n");
        return; //exits the game
    default:
        break;
    }
}

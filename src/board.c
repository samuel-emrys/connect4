/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2015 Assignment #1
 * Author       : Samuel Dowling
 * Start up code provided by Paul Miller
 ***********************************************************************/
#include "../includes/board.h"
#include "../includes/player.h"

/**
 * @file board.c contains implementations of functions related to the game 
 * board.
 **/

/**
 * @param board the board to reset the contents of
 **/

void initialise_board(enum cell_contents board[][BOARDWIDTH])
{
    int i=0, j=0;
    for (i=0; i<BOARDHEIGHT; i++) 
    {    
        for (j=0; j<BOARDWIDTH; j++)
        {
            board[i][j] = C_EMPTY; /* makes cell contents empty */
        }
    }
}

/**
 * In this requirement you are required to display the game board. 
 * The game board should be displayed as shown on the first page of the 
 * assignment specification. 
 * @param board the board to display
 **/

void display_board(enum cell_contents board[][BOARDWIDTH])
{
    int i=0,j=0,columns=0;

    printf("This is the current state of the board \n");
    for (j=0; j<BOARDWIDTH; j++) 
    {
        columns = j+1;
        printf(" %d |", columns); /*prints column numbers */
    }
    printf("\n");
    printf("----------------------------\n");
    
    for (i=0; i<BOARDHEIGHT; i++) 
    {    
        for (j=0; j<BOARDWIDTH; j++)
        {
            switch (board[i][j]) 
            {
                case C_EMPTY: /*prints updated cell content for board*/
                printf("   |");
                break;

                case C_RED:
                printf(" %s |",RED_TOKEN);
                break;

                case C_WHITE:
                printf(" %s |",WHITE_TOKEN);
                break;
            }
        }
        printf("\n");
        printf("----------------------------\n");
    }
}


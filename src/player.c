/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2015 Assignment #1
 * Author       : Samuel Dowling
 * Start up code provided by Paul Miller
 ***********************************************************************/
#include "../includes/player.h"
/*#define max_length 20*/
#define empty_spaces 2
#define LSIZE max_length+empty_spaces

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player* human)
{

    int col;
    char string_input[LSIZE];
    enum input_result input_success;
    while (TRUE)
    {
        printf("What is your name?\n");
        input_success = get_input(0,string_input,1);

        switch (input_success)
        {
            case RTM:
            return RTM;
            break;

            case SUCCESS:
            /*  initialises human player struct to known values
            *   and defines random counter colour */
            strcpy(human->name,string_input);
            col = rand() % 2;

            if (col == 0)
            {
                human->thiscolor = C_WHITE;
            }
            else if (col == 1)
            {
                human->thiscolor = C_RED;
            }
            human->counters = 0;
            human->type = HUMAN;

            return SUCCESS;
            break;

            case FAILURE:
            printf("fgets failed. You shouldn't be here.");
            return FAILURE;
            break;
        }
        break;
    }
    return SUCCESS;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
    /* initialise all variables that are part of the struct to sensible 
     * values */
    strcpy(computer->name, "Computer");
    computer->thiscolor = C_EMPTY;
    /*  initialises computer token to empty so it can be defined 
    *   based on colour of human player colour */
    computer->counters = 0;
    computer->type = COMPUTER;

    return SUCCESS;
}

/**
 * In this requirement, you need to handle the taking of a turn - either
 * of a human or a computer player.
 *
 * For the human player, you will need to allow the user to enter the 
 * column they wish to place a token in. You will need to validate what 
 * the user enters, then place a token correctly in that column so that
 * it occupies the cell closest to the bottom of the board array for that 
 * column.
 *
 * For the computer player, you will need to randomly generate a column 
 * number to place a token in and if that column is full, generate a 
 * different column number until a column number with some free space has 
 * been found.
 *
 * @param current the current player
 * @param board the game board that we will attempt to insert a token into
 * @return enum @ref input_result indicating the state of user input (in 
 * case this run involved user input
 **/
enum input_result take_turn(struct player * current,
        enum cell_contents board[][BOARDWIDTH])
{
    int long column=0;
    int row=0;
    enum input_result input_success;

    while(TRUE)
    {
        if(current->type == HUMAN)
        {
            printf("Please enter a column to place a token: \n");
            input_success = get_input(&column,0,0);
        }
        else
        {
            column = rand() % 7;
            input_success = SUCCESS;
        }

        switch (input_success)
        {
            case RTM:
            return (RTM);
            break;

            case FAILURE:
            printf("Please enter a column to place a token: \n");
            input_success = get_input(&column,0,0);
            break;

            case SUCCESS:
            if ((column < 1 || column > 7) && (current->type == HUMAN))
            {
                printf("Error: Select a valid column using "
                    "integers between 1-7\n");
            }

            else 
            {
                if(current->type == HUMAN)
                {                
                    column--;
                }

                if (board[0][column] == C_RED || board[0][column] == C_WHITE)
                {
                    if (current->type == HUMAN)
                    {
                        printf("Column is full, choose another column\n");
                    }
                    break;
                }

                for (row=BOARDHEIGHT-1;row>=0;row--)
                {
                    if (board[row][column] == C_EMPTY) 
                    {
                        board[row][column] = current->thiscolor;
                        return SUCCESS;
                    }
                }
            }
        }    
    }
    return SUCCESS;
}

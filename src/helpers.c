/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2015 Assignment #1
 * Author       : Samuel Dowling
 * Start up code provided by Paul Miller
 ***********************************************************************/
#include "../includes/helpers.h"
#include "../includes/game.h"


/**
 * @file helpers.c contains various functions that help in the
 * implementation of the program. You should put functions you create
 * here unless they logically belong to another module (such as
 * player, board or game
 **/

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch!=EOF && ch != '\n'); /* gobble each character */
    /* reset the error status of the stream */
    clearerr(stdin);
}

enum input_result get_input(int long * select,char string_input[LSIZE],int type)
{
	char * charSelectEndPtr=NULL;
    char charSelect[LSIZE];
    int long selection;

	while(TRUE)
	{
	    if(fgets(charSelect, LSIZE, stdin) == NULL)
        /* Ctrl-D check, return to main menu. */
	    {
            /*read_rest_of_line();*/
            /*can't be here for linux, has to be here for osx*/
	    	return RTM;
        }
		else
        {    
	    	if (charSelect[strlen(charSelect)-1] != '\n')
            /*ensures length of string is within allocated string length*/
		   	{
			   	printf("Error: Input too long. Please Re-enter \n");
			   	read_rest_of_line();
                /*clears left over input from the input buffer */
		   	}

            else if (charSelect[0] == '\n')
            /*returns to menu if new line command is given on a new line */
            {
                return RTM;
            }
		    else 
		    {
		    	charSelect[strlen(charSelect)-1] = '\0';

                if (type == 0)
                /*if output required is a number, i.e. column/menu selection*/
                {
                    selection = strtol(charSelect, &charSelectEndPtr, 10);
                    *select = selection;
                    break;
                }
                else if (type == 1)
                /*if output required is a string i.e. name entry*/
                {
                    strcpy(string_input,charSelect);
                    /*copies contents of charSelect into string_input*/
                    break;
                }
		    }
		}
	}
	return SUCCESS;
}

int main_menu()
{
    int long select;
    enum input_result input_success;

    printf("Welcome to connect 4\n -------------------\n1. Play Game\n" 
        "2. Display High Scores\n3. Quit\n");
    printf("Please enter your choice: \n");

    while(TRUE)
    {
        input_success = get_input(&select,0,0);

        switch (input_success)
        {
            case RTM:
            return(0); /* return to main to start loop again*/
            break;

            case FAILURE:
            printf("Please enter your choice: \n");
            get_input(&select,0,0);
            break;

            case SUCCESS:
            if (select > 3 || select < 1)
            {
                printf("Please select a valid option from the menu "
                    "using integers 1-3\n");
            }
            else
            {
                return select;
            }
            break;
        }
    }
}

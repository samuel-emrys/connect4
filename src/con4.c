/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2015 Assignment #1
 * Author       : Samuel Dowling
 * Start up code provided by Paul Miller
 ***********************************************************************/
#include "../includes/con4.h"
#include <string.h>


/**
 * @mainpage COSC1076 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for COSC1076 -
 * Advanced Programming Techniques for semester 2, 2015. You will find
 * here a description of the functions that you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the <b>Files</b> tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file con4.c contains the main function which is the entry point into the 
 * application and manages the main memory.
 **/

/**
 * the entry point into the game. You should display the main menu and 
 * respond to user requests.
 *
 * The main menu should look like this: 
 * Welcome to connect 4
 *  \n\--------------------
 * 1. Play Game
 * 2. Display High Scores
 * 3. Quit
 * Please enter your choice:
 *
 * This menu should also be redisplayed when the program returns from 
 * running an option.
 **/

int main(void)
{
    struct player human_player, computer_player, *winner=NULL;
    scoreboard scores;
    int long select=0;
    time_t t;

    srand((unsigned) time(&t));
    init_scoreboard(scores);
    while(TRUE)
    {
        select = main_menu();

        switch (select)
        {
            case 1:
                /*play a game option*/
                winner = play_game(&human_player, &computer_player);
                if (winner != NULL)
                {
                    /*add winner to scoreboard*/
                    add_to_scoreboard(scores, winner);
                }   
                break;
                
            case 2:
                /*display the scoreboard option */
                display_scores(scores);
                break;

            case 3:
                /* quit the program option */
                printf("Thankyou for playing, Goodbye.\n");
                exit(0);
                break;
        }
     }
     return EXIT_SUCCESS;
}

/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2015 Assignment #1
 * Author       : Samuel Dowling
 * Start up code provided by Paul Miller
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"
#include "board.h"
#define max_length 20
#define empty_spaces 2
#define LSIZE max_length+empty_spaces

/**
 * @file helpers.h contains the datastructures used for various helper 
 * functioons and their function prototypes
 **/
#ifndef HELPERS_H
#define HELPERS_H
/**
 * the possible values that can be returned from custom input handling 
 * functions
 **/
enum input_result
{
    /**
     * the input was valid
     **/
    SUCCESS,
    /**
     * the input was not valld
     **/
    FAILURE,
    /**
     * the user requested to return to the menu either by pressing enter on
     * an empty line or pressing ctrl-d on an empty line
     **/
    RTM=-1
};

/**
 * call this function whenever you detect buffer overflow but only call this
 * function when this has happened.
 **/
void read_rest_of_line(void);

int main_menu(void);

int get_input(int long * select, char string_input[LSIZE], int type);

#endif

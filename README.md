# README

Personal Note: This was the first programming project I undertook. The general
structure for the program was provided by Paul Miller, however the implementation
of the program is my own. This project was completed to satisfy the course 
requirementsof COSC1076 Advanced Programming Techniques at RMIT University in 
Semester 2 of 2015.

# Connect 4
---------------------------------------------------------------------------
This is a game of connect 4 in which a human player is able to play against
a computer.

## Compiling
---------------------------------------------------------------------------
In order to compile this program to an executable, run the following command
from the project root:

	gcc -ansi -pedantic -Wall src/*.c -o bin/con4

This will create an executable in the 'bin' directory named 'con4. This can then 
be opened in terminal using the command 
	
	./con4

## How to Play
---------------------------------------------------------------------------
Connect 4 is a game in which two players compete to be the first to have 
four tokens in a row, measured vertically, horizontally or diagonally. 
Tokens are dropped one by one into the appropriate columns (token will 
fill lowest available slot in a column) until one player gets four tokens in 
a row or all slots on the board are filled, at which point the game is a 
draw.

From the menu, a user will be able to select from three options:
1. Play Game (initiates the game)
2. Display Scoreboard (displays the scoreboard)
3. Quit Game (exits the game)

From the play game menu selection, the user will be prompted to enter their
name, at which point the game begins. The user will be required to select
columns in which to drop a token using the integers 1-7. Inputs outside of
this range will not be accepted.

Upon completion of the game, the user will be notified as to the game result
and returned to the main menu.

At any point during the game, the user is able to simply press enter or
Ctrl-D to return to the main menu.

## Known Bugs
---------------------------------------------------------------------------
1. Different behaviour on different operating systems. 
Specifically this refers to the difference between the way gcc compiles on
Linux distributions and on Mac OSX. This difference affects the way that the 
Ctrl-D character is read by the executable, and varies the need to clear the 
input buffer after Ctrl-D has been pressed. In OSX, there is a 
requirement to clear the buffer otherwise the game gets stuck in an infinite 
loop. This is not the case on Linux. This affects reading from input using 
fgets(), and so the  "readrestofline()" function has not been utilised in the
get_input() function specified in helpers.c to ensure Linux compatability.
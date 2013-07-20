#include <ncurses.h>

/*** These are the function prototypes ***/

void initCurses(); /*Starts ncurses*/

void drawBoard(); /*draws the game grid*/

void initBoard(int * boardData); /*initializes the array for the game pieces*/

int playGame(); /*plays the game*/

int updateBoardData(int * boardData, int x, int y, int XorO); /*Updates boardData when players move*/

int checkWin(int * boardData); /*Checks for possible wins*/





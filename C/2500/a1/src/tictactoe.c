/*************************tictactoe.c****************************
Student Name: Angus Galloway                        Student Number:0793049
Date: January 21, 2013                          Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include <ncurses.h>
#include "tictactoe.h"


int main() {
   
    int keepPlaying; /*Keeps the game going after a win or tie*/
    
    do{
	
    initCurses();  /*Starts ncurses*/   
	
    drawBoard();   /*Draws the board*/
    
    playGame();    /*Herein lies the code for gameplay between player 1 & 2*/    
  
    keepPlaying = playGame(); /*The playGame function returns a 3 if a tie or win has occured*/
       
    }while(keepPlaying == 3); 
    
    endwin();
       
  return(0);
  
  }
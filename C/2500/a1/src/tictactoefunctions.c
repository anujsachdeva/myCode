/*************************tictactoefunctions.c****************************
Student Name: Angus Galloway                        Student Number:  0793049
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

#include "tictactoe.h"
#include <ncurses.h>
#include <stdio.h>

void initCurses(){
    
    initscr ();
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);

}

/********************************************************
 * Function: drawBoard
 * Purpose: draws and refreshes the grid.
 ********************************************************/

void drawBoard (){
    
    int i;
    int h;

    for(i=0; i<=6; i++){  
	
	mvaddch(i, 0, '|');
	mvaddch(i, 4, '|');
	mvaddch(i, 8, '|');
	mvaddch(i, 12,'|');
     	 
	 if(i%2 ==0){
	     
	     for(h=0; h<=12; h++){		 
		mvaddch(i, h, '-');	      
	     } 
	 }    

    move (1,2);
    
    }
    refresh ();
} 
/********************************************************
 * Function: initBoard
 * Purpose: Fills the array boardData so that we can
 * 	    restart the game if someone wins.
 ********************************************************/

void initBoard(int * boardData){
    
    int i;
        
    for(i=0;i<=8;i++){
	boardData[i] = i+2;
    }
}
/********************************************************
 * Function: playGame
 * Purpose: Allows the user to move the arrow keys and place a marker.
 * 	    Most of the gameplay is housed here. 
 ********************************************************/

int playGame(){
    
    int boardData[9];   /*Holds values corresponding to X's and O's*/
    int playerNum = 1;	/*Determines which Player moves*/
    int inputChar;	/*Gets the input from keyboard for gameplay*/
    int x = 2,y = 1;	/*The initial x and y coordinates in our ncurses grid*/
    int didWin = 0;	/*Determines if the game has been won*/
    int canWeMove = 0;	/*This prevents from over-writing game pieces*/
    int nMoves = 0; 	/*Counts the number of moves for finding a tie*/
    
    initBoard(boardData);    
        
    mvprintw(8,0,"It is Player 1's turn to place an (X)");
    move(y,x);
    refresh();
    
    while (inputChar !='q'){
	
	if(nMoves == 9){
	    mvprintw(10,0,"There is no winner, the game is a tie!");
	    inputChar = getch();
	    erase();
	    return 3;
	    
	}    
      
      inputChar = getch(); 

      /*If they aren't placing a marker, they are moving */
      
      if (inputChar !=' '){
   
	  switch (inputChar){
	 
	      case KEY_UP:
		  if(y == 3 || y == 5){
			move(y=y-2,x); 
		   }
		   break;
	
	      case KEY_DOWN:
		  if(y == 1 || y == 3){
		      move(y=y+2,x);
		  }
		  break;
		  
	      case KEY_LEFT:
		  if(x == 10 || x == 6){
		      move(y,x=x-4);
		  }
		  break;
		  
	      case KEY_RIGHT:
		  if(x == 2 || x == 6){
		      move(y,x=x+4);
		  }
		  break;
	  }
	
      }	
      
        /* This is the code for what happens when player 1 places an X. The code for player 2 is similar.*/
	
	else if(playerNum == 1 && inputChar == ' '){ 
	  
	   getyx(stdscr,y,x);
	   
	   canWeMove = updateBoardData(boardData,x,y,1);
	   
	   if(canWeMove == 5){
	       
	       mvaddch(y,x,'X');
	       
	       didWin = checkWin(boardData);
	   
		/*didWin is a function that checks for winning scenarios. It returns 1 if the last move caused a win to occur*/
	   
		if(didWin == 1){ 
	       
		    mvprintw(10,0,"Congratulations Player 1, you win!");
		    inputChar = getch();
		    erase();
		    return 3;
		    
	   }
		nMoves = nMoves + 1;
		
		/*If player one has moved and did not win, it must be player 2's turn*/
	   
	   playerNum = 2;
	   mvprintw(8,0,"It is Player 2's turn to place an (O)");
	   move(y,x);
	   refresh();
	   }
	}
	
	else if(playerNum == 2 && inputChar == ' '){
	                       
	    getyx(stdscr,y,x);	   	
	    
	    canWeMove = updateBoardData(boardData,x,y,0);
	    
	    if(canWeMove == 5){
		
	        mvaddch(y,x,'O');   
	    
		didWin = checkWin(boardData);
		
		if(didWin == 1){
		    
		    mvprintw(10,0,"Congratulations Player 2, you win!");
		    inputChar = getch();
		    erase();
		    return 3;
		    
	   }
	   nMoves = nMoves + 1;
	       
	   playerNum = 1;	    
	   mvprintw(8,0,"It is Player 1's turn to place an (X)");
	   move(y,x);
	   refresh();   
	   }
	}
	refresh();
	
    }
    return 0;
    endwin();
}

/********************************************************
 * Function: updateBoardData
 * Purpose: To match x and y coordinates on the board to appropriate boardData elements. 
 * 	    'XorO' holds either the number 1 for an X or 0 for an O.
	    This function also determines if we can proceed to place a marker by returning the value 5.
 ********************************************************/

int updateBoardData(int * boardData, int x, int y, int XorO){   
    
	  if((y == 1 && x == 2) && (boardData[0] != 1 && boardData[0] != 0)){
	      boardData[0] = XorO;
	      return 5;
	  }
	  if((y == 1 && x == 6) && (boardData[1] != 1 && boardData[1] != 0)){
	       boardData[1]= XorO;
	       return 5;
	  }
	  if((y == 1 && x == 10) && (boardData[2] != 1 && boardData[2] != 0)){
	       boardData[2]= XorO;
	       return 5;
	  }
	  if((y == 3 && x == 2) && (boardData[3] != 1 && boardData[3] != 0)){
	       boardData[3]= XorO;
	       return 5;
	  }
	  if((y == 3 && x == 6) && (boardData[4] != 1 && boardData[4] != 0)){
	       boardData[4]= XorO;
	       return 5;
	  }
	  if((y == 3 && x == 10) && (boardData[5] != 1 && boardData[5] != 0)){
	       boardData[5]= XorO;
	       return 5;
	  }
	  if((y == 5 && x == 2) && (boardData[6] != 1 && boardData[6] != 0)){
	       boardData[6]= XorO;
	       return 5;
	  }
	  if((y == 5 && x == 6) && (boardData[7] != 1 && boardData[7] != 0)){
	       boardData[7]= XorO;
	       return 5;
	  }
	  if((y == 5 && x == 10) && (boardData[8] != 1 && boardData[8] != 0)){
	       boardData[8]= XorO;
	       return 5;
	  }  
	 else return 0;
}    

/********************************************************
 * Function: checkWin
 * Purpose: looks for all possible scenarios which lead to a player winning. 
 * 	    it returns a 1 if a winning scenario has occured. The game continues while this function is returning a 0.  
 ********************************************************/
    
int checkWin(int * boardData){
 
    if((boardData[0] == boardData[1]) && (boardData[1] == boardData[2])){ /****Checking rows for a win****/
	return 1;
    }
    if((boardData[3] == boardData[4]) && (boardData[4] == boardData[5])){
	return 1;
    }
    if((boardData[6] == boardData[7]) && (boardData[7] == boardData[8])){
	return 1;
    }
    if((boardData[0] == boardData[3]) && (boardData[3] == boardData[6])){ /****Checking columns for a win****/
	return 1;
    }
    if((boardData[1] == boardData[4]) && (boardData[4] == boardData[7])){
	return 1;
    }
    if((boardData[2] == boardData[5]) && (boardData[5] == boardData[8])){
	return 1;
    }
    if((boardData[0] == boardData[4]) && (boardData[4] == boardData[8])){ /****Checking diagonals for a win****/
	return 1;
    }
    if((boardData[2] == boardData[4]) && (boardData[4] == boardData[6])){
	return 1;
    }	    
    else{
	return 0;
    }
}
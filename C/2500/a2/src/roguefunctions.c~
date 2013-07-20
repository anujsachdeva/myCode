/*************************roguefunctions.c*******************************************
Student Name: Angus Galloway                        Student Number:  0793049
Date: February 8, 2013      	                   Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rogue.h"


void initCurses(){
    
    initscr ();
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);

}

/*Get the dimensions of the room, the location of items and fill a number of arrays 
 exactly equal to the number of rooms, */



int gameData(int rows, int cols, char ** roomDataPtr, char ** rmArray, int roomNum){
  
 char * roomString;
 int w,y,x,yofd,xofd,locTsr;
 char * dummy;
 char smallDummy[6];
 char * wallDoor;
 char * yDoor;
 char * xDoor;
 int Tx;
 int Ty;
 int dXY;
 
 
  /*String tok the dimensions using roomNum as the index of rmArray*/
   
  
  roomString = malloc(sizeof(char)*100);
  
  strcpy(roomString,rmArray[roomNum]); 
  
   /***Here I need to strtok the stuff after the dimension, which comes in an unpredictable order***/
   
  dummy = malloc(sizeof(char)*(6));  
  dummy = strtok(roomString, " ");
  dummy = strtok(NULL," ");
  
  while(dummy != NULL){
    
   
   printf("dummy has value:%s\n", dummy);     
   
  
   /*Here we need to get the location following the d to place a door in the array roomData*/
   
   if(dummy[0] == 'd'){
     printf("found a door:%s\n",dummy);
    
       findDoorPosn(dummy,&dXY);
       printf("dXY:%d\n",dXY);    
       
       placeDoor(rows,cols,roomDataPtr,dummy,dXY);       
       printf("dummy is now:%s\n",dummy);
    }
    else{
    printf("we have something other than a door:%s\n",dummy);
    printf("dummy[0]: %c\n", dummy[0]);
    
    findCoord(dummy,&Tx,&Ty);   
    printf("Tx,Ty:%d,%d\n",Tx,Ty);
    
    /*Fill in room array here*/    
    }    
    dummy = strtok(NULL," ");    
  }  
  
   printf("hello world\n");   
  
   return(3);
  }
  
void placeDoor(int r, int c, char ** mod2darray, char * door,int DXY){
  
  	 
	 if(door[1] == 'n'){
	   mod2darray[1][1] = 'd';
	 }/*
	 if(door[1] == 's'){
	   mod2darray[r][DXY] = 'd';
	 }
	 if(door[1] == 'w'){
	   mod2darray[DXY][0] = 'd';
	 }
	 if(door[1] == 'e'){
	   mod2darray[DXY][c] = 'd';
}*/
}
  
void findDoorPosn(char * array1, int * doorXorY){
  
  char * anchor1;
  int dXorY;
  char * strPtr1;
  char * tempXorY;
  char * buffer;
  
  strPtr1 = malloc(sizeof(char)*7);
  buffer = malloc(sizeof(char)*7);
  
  strcpy(buffer,array1);
  
  strPtr1 = strpbrk(array1,"0123456789");
  tempXorY = strtok_r(strPtr1,",",&anchor1);
  dXorY = atoi(tempXorY);
  *doorXorY = dXorY;
  printf("doorXorY = %d\n",*doorXorY);
}
  
void findCoord(char * array, int * numX, int * numY){
  
  char * tempX;
  char * tempY;
  char * anchor;
  int i,j;
  char * strPtr2;
    
  strPtr2 = strpbrk(array,"0123456789");  
  tempX = strtok_r(strPtr2,",",&anchor);
  i = atoi(tempX);
  printf("tempX has value:%d\n",i);
  *numX = i;
  printf("numX = %d\n", *numX);
  
  tempY = strtok_r(NULL,",",&anchor);    
  j = atoi(tempY);  
  printf("tempY has value:%d\n",j);
  *numY = j;
  printf("numY = %d\n", *numY); 
  
}
   
void drawRoom(char ** TwoDArray, int rows, int cols){
  
  int i,h;
  
  for(i=0; i<rows; i++){
    for(h=0; h<cols; h++){
      if(TwoDArray[i][h] == 'w'){
	mvaddch(h,i,'-');
	}
	if(TwoDArray[i][h] == 'l'){
	  mvaddch(h,i,'|');
	}
      else if(TwoDArray[i][h] == '.'){
	mvaddch(h,i,'.');	
     }
     else if(TwoDArray[i][h] == 'd'){
       mvaddch(h,i,'+');
    }
  }
}
}
  
  
   
/*void drawRoom(int width, int height){
    
    int i;
    int h;
    

    for(i=0; i<=height; i++){  
	
	mvaddch(i, 0, '|');
	mvaddch(i, width,'|');
     	 
    }
    
    for(h=1; h <width; h++){
      
      mvaddch(0, h, '-');
      mvaddch(height, h, '-');
      
    } 
	    
    move (1,2);
    
   
    refresh ();
}*/


/*switch (inputChar){
	 
  case(inputChar == 'h'):	  
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
*/	   
/*************************rogue.c***************************************
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

/*struct roomDimensions
{  
  int a;
  int b;
};*/

/*typedef struct roomDimensions wall;*/

//struct roomDimensions * wall;
  
 //wall = malloc(sizeof(struct roomDimensions));
 
 /*num = strtol(argv[2], NULL, 10);
 printf("This is how many names you say are in your file: %ld\n",num);*/

int main(int argc, char * argv[]){  
  
  int anumber,x,y,w,b;
  char ** roomData;
  int rmIndex = 1;
  char inputKey;
  char lineBuffer[100];
  FILE *inputFile = NULL;
  int i,j;
  char ** roomArray;
  char * rmString;
  char * rmDim;
  char *Y;
  char *X;
  int why,exx;
  int i1,i2;

 if (argc != 2) {
   printf ("Usage: please indicate name of input file\n");
   exit(1);
 }
 inputFile = fopen (argv[1], "r"); 

 roomArray = malloc(sizeof(char*)*9);
 if (inputFile == NULL) {
   printf ( "Error! Could not find input file\n");
   exit(1);
 }
 else {
   for (i=0; i<9; i++){
     fgets (lineBuffer, 100, inputFile); 
     /*fgets is awesome because it reads until it reaches a newline*/
     /*printf("Read in the following line: %s", lineBuffer); */
     
     /***Here we need to return a pointer to string we have read***/
     /*Need to make a call to drawRoom(dim1,dim2); */
     
     roomArray[i]= malloc(sizeof(char)*(strlen(lineBuffer)+1));
     if(lineBuffer == NULL){
     break;
     }       
     strcpy(roomArray[i], lineBuffer);
     
   }
   fclose(inputFile);
   
   //printf("This is our data in roomArray\n");
   
   /*for(j=0; j<9; j++){
     printf("%s", roomArray[j]);
  }*/
 }
  
  /***Next I need to send the roomArray to a function for parsing with strtok***/
  /*increment the number that I pass to this function if they teleport or hit a door*/
  
  
  /*I need to collect the two values, and pass them as arguments to drawRoom*/
  
  inputKey = getch();
  
  if(inputKey == 't'){rmIndex++;}
  
  rmString = malloc(sizeof(char)*(50));
  
  strcpy(rmString,roomArray[rmIndex]);
  
  Y = malloc(sizeof(char)*5);
  X = malloc(sizeof(char)*5);
  
  rmDim = strtok(rmString, " ");
  printf("rmDim has value:%s\n", rmDim);
  
  Y = strtok(rmDim, "X");
  why = atoi(Y);
  
  printf("Y has value:%d\n",why);
  
  X = strtok(NULL, " ");
  exx = atoi(X);
  
  printf("X has value:%d\n",exx);
  
    
  
  
 roomData = malloc(sizeof(char *)*(why+1));
 if(roomData == NULL){printf("Out of memory");exit(1);}
  
  for(w=0; w<why; w++){
    roomData[w] = malloc(sizeof(char)*(exx+1));
    if(roomData[w] == NULL){printf("Not enough memory for room");exit(1);}
     }
     
   /*Call a function that fills the array*/
   /*Build into main for now*/
   
   for(i1=0;i1<why;i1++){
     
     for(i2=0;i2<exx;i2++){
       
       roomData[i1][i2] = '.';
       
       if(i1 == 0 || i1 == why-1){
	  roomData[i1][i2] = 'l';
       }
       if(i2 == 0 || i2 == exx-1){
	  roomData[i1][i2] = 'w';
	}
          
	 
     }
    }     
  
  roomData[1][1] = 'd';
  anumber = gameData(why,exx,roomData,roomArray,rmIndex);
  printf("anumber has value: %d\n", anumber);
  
  initCurses();
  inputKey = getch();
  while(inputKey != 'q'){
  /*if(inputKey != 't'){
       
	 if(inputKey == 'h'){
		  move(y=y-1,x);
		   break;
	 }	   
	if(inputKey == 'j'){
		  move(y=y+1,x);
		   break;
	 }
	 if(inputKey == 'k'){
		  move(y,x=x-1);
		   break;
	 }
	 if(inputKey == 'l'){
		  move(y,x=x+1);
		   break;
	 }*/
	
      	
    drawRoom(roomData,why,exx);
  
  }
    
    
  
    
  
  endwin();
  
 
 return(0);
}

/*int main(void){
  
  int inputChar;
  
  initCurses();
  
  while(inputChar != 'q'){
    
   drawRoom();
   
   inputChar = getch(); Waits for a char
      
  }
  
  endwin();
  return 0;
  
}
*/


/*int main (int argc, char * argv[]){
  
  char * theString;
  char * theToken;

  if (argc != 2)
    { 
      printf("usage: enter a quoted string\n");
      exit(1);
    }
  theString = malloc((sizeof(char)*sizeof(argv[1])+1));
  strcpy(theString, argv[1]);
  
  printf("%s\n", theString);
  
  theToken = strtok(theString," ");
  
  while(theToken != NULL){
       
  printf("%s.\n", theToken); Generate dungeon here.
  theToken = strtok(NULL," "); 
  
  }
  printf("%s\n", argv[1]);
  
  
  
return 0;

}*/

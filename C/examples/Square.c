/*This program takes a set of dimensions from the command line and draws a corresponding square*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initCurses(){
    
    initscr ();
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);

}

int main(int argc, char * argv[]){
  
  char * inputLine;
  int debug = 1;
  char * ys;
  char * xs;
  int y,x,i,j;
  int inputKey;
  
  if(argc != 2){
    printf("Usage Error: Please enter a quoted string\n");
    exit(1);
  }
        
    inputLine = malloc(sizeof(char)*sizeof(argv[1]+1));
    strcpy(inputLine,argv[1]);
    
    if(debug == 1){    
    printf("inputLine is:%s\n",inputLine);
    }
    
    ys = malloc(sizeof(char)*4);
    
    ys = strtok(inputLine,"X");
    y = atoi(ys);
    
    xs = strtok(NULL,"\0");
    x = atoi(xs);
  
  if(debug == 1){
    printf("Y is: %d\n",y);
    printf("X is: %d\n",x);
  }
  
  initCurses();
  
  for(i=0;i<x+1;i++){
    
    mvaddch(0,i,'-');
    mvaddch(y,i,'-');
  }
  for(j=1;j<y;j++){
    
    mvaddch(j,0,'|');
    mvaddch(j,x,'|');
  }
  
  inputKey = getch();
  
  endwin();
  
  return 0;
}

void initCurses();
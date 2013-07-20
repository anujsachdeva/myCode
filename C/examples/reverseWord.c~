#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
  
  char * buffer = NULL;
  int i,j;
  char * Word;
  int length;
  
  buffer = malloc(sizeof(char)*15);
  
  printf("Please enter a word: \n");
  gets(buffer);
  printf("%s\n",buffer);
  
  length = strlen(buffer);
  printf("%d\n",length);
  
  Word = malloc(sizeof(char)*length);
  
  j = length-1; 
  
  for(i=0;i<length;i++){
    
    Word[i] = buffer[j];
    j--;
  }
  printf("The reversed word is:%s\n", Word);
  
  return 0;
}
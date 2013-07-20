#include<stdlib.h>
#include<stdio.h>

int strcmp ( char *str1 , char * str2 );

int main(){
  
  /**If sameOrNot is > 0, string one is longer, if sameOrNot = 0, they are the same**/
  
  char * stringone = "angu12";
  char * stringtwo = "angu1";
  int sameOrNot = 0;
  
  sameOrNot = strcmp(stringone, stringtwo);  
  
  if(sameOrNot == 0)
  {
    printf("The strings are the same\n");
    printf("sameOrNot has value:%d\n",sameOrNot);
  }
  else
  {
    printf("sameOrNot has value:%d\n",sameOrNot);
    printf("The Strings are different\n");
  }
  return 0;
}

int strcmp ( char *str1 , char * str2 ) {
  
	char char1 , char2 ;
	
	do {
	  
	  char1 = * str1 ++;
	  char2 = * str2 ++;
	  
	  if (char1 == '\0')
	  {
	    return char1 - char2 ;
	  }
	} while ( char1 == char2 );
	
return char1 - char2 ;
}
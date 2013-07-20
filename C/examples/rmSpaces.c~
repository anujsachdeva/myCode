#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void){

char buffer[20];
char newString[20];
int i, j = 0;
 
printf("Please enter a string: ");
gets(buffer);

/*newString = malloc(sizeof(char)*length);*/


for(i=0; buffer[i]!='\0'; i++){
  
  if(buffer[i] != ' '){
    newString[j] = buffer[i];
    j++;
  }
}
newString[j] = '\0';
  
printf("This is your string:%s\n", buffer);
printf("Your string without spaces is:%s\n", newString);

return 0; 

}
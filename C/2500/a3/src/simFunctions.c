/*************************simFunctions.c***************************************
Student Name: Angus Galloway                        Student Number:  0793049
Date: April 1, 2013                                Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include"linkedList.h"

/***********
REQUIRED
Patron functions
************/

/******************************************
 * Function: getFileLength
 * Purpose: Takes a filePtr and returns the number of lines in the file. 
 ****************************************/

int getFileLength(FILE * filePtr){
    
    char * buffer;
    int lengthOfFile = 0;
    
    buffer = malloc(sizeof(char)*20);
    
    while(fgets(buffer,20,filePtr) != NULL)
    {        
        lengthOfFile++;
    }
    rewind(filePtr);
          
    return lengthOfFile;            
}
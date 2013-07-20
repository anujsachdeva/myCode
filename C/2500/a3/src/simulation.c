/*************************simulation.c***************************************
Student Name: Angus Galloway                        Student Number:  0793049
Date: April 1, 2013      	                   Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include "linkedList.h"

int main(int argc, char * argv[]){ 
    
    FILE * filePtrOne; /*Used for opening files of patron data*/
    FILE * filePtrTwo; 
    
    ListHeadPtr ticketLineOne; /*Pointers to the head of a ticketLine*/
    ListHeadPtr ticketLineTwo;
    ListHeadPtr snackLine;	/*Pointer to the head of the snackLine*/
    ListHeadPtr tempSnackLine;
    ListHeadPtr tempPatron;
    
    char * lineOnePrint; /*Used to print out the linked lists*/
    char * lineTwoPrint;
    char * snackLinePrint; 
    char * patronID;
    
    bool movie; /*Used to capture booleans from the file and pass them into createPatron*/
    bool snack;
    
    int snackLineLen = 0;    
    int startList = 0; /*Used to determine when to add to back of first ticket line*/
    int startList2 = 0; /*Used to determine when to add to back of second ticket line*/   
    int seconds;    
    int snackLineTime = 0; /*The total time of the snack-only patrons*/
    int snackTime = 0;    
    int startSnack = 0; /*Used to determine if a snackLine has already been started*/
    int readFile = 1; /*Used to alternate between the files, has value 1 or 2*/
    int fileOneLen;
    int fileTwoLen; /*The number of lines in each file*/
    int minFileLen;
    int i,j,s; 
    int deltaFileLen;  /*The difference between file lengths*/
    Patron * newPerson;
        
    patronID = malloc(sizeof(char)*7);    
        
    if (argc != 3) 
    {
        printf ("Usage: please indicate name of input file\n");
        exit(1);    
    }     
    
    filePtrOne = fopen(argv[1], "r");
    filePtrTwo = fopen(argv[2], "r");      
    
    fileOneLen = getFileLength(filePtrOne);
    fileTwoLen = getFileLength(filePtrTwo);
    
    printf("fileOneLen = %d\n",fileOneLen);
    printf("fileTwoLen = %d\n",fileTwoLen);
    
    if(fileOneLen > fileTwoLen) 
    {
        minFileLen = fileTwoLen;
        deltaFileLen = fileOneLen - fileTwoLen;
    }
    else if(fileOneLen < fileTwoLen)
    {
        minFileLen = fileOneLen;
        deltaFileLen = fileTwoLen - fileOneLen;
    }
    else
    {
        minFileLen = fileOneLen;
        deltaFileLen = 0;
    }
    
    printf("minFileLen = %d\n", minFileLen);
    
    /*Alternating between the two files filling the snackline and ticket lines 
    for the minimum file length, the remainder is processed afterwards*/
        
    for(i=0;i<minFileLen;i++){
	
                      
        if(readFile == 1){
            
	    fscanf(filePtrOne,"%s %d %d %d",patronID,&movie,&snack,&seconds);
            
            newPerson = createPatron(patronID,movie,snack,seconds); 		
                                                
            if(newPerson->isMovie == true && startList == 0)
            {
		ticketLineOne = newPerson;
		startList++;
		readFile = 2;
		printf("Created ticketLineOne\n");
            }  
            else if(newPerson->isMovie == true && startList != 0)
            {   
		addToBack(ticketLineOne,newPerson);
		readFile = 2;
		printf("Added to ticketLineOne\n");
	    }
	    else if(newPerson->isSnack == true && startSnack == 0 && newPerson->isMovie == false)
	    {
		snackLine = newPerson;
		startSnack++;
		readFile = 2;
		printf("Started snackLine\n");		
	    }
            else if(newPerson->isSnack == true && startSnack != 0 && newPerson->isMovie == false)
	    {
		addToBack(snackLine,newPerson);
		readFile = 2;
		printf("Added to snackLine\n");
	    }
	}        
                
        if(readFile == 2){	    
	    
	    printf("Enterred loop 2\n");
            
            fscanf(filePtrTwo,"%s %d %d %d",patronID,&movie,&snack,&seconds);
            
            newPerson = createPatron(patronID,movie,snack,seconds); 
	    
	    if(newPerson->isMovie == true && startList2 == 0)
	    {
		ticketLineTwo = newPerson;
		startList2++;
		readFile = 1;
		printf("Created ticketLineTwo\n");
	    }
        
            else if(newPerson->isMovie == true && startList2 != 0)
            {    
		addToBack(ticketLineTwo,newPerson);
                readFile = 1;
                printf("Added to ticketLineTwo\n");
            }
            
            else if(newPerson->isSnack == true && startSnack == 0 && newPerson->isMovie == false)
            {
		snackLine = newPerson;
		startSnack++;
		readFile = 1;
		printf("Created snackLine\n");
	    }
	    
	    else if(newPerson->isSnack == true && startSnack != 0 && newPerson->isMovie == false)
            {
		addToBack(snackLine,newPerson);
		readFile = 1;
		printf("Added to snackLine\n");
	    }
	}       
    }
    
   /*Fills the remaining lines with the left over file pointer*/
   
   if(fileOneLen > fileTwoLen){
        
        for(j=0;j<deltaFileLen;j++){
	    
            
            fscanf(filePtrOne,"%s %d %d %d",patronID,&movie,&snack,&seconds);
            
            newPerson = createPatron(patronID,movie,snack,seconds);                 
                                
            if(newPerson->isMovie == true && startList == 0)
            {
                ticketLineOne = newPerson;
                startList++;
                readFile = 2;
                printf("Created ticketLineOne\n");                    
            } 
            else if(newPerson->isMovie == true && startList > 0)
	    {    
		addToBack(ticketLineOne,newPerson);
		readFile = 2;
		printf("Added to ticketLineOne\n");
	    }
	    else if(newPerson->isSnack == true && startSnack == 0 && newPerson->isMovie == false)
	    {
		snackLine = newPerson;
		startSnack++;
		readFile = 2;
		printf("Started snackLine\n");
	    }
	    else if(newPerson->isSnack == true && startSnack > 0 && newPerson->isMovie == false)
	    {
		addToBack(snackLine,newPerson);
		readFile = 2;
		printf("Added to snackLine\n");
	    }            
        }
    }
    if(fileOneLen < fileTwoLen){
        
        for(j=0;j<deltaFileLen;j++){ 
            
            fscanf(filePtrTwo,"%s %d %d %d",patronID,&movie,&snack,&seconds);
            
            newPerson = createPatron(patronID,movie,snack,seconds); 
	    
	    if(newPerson->isMovie == true && startList2 == 0)
	    {
		ticketLineTwo = newPerson;
		startList2++;
		readFile = 1;
		printf("Created ticketLineTwo\n");
	    }
	    else if(newPerson->isMovie == true && startList2 > 0)
	    {    
		addToBack(ticketLineTwo,newPerson);
		readFile = 1;
		printf("Added to ticketLineTwo\n");
	    }
	    else if(newPerson->isSnack == true && startSnack == 0 && newPerson->isMovie == false)
	    {
		snackLine = newPerson;
		startSnack++;
		readFile = 1;
		printf("Created snackLine\n");
	    }
	    else if(newPerson->isSnack == true && startSnack > 0 && newPerson->isMovie == false)
	    {
		addToBack(snackLine,newPerson);
		readFile = 1;
		printf("Added to snackLine\n");
	    }
        }
    }
            
    lineOnePrint = printList(ticketLineOne);
    printf("\nTicket line one:\n");
    printf("%s", lineOnePrint);    
    
    lineTwoPrint = printList(ticketLineTwo); 
    printf("\nTicket line two:\n");
    printf("%s", lineTwoPrint);  
    
    snackLinePrint = printList(snackLine);
    printf("\nSnack line:\n");
    printf("%s", snackLinePrint);
    
    /**Sum the time from each of the people in the snack line, add to the 1,1's**/
    
    snackLineLen = length(snackLine);
    printf("snackLine contains %d patrons.\n",snackLineLen);
    
    tempSnackLine = snackLine;
    
    /*Find the total time of the snack line purchases, add to the elapsed time of each patron waiting in snack line attending movie*/
    
    for(s=0;s<snackLineLen;s++){
	
	snackTime = tempSnackLine->seconds;	
	printf("%s spends %d seconds making their snack purchase\n",tempSnackLine->PatronID,snackTime);
	tempSnackLine = tempSnackLine->next;
	snackLineTime = snackLineTime + snackTime;
    }
    printf("The total time of the snackLine is %d\n",snackLineTime);
    
    while(ticketLineOne != NULL && ticketLineTwo != NULL) 
    {    
	if(ticketLineTwo->isSnack == true && ticketLineTwo->seconds < ticketLineOne->seconds){
	    
	    tempPatron = ticketLineTwo;
	    tempPatron->elapsedTime = tempPatron->seconds + snackLineTime;	   
	    ticketLineTwo = ticketLineTwo->next;
	    addToBack(snackLine,tempPatron);    
	    printf("%s was added to the snackLine.\n",tempPatron->PatronID);
	    
	}
	else if(ticketLineTwo->isSnack == true && ticketLineTwo->seconds >= ticketLineOne->seconds ){
	    
	    tempPatron = ticketLineOne;
	    tempPatron->elapsedTime = tempPatron->seconds + snackLineTime;
	    ticketLineOne = ticketLineOne->next;
	    addToBack(snackLine,tempPatron);
	    printf("%s was added to the snackLine.\n",tempPatron->PatronID);
    
	}
	return 0;
    }
    
    destroyPatronList(ticketLineOne);
    destroyPatronList(ticketLineTwo);
    destroyPatronList(snackLine);
     
    fclose(filePtrOne);
    fclose(filePtrTwo);
     
 return 0;
 
}
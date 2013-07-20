/*************************linkedList.c***************************************
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

#include "linkedList.h"

/******************************************
 * Function: isEmpty
 * Purpose: Returns true if the list is empty and false in all other cases.  
 * The function does not change the list in any way.
 *****************************************/

bool isEmpty(ListHeadPtr theList){
  
    ListHeadPtr tempoList;
    int numPatrons = 0;  
    tempoList = theList;
    
    while(tempoList != NULL)
    {
        numPatrons++;
        tempoList = tempoList->next;    
    }
    if(numPatrons == 0)
    {    
	return true;   
    }
    return false;    
}

/******************************************
 * Function: addtoFront
 * Purpose: This function adds the node sent in as a parameter to the front of the list that
 * is given as a parameter. The function returns the new head of the list.
 ****************************************/
    
ListHeadPtr addToFront(ListHeadPtr theList, Patron * toBeAdded){
    
    if(toBeAdded == NULL){
        printf("The struct is null, returning the original list.\n");
        return theList;
    }
    if(theList == NULL){
	return(toBeAdded);
    }
    else if(theList != NULL){
	toBeAdded->next = theList;
	theList = toBeAdded;
    }    
    return theList;
}

/******************************************
 * Function: removeFromFront
 * Purpose: This function removes the first item from the given list, sets the next pointer of that item to NULL
 * and returns a pointer to the new head of the list (the item that was the second item).
 * ***************************************/

ListHeadPtr removeFromFront(ListHeadPtr theList){
  
    ListHeadPtr temp;
    
    temp = theList;
 
    if(temp->next != NULL && temp != NULL)
    {       
        temp = theList;
        temp = temp->next; 
        return(temp);
    }
    return(NULL);    
}

/******************************************
 * Function: getFront
 * Purpose: This function returns a pointer to the item that is at the front of the list. 
 * It does not change the list in any way.
 * ***************************************/

Patron * getFront(ListHeadPtr theList){
    
    ListHeadPtr temp;
    Patron * theFront;
    
    temp = theList;
  
    theFront = malloc(sizeof(Patron));
  
    if(temp != NULL)
    {
       theFront = temp;
       return theFront;
    }
    else
    {
	printf("Usage: Could not find back, no list found\n");  
	return NULL;
    }    
 
}

/******************************************
 * Function: addToBack
 * Purpose: This function adds the node sent as a parameter to the back of the list sent in as a parameter.
 * It returns a pointer to the head of the list.
 *****************************************/

ListHeadPtr addToBack(ListHeadPtr theList, Patron * toBeAdded){
  
   Patron * theBack;      
   
    if(theList != NULL && toBeAdded != NULL)
    {         
	theBack = getBack(theList);
	
	if(theBack != NULL)
	{
	    theBack->next = toBeAdded;
	    toBeAdded->next = NULL;  
	}
    }
    else if(theList == NULL)
    {
	 return(toBeAdded);
    }
    else if(toBeAdded == NULL)
    {
	return(theList);
    }
    return(theList); 
}

/***********************************************************************
 * Function: removeFromBack
 * Purpose: This function removes the last item from the list and returns a pointer to 
 *          the head of the list. The function sets the next pointer of the new last 
 *          item to NULL and it sets the next pointer of the removed item to NULL. 
 ***********************************************************************/  
  
ListHeadPtr removeFromBack(ListHeadPtr theList){
  
    ListHeadPtr temp;  
    Patron * tempBack;
    Patron * newBack;
    
    temp = theList;
    
    if(temp == NULL){
        
        return NULL;
    }
    tempBack = getBack(temp);  
    
    while(temp != NULL)
    {     
	if(tempBack == temp->next)
	{            
	    newBack = temp;
	    newBack->next = NULL;
	}
	temp = temp->next;
    }  
	return(theList);      
}

/***********************************************************************
 * Function: getBack
 * Purpose: This function returns a pointer to the last item in the linked list that is
 * given as a parameter.  The function does not change the list in any way.
 ***********************************************************************/  

Patron * getBack(ListHeadPtr theList){
  
    ListHeadPtr temp;
    Patron * theBack;
    
    temp = theList;      
    
    while(temp != NULL)
    {    
	if(temp->next == NULL)
	{
	    theBack = temp;
	    return theBack; 
	}
	    
    temp = temp->next; 
    }
    
    return NULL;   
}
/******************************************
 * Function: printList
 * Purpose: Prints the patron ID for each patron in the list to a string beginning with 
 *  the front of the list. The Patron Ids are printed one per line with a newline immediately following the id.
 *  It returns the string.
 ****************************************/

char * printList(ListHeadPtr theList){
  
    ListHeadPtr temp;
    char * printBuf;
    char * sumOfStrings;
    int numPatrons;
    
    temp = theList;
    printBuf = malloc(sizeof(char)*15);
    
    if(temp != NULL){       
    
        numPatrons = length(theList);
        
        numPatrons = numPatrons * 20;    
        sumOfStrings = malloc(sizeof(char)*(numPatrons));
        
        while(temp != NULL)
        {
            sprintf(printBuf,"%s\n", temp->PatronID);
            strcat(sumOfStrings,printBuf);
            temp = temp->next;
        }
    return(sumOfStrings);
    }
    return("");
}

/******************************************
 * Function: length
 * Purpose: Finds the length of a linkedList by incrementing 
 * a counter for every stuct it contains. 
 ****************************************/

int length(ListHeadPtr theList){
  
    ListHeadPtr tempoList;
    int count=0;
    
    tempoList = theList;      
  
    if(theList != NULL)
    {
        while(tempoList != NULL)
        {
            count++;
            tempoList = tempoList->next;
        }
        return count; 
    }
    return 0;
}

/******************************************
 * Function: destroyPatronList
 * Purpose: this function should free all the memory for the list, except possibly the head pointer
 * which will need to be freed separately.
 ****************************************/
void  destroyPatronList(ListHeadPtr theList){
    
    ListHeadPtr temp;
    
    while(theList != NULL)
    {        
        temp = theList;
        theList = temp->next;
        destroyPatron(temp);
	free(temp);
    }       
}

/******************************************
 * Function: createPatron
 * Purpose: This list must take in four parameters and return a pointer to a patron struct.
 ****************************************/

Patron * createPatron(char * id, bool movie, bool snack, int time){
    
    Patron * newPatron = malloc(sizeof(Patron));
    newPatron->PatronID = malloc (sizeof(char )*6);
    
    if((movie == 1 || movie == 0) && (snack == 1 || snack == 0) && (strlen(id) == 6)){  
		             
	strcpy(newPatron->PatronID,id);
	newPatron->isMovie = movie;
        newPatron->isSnack = snack;
        newPatron->seconds = time;
    }
    else{
        strcpy(newPatron->PatronID,"No ID");
        newPatron->isMovie = 0;
        newPatron->isSnack = 0;
        newPatron->seconds = 0;
    }
    return (newPatron);   
}  
/******************************************
 * Function: getID
 * Purpose: This function must return a pointer to the ID of the Patron.  It should
 * not allocate extra memory.
 ****************************************/

char * getID(Patron * thePatron){
    
    return thePatron->PatronID;
}

/******************************************
 * Function: getTime
 * Purpose: This function should return the amount of time that a patron takes
 * to purchase items.
 ****************************************/

int getTime(Patron * thePatron){
    
    return thePatron ->seconds;
}

/******************************************
 * Function: getMovie
 * Purpose: this function should return a boolean indicating whether or not the Patron
 * is attending the movie.
 ****************************************/

bool getMovie(Patron * thePatron){

    return thePatron->isMovie;
}

/******************************************
 * Function: getSnack
 * Purpose: this function should return a boolean indicating whether or not the Patron
  is purchasing a snack 
 ****************************************/

bool getSnack(Patron * thePatron){
    
    return thePatron->isSnack;
}

/******************************************
 * Function: getNextPatron
 * Purpose: This function is for testing purposes only and doesn't belong in a linked list 
 *      implementation.  Please include it so we can use it to test your software.  It should
 *      return the pointer to the 'next' item in the linked list, given a patron pointer as a parameter. 
 ****************************************/

Patron * getNextPatron(Patron * thePatron){
 
    if(thePatron->next != NULL)
    {
        return thePatron->next;    
    }
    else
    {
        printf("Reached end of List, could not find next patron.\n");
        return NULL;
    }
}

/******************************************
 * Function: destroyPatron
 * Purpose: this function should free any memory allocated to the patron and 
 * should set all of the non-dynamic variables to a default value.  The pointer
 * to the patron will have to be freed separately 
 ****************************************/

void destroyPatron(Patron * thePatron){    
    
    free(thePatron->PatronID);
    thePatron->isMovie = 10;
    thePatron->isSnack = 10;
    thePatron->seconds = 0;
    
}

#include<ncurses.h>


void initCurses();

void drawRoom();

int gameData(int rows, int cols, char ** roomDataPtr, char ** rmArray, int roomNum);

void findCoord(char * array, int * X, int * Y);

void findDoorPosn(char * array1, int * doorXorY);

void placeDoor(int r, int c, char ** mod2darray, char * door,int DXY);


/*typedef struct roomDimensions wall;*/



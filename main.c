#include <stdio.h>
#include <stdlib.h>
#include "readArgs.h"
#include "boardWork.h"
#include "playTurns.h"
#include "winLose.h"

int main(int argc, char** argv){ //main needs to accept 3 args
    
    int numRows= 0;
    int numCols= 0;
    int numWin = 0; //initialize variables of user input
    int num = 1;
    char** board = NULL;
    int curPlayer = 1;
    
    
    numRows = readArgs(argc, argv, num); //read in control arguments

    //FIXME:
    printf("%d\n", numRows);

    numCols = readArgs(argc, argv, num + 1); //num keeps track of location
    numWin = readArgs(argc, argv, num + 2);

    board = createBoard(numRows, numCols); //create a board using malloc
    printBoard(board, numRows, numCols); //printboard for user
    
    playGame(numRows, numCols, board, curPlayer, numWin); //call gameplay function
    
    destroyBoard(board); //free the space used by malloc
    
    return 0;
}
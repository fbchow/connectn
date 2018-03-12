#include "playTurns.h"
#include "winLose.h"
#include "boardWork.h"
#include <stdio.h>

void playGame(int numRows, int numCols, char** board, int curPlayer, int numWin){
    int heights[numCols];
    int colChoice;
    int playerChar;
    int i;
    int isGameOver = 0; //game isn't over if =0
    /*
     This function needs to get a play,determine if it's valid, if it is, validPlay will return it. If not, it will recursively keep asking for input. then the program has to check if there is available space using the heights array, and if there is
     */
    
    if(curPlayer == 1){
        playerChar = 'X';
    }
    if(curPlayer == 2){
        playerChar = 'O';
    }

    while(isGameOver != 1){
        
        colChoice = getPlay(numCols, numRows, board);
        printf("Passed column checking\n");
        if(heights[colChoice] >= numRows){
            colChoice = getPlay(numCols, numRows, board);
            continue;
        }
    
        i = numRows - heights[colChoice] - 1;
        board[i][colChoice] = playerChar;
        printBoard(board, numRows, numCols);
        
        if(curPlayer == 1){
            curPlayer = 2;
        }
        if(curPlayer == 2){
            curPlayer = 1;
        }
        printf("player changed to %d",curPlayer);
        isGameOver = gameOver(board, numRows, numCols, playerChar, numWin);
    }
}

int getPlay(int numCols, int numRows, char** board){
    int colChoice;
    
    printf("Enter a column between 0 and %d to play in: ", numCols - 1);
    scanf(" %d ", &colChoice);
    printf("scanned choice");
    playValid(colChoice, numRows, numCols, board);
    printf("checked if play valid");
    if(colChoice == 'q'){
        getPlay(numCols, numRows, board);
    }
    return colChoice;
}

int playValid(int colChoice, int numRows, int numCols, char** board){
    int i,j,k = 0;
    //if incorrect choice, colChoice == 'q'
    
    if((colChoice < 0) || (colChoice > numCols - 1)){//if choice isn't between 0 and numCols - 1
        colChoice = 'q';
        return colChoice;
    }
    
    j = colChoice;
    for(i = 0; i < numCols; i++){//ifcolumn isfull
        if((board[i][j] == 'X') || (board[i][j] == 'O')){
            k++;
        }
    }
    if(k == numRows){
        colChoice = 'q';
        return colChoice;
    }
    
    return colChoice; //else - return colChoice to playGame - not q so a playable option
}
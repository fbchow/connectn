#include "winLose.h"
#include "boardWork.h"
#include <stdio.h>
#include <stdlib.h>

int gameOver(char** board, int numRows, int numCols, int playerChar, int numWin){
    int rWin,cWin,dWin,rdWin = 0;
    int numChar = 0;
    int i,j = 0;
    char checkPlayer = '.';

    if(playerChar == 'X'){
        checkPlayer = 'O';
    }
    else if(playerChar == 'O'){
        checkPlayer = 'X';
    }
    
    //call functions to check if the latest move resulted in a win
    rWin = rowWin(board, numRows, numCols, checkPlayer, numWin);
    cWin = colWin(board, numRows, numCols, checkPlayer, numWin);
    dWin = diagWin(board, numRows, numCols, numWin, checkPlayer);
    rdWin = rightdiagWin(board, numRows, numCols, numWin, checkPlayer);
    
    //iterate through board
    //keep track of the number of characters on the board with the counter numChar
    for(i = 0; i < numRows; i++){
        for(j = 0; j < numCols; j++){
            if((board[i][j] == 'X') || (board[i][j] == 'O')){
                numChar++;
            }
        }
    }


    //if the latest play resulted in 0 values for every win scenario
    // and the board is full
    //call the isTie function
    if((rWin == 0) && (cWin == 0) && (dWin == 0) && (rdWin == 0) && (numChar == numRows * numCols)){
        isTie();
    }
    
    //if the latest play resulted in 1 value, the player won
    if((rWin == 1) || (cWin == 1) || (dWin == 1) || (rdWin == 1)){
        gameWon(checkPlayer);
    }
    return 0; //0 means no one won; play the game again
}

//tie game situation: numRows == numRows * numCols
void isTie(){
    printf("Tie game!");
    exit(0);
}

//declare the winner of th game
void gameWon(int checkPlayer){
    int curPlayer;
    
    //the latest player by the 'X' is coded as Player 1
    if(checkPlayer == 'X'){
        curPlayer = 1;
    }
    //the last play by the 'O' is coded as Player 2
    if(checkPlayer == 'O'){
        curPlayer = 2;
    }

    printf("Player %d won!", curPlayer);
    exit(0);
    
}

int rowWin(char** board, int numRows, int numCols, char checkPlayer, int numWin){
    int i,j = 0;
    int charinRow = 0;
    
    for(i = 0; i < numRows; i++){
        charinRow = 0;
        for(j = 0; j < numCols; j++){
            if(board[i][j] == checkPlayer){
                charinRow++;
            }
        }
        if(charinRow == numWin){
            return 1;
        }
    }
    return 0; //return 1 if win
}

int colWin(char** board, int numRows, int numCols, int checkPlayer, int numWin){
    int i,j = 0;
    int charinCol = 0;

    for(j = 0; j < numCols; j++){
        charinCol = 0;
        for(i = 0; i < numRows; i++){
            if(board[i][j] == checkPlayer){
                charinCol++;
            }
        }
        if(charinCol == numWin){
            return 1;
        }
    }
    
    return 0; //return 1 if win
}

int diagWin(char** board, int numRows, int numCols, int numWin, char checkPlayer){
    int i,j,l,m = 0;
    int h = 0;

    if((numCols >= numWin) || (numRows >= numWin)) {
        while(m < numRows){
            l = 0;
            
            for(i = m; i >= 0; i--){ //FIXME - check on how to iterate diagonal
                for(j = 0; ((j < numCols) && (j < m)); j++){
                    l++;
                    if(board[i][j] == checkPlayer){
                        h++;
                    }
                }
            }
            
            m++;
        }
        if((l >= numWin) && (h == numWin)){
            return 1;
        }
    }
    else{
        return 0;
    }
    
    return 1; //return 1 if win
}

int rightdiagWin(char** board, int numRows, int numCols, int numWin, char checkPlayer){
    int i,j,l,m = 0;
    int h = 0;
    
    if((numCols >= numWin) || (numRows >= numWin)) {
        while(m < numRows){
            l = 0;
            
            for(i = m; i >= 0; i--){ //FIXME - check on how to iterate right diagonal
                for(j = numCols - 1; ((j < l) && (j < m)); j--){
                    l++;
                    if(board[i][j] == checkPlayer){
                        h++;
                    }
                }
            }
            
            m++;
        }
        if((l >= numWin) && (h == numWin)){
            return 1;
        }
    }
    else{
        return 0;
    }
    
    return 1; //return 1 if win
}

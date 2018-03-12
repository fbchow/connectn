#include "boardWork.h"
#include <stdio.h>
#include <stdlib.h>

char** createBoard(int numRows, int numCols){
    int i,j;
    char** board;

    board = (char**)malloc(numRows * sizeof(char*));
    
    for(i = 0; i < numRows; i++){
        board[i] = (char*)malloc(numCols * sizeof(char));
    }
    
    for(i = 0; i < numRows; i++){
        for(j = 0; j < numCols; j++){
            board[i][j] = '*';
        }
    }
    return board;
}

void printBoard(char** board, int numRows, int numCols){
    int i,j = 0;
    
    for(i = 0; i < numRows; i++){
        printf("%d ", i);
        for(j = 0; j < numCols; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(i = 0; i < numCols; i++){
        printf("%d ", i);
    }
    printf("\n");
}

void destroyBoard(char** board){
    free(board);
}
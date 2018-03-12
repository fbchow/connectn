#ifndef BOARDWORK_H
    #define BOARDWORK_H

char** createBoard(int numRows, int numCols);
void printBoard(char** board, int numRows, int numCols);
void destroyBoard(char** board);

#endif
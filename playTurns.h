#ifndef PLAYTURNS_H
    #define PLAYTURNS_H

void playGame(int numRows, int numCols, char** board, int curPlayer, int numWin);
int getPlay(int numCols, int numRows, char** board);
int playValid(int colChoice, int numRows, int numCols, char** board);

#endif
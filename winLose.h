#ifndef WINLOSE_H
    #define WINLOSE_H

int gameOver(char** board, int numRows, int numCols, int playerChar, int numWin);
void gameWon(int checkPlayer);
int rowWin(char** board, int numRows, int numCols, char checkPlayer, int numWin);
int colWin(char** board, int numRows, int numCols, int checkPlayer, int numWin);
int diagWin(char** board, int numRows, int numCols, int numWin, char checkPlayer);
int rightdiagWin(char** board, int numRows, int numCols, int numWin, char checkPlayer);
void isTie();

#endif
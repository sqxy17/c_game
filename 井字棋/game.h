#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COLUMN 3

void InitBoard(char board[ROW][COLUMN],int  row,int column);

void DisplayBoard(char board[ROW][COLUMN],int row,int column);

void PlayerRound(char board[ROW][COLUMN],int row,int column);

void ComputerRound(char board[ROW][COLUMN],int row,int column);

char IsWin(char board[ROW][COLUMN],char piece) ;



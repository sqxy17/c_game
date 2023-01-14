#include "game.h"

void InitBoard(char board[ROW][COLUMN],int row,int column)
{
    int m;
    int n;
    for(m=0;m<row;m++)
    {
        for(n=0;n<column;n++)
        {
            board[m][n]=' ';
        }
    }
}



void DisplayBoard(char board[ROW][COLUMN],int row,int column)
{
    int m;
    int n;
    for(m=0;m<row;m++)
    {
        for(n=0;n<column;n++)
        {
            printf(" %c",board[m][n]);
            if(n<2)
            {
                printf("|");
            }

        }
        printf("\n");
        for(n=0;n<row;n++)
        {
            if(m<2)
            {
                printf("__ ");
            }
        }
        printf("\n");
    }
}



void PlayerRound(char board[ROW][COLUMN],int row,int column)//玩家进行下棋
{
    int x;
    int y;
    do
    {
        printf("请输入下的棋子的坐标，用空格隔开：");
        scanf("%d%d", &x, &y);
        if (x < 1 || x > 3 || y < 1 || y > 3)
        {
            printf("坐标输入错误，请重新输入：\n");
        }
        else
        {   if(board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='o';
                break;
            }
            else
            {
                printf("当前坐标已被占用，请重新输入\n");
            }
        }
    }while(1);
}

void ComputerRound(char board[ROW][COLUMN],int row,int column)
{
    int x;
    int y;
    while(1)
    {
         x=rand()%3;
         y=rand()%3;
         if(board[x][y]==' ')
            {
                board[x][y]='x';
                break;
            }
    }
}


char condition(char board[ROW][COLUMN],char piece)
{
    int x;
    int y;
    for(x=0;x<ROW;x++)
    {
        if(board[x][1]==piece && board[x][2]==piece && board[x][3]==piece)//在这里不能用连等a==b==c    要用a==c && b==c,否则实际的语法会变成1/0==c,前面的判断会将a==b转换成1或者0
            return piece;
    }

    for(y=0;y<COLUMN;y++)
    {
        if(board[0][y]==piece && board[1][y]==piece && board[2][y]==piece)
            return piece;
    }

    if((board[0][0]==piece && board[1][1]==piece && board[2][2]==piece)||
            (board[0][2]==piece && board[1][1]==piece && board[2][0]==piece))
        return piece;
}


char IsFull(char board[ROW][COLUMN])
{
    int count=9;
    int i=0,j=0;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            if(board[i][j]!=' ')
                count--;
        }
    }
    if(count==0)
        return 'f';
}


char IsWin(char board[ROW][COLUMN],char piece)
{
    if (condition(board, piece) == piece) {
        return piece;//玩家胜
    }

    if (condition(board, piece) == piece) {
        return piece;//电脑胜
    }

    if(IsFull(board)=='f'){
        return 'f';//平局
    }
}
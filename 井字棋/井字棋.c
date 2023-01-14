#include"game.h"


void game_related_function()
{
    char judge_wol;//接收返回值，用来判断输赢以及棋盘是否下满

    char board[ROW][COLUMN];

    InitBoard(board,ROW,COLUMN);//初始化数组

    DisplayBoard(board,ROW,COLUMN);//将其盘打印出来
    while(1)
    {
        PlayerRound(board,ROW,COLUMN);//玩家回合下棋
        DisplayBoard(board,ROW,COLUMN);//将其盘打印出来
        judge_wol=IsWin(board,'o');//判断下棋后是否获胜
        if(judge_wol=='o')
        {
            printf("玩家获胜");
            break;
        }
        if(judge_wol=='f')
        {
            printf("平局\n");
            break;
        }
        if(judge_wol=='v')
        {

        }



        ComputerRound(board,ROW,COLUMN);
        DisplayBoard(board,ROW,COLUMN);//将其盘打印出来

        judge_wol=IsWin(board,'x');
        if(judge_wol=='x')
        {
            printf("电脑获胜");
            break;
        }
        if(judge_wol=='v')
        {

        }
    }
}


void menu()
{
    printf("-----1.开始游戏      0.退出游戏------\n");
}


void option()
{
    int i;//用来选项游戏项目
    do
    {
        menu();
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                game_related_function();//游戏相关功能
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误请重新输入：\n");
                break;
        }

    }while(i);
}

int main(void)
{
    srand((unsigned int)time(NULL));
    option();//option:选项
}
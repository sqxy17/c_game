#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
    printf("-----1.开始游戏   0.退出游戏-----\n");
}

void game()
{
    int x=rand()%10;
    int y=-1;
    printf("请开始输入猜测的数字：");
    while(y!=x)
    {  
        scanf("%d",&y);
        if(y>x)
            printf("猜大了，请继续输入：");
        else if(y<x)
            printf("猜小了,请继续输入：");
        else
            printf("猜对了");
    }
}

void guess()
{
    int i=1;
    while(i){
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            game();
            menu();
            break;
        case 0:
            printf("退出游戏");
            break;
        default:
            printf("输入错误请重新输入:");
    }
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));
    menu();
    guess();
}
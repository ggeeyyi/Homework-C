#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    int com,user;
    char c;
    srand((unsigned)time(NULL)); 
    printf("进入游戏\n");
    do{
        printf("请出拳(1.剪刀、2.石头、3.布）:");
        scanf("%d",&user);
        com=rand()%3+1; 
        printf("电脑出%s\n",com==1?"剪刀":com==2?"石头":"布");
        switch(com-user)
        {
            case 0:
                printf("平手\n");
            break;
            case 1:
            case -2:
                printf("电脑赢了\n");
            break;
            case -1:
            case 2:
                printf("你赢了\n");
    }
    printf("继续游戏按Y键、按其它键退出");
        getchar();
    c=getchar();
    }
        while(c=='Y');
    printf("退出游戏");
    return 0;
}
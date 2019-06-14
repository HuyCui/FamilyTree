/********************************************************
         Copyright: SDUT 2018-2068
         Author: 崔辉
         Data:2018-01-14
         Description:添加成员信息界面
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
void show_creat(tree *root)
{
    while(1)
    {
        printf("\033[34m***************新建家谱树*****************\033[34m\n\n");
        printf("\033[34m           1、建立家谱\033[34m\n");
        printf("\033[34m           0、退出\033[34m\n\n");
        printf("\033[34m           （性别：男 M;  女 F）\n");
        printf("\033[34m******************************************\033[34m\n");
        printf("\033[34m请输入您的选择：\033[34m");
        int n;
        char order[105];
        scanf("%s", order);
        if(strlen(order) > 1)//指令长度大于一
        {
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
            sleep(2);
            system("clear");
            continue;
        }
        switch(order[0]-'0')
        {
        case 1:
            create(root);
            break;
        case 0:
            system("clear");
            return;
            break;
        default:
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
        }
        sleep(2);
        system("clear");
    }
}


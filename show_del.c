/********************************************************
         Copyright: SDUT 2018-2068
         Author: 崔辉
         Data:2018-01-14
         Description:删除成员信息界面
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "del.h"
#include "tree.h"

void show_del(tree *root)
{
    char Name[15], for_sure, order[105];
    int num;
    while(1)
    {
        printf("\033[34m*****************选择你的操作****************\033[34m\n");
        printf("\033[34m***************1：删除某一成员****************\033[34m\n");
        printf("\033[34m******************0：退出****************\033[34m\n");
        scanf("%s", order);
        if(strlen(order) > 1)
        {
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
            sleep(2);
            system("clear");
            continue;
        }
        if(order[0]-'0' == 1)//指令长度大于一
        {
            printf("\033[34m***********请输入要删除成员的名字***************\033[34m\n");
            scanf("%s%*c", Name);
            printf("\033[34m***********您确认删除吗（y/n）***************\033[34m\n");
            scanf("%c", &for_sure);
            if(for_sure == 'y')
            {
                Delete(root, Name);
            }
            else
            {
                system("clear");
                return ;
            }
        }
        else if(order[0]-'0' == 0)
        {
            system("clear");
            return ;
        }
        else
        {
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
        }
    }
}


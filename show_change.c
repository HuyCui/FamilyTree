/********************************************************
         Copyright: SDUT 2018-2068
         Author: 王姗姗
         Data:2018-01-14
         Description:修改成员信息界面
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "change.h"
void show_change(tree *root)
{
    while(1)
    {
        printf("\033[34m******************成员信息修改**************\033[34m\n\n");
        printf("\033[34m           1、信息修改\033[34m\n");
        printf("\033[34m           2、确认修改\033[34m\n");
        printf("\033[34m           3、撤销修改\033[34m\n");
        printf("\033[34m           0、退出\033[34m\n\n");
        printf("\033[34m******************************************\033[34m\n");
        printf("\033[34m请输入您的选择：\033[34m");
        int n, d;
        char order[105];
        scanf("%s%*c", order);
        if(strlen(order) > 1)//指令长度大于一
        {
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
            sleep(2);
            system("clear");
            continue;
        }
        char name[15], name1[15];
        switch(order[0]-'0')
        {
        case 1:
            printf("\033[34m请输入要修改成员的姓名：\033[34m");
            scanf("%s%*c", name);
            printf("\033[34m请输入修改后的姓名：\033[34m");
            scanf("%s%*c", name1);
            printf("\033[31m是否确认修改？\033[31m\n");
            scanf("%d%*c", &d);
            if(d == 2)
            {
                change(root, name, name1);
            }
            else
            {
                printf("\033[34m撤销成功！\033[34m");
            }
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


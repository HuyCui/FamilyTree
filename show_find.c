/********************************************************
         Copyright:SDUT 2018-2068
         Author: 王姗姗
         Data:2018-01-14
         Description:查询成员信息界面
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "cha.h"
void show_find(tree *root)
{
    while(1)
    {
        printf("\033[34m***************成员信息查询****************\033[34m\n");
        printf("\033[34m           1、查找成员信息\033[34m\n");
        printf("\033[34m           2、查找成员孩子信息\033[34m\n");
        printf("\033[34m           3、查找两个人的关系\033[34m\n");
        printf("\033[34m           4、查找成员三代人信息\033[34m\n");
        printf("\033[34m           5、查找同一辈份成员信息\033[34m\n");
        printf("\033[34m           0、退出\033[34m\n");
        printf("\033[34m******************************************\033[34m\n");
        printf("\033[34m请输入您的选择：\033[34m");
        int n, class, i;
        char name[15], name1[15], order[105];
        scanf("%s%*c", order);
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
            printf("\033[34m请输入要查询成员的姓名:\033[34m");
            scanf("%s%*c", name);
            chu();
            if(!find(root, name))
            {
                printf("\033[31m没有该成员信息！\033[31m\n");
            }
            break;
        case 2:
            printf("\033[34m请输入要查询成员的姓名:\033[34m");
            scanf("%s%*c", name);
            chu();
            if(!find_parent(root, name))
            {
                printf("\033[31m没有该成员信息！\033[31m\n");
            }
            break;
        case 3:
            printf("\033[34m请输入两个查询成员的姓名（名字之间用空格隔开）:\033[34m\n");
            scanf("%s %s%*c", name, name1);
            chu();
            if(!find_connect(root, name, name1))
            {
                printf("\033[31m没有该成员信息！\033[31m\n");
            }
            break;
        case 4:
            printf("\033[34m请输入要查询成员的姓名:\033[34m");
            scanf("%s%*c", name);
            find_three(root, name);
            break;
        case 5:
            printf("\033[34m请输入要查询辈份:\033[34m");
            scanf("%d%*c", &class);
            chu();
            if(!find_same_class(root, class))
            {
                printf("\033[31m没有该辈份成员信息！\033[31m\n");
            }
            break;
        case 0:
            system("clear");
            return;
            break;
        default:
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
        }
        printf("\033[34m***************按ENTER键继续**************\033[34m\n");
        getchar();
        system("clear");
    }
}


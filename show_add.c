/********************************************************
         Copyright: SDUT 2018-2068
         Author: 王姗姗
         Data:2018-01-14
         Description:添加成员信息界面
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "cha.h"

void show_add(tree **root)
{
	tree *temp, *temp1;
    while(1)
    {
        printf("\033[34m******************成员添加****************\033[34m\n\n");
        printf("\033[34m       1、添加新成员作为整个家谱的祖先\033[34m\n");
        printf("\033[34m       2、添加新成员作为某一成员的孩子\033[34m\n");
        printf("\033[34m       0、退出\033[34m\n\n");
        printf("\033[34m           （性别：男 M;  女 F）\n");
        printf("\033[34m******************************************\033[34m\n");
        printf("\033[34m请输入您的选择：\033[34m");
        int n, flag = 0;
        char name[105], ch, name1[105], order[105];
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
            printf("\033[34m请输入祖先姓名：\033[34m");
            scanf("%s%*c", name);
            printf("\033[34m请输入祖先性别：\033[34m");
            scanf("%c%*c", &ch);
            chu();
            temp = (tree *)find_point(*root, name);//查找成员位置
            if(temp == NULL)//未找到
	            *root = add_zuxian(*root, name, ch);
	        else
	        	printf("\033[31m家谱中已存在该成员！\033[31m\n");
            break;
        case 2:
            printf("\033[34m请输入新成员姓名：\033[34m");
            scanf("%s%*c", name);
            printf("\033[34m请输入新成员父亲姓名：\033[34m");
            scanf("%s%*c", name1);
            printf("\033[34m请输入新成员性别：\033[34m");
            scanf("%c%*c", &ch);
            chu();
            temp = (tree *)find_point(*root, name);//查找成员位置
            chu();
            temp1 = (tree *)find_point(*root, name1);//查找父亲位置
            if(temp1)//找到父亲
			{
				if(temp == NULL)
					add(*root, name, name1, ch, &flag);
				else
					printf("\033[31m家谱中已存在该成员！\033[31m\n");
			}
	        else
	        	printf("\033[31m添加成员失败！\033[31m\n");
            if(flag)//添加成功
            {
                printf("\033[34m添加成功！\033[34m\n");
            }
            /*else
            {
            	printf("\033[31m添加成员失败！\033[31m\n");
            }*/
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


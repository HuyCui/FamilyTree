/********************************************************
         Copyright: SDUT 2018-2068
         Author: 崔辉
         Data:2018-01-14
         Description:修改成员信息
         Email:
********************************************************/
#include <stdio.h>
#include <string.h>
#include "change.h"
#include "cha.h"
#include "tree.h"
/********************************************************
         fountion:修改成员信息
         in:tree *root 家谱树
            char Name[] 成员原来的名字
            char Name_changed[] 成员修改后的名字
         step:1、查看成员是否存在
              2、如果存在则修改成员信息
********************************************************/
void change(tree *root, char Name[], char Name_changed[])
{
    tree *temp;
    temp = (tree *)find_point(root, Name);//查看该成员是否存在
    if(temp == NULL)//不存在
        printf("\033[31m没有该成员信息！\033[31m\n");
    else
    {
        strcpy(temp->name, Name_changed);//修改成员信息
        printf("\033[34m该成员的信息已经成功修改！\033[34m\n");
    }
}

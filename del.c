/********************************************************
         Copyright: SDUT 2018-2068
         Author: 李晓龙
         Data:2018-01-14
         Description:修改成员信息
         Email:
********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "del.h"
#include "tree.h"
#include "cha.h"
/********************************************************
         fountion: 删除成员信息
         in:tree *root 家谱树
            char name[] 成员信息
         step:1、查看成员是否存在
              2、如果存在则删除成员信息
********************************************************/
void Delete(tree *root, char name[])
{
    tree *temp_child, *temp;
    chu();//初始化
    temp_child = (tree *)find_point(root, name);//查看是否存在
    if(temp_child && temp_child == root)//存在且为祖先
    {
        printf("\033[31m你不能删除祖先！\033[31m\n");
        return ;
    }
    if(temp_child == NULL)//不存在
    {
        printf("\033[31m没有该成员信息！\033[31m\n");
        return ;
    }
    if(temp_child->parent->child == temp_child)//该成员直接连接在父亲上
    {
        temp_child->parent->child = NULL;
        temp_child->parent->child = temp_child->brother;
    }
    else
    {
        temp = temp_child->parent->child;//连接该孩子的上一个指针
        while(temp->brother != temp_child  && temp)
        {
            temp = temp->brother;
        }
        temp->brother = temp->brother->brother;
    }
    printf("\033[31m该成员已被删除！\033[31m\n");
}


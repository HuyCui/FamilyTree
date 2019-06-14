/********************************************************
         Copyright: SDUT 2018-2068
         Author: 孙昊
         Data:2018-01-14
         Description:展示家谱树信息
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include "show.h"
#include "tree.h"
/************************************************************
           fountion:展示家谱树信息
           in: tree *root 家谱树
************************************************************/
void show(tree *root)
{
    long long int aa;
    if(root == NULL) return ;//家谱树为空
    else
    {
        for(aa = 1; aa < root->degree; aa++)
        {
            printf("        ");
        }
        printf("%s\n", root->name);
        show(root->child);//输出孩子信息
        show(root->brother);//输出兄弟信息
    }
}


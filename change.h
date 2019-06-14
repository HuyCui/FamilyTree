/********************************************************
         Copyright: SDUT 2018-2068
         Author: 崔辉
         Data:2018-01-14
         Description:修改成员信息
         Email:
********************************************************/
#ifndef _CHANGE_H
#define _CHANGE_H
#include "tree.h"
/********************************************************
         fountion:修改成员信息
         in:tree *root 家谱树
            char Name[] 成员原来的名字
            char Name_changed[] 成员修改后的名字
********************************************************/
void change(tree *root, char Name[], char Name_changed[]);

#endif

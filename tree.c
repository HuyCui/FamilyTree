/********************************************************
         Copyright: SDUT 2018-2068
         Author: 崔辉
         Data:2018-01-14
         Description:添加成员信息
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
/************************************************************
           fountion:创建家谱树
           in: tree *root   家谱树
************************************************************/
void create(tree *root)
{
    printf("\033[34m*************请输入祖先的姓名、性别：**************\033[34m\n");
    scanf("%s %c", root->name, &root->sex);
    if(strlen(root->name) > 12)                  //判断输入长度是否合法
    {
        printf("\033[31m您输入的名字长度太长！\033[31m\n");
        return;
    }
    strcpy(root->fathername, "wu");
    root->num = 0;
    root->degree = 1;
    root = (tree *)malloc(sizeof(struct treenode));  //新建根结点
    root->child = NULL;
    root->parent = NULL;
    root->brother = NULL;
    printf("\033[34m*************家谱树创建成功**************\033[34m\n");
}
/************************************************************
           fountion:查询成员信息
           in: tree *root   家谱树
               char Name[]  新成员姓名
               char father_name[] 新成员父亲信息
               char Sex    成员性别
               int *flag   标记指针
           step:1、查找成员父亲位置
                2、递归添加左孩子
                3、递归添加右兄弟
************************************************************/
void add(tree *root, char Name[], char father_name[], char Sex, int *flag)
{
    tree *p, *q;
    //*flag = 0;    //查找父亲失败的话flag带出的值为0
    if(strlen(Name) > 12)
    {
        printf("\033[31m您输入的名字长度太长！\033[31m\n");
        printf("\033[31m添加成员失败！\033[31m\n");
        *flag = 0;
        return;
    }
    p = (tree *)malloc(sizeof(struct treenode));
    p->sex = Sex;
    strcpy(p->name, Name);              //更新成员以及父亲信息
    strcpy(p->fathername, father_name);
    if(root == NULL)
    {
        return ;
    }
    if(strcmp(root->name, p->fathername) == 0)   //找到父亲
    {
        *flag = 1;
        p->degree = root->degree+1;         //更新辈份
        if(root->child == NULL)              //左孩子为空直接添加为左孩子
        {
            root->child = p;
            root->num++;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
        }
        else                    //不为空添加在兄弟结点上
        {
            q = root->child;
            while(q->brother)
            {
                q = q->brother;
            }
            q->brother = p;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
            root->num++;
        }
        return ;
    }
    add(root->child, Name, father_name, Sex, flag);              //递归寻找创建
    add(root->brother, Name, father_name, Sex, flag);
}
/************************************************************
           fountion:查询祖先信息
           in: tree *root   家谱树
               char name[]  祖先姓名
************************************************************/
tree *add_zuxian(tree *root, char Name[], char Sex)  //增加祖先要把根指针更新
{
    if(strlen(Name) > 12)
    {
        printf("\033[31m您输入的名字长度太长！\033[31m\n");
        return;
    }
    tree *p;
    p = (tree *)malloc(sizeof(struct treenode));
    p->sex = Sex;
    strcpy(p->name, Name);
    strcpy(p->fathername, "wu");
    p->degree = 1;          //更改祖先的个人信息
    p->brother = NULL;
    p->parent = NULL;
    p->child = root;
    p->num = 1;
    //将原祖先的信息更改
    root->parent = p;
    strcpy(root->fathername, Name);
    change_degree(root);    //每个人的辈份降低
    printf("\033[34m添加祖先成功！\033[34m\n");
    root = p;
    return p;
}
/************************************************************
           fountion:改变成员辈份
           in: tree *root   家谱树
************************************************************/
void change_degree(tree *root)
{
    if(root == NULL)    
    {
        return;
    }
    else
    {
        root->degree++;        //每个人的辈份降低
    }
    change_degree(root->child);   //递归更改辈份
    change_degree(root->brother);
}
/************************************************************
           fountion:重新创建家谱树
           in: tree *root   家谱树
************************************************************/
void recreate(tree **root, char Name[], char Sex)
{
	printf("进了重构函数\n");
	*root = (tree *)malloc(sizeof(struct treenode));  //新建根结点
	(*root)->sex = Sex;
	strcpy((*root)->name, Name);
    strcpy((*root)->fathername, "wu");
	(*root)->num = 0;
    (*root)->degree = 1;
    (*root)->child = NULL;
    (*root)->parent = NULL;
    (*root)->brother = NULL;
}
/************************************************************
           fountion:查询成员信息
           in: tree *root   家谱树
               char Name[]  新成员姓名
               char father_name[] 新成员父亲信息
               char Sex    成员性别
               int *flag   标记指针
           step:1、查找成员父亲位置
                2、递归添加左孩子
                3、递归添加右兄弟
************************************************************/
void readd(tree *root, char Name[], char father_name[], char Sex)
{
    tree *p, *q;
    p = (tree *)malloc(sizeof(struct treenode));
    p->sex = Sex;
    strcpy(p->name, Name);              //更新成员以及父亲信息
    strcpy(p->fathername, father_name);
    if(root == NULL)
    {
        return ;
    }
    /*printf("没进if\n");
    printf("*-*-*%s\n", root->name);
    printf("-*-*-%s\n", p->fathername);*/
    if(strcmp(root->name, p->fathername) == 0)   //找到父亲
    {
		//printf("进来过\n");
        p->degree = root->degree+1;         //更新辈份
        if(root->child == NULL)              //左孩子为空直接添加为左孩子
        {
            root->child = p;
            root->num++;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
        }
        else                    //不为空添加在兄弟结点上
        {
            q = root->child;
            while(q->brother)
            {
                q = q->brother;
            }
            q->brother = p;
            p->parent = root;
            p->brother = NULL;
            p->child = NULL;
            root->num++;
        }
        return ;
    }
    readd(root->child, Name, father_name, Sex);              //递归寻找创建
    readd(root->brother, Name, father_name, Sex);
}


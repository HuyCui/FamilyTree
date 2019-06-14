/********************************************************
         Copyright: SDUT 2018-2068
         Author: 崔辉
         Data:2018-01-14
         Description:添加成员信息
         Email:17853312495@163.com
********************************************************/
#ifndef _TREE_H
#define _TREE_H

typedef struct treenode
{
    char sex;
    int num;                   //记录孩子个数
    int degree;                //记录辈份
    char name[20];
    char fathername[20];       //记录父亲名字
    struct treenode *child;    //记录孩子结点
    struct treenode *brother;  //记录兄弟结点
    struct treenode *parent;   //记录父亲结点
}tree;
/************************************************************
           fountion:创建家谱树
           in: tree *root   家谱树
************************************************************/
void create(tree *root);                      //建立家谱
/************************************************************
           fountion:查询成员信息
           in: tree *root   家谱树
               char Name[]  新成员姓名
               char father_name[] 新成员父亲信息
               char Sex    成员性别
               int *flag   标记指针
************************************************************/
void add(tree *root, char Name[], char father_name[], char Sex, int *flag);   //添加成员
/************************************************************
           fountion:查询祖先信息
           in: tree *root   家谱树
               char name[]  祖先姓名
************************************************************/
tree *add_zuxian(tree *root, char Name[], char Sex);      //添加祖先
/************************************************************
           fountion:改变成员辈份
           in: tree *root   家谱树
************************************************************/
void change_degree(tree *root);             //改变辈份
void recreate(tree **root, char Name[], char Sex);
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
void readd(tree *root, char Name[], char father_name[], char Sex);
#endif

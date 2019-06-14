/********************************************************
         Copyright: SDUT 2018-2068
         Author: 王姗姗
         Data:2018-01-14
         Description:家谱树操作界面
         Email:17853312495@163.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "show_creat.h"
#include "show_add.h"
#include "show_del.h"
#include "show_find.h"
#include "show_change.h"
#include "show.h"
#include "show_main.h"
#include "file.h"

void show_main()
{
    tree *root;
    char str[1500];
    root = (tree *)malloc(sizeof(struct treenode));
    while(1)
    {
        printf("\033[34m****************家谱树操作*******************\033[34m\n");
        printf("\033[31m           1、新建家谱树                     \033[31m\n");
        printf("\033[32m           2、成员添加                       \033[32m\n");
        printf("\033[33m           3、成员信息查询                   \033[33m\n");
        printf("\033[34m           4、删除家谱成员                   \033[34m\n");
        printf("\033[35m           5、成员信息修改                   \033[35m\n");
        printf("\033[36m           6、家谱树显示                     \033[36m\n");
        printf("\033[31m           7、从文件中读取信息重建家谱树     \033[31m\n");
        printf("\033[32m           8、保存家谱到文件                 \033[32m\n");
        printf("\033[31m           0、退出                           \033[31m\n");
        printf("\033[39m********************************************\033[39m\n");
        printf("\033[34m请输入您的选择：\033[34m");
        int i, n;
        char order[105];
        scanf("%s%*c", order);
        if(strlen(order) > 1)
        {
            printf("\033[31m指令错误，请重新输入！\033[31m\n");
            sleep(2);
            system("clear");
            continue;
        }
        sleep(1);
        system("clear");
        switch(order[0]-'0')
        {
        case 1:
            show_creat(root);
            break;
        case 2:
            show_add(&root);
            break;
        case 3:
            show_find(root);
            break;
        case 4:
            show_del(root);
            break;
        case 5:
            show_change(root);
            break;
        case 6:
            show(root);
            break;
        case 7:
            root = (tree *)read_from_file();
            break;
        case 8:
            write_to_file(&root);
            break;
        case 0:
            system("clear");
            return;
            break;
        default:
            printf("\033[31m指令错误，请重新输入！\033[34m\n");
        }
        printf("\033[36m***************按ENTER键继续**************\033[36m\n");
        getchar();
        system("clear");
    }

}


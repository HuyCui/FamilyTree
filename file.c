#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "file.h"

int point = 0;
/*struct person
{
	char Name[15];
	char fatherName[15];
	char Sex;
}person;*/
void save_as_string(tree *root, char str[])
{
	if(root == NULL)
		return ;
	if(root)
	{
		int i;
		int len = strlen(root->name);
		for(i = 0; i < len; i++)
		{
			str[point++] = root->name[i];
		}
		//str[point++] = '\0';
		str[point++] = '-';
		len = strlen(root->fathername);
		for(i = 0; i < len; i++)
		{
			str[point++] = root->fathername[i];
		}
		//str[point++] = '\0';
		str[point++] = '-';
		str[point++] = root->sex;
		str[point++] = '\n';
		
		save_as_string(root->child, str);
		save_as_string(root->brother, str);
	}	
}

void write_to_file(tree **root)
{
	point = 0;
	char str[2000];
	save_as_string(*root, str);
	str[point] = '\0';
	FILE *fp;
	fp = fopen("ftree.txt", "w");
	fprintf(fp, "%s", str);
	fclose(fp);
	
}

tree *read_from_file()
{
	FILE *fp;
	fp = fopen("ftree.txt", "r+");
	int i = 0;
	struct person s[1000];
	tree *root, *temp;
	int la, lb;
	while(fscanf(fp, "%[^-]-%[^-]-%c%*c", s[i].Name, s[i].fatherName, &s[i].Sex) != EOF)
	{
		/*la = strlen(s[i].Name);
		s[i].Name[la] = '\0';
		lb = strlen(s[i].fatherName);
		s[i].Name[lb] = '\0';*/
		i++;
	}
	root = rebuild(&temp, s, i);
	fclose(fp);
	printf("\033[36m文件已读入，正在重构家谱树\033[36m\n");
	return root;
}

tree *rebuild(tree **root, struct person s[], int len)
{
	*root = (tree *)malloc(sizeof(struct treenode));
	if(len == 0)
		printf("\033[31m指令错误，请重新输入！\033[31m\n");
	int j = 0;
	struct person t;
	t = s[j];
	printf("-----%s %s %c\n", t.Name, t.fatherName, t.Sex);
	recreate(root, t.Name, t.Sex);
	j++;
	while(j < len)
	{
		t = s[j];
		printf("-----%s %s %c\n", t.Name, t.fatherName, t.Sex);
		readd(*root, t.Name, t.fatherName, t.Sex);
		j++;
	}
	return *root;
}

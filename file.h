#ifndef _FILE_H
#define _FILE_H
#include "tree.h"

struct person
{
	char Name[15];
	char fatherName[15];
	char Sex;
}person;
void save_as_string(tree *root, char str[]);
void write_to_file(tree **root);
tree *read_from_file();
tree *rebuild(tree **root, struct person s[], int len);

#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
	struct Tree *left;
	char code;
	struct Tree *rigth;
} Tree;

Tree *alloc(char data)
{
	Tree *newTree = (Tree*)malloc(sizeof(Tree));
	newTree->code = data;
	newTree->left = NULL;
	newTree->rigth = NULL;
	return newTree;
}

bool isEmpty(Tree* leaf)
{
	if(leaf == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int i = 0;
Tree *buildsTree(char *data){

    Tree *leaf= NULL;
    if((data[i]!='.') && (data[i]!='\0')){
    leaf = alloc(data[i]);
    i++;
    leaf->left = buildsTree(data);
    i++;
    leaf->rigth = buildsTree(data);
    }
    return leaf;
}

void printTree(Tree *leaf)
{
	if (isEmpty(leaf))
	{
		printf(".");
	}
	else
	{
		printf("%c", leaf->code);
		printTree(leaf->left);
		printTree(leaf->rigth);
	}
}

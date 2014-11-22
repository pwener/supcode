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
Tree *buildsTree(char *data)
{

	Tree *leaf = NULL;
	if((data[i] != '.') && (data[i] != '\0'))
	{
		leaf = alloc(data[i]);
		i++;
		leaf->left = buildsTree(data);
		i++;
		leaf->rigth = buildsTree(data);
	}
	return leaf;
}

int count(Tree *leaf)
{
	if (leaf == NULL)
	{
		return 0;
	}
	else
	{
		return count(leaf->left) + count(leaf->rigth) + 1;
	}
}

int heightTree(Tree *leaf)
{

	int left, rigth;
	if (leaf == NULL)
	{
		return -1;
	}
	else
	{
		left = heightTree(leaf->left);
		rigth = heightTree(leaf->rigth);
		if (left > rigth)
		{
			return left + 1;
		}
		else
		{
			return rigth + 1;
		}
	}
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

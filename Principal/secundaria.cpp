#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    unsigned int sizeTree;
	struct Tree *left;
	char code;
	struct Tree *rigth;
} Tree;


Tree *alloc(char data)
{
	Tree *newTree = (Tree*)malloc(sizeof(Tree));
	newTree->code = data;
	newTree->left = NULL;
	newTree->sizeTree = 0;
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
/*
int main()
{
    Tree *leaf= NULL;

    char *arvore;
    printf("Entre com a frase");
    gets(arvore);
    //arvore = "ABG..C.DE.F....";

    leaf = buildsTree(arvore);
    printTree(leaf);

    int sizeTree = countLeafs(leaf);
    int height = heightTree(leaf);

    printf("\n%d\t%d",sizeTree,height);


    return 0;
}*/


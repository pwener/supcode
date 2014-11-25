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

int sizeDataTree = 0;
Tree *buildsTree(char *stringTree){

    Tree *leaf = NULL;
    if((stringTree[sizeDataTree]!='.') && (stringTree[sizeDataTree] !='\0'))
    {
        leaf = alloc(stringTree[sizeDataTree]);
        sizeDataTree++;
        leaf->left = buildsTree(stringTree);
        sizeDataTree++;
        leaf->rigth = buildsTree(stringTree);

    }
    else
    {
        leaf = NULL;
    }
    return leaf;

}

int countLeafs(Tree *leaf)
{
	if (leaf == NULL)
	{
		return 0;
	}
	else
	{
		return countLeafs(leaf->left) + countLeafs(leaf->rigth) + 1;
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

Tree *searchValue(char data, Tree *leaf)
{
    if(isEmpty(leaf))
    {
        printf("A arvore estar vazia");
        return NULL;
    }
    else
    {
        do
        {
            if(data==leaf->code){
                return leaf;
            }
            if(data >= leaf->code)
            {
                leaf = leaf->rigth;
            }
            else if (data <= leaf->code)
            {
                leaf = leaf->left;
            }
        }while((leaf != NULL) && (data != leaf->code));
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

Tree *inserir(Tree *leaf, char numero, Tree *father){
    if(leaf == NULL)
    {
        father = leaf;
        leaf = alloc(numero);
        return leaf;
    }else{
        if(numero <leaf->code)

            return leaf = inserir(leaf->left, numero, leaf);
        else
            return leaf = inserir(leaf->rigth, numero, leaf);
    }
}

Tree *insertTree(char data, Tree *leaf)
{
    if(isEmpty((leaf)))
    {
        leaf = alloc(data);
    }
    else
    {
        Tree *neWLeaf = alloc(data);
        Tree *father = searchValue(NULL,leaf);
      //  printf(("\n%c\n", father.code));
        if(father->code > data){
            father->left = neWLeaf;
        }else if(father->code<-data){
            father->rigth = neWLeaf;
        }

        return leaf;
    }

}

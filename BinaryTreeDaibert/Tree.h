#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


typedef struct TreeData{

    int code;
    char course[50];
    int	locality;

}TreeData;

struct Tree
{
	TreeData data;
	struct Tree *left;
	struct Tree *rigth;
};

Tree *alloc(TreeData dados)
{
	Tree *treeRoot = (Tree*)malloc(sizeof(Tree));

	treeRoot->left = NULL;
	treeRoot->rigth = NULL;
	treeRoot->data = dados;

	return treeRoot;
}

//Primeiro parametro refere-se ao topo da arvore,
// o segundo sera seuas ramificações para a direita ou esquerda dependedendo de treedata, valor a ser indserido.
Tree *insertInTree(Tree *Topo, Tree *treeLeaf, TreeData dados)
{
	if(treeLeaf == NULL)
	{
        treeLeaf = alloc(dados);
		if(Topo == NULL)
		{
			printf("\n%d	%s	%d\n", dados.code, dados.course, dados.locality);	
		}
		else
		{
		    //se o valor for menor que o topo, coloca na esquerda, e caso for maior coloca na direita.
            if(dados.code <= Topo->data.code)
            {
                Topo->left = treeLeaf;
                printf("\n%c esqueda de %c\n",dados.code, Topo->data.code);
            }
            else if(dados.code >= Topo->data.code)
            {
                Topo->rigth = treeLeaf;
                printf("\n%c direita de %c\n",dados.code, Topo->data.code);
            }
		}
        //system("pause");
		return treeLeaf;
	}
	//Vasculha a esquerda até encontar um valor nulo. treeLeaf->left==NULL
	if(dados.code < treeLeaf->data.code)
	{
		insertInTree(treeLeaf, treeLeaf->left, dados);
	}
	else
	{
		insertInTree(treeLeaf, treeLeaf->rigth, dados);
	}
}

Tree * includeTree (Tree *root, TreeData dados)
{
	if (root == NULL)
	{
		root = insertInTree(root, root, dados);
	}
	else
	{
		insertInTree(root, root, dados);
	}
	return root;
}
/*
void preordem(Tree *leaf)
{
	if (leaf != NULL)
	{
		printf("%c - ", leaf->data);
		preordem(leaf->left);
		preordem(leaf->rigth);
	}
}

void posordem(Tree *leaf)
{
	if (leaf != NULL)
	{
		posordem(leaf->left);
		posordem(leaf->rigth);
		printf("%c - ", leaf->data);
	}
}

void emordem(Tree *leaf)
{
	if (leaf != NULL)
	{
		emordem(leaf->left);
		printf("%c - ", leaf->data);
		emordem(leaf->rigth);
	}
}

bool printTree(Tree *leaf)
{
	char left = true;
	char rigth = true;

	if(leaf != NULL)
	{
		printf("%c", leaf->data);
		left = printTree(leaf->left); ///a==0 caso sub_arvore_esquerda==NULL
		rigth = printTree(leaf->rigth); ///a==0 caso sub_arvore_direita==NULL

	}
	else
	{
		printf(".");
		return false;//retorna 0 caso arvore == NULL
	}
}

*/

void emordem(Tree *leaf)
{
	if (leaf != NULL)
	{
		emordem(leaf->left);
	   	printf("%d	%s	%d\n", leaf->data.code, leaf->data.course, leaf->data.locality);	
		emordem(leaf->rigth);
	}
}
int contarLinhasArquivo(char *arquivo)
{
	char caractere;
	int existe_linhas = 0;
	int quant_linhas = 0;
	FILE *file = fopen(arquivo,"r");
	
	while((caractere = fgetc(file)) != EOF)
	{
		existe_linhas = 1; // há conteúdo no arquivo
		if(caractere == '\n')  // é uma quebra de linha?
		{
			// vamos incrementar a quantidade de linhas
			quant_linhas++;
		}
	}
	if(existe_linhas)
		quant_linhas++;
	return quant_linhas;
}

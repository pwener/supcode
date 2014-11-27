#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Tree
{
	char data;
	struct Tree *left;
	struct Tree *rigth;
};


Tree *alloc(char dados)
{
	Tree *treeRoot = (Tree*)malloc(sizeof(Tree));

	treeRoot->left = NULL;
	treeRoot->rigth = NULL;
	treeRoot->data = dados;

	return treeRoot;
}

Tree *ordenaTipo(Tree *Topo, Tree *treeLeaf, char dados)
{

	//se o valor for menor que o topo, coloca na esquerda, e caso for maior coloca na direita.
	if(dados <= Topo->data)
	{
		Topo->left = treeLeaf;
		printf("\n%c esqueda de %c\n", dados, Topo->data);
	}
	else if(dados >= Topo->data)
	{
		Topo->rigth = treeLeaf;
		printf("\n%c direita de %c\n", dados, Topo->data);
	}

	return treeLeaf;
}


//Primeiro parametro refere-se ao topo da arvore,
// o segundo sera seuas ramificações para a direita ou esquerda dependedendo de treedata, valor a ser indserido.
Tree *insertInTree(Tree *Topo, Tree *treeLeaf, char dados)
{
	if(treeLeaf == NULL)
	{
		treeLeaf = alloc(dados);
		if(Topo == NULL)
		{
			printf("\nO topo foi adicionado com sucesso - %c!!!\n", treeLeaf->data);
		}
		else
		{
			ordenaTipo(Topo, treeLeaf, dados);
		}
		return treeLeaf;
	}
	else
	{
		//Vasculha a esquerda até encontar um valor nulo. treeLeaf->left==NULL

		if(dados <= treeLeaf->data)
		{
			insertInTree(treeLeaf, treeLeaf->left, dados);
		}
		else
		{
			insertInTree(treeLeaf, treeLeaf->rigth, dados);
		}

	}
}

Tree * includeTree (Tree *root, char dados)
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

void imprimiDecrescente(Tree *leaf)
{
	if (leaf != NULL)
	{
		imprimiDecrescente(leaf->rigth);
		printf("%c\n", leaf->data);
		imprimiDecrescente(leaf->left);

	}
}

FILE *saida = fopen("Saida.txt", "w");
void imprimiCrescente(Tree *leaf)
{
	if (leaf != NULL)
	{
		imprimiCrescente(leaf->left);
		printf("%c", leaf->data);
		fprintf(saida,"%c",leaf->data);
		imprimiCrescente(leaf->rigth);

	}
}
int contarLinhasArquivo(char *arquivo)
{
	char caractere;
	int existe_linhas = 0;
	int quant_linhas = 0;
	FILE *file = fopen(arquivo, "r");

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

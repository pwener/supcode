
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct TreeData
{

	int code;
	char course[50];
	int	locality;
	int linha;

} TreeData;

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

Tree *ordenaTipo(Tree *Topo, Tree *treeLeaf, TreeData dados, int tipo)
{
	if(tipo == 1 )
	{
		//se o valor for menor que o topo, coloca na esquerda, e caso for maior coloca na direita.
		if(dados.code <= Topo->data.code)
		{
			Topo->left = treeLeaf;
			printf("\n%d esqueda de %d\n", dados.code, Topo->data.code);
		}
		else if(dados.code >= Topo->data.code)
		{
			Topo->rigth = treeLeaf;
			printf("\n%d direita de %d\n", dados.code, Topo->data.code);
		}
	}
	else if(tipo == 2 )
	{
		//se o valor for menor que o topo, coloca na esquerda, e caso for maior coloca na direita.
		if(dados.course <= Topo->data.course)
		{
			Topo->left = treeLeaf;
			printf("\n%s esqueda de %s\n", dados.course, Topo->data.course);
		}
		else if(dados.course >= Topo->data.course)
		{
			Topo->rigth = treeLeaf;
			printf("\n%s esqueda de %s\n", dados.course, Topo->data.course);
		}
	}
	else if(tipo == 3 )
	{
		//se o valor for menor que o topo, coloca na esquerda, e caso for maior coloca na direita.
		if(dados.locality <= Topo->data.locality)
		{
			Topo->left = treeLeaf;
			printf("\n%d esqueda de %d\n", dados.locality, Topo->data.locality);
		}
		else if(dados.locality >= Topo->data.locality)
		{
			Topo->rigth = treeLeaf;
			printf("\n%d direita de %d\n", dados.locality, Topo->data.locality);
		}
	}
	return treeLeaf;
}


//Primeiro parametro refere-se ao topo da arvore,
// o segundo sera seuas ramificações para a direita ou esquerda dependedendo de treedata, valor a ser indserido.
Tree *insertInTree(Tree *Topo, Tree *treeLeaf, TreeData dados, int tipo)
{
	if(treeLeaf == NULL)
	{
		treeLeaf = alloc(dados);
		if(Topo == NULL)
		{
			printf("\nO topo foi adicionado com sucesso - %d!!!\n", treeLeaf->data.code);
		}
		else
		{
			ordenaTipo(Topo, treeLeaf, dados, tipo);
		}
		return treeLeaf;
	}
	else
	{
		//Vasculha a esquerda até encontar um valor nulo. treeLeaf->left==NULL
		if(tipo == 1)
		{
			if(dados.code < treeLeaf->data.code)
			{
				insertInTree(treeLeaf, treeLeaf->left, dados, tipo);
			}
			else
			{
				insertInTree(treeLeaf, treeLeaf->rigth, dados, tipo);
			}
		}
		else if(tipo == 2)
		{
			if(dados.course < treeLeaf->data.course)
			{
				insertInTree(treeLeaf, treeLeaf->left, dados, tipo);
			}
			else
			{
				insertInTree(treeLeaf, treeLeaf->rigth, dados, tipo);
			}
		}
		else if(tipo == 3)
		{
			if(dados.locality < treeLeaf->data.locality)
			{
				insertInTree(treeLeaf, treeLeaf->left, dados, tipo);
			}
			else
			{
				insertInTree(treeLeaf, treeLeaf->rigth, dados, tipo);
			}
		}
	}
}

Tree * includeTree (Tree *root, TreeData dados, int tipo)
{
	if (root == NULL)
	{
		root = insertInTree(root, root, dados, tipo);
	}
	else
	{
		insertInTree(root, root, dados, tipo);
	}
	return root;
}

void imprimiDecrescente(Tree *leaf)
{
	if (leaf != NULL)
	{
		imprimiDecrescente(leaf->rigth);
		printf("%d\t%s\t%d\n", leaf->data.code, leaf->data.course, leaf->data.locality);
		imprimiDecrescente(leaf->left);

	}
}

void imprimiCrescente(Tree *leaf)
{
	if (leaf != NULL)
	{	
		imprimiCrescente(leaf->left);
		printf("%d\t%s\t%d\n", leaf->data.code, leaf->data.course, leaf->data.locality);
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

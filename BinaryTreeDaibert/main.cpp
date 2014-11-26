#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

using namespace std;

int main ()
{
	Tree *raiz = NULL;
	FILE *file = fopen("ArvoresBinarias_BD.txt", "r");
	char titulo[50];
	
	fscanf(file,"%[^\n]", titulo);
	printf("%s\n", titulo);

	TreeData dados;
	int cont = 0;
	int linhas = contarLinhasArquivo("ArvoresBinarias_BD.txt");
	
	for(cont = 0; cont<41; cont++){
		fscanf(file, "%d	%[^\t]	%d\n", &dados.code, dados.course, &dados.locality);
		raiz = includeTree(raiz,dados);
	}
	emordem(raiz);
	return 0;
}


/*
int main (void)
{
	int opcao;
	Tree *raiz = NULL;

	while(1)
	{
		system ("cls");
		printf ("\nMenu");
		printf ("\n\n 1. Insere");
		printf ("\n 2. Exibe Arvore");
		printf ("\n 3. Exibe Arvore em PreOrdem");
		printf ("\n 4. Exibe Arvore em PosOrdem");
		printf ("\n 5. Exibe Arvore em EmOrdem");
		printf ("\n 6. Sair");
		printf ("\n\n Entre a sua opcao: ");
		scanf ("%d", &opcao);

		fflush(stdin);

		switch (opcao)
		{
		case 1 :
			raiz = includeTree(raiz);
			break;
		case 2 :
			printTree(raiz);
			puts("\n\n");
			system("pause");
			break;
		case 3 :
			preordem(raiz);
			system("pause");
			break;
		case 4 :
			posordem(raiz);
			system("pause");
			break;
		case 5 :
			emordem(raiz);
			system("pause");
			break;
		case 6 :
			exit(0);
		default:
			printf ("\nOpcao errada");
			system ("pause");
			break;
		}
	}
}
*/

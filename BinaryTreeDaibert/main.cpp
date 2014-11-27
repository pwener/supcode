#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

using namespace std;

int main ()
{
	Tree *ABPcodigo = NULL;
	Tree *ABPcurso = NULL;
	Tree *ABPlocal = NULL;

	int opcao;

	FILE *file = fopen("ArvoresBinarias_BD.txt", "r");
	char titulo[50];

	fscanf(file, "%[^\n]", titulo);
	printf("%s\n", titulo);

	TreeData dados;
	int cont = 0;
	int linhas = contarLinhasArquivo("ArvoresBinarias_BD.txt");

	for(cont = 0; cont < linhas-1; cont++)
	{
		fscanf(file, "%d	%[^\t]	%d", &dados.code, dados.course, &dados.locality);
		dados.linha = cont + 2;

		ABPcodigo = includeTree(ABPcodigo, dados, 1);
		ABPcurso = includeTree(ABPcurso, dados, 2);
		ABPlocal = includeTree(ABPlocal, dados, 3);
	}

	while(1)
	{
		system ("cls");
		printf ("\n\tMenu");
		printf ("\n 1. Exibe Arvore pelo codigo decrescente: ");
		printf ("\n 2. Exibe Arvore em ordem alfabetica decrescente: ");
		printf ("\n 3. Exibe Arvore pelo local decrescente: ");
		printf ("\n 4. Exibe Arvore pelo codigo crescente: ");
		printf ("\n 5. Exibe Arvore em ordem alfabetica crescente: ");
		printf ("\n 6. Exibe Arvore pelo local crescente: ");
		printf ("\n 7. Sair: ");;
		scanf ("%d", &opcao);

		fflush(stdin);

		switch (opcao)
		{
		case 1 :
			printf("\n\n");
			imprimiDecrescente(ABPcodigo);
			system("pause");
			break;
		case 2 :
			printf("\n\n");
			imprimiDecrescente(ABPcurso);
			system("pause");
			break;
		case 3 :
			printf("\n\n");
			imprimiDecrescente(ABPlocal);
			system("pause");
			break;
		case 4 :
			printf("\n\n");
			imprimiCrescente(ABPcodigo);
			system("pause");
			break;
		case 5 :
			printf("\n\n");
			imprimiCrescente(ABPcurso);
			system("pause");
			break;
		case 6 :
			printf("\n\n");
			imprimiCrescente(ABPlocal);
			system("pause");
			break;
		case 7 :
			exit(0);
		default:
			printf ("\nOpcao errada");
			system ("pause");
			break;
		}
	}
	printf("\n\n");
	return 0;
}
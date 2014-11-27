#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "exercicioUm.h"

using namespace std;

int main ()
{
	Tree *arvore1 = NULL;

	int opcao;

	FILE *entrada = fopen("ArvoresBinarias_Dados.txt", "r");
	FILE *saida = fopen("Saida.txt", "w+");

	char dados;
	int cont = 0;
	int linhas = contarLinhasArquivo("ArvoresBinarias_Dados.txt");

	for(cont = 0; cont < linhas ; cont++)
	{
		fscanf(entrada, "%s\n", dados);
		arvore1 = includeTree(arvore1, dados);
	}

	printf("\n\n");

	return 0;
}

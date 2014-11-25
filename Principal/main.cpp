#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{
    Tree *leaf = NULL;
    char *arvore;
    arvore = "532..4..8.9..";

    leaf = buildsTree(arvore);
    printTree(leaf);

    int sizeTree = countLeafs(leaf);
    int height = heightTree(leaf);

    printf("\nQuantidade: %d\tNivel: %d\t\n",sizeTree,height);

    Tree *root = NULL;
    root = searchValue('2', leaf);

    printTree(root);
    //root = insertTree('7', leaf);

    return 0;
}

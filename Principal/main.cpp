#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{
    Tree *leaf= NULL;

    char *arvore;
    arvore = "273..65..8..5.94...";

    leaf = buildsTree(arvore);
    printTree(leaf);

    int sizeTree = count(leaf);
    int height = heightTree(leaf);

    printf("\n%d\t%d",sizeTree,height);

    return 0;
}

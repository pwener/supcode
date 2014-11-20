#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{
    Tree *leaf= NULL;

    char *arvore;
    arvore = "ABG..C.DE.F....";

    leaf = buildsTree(arvore);
    printTree(leaf);
    return 0;
}

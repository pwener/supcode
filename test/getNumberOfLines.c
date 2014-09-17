#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supcode.h"

int main(){
	int n = numberoflines("example.txt");
	printf("Number of lines in example.txt = %d\n", n);
	return 0;
}

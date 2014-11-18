#include <stdio.h>
#include <stdlib.h>
#include "supcodeList.h"

int main(){
	blockInt *listOfInteger;
	if(isempty(&listOfInteger) == 1){
        addhead(&listOfInteger, 10);
	}
	addtail(&listOfInteger, 20);

	printf("Head = %d\n", listOfInteger->value);
	printf("Tail = %d\n", listOfInteger->next->value);

	addaftervalue(&listOfInteger, 10, 15);
	printf("\n");
	printListOfIntegers(&listOfInteger);

	printf("\n");
	addbeforevalue(&listOfInteger, 10, 5);
	removebykey(&listOfInteger, 15);
	printListOfIntegers(&listOfInteger);
	printf("\n");

	removetail(&listOfInteger);
	removehead(&listOfInteger);
	printListOfIntegers(&listOfInteger);
	printf("\n");

	free(listOfInteger);
}

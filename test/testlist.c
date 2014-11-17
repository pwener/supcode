#include <stdio.h>
#include <stdlib.h>
#include "supcodeList.h"

int main(){
	blockInt *listInteger;
	listInteger = addhead(listInteger, 10);
	listInteger = addtail(listInteger, 20);
	printf("Head = %d\n", listInteger->value);
	printf("Tail = %d\n", listInteger->next->value);
	listInteger = addaftervalue(listInteger, 20, 15);
	printf("\n");
	printListOfIntegers(listInteger);
	printf("\n");
	listInteger = addbefore(listInteger, 10, 25);
	listInteger = removebykey(listInteger, 15);
	printListOfIntegers(listInteger);	
	printf("\n");
	listInteger = removetail(listInteger);
	listInteger = removehead(listInteger);
	printListOfIntegers(listInteger);
	printf("\n");
	free(listInteger);
}

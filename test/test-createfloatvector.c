#include <stdio.h>
#include <stdlib.h>
#include "supcode.h"

int main(){
	float *x = createfloatvector(10);
	int i;
	printf("\n Will print 10 numbers of fibonacci's sequence\n");
	printf(" float *x = createfloatvector(10) \n\n");
	for(i = 0; i < 10; i++)
		if(i <= 1)
			x[i] = 1;
		else
			x[i] = x[i-1] + x[i-2];
	
	for(i = 0; i < 10; i++)
		printf("%f\n", x[i]);
	
	printf("\n If i call index 100, return: %f", x[100]);
	printf("\n It's an invalid value\n");
	
	free(x);
	x = NULL;
		
	return 0;
}

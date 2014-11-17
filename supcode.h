#include <stdio.h>
#include <stdlib.h>

#define STRLENGTH 255

/* Core of lib SUPCOD by Phelipe Wener*/


/**
* readstr should be used for read an String of keyboard and return in the context of called.
* Receives a char pointer named 'message', used to print a message on the terminal,
* functions as the requisition stated. Example:
* We want which the user insert an name, so:
*	char *name = readstr("Insert an name");
*/
char * readstr(char *message){
	printf("\n%s", message);
	char *text;
	text = (char * ) malloc(sizeof(STRLENGTH));
	scanf("%s", text);
	__fpurge(stdin);
	return text;
}

/**
* readint should be used for read an Integer of keyboard and return in the context of called.
* Receives a char pointer named 'message', used to print a message on the terminal,
* functions as the requisition stated. Example:
* We want which the user insert your age, so:
* 	int age = readint("Insert your age");
*/
int readint(char *message){
  	int integer;
  	printf("\n%s", message);
  	scanf ("%d", &integer);
	__fpurge(stdin); 
 	return integer;
}

/**
* readfloat should be used for read an Integer of keyboard and return in the context of called.
* Receives a char pointer named 'message', used to print a message on the terminal,
* functions as the requisition stated. Example:
* We want which the user insert the number pi, so:
*       float pi = readfloat("PI aproximate is:");
*/
float readfloat(char *message){
	float decimal;
 	printf("\n%s", message);
	scanf("%f", &decimal);
	__fpurge(stdin);
	return decimal;
}

/**
* createintvector will allocate an vector of integers and then returns it.
* Receives an Integer named 'size', for specify size of the structure.
*/
int * createintvector(int size){
	return (int*) malloc(size*sizeof(int));
}

/**
* createfloatvector will allocate an vector of float and then returns it.
* Receives an Integer named 'size', for specify size of the structure.
*/
float * createfloatvector(int size){
	return (float*) malloc(size*sizeof(float));
}
/**
* findfirststr return the index of the first occurrence of the last parameter str.
* If an valid value is find will be returned the index, else a value -1.
*/
int findfirststr(const char *list[], char *str){
	int i;
	for(i = 0; i < sizeof(list); i++)
		if(list[i] == str)
			return i;
	return -1;
}

/**
* Returns the number of lines in an file, the URL parameter passed as a string.
*/
int numberoflines(char *file){
	FILE *target = fopen(file, "r");
	char s;
	int n = 0;
	while((s = fgetc(target)) != EOF){
		if(s == '\n')
			n++;
	}
	fclose(target);
	return n;
}



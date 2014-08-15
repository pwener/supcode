#include <stdio.h>
#include <stdlib.h>

#define STRLENGTH 128

const char * readstr(const char *message){
	printf("\n%s", message);
	char *text;
	text = malloc(sizeof(STRLENGTH));
	scanf("%s", text);
	return text;
}

int readint(char *message){
  	int integer;
  	printf("\n%s", message);
  	scanf ("%d", &integer);  
 	return integer;
}

float readfloat(char *message){
	float decimal;
 	printf("\n%s", message);
	scanf("%f", &decimal);  
 	return decimal;
}

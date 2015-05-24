#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* An limit to strings */
#define STRLENGTH 255

/* Boolean values */
#define true 1
#define false 0

/* Core of lib SUPCOD by Phelipe Wener*/


/**
* readString should be used for read an String of keyboard and return in the context of called.
* Receives a char pointer named 'message', used to print a message on the terminal,
* functions as the requisition stated. Example:
* We want which the user insert an name, so:
*	char *name = readstr("Insert an name");
*/
char * readString(char *message){
	printf("\n%s", message);
	char *text;
	text = (char * ) malloc(sizeof(STRLENGTH));
	scanf("%s", text);
	return text;
}

/**
* readInt should be used for read an Integer of keyboard and return in the context of called.
* Receives a char pointer named 'message', used to print a message on the terminal,
* functions as the requisition stated. Example:
* We want which the user insert your age, so:
* 	int age = readint("Insert your age");
*/
int readInt(char *message){
  	int integer;
  	printf("\n%s", message);
  	scanf ("%d", &integer);
 	return integer;
}

/**
* readFloat should be used for read an Integer of keyboard and return in the context of called.
* Receives a char pointer named 'message', used to print a message on the terminal,
* functions as the requisition stated. Example:
* We want which the user insert the number pi, so:
*       float pi = readfloat("PI aproximate is:");
*/
float readFloat(char *message){
	float decimal;
 	printf("\n%s", message);
	scanf("%f", &decimal);
	return decimal;
}

/**
* Method that will allocate an vector of integers and then returns it.
* Receives an Integer named 'size', for specify size of the structure.
*/
int * createIntVector(int size){
	return (int*) malloc(size*sizeof(int));
}

/**
* Method that will allocate an vector of float and then returns it.
* Receives an Integer named 'size', for specify size of the structure.
*/
float * createFloatVector(int size){
	return (float*) malloc(size*sizeof(float));
}
/**
* Return the index of the first occurrence of toFind parametter.
* If an valid value is find will be returned the index, else a value -1.
*/
int findFirstOccurrence(const char *string, const char toFind){
	int count;
	for(count = 0; count < sizeof(string); count++){
		if(string[count] == toFind){
			return count;
		} else {
			// do nothing
		}
	}
	return -1;
}

/**
* Return first index that initiate substring passed by parameter
*/
int findOccurrenceOfSubstring(const char *string, const char *toFind){
	int count;
	int equivalentCharactersCounted = 0;
	for(count = 0; count < strlen(string); count++){
		if(string[count] == toFind[equivalentCharactersCounted]){
			equivalentCharactersCounted++;
			if(equivalentCharactersCounted == strlen(toFind)){
				return count - equivalentCharactersCounted + 1;
			}
		}else{
			equivalentCharactersCounted = 0;
		}
	}
	// Result none
	return 0;
}

/**
* Returns a new string from the newIndex, that is a substring of this string.
*/
char * substring(const char *string, const int newIndex){
	int size = strlen(string) - newIndex;
	// An new string to get rest
	char *sub = malloc(sizeof(char)*size);
	// To iterate in string
	int count;
	for(count = 0; count < size; count++){
		// from newIndex, get to sub all chars in string
		sub[count] = string[newIndex+count];
	}
	return sub;
}

/**
* Returns a new string inside passed interval
*/
char * substringByPositions(const char *string, const int index, const int final){
	// Size of substring
	int size = final - index;
	// Resulting substring
	char * firstSubstring = substring(string, index);
	char * newString = malloc(sizeof(char)*size);
	strncpy(newString, firstSubstring, size);
	return newString;
}

/**
* Verify if an given occurrency is found in an string
*/
int stringContains(const char *string, const char *occurrence){
	unsigned int index;
	index = findFirstOccurrence(string, occurrence[0]);

	unsigned int sizeOfOcurrency;
	sizeOfOcurrency = strlen(occurrence);

	char * substr = malloc(sizeof(char)*strlen(string));
	strcpy(substr, string);

	// If find an index that appear in string
	while(index != -1){
		// get a new sub from the index
		substr = substring(substr, index);
		// Reset index to percours occurrence and substr
		index = 0;
		// Run strings while they are equals or until that find the final.
		while(substr[index] == occurrence[index] && substr[index] != '\0'){
			// register in index countValue
			index++;
		}
		// If index was incremented until size of currency, substring was found
		if(index == sizeOfOcurrency){
			return true;
		} else {
			// do nothing...
		}

		substr = substring(substr, 1);

		index = findFirstOccurrence(substr, occurrence[0]);
	}
	// Only if never find sequence
	return false;
}

/**
* Replace first occurrency of an toReplace in an String for an changeSequence
*/
char * replace(const char *targetString, const char *toReplace, const char *changeSequence){
	if(stringContains(targetString, toReplace)){
		// Get length of passed parameters
		unsigned int sizeOfTarget = strlen(targetString);
		unsigned int sizeOfChange = strlen(changeSequence);
		unsigned int sizeOfToReplace = strlen(toReplace);

		// String to build the new
		char *builder;

		int sizeOfNewString = sizeOfTarget - sizeOfToReplace +sizeOfChange;
		// String that will be returned
		char *newString = malloc(sizeof(char)*sizeOfNewString);
		// Find position where replace the new sequence
		unsigned int positionOfChangeSequence = findOccurrenceOfSubstring(targetString, toReplace);
		
		builder = substringByPositions(targetString, 0, positionOfChangeSequence);
		// Copy targetString until string that will be replace
		strcpy(newString, builder);
		// Concatenate changeSequence
		strcat(newString, changeSequence);

		free(builder);

		// Complete with the rest after the substring replaced
		builder = substring(targetString, positionOfChangeSequence+sizeOfToReplace);
		strncat(newString, builder, sizeOfNewString);

		free(builder);

		return newString;
	} else {
		return NULL;
	}
}

/**
* Returns the number of lines in an file, the URL parameter passed as a string.
*/
int numberOfLines(char *file){
	FILE *target = fopen(file, "r");
	char s;
	int n = 0;
	while((s = fgetc(target)) != EOF){
		if(s == '\n'){
			n++;
		}
	}
	fclose(target);
	return n;
}

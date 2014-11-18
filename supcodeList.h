#include <stdio.h>
#include <stdlib.h>

struct blockint{
	struct blockint *previous;
	int value;
	struct blockint *next;
};

typedef struct blockint blockInt;

/**
* Verify if an list of integers is NULL
*	return 1 if NULL and 0 if not
*/
int isempty(blockInt **list){
	if(*list == NULL){
		return 1;
	}else{
		return 0;
	}
}
/**
* Insert the first element in a null list of integers
*/
void addfirstelement(blockInt **list, int value){
	*list = (blockInt*) malloc(sizeof(blockInt));
	(*list) -> previous = NULL;
	(*list) -> next = NULL;
	(*list) -> value = value;
}

/**
* Insert an new head in a list of integers
*/
void addhead(blockInt **list, int value){
	if(list == NULL){
		addfirstelement(list, value);
	}else{
		blockInt *newblockint = (blockInt*) malloc(sizeof(blockInt));
		newblockint -> next = *list;
		newblockint -> value = value;
		newblockint -> previous = NULL;
		*list = newblockint;
	}
}

/**
* Insert an last element in a list of
*/
void addtail(blockInt **list, int value){
	if(list == NULL){
		addfirstelement(list, value);
	}else{
		blockInt *newblock = (blockInt*) malloc(sizeof(blockInt));
		newblock -> next = NULL;
		newblock -> value = value;
		blockInt *aux = *list;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = newblock;
		newblock -> previous = aux;
	}
}

/**
* Inserting an element after other that containing a same key value passed by parameter
*
*/
void addaftervalue(blockInt **list, int key, int value){
    if(list != NULL){
		blockInt *newblock, *aux;
		newblock = (blockInt*) malloc(sizeof(blockInt));
		newblock -> value = value;
		aux = *list;
		while(aux -> next != NULL){
			if(aux -> value == key){
				break;
			}else{
				aux = aux -> next;
			}
		}
		if(aux -> value == key){
		    newblock->next = aux->next;
			newblock->previous = aux;
			aux->next = newblock;
		}
	}
}


/**
* Inserting an element before other that containing a same key value passed by parameter
*/
void *addbeforevalue(blockInt **list, int key, int value){
	if(list != NULL){
		blockInt *newblock, *aux;
		newblock = (blockInt*) malloc(sizeof(blockInt));
		newblock -> value = value;
		aux = *list;
		if(aux->value == key){
			newblock->next = aux;
			*list = newblock;
		}else{
			while(aux->next != NULL){
				if(aux->next->value == key){
					break;
				}else{
					aux = aux->next;
				}
			}
			if(aux->next != NULL){
				if(aux->next->value == key){
					newblock->next = aux->next;
					aux->next = newblock;
				}
			}
		}
	}
}

/**
* Removing an element that containing a same key value passed by parameter
*/
void removebykey(blockInt **list, int key){
	if(list != NULL){
		blockInt *aux, *rest;
		aux = *list;
		if(aux->value == key){
			rest = aux->next;
			free(aux);
			*list = rest;
		}
		while(aux->next->next != NULL  && aux->next->value != key){
			aux = aux->next;
		}
		if(aux->next->value == key){
			rest = aux->next->next;
			free(aux->next);
			aux->next = rest;
		}
	}
}

/**
* Removing head of an list passed by parameter
*/
void removehead(blockInt **list){
	blockInt *aux = *list;
	(*list) -> next -> previous = NULL;
	(*list) = (*list) -> next;
	free(aux);
}

/**
* Removing tail of an list passed by paremeter
*/
void removetail(blockInt **list){
	blockInt *aux = *list;
	while(aux->next->next != NULL){
		aux = aux->next;
	}
	free(aux->next);
	aux->next = NULL;
}

/**
* print all elements of an integer's list
*/
void printListOfIntegers(blockInt **list){
	blockInt *aux = NULL;
	for(aux = *list; aux != NULL; aux = aux->next){
		printf("%d ", aux->value);
	}
}

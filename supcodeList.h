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
int isempty(blockInt *list){
	if(list == NULL){
		return 1;
	}else{
		return 0;
	}
}
/**
* Insert the first element in a null list of integers 
*/
blockInt* addfirstelement(blockInt *list, int value){
	list = (blockInt*) malloc(sizeof(blockInt));
	list -> previous = NULL;
	list -> next = NULL;
	list -> value = value;
	return list;
}

/**
* Insert an new head in a list of integers
*/
blockInt* addhead(blockInt *list, int value){
	if(list == NULL){
		return addfirstelement(list, value);
	}else{
		blockInt *newblockint = (blockInt*) malloc(sizeof(blockInt));
		newblockint -> next = list;
		newblockint -> value = value;
		newblockint -> previous = NULL;
		list = newblockint;
	}
	return list;
}

/**
* Insert an last element in a list of
*/
blockInt* addtail(blockInt *list, int value){
	if(list == NULL){
		return addfirstelement(list, value);
	}else{
		blockInt *newblock = (blockInt*) malloc(sizeof(blockInt));
		newblock -> next = NULL;
		newblock -> value = value;
		blockInt *aux = list;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = newblock;
		newblock -> previous = aux;
		return list;
	}
}

/**
* Inserting an element after other that containing a same key value passed by parameter
*
*/
blockInt *addaftervalue(blockInt *list, int key, int value){
	if(list != NULL){
		blockInt *newblock, *aux;
		newblock = (blockInt*) malloc(sizeof(blockInt));
		newblock -> value = value;
		aux = list;
		while(aux -> next != NULL){
			if(aux -> value == key){
				break;
			}else{
				aux = aux -> next;
			}
		}
		if(aux -> value != key){
			return list;
		}else{
			newblock->next = aux->next;
			newblock->previous = aux;
			aux->next = newblock;
			newblock->next->previous = newblock;
		}
		return list;
	}else{
		return NULL;
	}
}

/**
* Inserting an element before other that containing a same key value passed by parameter
*/
blockInt *addbeforevalue(blockInt *list, int key, int value){
	if(list != NULL){
		blockInt *newblock, *aux;
		newblock = (blockInt*) malloc(sizeof(blockInt));
		newblock -> value = value;
		aux = list;
		if(list->value == key){
			newblock -> next = aux;
			return newblock;
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
			return list;
		}
	}else{
		return list;
	}
}

/**
* Removing an element that containing a same key value passed by parameter
*/
blockInt* removebykey(blockInt *list, int key){
	if(list == NULL){
		return list;
	}
	blockInt *aux, *rest;
	aux = list;
	if(aux->value == key){
		rest = aux->next;
		free(aux);
		return rest;
	}
	while(aux->next->next != NULL  && aux->next->value != key){
		aux = aux->next;
	}
	if(aux->next->value == key){
		rest = aux->next->next;
		free(aux->next);
		aux->next = rest;
	}
	return list;
}

/**
* Removing head of an list passed by parameter
*/
blockInt* removehead(blockInt* list){
	blockInt *aux = list;
	list -> next -> previous = NULL;
	list = list -> next;
	free(aux);
	return list;
}

/**
* Removing tail of an list passed by paremeter
*/
blockInt *removetail(blockInt *list){
	blockInt *aux = list;
	while(aux->next->next != NULL){
		aux = aux->next;
	}
	free(aux->next);
	aux->next = NULL;
	return list;
}

/**
* print all elements of an integer's list
*/
void printListOfIntegers(blockInt *list){
	blockInt *aux = NULL;
	for(aux = list; aux != NULL; aux = aux->next){
		printf("%d ", aux->value);
	}
}

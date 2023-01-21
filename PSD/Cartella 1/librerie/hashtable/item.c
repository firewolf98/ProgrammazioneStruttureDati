#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"

struct canzone{
	char titolo[20];
	char autore[20];
	int anno;
};

static item newItem ( char title[], char autor[], int a ){
	struct canzone *new = malloc(sizeof(struct canzone));
	
	if ( new != NULL ){
		strcpy(new->titolo, title);
		strcpy(new->autore, autor);
		new->anno = a;
		return new;
	}
	return NULLITEM;
}

item inputItem (){
char title[20], autor[20];
int a;
	printf("\nInserisci titolo canzone: ");
	scanf("%s", title);
	printf("\nInserisci autore: ");
	scanf("%s", autor);
	printf("\nInserisci anno: ");
	scanf("%d", &a);
	
	return(newItem(title,autor,a));
}

int cmp ( char k1[], char k2[]){
	return (strcmp(k1, k2));
}

char *getTitolo (item a){
	if ( a != NULL )
		return a->titolo;
		
	return NULL;
}

char *getAutore (item a){
	if ( a != NULL )
		return a->autore;
	
	return NULL;
}

void outputItem (item a){
	if ( a != NULL )
		printf("\nIl titolo è: %s\nL'autore è: %s\nL'anno è: %d\n", a->titolo, a->autore, a->anno);
		
	return;
}

void destroyItem (item *a){
	if ( *a != NULL ){
		free(*a);
		*a = NULL;
	}
}

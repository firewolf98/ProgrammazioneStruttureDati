#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"

struct canzone{
	char ISBN[20];
	char autore[20];
	char titolo[20];
	int copie;
};

static item newItem ( char code[], char autor[], char title[], int copies ){
	struct canzone *new = malloc(sizeof(struct canzone));
	
	if ( new != NULL ){
		strcpy(new->ISBN, code);
		strcpy(new->autore, autor);
		strcpy(new->titolo, title);
		new->copie = copies;
		return new;
	}
	return NULLITEM;
}

item inputItem (){
char code[20], autor[20], title[20];
int copies;
	printf("\nInserisci ISBN: ");
	scanf("%s", code);
	printf("\nInserisci autore: ");
	scanf("%s", autor);
	printf("Inserisci titolo: ");
	scanf("%s", title);
	printf("\nInserisci copie: ");
	scanf("%d", &copies);
	
	return(newItem(code,autor,title,copies));
}

int cmp ( char k1[], char k2[]){
	return (strcmp(k1, k2));
}

int getCopie (item a){
	if ( a != NULL )
		return (a->copie);
}

char *getISBN (item a){
	if (a != NULL)
		return a->ISBN;
	return NULL;
}

int upCopies (item a, int copies){
	if ( a == NULL )
		return -1;
	a->copie = copies;
	
	return 1;
}

int removeCopies (item a, int copies){
	if (a==NULL)
		return -1;
	if (copies > a->copie)
		a->copie = 0;
	else
		a->copie = copies;
	return 1;
}

void outputItem (item a){
	if ( a != NULL )
		printf("\nIl codice è: %s\nL'autore è: %s\nIl titolo è: %s\nLe copie sono: %d\n", a->ISBN, a->autore,a->titolo, a->copie);
		
	return;
}

void destroyItem (item *a){
	if ( *a != NULL ){
		free(*a);
		*a = NULL;
	}
}

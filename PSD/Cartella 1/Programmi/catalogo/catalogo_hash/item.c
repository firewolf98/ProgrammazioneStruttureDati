#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"

struct viaggio{
	char codice[20];
	char localita[20];
	char nome[20];
	char durata[5];
	int prezzo;
	int posti;
};

static item newItem ( char code[], char local[], char name[], char time[], int prize, int num ){
	struct viaggio *new = malloc(sizeof(struct viaggio));
	
	if ( new != NULL ){
		strcpy(new->codice, code);
		strcpy(new->localita, local);
		strcpy(new->nome, name);
		strcpy(new->durata, time);
		new->prezzo = prize;
		new->posti = num;
		return new;
	}
	return NULLITEM;
}

item inputItem (){
	
	char code[20], dest[20], dur[5], name[20];
	int price, posti;
	
	printf("*****INSERIMENTO VIAGGIO!*****\n");
	printf("CODICE VIAGGIO: ");
	scanf("%s", code);
	printf("DESTINAZIONE: ");
	scanf("%s", dest);
	printf("INSERISCI NOME COMPAGNIA: ");
	scanf("%s", name);
	printf("DURATA: ");
	scanf("%s", dur);
	printf("PREZZO: ");
	scanf("%d", &price);
	printf("POSTI: ");
	scanf("%d", &posti);
	
	struct viaggio *nuovo = newItem(code, dest, name, dur, price, posti);
	if ( nuovo != NULL )
		return nuovo;
}

int cmp ( char k1[], char k2[]){
	return (strcmp(k1, k2));
}

char *getCode (item a){
	if ( a != NULL )
		return a->codice;
		
	return NULL;
}

void outputItem (item a){
	if ( a != NULL )

	printf("\nCODICE VIAGGIO: %s\nDESTINAZIONE: %s\nNOME COMPAGNIA: %s\nDURATA: %s\nPREZZO: %d\nPOSTI: %d\n", a->codice, a->localita, a->nome, a->durata, a->prezzo, a->posti);
		
	return;
}

void upPrice(item e, int price){
	e->prezzo = price;
}
	
void upPosti(item e, int posti){
	e->posti = posti;
}

void destroyItem (item *a){
	if ( *a != NULL ){
		free(*a);
		*a = NULL;
	}
}

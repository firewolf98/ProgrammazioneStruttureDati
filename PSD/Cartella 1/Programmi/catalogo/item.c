#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct viaggio{
	char codice[20];
	char destinazione[20];
	char durata[5];
	int prezzo;
	int posti;
};

item newItem ( char code[], char dest[], char dur[], int price, int posti ){
	
	struct viaggio *nuovo = malloc(sizeof(struct viaggio));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->codice, code);
		strcpy(nuovo->destinazione, dest);
		strcpu(nuovo->durata, dur);
		nuovo->prezzo = price;
		nuovo->posti  = posti;
	}
	
	return nuovo;
}

item inputItem (){
	
	char code[20], dest[20], dur[5];
	int price, posti
	
	printf("*****INSERIMENTO VIAGGIO!*****\n");
	printf("CODICE VIAGGIO: ");
	scanf("%s", code);
	printf("DESTINAZIONE: ");
	scanf("%s", dest);
	printf("DURATA: ");
	scanf("%s", dur);
	printf("PREZZO: ");
	scanf("%d", &price);
	printf("POSTI: ");
	scanf("%d", &posti);
	
	struct esame *nuovo = newItem(code, dest, dur, price, posti);
	if ( nuovo != NULL )
		return nuovo;
}
void outputItem ( item a ){

	printf("\nCODICE VIAGGIO: %s\nDESTINAZIONE: %s\nDURATA: %s\nPREZZO: %d\nPOSTI: %d\n", a->codice, a->destinazione, a->durata, a->prezzo, a->posti);
}

int eq( item a, item b ){
	
	return (strcmp(a->codice,b->codice)==0);
}

item cloneItem( item a ){

}

void destroyItem( item *a ){

	free(*a);
	*a = NULL;
}

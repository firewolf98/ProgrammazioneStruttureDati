#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"

struct conto{
	char IBAN[20];
	char cognome[20];
	char nome[20];
	char codice[30];
	int tipo;
	int saldo;
};

static item newItem ( char IBAN[], char cognome[], char nome[], char codice[], int tipo, int saldo ){
	struct conto *new = malloc(sizeof(struct conto));
	
	if ( new != NULL ){
		strcpy(new->IBAN, IBAN);
		strcpy(new->cognome, cognome);
		strcpy(new->nome, nome);
		strcpy(new->codice, codice);
		new->tipo = tipo;
		new->saldo = saldo;
		return new;
	}
	return NULLITEM;
}

item inputItem (){
	char IBAN[20];
	char cognome[20];
	char nome[20];
	char codice[30];
	int tipo;
	int saldo;

	printf("\nInserisci IBAN ");
	scanf("%s", IBAN);
	printf("\nInserisci cognome: ");
	scanf("%s", cognome);
	printf("\nInserisci nome: ");
	scanf("%s", nome);
	printf("\nInserisci codice fiscale: ");
	scanf("%s", codice);
	printf("\nInserisci tipo(1:risparmio/0:giovani): ");
	scanf("%d", &tipo);
	printf("\nInserisci saldo: ");
	scanf("%d", &saldo);	

	return(newItem(IBAN, cognome, nome, codice, tipo, saldo));
}

int cmp ( char k1[], char k2[]){
	return (strcmp(k1, k2));
}

char *getIBAN (item a){
	if ( a != NULL )
		return a->IBAN;
		
	return NULL;
}

int getTipo (item a){
	if ( a != NULL )
		return a->tipo;
	
	return -1;
}

void outputItem (item a){
	if ( a != NULL )
		printf("\nL'IBAN è: %s\nIl cognome è: %s\nIl nome è: %s\nIl codice fiscale è: %s\nIl tipo è: %d\nIl saldo è: %d\n", a->IBAN, a->cognome, a->nome, a->codice, a->tipo, a->saldo);
		
	return;
}

item upSaldo(item e, int saldo){
	e->saldo = saldo;
return e;
}
void destroyItem (item *a){
	if ( *a != NULL ){
		free(*a);
		*a = NULL;
	}
}

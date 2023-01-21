#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


struct libro{
	char codice[20];
	char titolo[20];
	char autore[20];
	int copie_disponibili;
	int copie_prestito;
};

item creaLibro(char *cod, char *tit, char *aut, int disp, int prest){
	struct libro *l = malloc(sizeof(struct libro));
	if(l!=NULL){
		strcpy(l->codice, cod);
		strcpy(l->titolo, tit);
		strcpy(l->autore, aut);
		l->copie_disponibili=disp;
		l->copie_prestito=prest;
	}
	return l;
}

item inputLibro(){
	char cod[20], tit[20], aut[20];
	int disp, prest;

	printf("Inserisci codice libro: ");
	scanf("%s", cod);
	printf("Inserisci titolo: ");
	scanf("%s", tit);
	printf("Inserisci nome autore: ");
	scanf("%s", aut);
	printf("Inserisci il numero di copie disponibili: ");
	scanf("%d", &disp);
	printf("Inserisci il numero di copie in prestito: ");
	scanf("%d", &prest);
	
	return creaLibro(cod,tit,aut,disp,prest);
}

void outputLibro(item l){
	printf("\n\nCodice libro: %s\nTitolo: %s\nAutore: %s\nCopie disponibili: %d\nCopie in prestito: %d\n",l->codice, l->titolo, l->autore,l->copie_disponibili,l->copie_prestito);
}

char *getKey(item x){
	return x->codice;
}

int cmpItem(item a, item b){
	return strcmp(a->codice,b->codice);
}

void aggiornaPrest(item *l1){
	((*l1)->copie_disponibili)--;
	((*l1)->copie_prestito)++;
}

void aggiornaDisp(item *l1){
	((*l1)->copie_disponibili)++;
	((*l1)->copie_prestito)--;
}
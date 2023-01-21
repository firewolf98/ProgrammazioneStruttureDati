#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct viaggio{
	char codice[20];
	char destinazione[20];
	char tour_op[20];
	int durata;
	int prezzo;
	int posti;
};

item newViaggio(char *cod, char*dest, char *op, int dur, int prez, int pos)
{
	struct viaggio *v = malloc(sizeof(struct viaggio));
	if(v!=NULL){
		strcpy(v->codice,cod);
		strcpy(v->destinazione, dest);
		strcpy(v->tour_op, op);
		v->durata=dur;
		v->prezzo=prez;
		v->posti=pos;
	}
	return v;
}

item input_Viaggio(){
	char cod[20], dest[20], op[20];
	int dur, prez, pos;

	printf("Inserisci codice viaggio: ");
	scanf("%s",cod);
	printf("Inserisci destinazione: ");
	scanf("%s",dest);
	printf("Inserisci tour operatore: ");
	scanf("%s",op);
	printf("Inserisci durata (in giorni): ");
	scanf("%d",&dur);
	printf("Inserisci prezzo a persona: ");
	scanf("%d",&prez);
	printf("Inserisci posti disponibili: ");
	scanf("%d",&pos);

	return newViaggio(cod,dest,op,dur,prez,pos);
}

void output_Viaggio(item v)
{
	printf("\n\nCodice viaggio: %s\nDestinazione: %s\nTour operatore: %s\nDurata in giorni: %d\nPrezzo a persona: %d\nPosti disponibili: %d\n",v->codice, v->destinazione, v->tour_op, v->durata, v->prezzo, v->posti);
}

char *getKey(item x)
{
	return x->codice;
}

void modPrezzo(item *v, int p)
{
	(*v)->prezzo = p;
}

void modPosti(item *v, int p)
{
	(*v)->posti = p;
}

char *getNome(item v)
{
	return v->destinazione;
}
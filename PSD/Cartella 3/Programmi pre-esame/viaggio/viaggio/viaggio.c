#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaggio.h"

struct viaggio {
	char codice[20];
	char localita[20];
	int durata;
	int prezzo;
	int posti;
};

viaggio NewViaggio(char cod[],char localita[],int dur,int price,int posti)
{
	struct viaggio *nuovo=malloc(sizeof(struct viaggio));
	strcpy(nuovo->codice,cod);
	strcpy(nuovo->localita,localita);
	nuovo->durata=dur;
	nuovo->prezzo=price;
	nuovo->posti=posti;
	return nuovo;
}

viaggio InputViaggio()
{
	int price,pos,dur;
	char localita[20],cod[20];
	printf("CODICE VIAGGIO:\n");
	scanf("%s",cod);
	printf("LOCALITA':\n");
	scanf("%s",localita);
	printf("DURATA:\n");
	scanf("%d",&dur);
	printf("PREZZO:\n");
	scanf("%d",&price);
	printf("POSTI DISPONIBILI:\n");	
	scanf("%d",&pos);
	return NewViaggio(cod,localita,dur,price,pos);
}

void OutputViaggio(viaggio v)
{
	printf("CODICE VIAGGIO: %s\n",v->codice);
	printf("LOCALITA': %s\n",v->localita);
	printf("DURATA: %d\n",v->durata);
	printf("PREZZO: %d\n",v->prezzo);
	printf("POSTI DISPONIBILI: %d\n",v->posti);
}	

char *getKey(viaggio v)
{
	return v->codice;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct prenotazione{
	char cognome[20];
	char nome[20];
	char cod_fisc[20];
	int num_pren;
};

item NewPrenotazione ( char cogn[], char nome[], char cod_fisc[], int num_pren)
{
	
	struct prenotazione *nuovo = malloc(sizeof(struct prenotazione));
	
	if (nuovo != NULL)
	{
		strcpy(nuovo->cognome, cogn);
		strcpy(nuovo->nome, nome);
		strcpy(nuovo->cod_fisc, cod_fisc);
		nuovo->num_pren=num_pren;
	}
	
	return nuovo;
}

item InputPren(int num_pren)
{
	
	char cogn[20], nome[20], cod_fisc[5];
		
	printf("*****INSERIMENTO PRENOTAZIONE!*****\n");
	printf("COGNOME: ");
	scanf("%s", cogn);
	printf("NOME: ");
	scanf("%s", nome);
	printf("CODICE FISCALE: ");
	scanf("%s", cod_fisc);
	return NewPrenotazione(cogn,nome,cod_fisc,num_pren);
}

void outputItem (item a)
{

	printf("\nCOGNOME: %s\nNOME: %s\nCODICE FISCALE: %s",a->cognome,a->nome,a->cod_fisc);
}

/* int eq( item a, item b ){
	
	return (strcmp(a->codice,b->codice)==0);
}

item cloneItem( item a ){

}

void destroyItem( item *a ){

	free(*a);
	*a = NULL;
}
*/

int *getKey(item x)
{
	return x->num_pren;
}

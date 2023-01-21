#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ordSet.h"

struct squadra{
	char nome[20];
	int partite;
	int punti;
	int reti;
	int subite;
};

item newItem ( char name[], int match, int points, int goal, int sub){
	
	struct squadra *nuovo = malloc(sizeof(struct squadra));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->nome, name);
		nuovo->partite = match;
		nuovo->punti  =points;
		nuovo->reti = goal;
		nuovo->subite = sub;
	}
	
	return nuovo;
}

item inputItem (){
	
	char name[20];
	
	printf("*****INSERIMENTO SQUADRA!*****\n");
	printf("NOME: ");
	scanf("%s", name);
	struct squadra *nuovo = newItem(name, 0,0,0,0);
	if ( nuovo != NULL )
		return nuovo;
}

void outputItem ( item a ){

printf("\nNOME: %s\nPARTITE GIOCATE: %d\nPUNTI: %d\nGOAL: %d\nRETI SUBITE: %d\n", a->nome, a->partite, a->punti, a->reti, a->subite);

}

int cmpItem ( item a, item b ){
	return (strcmp(a->nome, b->nome));
}

int eq( item a, item b ){
	return ((b->punti)-(a->punti));
}

item updateItem ( item s, int val1, int val2, int val3 ){
	(s)->partite++;
	(s)->punti+= val1;
	(s)->reti+= val2;
	(s)->subite+= val3;
	
	return (s);
}

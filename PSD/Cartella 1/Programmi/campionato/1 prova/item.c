#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

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
	int match, points, goal, sub;
	
	printf("*****INSERIMENTO SQUADRA!*****\n");
	printf("NOME: ");
	scanf("%s", name);
	printf("PARTITE GIOCATE: ");
	scanf("%d", &match);
	printf("PUNTI: ");
	scanf("%d", &points);
	printf("GOAL: ");
	scanf("%d", &goal);
	printf("RETI SUBITE: ");
	scanf("%d", &sub);
	
	struct squadra *nuovo = newItem(name, match, points, goal, sub);
	if ( nuovo != NULL )
		return nuovo;
}
void outputItem ( item a ){

printf("\nNOME: %s\nPARTITE GIOCATE: %d\nPUNTI: %d\nGOAL: %d\nRETI SUBITE: %d\n", a->nome, a->partite, a->punti, a->reti, a->subite);

}

int eq( item a, item b ){
	
	return (strcmp(a->nome,b->nome)==0);
}

int eq1(item a, item b){

	if(strcmp(a->nome, b->nome) < 0)
		return 0;
}
void destroyItem( item *a ){

	free(*a);
	*a = NULL;
}

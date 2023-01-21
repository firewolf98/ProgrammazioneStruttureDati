#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct esame{
	char corso[20];
	int voto;
	char data[11];
};

item newItem ( char nome[], int val, char date[] ){
	
	struct esame *nuovo = malloc(sizeof(struct esame));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->corso, nome);
		nuovo->voto = val;
		strcpy(nuovo->data, date);
	}
	
	return nuovo;
}

item inputItem (){
	
	char nome[20], date[11];
	int val;
	
	printf("*****INSERIMENTO ESAME!*****\n");
	printf("Nome esame: ");
	scanf("%s", nome);
	printf("Voto: ");
	scanf("%d", &val);
	printf("Data: ");
	scanf("%s", date);
	
	struct esame *nuovo = newItem(nome, val, date);
	if ( nuovo != NULL )
		return nuovo;
}
void outputItem ( item a ){

	printf("\nNome esame: %s\nVoto: %d\nData: %s\n", a->corso, a->voto, a->data);
}

int eq( item a, item b ){
	
	return (strcmp(a->corso,b->corso)==0);
}

item cloneItem( item a ){

}

void destroyItem( item *a ){

	free(*a);
	*a = NULL;
}

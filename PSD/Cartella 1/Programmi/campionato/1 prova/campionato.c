#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "a_list.h"
#include "campionato.h"

struct campionato{
	char nome[20];
	list squadre;
};

struct campionato *newCampionato( char c[] ){

	struct campionato *nuovo = malloc(sizeof(struct campionato));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->nome, c);
		nuovo->squadre = newList();
	}
	 
	return nuovo;
}

item searchSquadra ( struct campionato *c, char name[] ){

	if ( c == NULL )
		return NULLITEM;
	
	item val = newItem (name, 0, 0, 0, 0);
	int p = posItem(c->squadre, val);
	free ( val );
	if ( p != -1 )
		return (getItem(c->squadre, p));
		
	//per semplicità restituisco direttamente il puntatore all'item senza clonarlo	

	return NULLITEM;
}

int addSquadra ( struct campionato *c ){

	if ( c == NULL )
		return -1;
		
	item es = inputItem();

	if (posItem(c->squadre, es) != -1)
		return -1;
		
	int i;	
	for ( i = 0; i < sizeList(c->squadre); i++ ){
		if (eq1(es, getItem(c->squadre, i)) == 0)	
			break;
	}
			return (insertList(c->squadre, i, es));
}

int outputCampionato ( struct campionato *c ){

	if ( c == NULL )
		return -1;
		
	printf("NOME CAMPIONATO: %s", c->nome);
	outputList(c->squadre);
	
	return 1;
}

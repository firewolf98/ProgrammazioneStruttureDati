#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ordSet.h"
#include "ADT.h"
#include "campionato.h"

struct campionato{
	char nome[20];
	ADT squadre;
};

struct campionato *newCampionato( char c[] ){

	struct campionato *nuovo = malloc(sizeof(struct campionato));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->nome, c);
		nuovo->squadre = newADT();
		
	}
	 
	return nuovo;
}

item searchSquadra ( struct campionato *c, char name[] ){

	if ( c == NULL )
		return NULLITEM;
	
	item val = newItem (name, 0, 0, 0, 0);
	item res;
	if ( containsADT(c->squadre, val) ){
		res = searchBinary(c->squadre, val);
		free (val);
		return res;
	}

	return NULLITEM;
}

int addSquadra ( struct campionato *c ){

	if ( c == NULL )
		return -1;
		
	item es = inputItem();

	if (containsADT(c->squadre,es)==1)
		return 0;
	
	return (insertADT(c->squadre, es));
}

int outputCampionato ( struct campionato *c ){

	if ( c == NULL )
		return -1;
		
	printf("NOME CAMPIONATO: %s", c->nome);
	outputADT(c->squadre);
	
	return 1;
}

int updateCampionato ( Campionato c, char squadra1[], char squadra2[], int goal1, int goal2 ){
	if ( c == NULL )
		return -1;
	item s1 = searchSquadra(c, squadra1);
	if ( s1 == NULL )
		return 0;
	item s2 = searchSquadra(c, squadra2);
	if ( s2 == NULL )
		return 0;
		
	if ( goal1 == goal2 ){
		s1 = updateItem(s1, 1,goal1, goal2);
		s2 = updateItem(s2, 1, goal2, goal1);
	}
	
	if ( goal1 > goal2 ){
		s1 = updateItem (s1, 3, goal1, goal2);
		s2 = updateItem (s2, 0, goal2, goal1);
	}
	
	if ( goal1 < goal2 ){
		s1 = updateItem (s1, 0, goal1, goal2);
		s2 = updateItem (s2, 3, goal2, goal1);
	}
	return 1;
}

struct c_set *outputPoints ( Campionato c ){
	set new = pointSet(c->squadre);
	return new;
}

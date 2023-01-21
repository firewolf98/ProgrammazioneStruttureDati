#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "set.h"
#include "BSTree.h"
#include "classifica.h"
#define MAX 20

struct classifica{
	char nome[20];
	BSTree squadre;
};

classifica nuovaClassifica(char *nome){
	struct classifica *c = malloc(sizeof(struct classifica));
	if(c!=NULL){
		strcpy(c->nome, nome);
		c->squadre=newBSTree();
	}
	return c;
}

int aggiungiSquadra(classifica c, item sq){
	if(c==NULL)
		return 0;
	return insertBSTree(c->squadre, sq);
}

int outputClassifica(classifica c){
	if(c!=NULL){
		printf("CLASSIFICA\n\nNOME: %s\n",c->nome);
		outputBSTree(c->squadre);
		return 1;
	}
	return 0;
}


int aggiorna(classifica c, char *nome1, char *nome2, int reti1, int reti2){
	item s1=getItem(c->squadre, nome1);
	if(s1==NULL)
		return 0;
	item s2=getItem(c->squadre, nome2);
	if(s2==NULL)
		return 0;
	incrementaPartite(&s1);
	incrementaPartite(&s2);

	aggiornaReti(&s1,reti1,reti2);
	aggiornaReti(&s2,reti2, reti1);

	if(reti1==reti2)
		aggiungiPunti(&s1,&s2,1,1);
	else if(reti1<reti2)
		aggiungiPunti(&s1,&s2,0,3);
	else
		aggiungiPunti(&s1,&s2,3,0);
	return 1;
}

item cercaSquadra(classifica c, char *nome){
	if(c==NULL)
		return NULL;
	return getItem(c->squadre, nome);
}

set ordinaClassifica(classifica c){
	if(c==NULL)
		return 0;
	else
		return BSTreeToSet(c->squadre);
}
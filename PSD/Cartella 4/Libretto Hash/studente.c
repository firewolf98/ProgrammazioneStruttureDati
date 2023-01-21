#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "chainedHash.h"
#include "studente.h"
#define MAX 20

struct studente{
	int matricola;
	char cognome[20];
	char nome[20];
	hashtable esami_sostenuti;
	int num_cfu_totali;
	
};

studente newStudente(int mat, char *cogn, char *nom)
{
	int i,n;
	struct studente *nuovo = malloc(sizeof(struct studente));
	if(nuovo!=NULL){
		nuovo->matricola = mat;
		strcpy(nuovo->cognome, cogn);
		strcpy(nuovo->nome, nom);
		nuovo->esami_sostenuti = newHashtable(MAX);
		}
		return nuovo;
}

int aggiungiEsame(studente s, item es)
{
	if(s==NULL)
		return 0;
	return insertHash(s->esami_sostenuti, es);
}

int outputStudente(studente s){
	if(s!=NULL){
		printf("STUDENTE\n\nMATRICOLA: %d\nCOGNOME: %s\nNOME: %s\n",s->matricola, s->cognome, s->nome);
		outputHash(s->esami_sostenuti);
		return 1;
	}
	return 0;
}

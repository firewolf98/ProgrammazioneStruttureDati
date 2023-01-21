#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esame.h"
#include "BSTree.h"
#include "studente.h"

struct studente{
	int matricola;
	char cognome[20];
	char nome[20];
	BSTree esami_sostenuti;
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
		nuovo->esami_sostenuti = newBSTree();
		}
		return nuovo;
}

int aggiungiEsame(studente s, item es)
{
	if(s==NULL)
		return 0;
	return insertBSTree(s->esami_sostenuti, es);
}

int outputStudente(studente s,FILE *output){
	if(s!=NULL){
		fprintf(output,"STUDENTE\n\nMATRICOLA: %d\nCOGNOME: %s\nNOME: %s\n",s->matricola, s->cognome, s->nome);
		outputBSTree(s->esami_sostenuti,output);
		return 1;
	}
	return 0;
}

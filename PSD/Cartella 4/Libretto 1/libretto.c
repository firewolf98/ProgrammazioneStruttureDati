#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"esame.h"
#include"libretto.h"
#define max_esami 25

struct libretto{
	int matricola;
	char nome[20];
	char cognome[20];
	esame esami[max_esami];
	int num_esami;
};

libretto newLibretto(int mat, char *n, char *c){
	struct libretto *l=malloc(sizeof(struct libretto));
	if(l!=NULL){
		l->matricola=mat;
		strcpy(l->nome, n);
		strcpy(l->cognome, c);
		l->num_esami=0;
	}
	return l;
}

esame cercaEsame(libretto l, char *c){
	if (l==NULL)
		return NULLEXAM;
	int i=0, trovato=0;
	while(i<l->num_esami&&!trovato){
		if ((strcmp(getCorso(l->esami[i]), c))==0){
			trovato=1;
		}
		else i++;
	}
	if (trovato)
		return cloneEsame(l->esami[i]);
	return NULLEXAM;
}


int addEsame(libretto l, esame e){
	if (l==NULL)
		return 0;
	if (l->num_esami==max_esami)
		return 0; //array pieno
	if (cercaEsame(l,getCorso(e))) //l'esame è già presente
		return 0;
	esame val=cloneEsame(e);
	if (val==NULL)
		return 0;
	l->esami[l->num_esami]=e;
	(l->num_esami)++;
	return 1;
}

int outputLibretto(libretto l){
	if (l!=NULL){
		printf("Libretto\nMatricola %d\nCognome %s\nNome %s\nEsami sostenuti:\n", l->matricola, l->cognome, l->nome);
	for (int i=0;i<l->num_esami;i++){
		outputEsame(l->esami[i]);
		printf("\n");
	}
	return 1;
	}
	else return 0;
}

 


	
		

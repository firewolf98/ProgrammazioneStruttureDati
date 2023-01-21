#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct squadra{
	char nome[20];
	int partite;
	int punti;
	int reti_fatte;
	int reti_subite;
};

item newSquadra(char nom[], int par, int pun, int r_f, int r_s){
	struct squadra *s = malloc(sizeof(struct squadra));
	if(s!=NULL){
		strcpy(s->nome, nom);
		s->partite=par;
		s->punti=pun;
		s->reti_fatte=r_f;
		s->reti_subite=r_s;
	}
	return s;
}

item inputSquadra(){
	char nome[20];
	int partite,punti,reti_fatte,reti_subite;

	printf("\nInserisci il nome della squadra: ");
	scanf("%s",nome);
	printf("\nInserisci il numero di partite disputate: ");
	scanf("%d",&partite);
	printf("\nInserisci il numero di punti (3 punti per vittore, 1 per pareggio, 0 altrimenti): ");
	scanf("%d",&punti);
	printf("\nInserisci il numero di reti fatte: ");
	scanf("%d",&reti_fatte);
	printf("\nInserisci il numero di reti subite: ");
	scanf("%d",&reti_subite);
	return newSquadra(nome,partite,punti,reti_fatte,reti_subite);
}

void output_Squadra(item v)
{
	printf("\n\nNome squadra: %s\nPartite disputate: %d\nPunti: %d\nReti fatte: %d\nReti subite: %d\n",v->nome, v->partite, v->punti, v->reti_fatte, v->reti_subite);
}

int cmpItem(item a, item b){
	return strcmp(a->nome,b->nome);
}

void incrementaPartite(item *s1){
	((*s1)->partite)++;
}

void aggiornaReti(item * s1, int reti1, int reti2){
	((*s1)->reti_fatte) = ((*s1)->reti_fatte)+reti1;
	((*s1)->reti_subite) = ((*s1)->reti_subite)+reti2;
}

void aggiungiPunti(item * s1, item * s2, int puntis1, int puntis2){
	((*s1)->punti) = ((*s1)->punti)+puntis1;
	((*s2)->punti) = ((*s2)->punti)+puntis2;
}

char *getKey(item value){
	return value->nome;
}

int compare(item a, item b){
	return (b->punti)-(a->punti);
}
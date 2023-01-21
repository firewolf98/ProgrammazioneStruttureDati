#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esame.h"

struct esame{
	char nome_insegnamento[20];
	int numero_cfu;
	int voto;
	char lode[20];
	int data;
};

item newEsame(char *nom, int num_cfu, int voto, char *lode, int data){
	struct esame *s = malloc(sizeof(struct esame));
	if(s!=NULL){
		strcpy(s->nome_insegnamento, nom);
		s->numero_cfu= num_cfu;
		s->voto= voto;
		strcpy(s->lode, lode);
		s->data=data;
	}
	return s;
}

item inputEsame(){
	char nome[20], lode[20], ris[10]={"---"};
	int cfu, voto, data;

	printf("\nInserisci il nome dell'esame: ");
	scanf("%s", nome);
	
	printf("\nInserisci il numero dei cfu: ");
	scanf("%d",&cfu);
	
	printf("\nInserisci il voto dell'esame: ");
	scanf("%d", &voto);
	if(voto<18 || voto>30)
		printf("Errore!\n");
		if(voto==30){
		printf("\nLo studente ha avuto la lode? si - no: ");
		scanf("%s",lode);}
		else strcpy(lode,ris);
	
	printf("\nInserisci la data di esame (il giorno): ");
	scanf("%d",&data);
	
	return newEsame(nome, cfu, voto, lode, data);
}

void outputEsame(item v,FILE *output)
{
	fprintf(output,"\n\nNome: %s\nCFU: %d\nVoto: %d\nLode: %s\nData: %d\n",v->nome_insegnamento, v->numero_cfu, v->voto, v->lode, v->data);
}

char *getKey(item value){
	return value->nome_insegnamento;
}

int cmpItem(item a, item b){
	return strcmp(a->nome_insegnamento,b->nome_insegnamento);
}

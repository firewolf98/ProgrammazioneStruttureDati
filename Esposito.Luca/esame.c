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

item inputEsame(FILE *input)
{
	char nome[20], lode[20];
	int cfu, voto, data;

	fscanf(input,"%s %d %d %s %d",nome,&cfu,&voto,lode,&data); 
	//if(strcmp(lode,ris)
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

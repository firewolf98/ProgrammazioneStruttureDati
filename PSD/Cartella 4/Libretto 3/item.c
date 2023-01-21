#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"

struct esame{
	char corso[20];
	int voto;
	char data[11];
};

item newItem(char *nome, int voto, char *date){
	struct esame *e=malloc(sizeof(struct esame));
	if (e!=NULL){
		strcpy(e->corso, nome);
		e->voto=voto;
		strcpy(e->data, date);
	}
	return e;
}

char *getCorso(item e){
	if (e==NULL)
		return NULL;
	char *nome=malloc(20*sizeof(char));
	if (nome!=NULL)
		strcpy(nome, e->corso);
	return nome;
}

item input_item(){
	char nome[20], date[11];
	int v;
	printf("Inserisci nome del corso: ");
	scanf("%s", nome);
	printf("Inserisci voto dell'esame: ");
	scanf("%d", &v);
	printf("Inserisci data dell'esame; (GG/MM/AAAA) ");
	scanf("%s", date);
	if (v>=18&&v<=31) //si assume 31=30 e lode
		return newItem(nome, v, date);
	return NULLITEM;
}

void output_item(item e){
	printf("Esame:\nCorso: %s\nVoto: %d\nData: %s\n", e->corso, e->voto, e->data);
}

item cloneItem(item e){
	if (e==NULL)
		return NULL;
	struct esame *new=malloc(sizeof(struct esame));
	if (e!=NULL)
		new=e;
	return new;
}

int eq(item a, item b){
	return (strcmp(a->corso, b->corso)==0);
}

int getVoto(item e){
	int a=e->voto;
	return a;
}

int cmpItem(item e1, item e2){
	return (strcmp(e1->corso, e2->corso));
}




	

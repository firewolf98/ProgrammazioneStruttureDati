#include <stdlib.h>
#include <string.h>
#include "ADTesame.h"

struct esame{
	char corso[20];
	int voto;
	struct esame *next;
};

Esame inserisciEsame(char nome[], int val, Esame head){

	Esame nuovo = malloc(sizeof(struct esame));
	strcpy(nuovo->corso, nome);
	nuovo->voto=val;
	nuovo->next=head;
	head = nuovo;

	return head;
}

Esame inserisciCentro( char nome[], int val, int pos, Esame head){
	
	Esame nuovo = malloc(sizeof(struct esame));
	strcpy(nuovo->corso, nome);
	nuovo->voto=val;
	
	Esame tmp=head;
	int i=0;

	while( tmp != NULL && i<pos ){
		i++;
		tmp=tmp->next;
	}
	
	nuovo->next = tmp->next;
	tmp->next = nuovo;
	
	return head;
}

Esame cancellaTesta(Esame head){

	Esame p = head;
	head = head->next;
	free (p);
	return head;
}

Esame cancellaCentro(Esame head, int pos){

	int i=0;
	Esame tmp=head;
	while(i<pos-1 && tmp!=NULL){
		i++;
		tmp=tmp->next;
	}
	Esame p=tmp->next;
	tmp->next=tmp->next->next;
	free(p);
	return tmp;
}

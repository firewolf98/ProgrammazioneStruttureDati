#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun_libretto.h"

struct esame{
	char corso[20];
	int voto;
	Esame next;
};

Esame inserisciEsame(char nome[], int val, Esame head){	 //inserimento in testa
	Esame nuovo = malloc(sizeof(struct esame));
	strcpy(nuovo->corso, nome);
	nuovo->voto = val;
	nuovo->next = head;
	head = nuovo;			//la testa della lista è stata aggiornata
	return head;
}

Esame inserisciCentro(char nome[], int val, int pos, Esame head){
	Esame nuovo = malloc(sizeof(struct esame));
	strcpy(nuovo->corso, nome);
	nuovo->voto = val;
	Esame p = head;  		//puntatore alla testa
	int i = 0;
	while(p != NULL && i < pos){
			i++;
			p = p->next;    //scorre la p  
		}
	nuovo->next = p->next;			
	p->next = nuovo;			
	
	return head;
}

Esame cancellaTesta(Esame head){
	Esame p = head;
	head = head->next;
	free(p);
	return head;
}

Esame cancellaCentro(int posizione, Esame head){
	Esame p = head;
	int i = 0;
	while(p != NULL && i < posizione-1){
		i++;
		p = p->next;
	}
	Esame temp = p->next;
	p->next = p->next->next;
	free(temp);
	return head;
}

Esame bubbleSort(Esame head){
	int flag = 1;
	while(flag == 1){
		flag = 0;
		Esame p = head;
		while(p != NULL){
			if(p->voto > p->next->voto){
				Esame temp = p->next;
				p->next = temp->next;
				temp->next = p;	
				if(p == head)			//modifica la testa
					head = temp;
				flag = 1;
			}	
		}		
	return head;	
	}			
}


















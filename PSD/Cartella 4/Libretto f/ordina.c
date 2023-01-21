#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "ordina.h"

struct node {
	item value;
	struct node *next;
};



struct c_list {
	struct node *first;
	int size;
};



list ordina(item e, list l){
	
	int trovato=0;
	struct node *aux,*prec, *current;/*inserimento ordinato con possibili duplicazioni*/
	aux=malloc(sizeof(struct node));
	aux->value=e;
	aux->next=NULL;
	
	if(l==NULL)
		l->first=aux;
		/*primo elemento*/
	else{
		current=l->first;
		while((current!=NULL && !trovato)){
			if(current->value<e)
			{
				prec=current;
				current=current->next;
			}
			else
				trovato=1;
		}
	if(current=NULL)
		prec->next=aux;/*in fondo*/
	else{
		if(current==l->first){
			aux->next=current;
			l->first=aux;
		}
		else{
			prec->next=aux;
			aux->next=current;/*inserisce in mezzo*/
		}
	}
	l->size++;
	return l;
} }
	


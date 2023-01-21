#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "set.h"

struct node {
	item value;
	struct node * next;
};

struct c_set {
	struct node *first;
	int size;
};


static struct node* makeNode(item val, struct node* nxt);
// implementazione simile a quella di ADT list

set newSet(void) {
	struct c_set *s;
	s = malloc (sizeof(struct c_set));
	if (s != NULL) {
		s->first = NULL;
		s->size = 0;
	}
	return s;
}


int emptySet(set s) {
	if(s == NULL) return -1;
	return (s->size == 0);
}


int cardinalitys(set s) {
	if(s == NULL) return -1;
	return s->size;
}


int containss(set s, item val)
{
	if(s == NULL) 
			return 0;
	int res;
	int found = 0;
	int greater = 0;
	struct node *temp = s->first;	// per attraversare i nodi
	while (temp != NULL && !found && !greater) {
		res = compare(temp->value, val);
		if (res == 0)
			found = 1;		// elemento trovato
		else if (res > 0)	// temp->value > val
			greater = 1;	// non può essere trovato
		else temp=temp->next; // continua ricerca
	}
	return found;
}


int insertSet(set s, item val)
{
	if(s == NULL)
		return -1;
	struct node *temp, *temp1;
	if(s->first == NULL) {		// caso s vuoto
		temp1 = makeNode(val, NULL);
		if(temp1 == NULL)
			return -1;		// inserimento non riuscito
		s->first = temp1;		
		s->size++;
		return 1;		// inserimento riuscito
	}
	int res = compare(s->first->value, val);
	if(res == 0) 
		return 0;		// elemento gia’ presente in prima posizione
	if(res > 0){		
		temp1 = makeNode(val, s->first);
		if(temp1 == NULL)
			return -1;	// inserimento non riuscito
		s->first = temp1;		
		s->size++;
		return 1;		// inserimento riuscito
	}
	temp = s->first; 	//per attraversare i nodi
	int found = 0;
	int greater = 0;
	// visitiamo il resto della struttura a puntatori
	// temp punta a nodo precedente quello corrente
	while (temp->next != NULL && !found && !greater){ // visita finalizzata
		res = compare(temp->next->value, val);
			if(res == 0) 
				found = 1;  	// elemento trovato
			else if(res > 0)
				greater = 1;	// trovato elemento maggiore
				else temp=temp->next;  // continua ricerca
	}	
	if(found) return 0;			// elemento già presente
	/* se found == 0, allora temp punta al nodo precedente
	     alla posizione in cui inserire val */
	// il nuovo nodo va inserito tra temp e temp-->next
	temp1 = makeNode(val,temp -> next);
	if(temp1 == NULL)
		return -1;		// inserimento non riuscito
	temp -> next = temp1;		
	s->size++;
	return 1;		// inserimento riuscito
}


int removeSet(set s, item val){
	if(s== NULL)
		return -1;
	if(s->first == NULL) {		// caso s vuoto
		return 0;				// rimozione non riuscita
	}
	struct node *temp = s->first;	// per attraversare i nodi
	int res = compare(temp->value, val);
	if(res == 0) {		// elemento presente in prima posizione
	s->first = s->first->next;
	free(temp);
	s->size--;
	return 1;
	}
	if(res > 0) 		// s->first->value > vacmpl
		return 0;		// val non può essere trovato
	// visitiamo il resto della struttura a puntatori
	// temp punta a nodo precedente quello corrente
	int found = 0;
	int greater = 0;
	while (temp->next != NULL && !found && !greater) {
		res = compare(temp->next->value, val);
		if (res == 0)
			found = 1;		// elemento trovato
		else if(res > 0)	// trovato elemento maggiore
			greater = 1;	// fermiamo la ricerca
		else temp=temp->next; // continua ricerca
	}
	if(!found)		// elemento non presente
		return 0;
	// se found == 1, temp punta a nodo precedente
	// a quello da rimuovere (che contiene val)
	struct node *temp1 = temp->next;	 // nodo da rimuovere
	temp->next = temp1->next;
	free(temp1);
	s->size--;
	return 1;		//eliminazione effettuata
}

int unionSet(set s1, set s2)
{
	if(s1 == NULL || s2 == NULL)
		return 0; // operazione non riuscita
	struct node *temp = s2->first;
	int res = 0;
	// scorriamo s2 e inseriamo in s1 gli elementi di s2
	while (temp != NULL && res != -1) { // visita di s2
		res = insertSet(s1, temp->value);
		temp = temp->next;
	} // temp->value inserito in s1 solo se non presente
	if(res == -1) return 0; // operazione non ruscita
		return 1;
}

int intersectSet(set s1, set s2)
{
	if(s1 == NULL || s2 == NULL)
		return 0; // operazione non riuscita
	if(s1->first == NULL) {
		return 1; // se s1 è vuoto, resta vuoto
	}
	struct node *temp = s1->first;
	struct node *temp1;
// eliminiamo da s1 gli elementi non presenti in s2
// scorriamo s1 a partire dal secondo elemento
// trattiamo il primo elemento di s1 alla fine

	while (temp->next != NULL)
		if(!containss(s2, temp->next->value)) {
			temp1 = temp->next; // nodo da rimuovere
			temp->next = temp1->next;
			s1->size--;
			free(temp1);
		}
	else temp = temp->next;
// ora trattiamo il primo elemento di s1
	if(!containss(s2, s1->first->value)) {
		temp1 = s1->first; // rimuoviamo primo elemento
		s1->first = s1->first->next;
		s1->size--;
	free(temp1);
	}
return 1;
}

static struct node* makeNode(item val, struct node* nxt)
{
struct node *nuovo = malloc (sizeof(struct node));
if (nuovo != NULL) {
nuovo->value = val;
nuovo->next = nxt;
}
return nuovo;
}

void outputSet(set s){
	struct node * temp = s->first;
	while(temp != NULL) {
		output_Squadra(temp->value);
		printf("\n");
		temp = temp->next;
	}
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "key.h"
#include "item.h"
#include "htable.h"

struct hash{
	int size;
	struct elem **table;
};

struct elem{
	key k;
	item value;
	struct elem *next;
};

htable newHash ( int dim ){
	htable new = malloc(sizeof(struct hash));
	
	if ( new != NULL ){
		new->size = dim;
		new->table = (struct elem **) malloc(dim*sizeof(struct elem *));
	}
	
	for ( int i = 0; i < dim; i++ )
		new->table[i] = NULL;

	return new;
}
static struct elem *makeNode( item e, key k, struct elem *nxt){
	struct elem *new = malloc(sizeof(struct elem));
	
	if ( new != NULL ){
		new->k = k;
		new->value = e;
		new->next = nxt;
	}
	return new;
}

int insertHash (htable h, item e, key k){
	if ( h == NULL )
		return -1;
	
	int idx = fhash(h->size, k);
	struct elem *head, *curr;
	head = curr = h->table[idx];
	if(h->table[idx] == NULL){
		h->table[idx] = makeNode(e,k,NULL);
		return 1;
	}
	
	while (curr){
		if(cmp(k, curr->k)==0)
			return 0;
		else 
			curr = curr->next;
	}
	
	h->table[idx] = makeNode(e, k, head);
	return 1;
}

item searchHash (htable h, key k){
	if ( h == NULL )
		return NULLITEM;
		
	int idx = fhash(h->size, k);
	int found = 0;
	
	struct elem *temp = h->table[idx];
	if(h->table[idx] == NULL)
		return NULLITEM;
	while(temp != NULL && !found){
		if(cmp(temp->k, k)==0)
			found = 1;
		else
			temp = temp->next;
	}
	
	if ( found )
		return (temp->value);
		
	return NULLITEM;
}

int removeHash (htable h, key k){
	if ( h == NULL )
		return -1;
	int idx = fhash(h->size, k);
	struct elem *prec, *curr;
	prec = curr = h->table[idx];
	
	if(h->table[idx] == NULL )
		return -1;
		
	if(cmp(curr->k, k)==0){
		h->table[idx] = curr->next;
		destroyItem(&(prec->value));
		free(curr);
		return 1;
	}
		
	while(curr){
		if(cmp(curr->k, k)==0){
			prec = curr->next;
			destroyItem(&(curr->value));
			free(prec);
			return 1;
		}
		else{
			prec = curr;
			curr = curr->next;
		}
	}
	free(prec);
	free(curr);
	return 0;
}

/*int fhash (int size, key k){
	int val;
	int len = strlen(k);
	val = k[0] + k[len-1] +len;
	
	return (val%size);
}*/

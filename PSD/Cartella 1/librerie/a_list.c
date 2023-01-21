#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "a_list.h"

#define RESIZE 20

struct a_list{
	item *array;
	int size;
	int dim;
};

list newList(){

	struct a_list *l=malloc(sizeof(struct a_list));
	
	if(l!=NULL){
		l->size=0;
		l->dim=50;
		l->array=calloc(l->dim, sizeof(item));
	}
		
	return l;
}

item getItem ( list l, int pos ){
	
	if ( l == NULL )
		return NULLITEM;
		
	if ( pos>l->size || pos<0 )
		return NULLITEM;
	
	return (l->array[pos]);
}

int posItem ( list l, item val ){

	int i = 0, found = 0;

	if ( l == NULL )
		return -1;
		
	while ( i < (l->size) && !found ){
	
		if(eq(&l->array[i], &val)){
		
			found = 1;
			return i;
		}
		else i++;
	}
	
	if (!found){
		return -1;
	}

}

int sizeList ( list l ){

	if ( l == NULL )
		return -1;
		
	if ( l != NULL )
		if ( l->array != NULL )
			return (l->size);
		else return 0;
}

int emptyList ( list l ){

	if ( l == NULL )
		return -1;
		
	if ( l->size == 0 )
		return 0;
	return 1;
}

int insertList ( list l, int pos, item val ){

	if ( l == NULL )
		return 0;

	if ( l->size == l->dim ){
		item *temp = realloc(l->array,(l->dim+RESIZE)*sizeof(item));
		if ( temp == NULL ){
			return 0;
		}
		
		l->array = temp;
		l->dim+= RESIZE;
	}
		
	
	if ( pos < 0 || pos > l->size )
		return 0;
		
	int i = 0;	
	for ( i = l->size; i >= pos; i--){
		l->array[i+1] = l->array[i];
	}
		
	l->array[pos] = val;
	l->size++;

	return 1;
}

int removeList ( list l, int pos ){

	if ( l == NULL )
		return 0;
		
	if ( pos < 0 || pos > l->size )
		return 0;
		
	int i;
	for ( i = pos; i < l->size; i++ ){
		l->array[i] = l->array[i+1];
	}
	
	destroyItem(&l->array[l->size-1]);
	l->size--;
	
	return 1;
}

list reverseList1 ( list l ){

	if ( l == NULL )
		return NULL;
		
	int i, k;
	list l1 = newList();
		if ( l1 == NULL )
			return NULL;
		
	for ( i = l->size-1, k = 0; k < l->size; i--, k++ ){
	
		l1->array[k] = l->array[i];
		
	}
		l1->size = l->size;
		l1->dim = l->dim;
	if ( l1 == NULL )
		return NULL;

	return l1;
		
}

int reverseList2 ( list l ){

	if ( l == NULL )
		return 0;
		
	item temp;
		
	int i, k;
	for ( i = 0, k = l->size-1; i < k; i++, k-- ){
		temp = l->array[i];
		l->array[i] = l->array[k];
		l->array[k] = temp;
	}
	
	return 1;
}

int deleteList ( list l ){

	if ( l == NULL )
		return 0;
		
	int i;
	for ( i = 0; i < l->size; i++ ){
		destroyItem(&l->array[i]);
	}
	
	l->size = 0;
}

list cloneList(list l){

	if ( l == NULL )
		return NULL;
		
	list l1=newList();
		if ( l1 == NULL )
			return NULL;
	
	int i;
	
	for ( i = 0; i < l->size; i++ ){
	
		l1->array[i] = l->array[i];
		
	}
	
	l1->size = l->size;
	l1->dim = l->dim;
	
	return l1;
}

int outputList (list l){

	if ( l == NULL )
		return -1;
		
	int i;
	
	for ( i = 0; i < l->size; i++ ){
	
		printf (" %d° elemento: ", i);
		outputItem(&l->array[i]);
		
	}
	
	return 1;
}

list inputList (int n){

	if ( n <= 0 )
		return NULL;
		
	list l=newList();
		
	int i;	
	for ( i = 0; i < n; i++ ){
	
		inputItem(&l->array[i]);
		
	}
	
	l->size = n;
	
}

void destroyList ( list *l ){

	if ( *l != NULL )
		deleteList(*l);
		
	free ((*l)->array);
	free (*l);
	*l = NULL;
}

#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "queue.h"

#define MAXQUEUE 100

struct c_queue{
	item *vect;
	int size;
	int head, tail;
};

queue newQueue (int maxSize){

	struct c_queue *new = malloc(sizeof(queue));
	
	if ( new == NULL )
		return NULL;
	
	if ( maxSize < 0 )
		new->size = MAXQUEUE;
	else
		new->size = maxSize;
	
	new->vect = malloc (new->size*sizeof(item));
	
	if ( new->vect == NULL ){
		free (new);
		return NULL;
	}
	
	new->head = new->tail = 0;
	
	return new;
}

int emptyQueue ( queue q ){

	if ( q == NULL )
		return -1;
		
	return ( q->head == q->tail );
}

item dequeue ( queue q ){

	if ( q == NULL )
		return NULLITEM;
		
	if ( emptyQueue(q) )
		return NULLITEM;
		
	item result = q->vect[q->head];
	q->head = (q->head+1) % q->size;
	
	return result;
}

int enqueue ( item val, queue q ){

	if ( q == NULL )
		return -1;
		
	q->vect[q->tail] = val;
	q->head = (q->head+1) % q->size;
	
	return 1;
}

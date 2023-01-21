#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

#define MAXQUEUE 100

struct c_queue{
	item *vet;
	int size;			//dimensione della coda
	int head,tail;
};

queue newQueue(int maxSize)
{
	struct c_queue *q=malloc(sizeof(struct c_queue));

	if(q==NULL)
		return NULL;

	if(maxSize<=0)
		q->size=MAXQUEUE;
	else
		q->size=maxSize;

	q->vet=malloc(q->size*sizeof(item));

	if(q->vet == NULL) {
		free(q);
		return NULL;
	}

	q->head = q->tail = 0;

	return q;
}

int emptyQueue(queue q)
{
	if(q==NULL)
		return -1;

	return (q->head==q->tail);
}

int enqueue(item val, queue q)
{
	if(q==NULL)
		return -1;

	if(q->head==(q->tail+1)%q->size)
		return 0;

	//a differenza di prima non dobbiamo
	//distinguere il caso di coda vuota
	//perchè head e tail sono sempre
	//definiti

	q->vet[q->tail] = val;
	q->tail = (q->tail+1)%q->size;

	return 1;
}

item dequeue(queue q)
{
	if(q==NULL)
		return NULLITEM;
	if(q->head==q->tail)
		return NULLITEM;

	item result = q->vet[q->head];

	q->head = (q->head +1)%q->size;

	return result;
}

void outputQueue(queue q)
{
	if(q==NULL)
		return;

	int pos;

	for(pos=q->head; pos!=q->tail; pos=(pos+1)%q->size)
		output_item(q->vet[pos]);
}

int search(queue q, item value)
{
	if(q==NULL)
		return 0;

	int found=0;
	int pos=q->head;

	while(!found && pos!=q->tail){
		if(eq(q->vet[pos],value))
			found=1;
		else
			pos=(pos+1)%q->size;
	}

	return found;
}
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#define MAXSTACK 50

struct c_stack{
	item vet[MAXSTACK];
	int top;
};

stack newStack()
{
	stack s = malloc(sizeof(struct c_stack));

	if(s==NULL) 
		return NULL;

	s->top = 0;
	return s;
}

int emptyStack(stack s)
{
	if(s!=NULL)
		return s->top==0;
}

int push(item val, stack s)
{
	if(s==NULL)
		return 0;
	if(s->top==MAXSTACK)
		return 0;

	s->vet[s->top]=val;
	(s->top)++;
	return 1;
}

int pop(stack s)		//prelievo
{
if(s==NULL)
		return 0;
if(s->top==0)
		return 0;
	(s->top)--;
	return 1;
}

item pop_val(stack s)		//prelievo del valore
{
	item x;
	x = s->vet[s->top];
	(s->top)--;

	return x;
}

item top(stack s)
{
	item e;
	if(s->top>0)
		e=s->vet[s->top-1];
	
	else 
		e = NULLITEM;
	return e;
}
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

#define STARTSIZE 50
#define ADDSIZE 20

struct c_stack{
	item *vet;
	int size;
	int top;
};

struct c_stack *newStack (){
	struct c_stack *s;
	s = malloc(sizeof(struct c_stack));
	if ( s == NULL )
		return 0;
	s->vet = calloc(STARTSIZE, sizeof(item));
	s->size = STARTSIZE;
	s->top = 0;
	
	return s;
}

int emptyStack (stack s){
	
	if ( s == NULL )
		return -1;
	
	return (s->top == 0);
}

int pop (stack s){

	if ( s->top == 0 )
		return 0;
		
	s->top--;
	
	return 1;
}

int push ( item val, stack s ){

	if ( s == NULL )
		return -1;
	
	if ( s->top == s->size ){
		item *temp = realloc (s->vet,(s->size+ADDSIZE)*sizeof(item));
		if ( temp == NULL ){
			return -1;
		}
	s->vet = temp;
	s->size = s->size+ADDSIZE;
	}	
	
	s->vet[s->top] = val;
	s->top++;
}

item top (stack s){
	
	item e;
	if ( s->top > 0 )
		e = s->vet[s->top-1];
		
	else 
		e = NULLITEM;
		
	return e;
}

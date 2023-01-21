#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "set.h"

static struct node *makeNode( item val, struct node * );

struct node{
	item value;
	struct node *next;
};

struct c_set{
	struct node *first;
	int size;
};

set newSet(){

	struct c_set *s = malloc(sizeof(struct c_set));
	
	if ( s != NULL ){
		s->first = NULL;
		s->size = 0;
	}
	
	return s;
}

int emptySet( set s ){

	if ( s == NULL )
		return -1;
		
	return (s->size == 0);
}

int cardinality( set s ){

	if ( s == NULL )
		return -1;

	return s->size;
}

int contains( set s, item val ){

	if ( s == NULL )
		return -1;
		
	int found = 0;
	
	struct node *temp = s->first;
	
	while( temp != NULL && !found ){
		if (eq( val, temp->value))
			found = 1;
		else temp = temp->next;
	}
		
	return found;
}

static struct node *makeNode ( item val, struct node *nxt ){

	struct node *nuovo = malloc(sizeof(struct node));
	
	if ( nuovo != NULL ){
		nuovo->value = val;
		nuovo->next = nxt;
	}
	
	return nuovo;
}

int insertSet( set s , item val ){

	if ( s == NULL )
		return -1;
		
	if ( s->first == NULL ){
		s->first = makeNode(val, NULL);
		
		if ( s->first == NULL ){
			return -1;
		}
		
		s->size++;
		return 1;
	}
	
	struct node *temp = s->first;
	
	if (eq(temp->value, val))
		return 0;
		
	int found = 0;
	
	while ( temp != NULL && !found ){
		if(eq(temp->value, val))
			found = 1;
		
		else 
			temp = temp->next;
	}
		
	if ( found )
		return 0;
			
	temp->next = makeNode(val, NULL);
	if ( temp->next == NULL )
		return -1;
		
	s->size++;
	return 1;
}

int removeSet ( set s, item val ){
	
	if ( s == NULL )
		return -1;
	
	if ( s->first == NULL )
		return -1;
		
	struct node *temp = s->first;
	
	if (eq(temp->value, val)){
		s->first = temp->next;
		free(temp);
		s->size--;
		return 1;
	}
	
	int found = 0;
	
	while ( temp != NULL && !found ){
		if(eq(temp->value, val))
			found = 1;
		else 
			temp = temp->next;
	}
	
	if ( !found )
		return 0;
		
	if ( found ){
		struct node *temp1 = temp->next;
		temp = temp->next->next;
		free(temp1);
		s->size--;
		return 1;
	}
}

int unionSet( set s1, set s2 ){
	
	if ( s1 == NULL || s2 == NULL )
		return -1;
		
	struct node *temp = s2->first;
	int res = 0;
	
	while ( temp != NULL && res != -1){
		res = insertSet(s1, temp->value);
		temp = temp->next;
	}
	
	if ( res == -1 )
		return 0;
	return 1;
}

int intersectSet( set s1, set s2 ){

	if ( s1 == NULL || s2 == NULL )
		return -1;
		
	if ( s1->first == NULL )
		return 1;
		
	struct node *temp = s1->first;
	struct node *temp1;
	
	while ( temp->next != NULL ){
		if(!contains(s2,temp->next->value)){
			temp1 = temp->next;
			temp->next = temp1->next;
			s1->size--;
			free(temp1);
		}
		
		else 
			temp = temp->next;
	}
			
	if (!contains(s2, s1->first->value)){
		temp1=s1->first;
		s1->first = temp1->next;
		s1->size--;
		free(temp1);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node {
	item value;
	struct node *next;
};

list NewList(void)
{
	return NULL;
}

int EmptyList(list l)
{
	return l==NULL;
}

list ConsList(item val, list l)
{
	struct node *nuovo;
	nuovo=malloc(sizeof(struct node));
	if(nuovo!=NULL)
	{
		nuovo->value=val;
		nuovo->next=l;
		l=nuovo;
	}
	return l;
}

list TailList(list l)
{
	list temp;
	if(l!=NULL)
		temp=l->next;
	else
		temp=NULL;
	return temp;
}

item GetFirst(list l)
{
	item e;
	if(l!=NULL)
		e=l->value;
	else
		e=NULLITEM;
	return e;
}

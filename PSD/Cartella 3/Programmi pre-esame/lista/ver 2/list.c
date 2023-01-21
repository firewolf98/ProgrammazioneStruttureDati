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

int SizeList(list l)
{
	int n=0;
	while(!EmptyList(l))
	{
		n++;
		l=TailList(l);
	}
	return n;
}

int PosItem(list l,item value)
{
	int pos=0;
	int found=0;
	while(!EmptyList(l) && !found)
	{
		if(eq(GetFirst(l),val))
			found=1;
		else
		{
			pos++;
			l=TailList(l);
		}
	}
	if(!found)
		pos=-1;
	return pos;
}

list InputList(int n) 
{
	item val;
	list l=NewList();
	for(int i=0;i<n;i++)
	{
		printf("Elemento di posizione %d:\n",i);
		input_item(&val);
		l=ConsList(val,l);
	}
	return ReverseList(l);
}
	

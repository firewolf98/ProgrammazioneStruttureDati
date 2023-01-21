#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzionilibretto.h"

struct esame 
{
	char corso[20];
	int voto;
	Esame next;
};


Esame inserisciesame (char nome[],int val,Esame head)
{
	Esame nuovo=malloc(sizeof(struct esame));
	strcpy(nuovo->corso,nome);	
	nuovo->voto=val;
	nuovo->next=head;
	head=nuovo;
	return head;
}


Esame inseriscipos (char nome[],int val,int pos,Esame head)
{
	Esame nuovo=malloc(sizeof(struct esame));
	strcpy(nuovo->corso,nome);	
	nuovo->voto=val;
	Esame p=head;
	int i;
	while(p!=NULL && i<pos)
	{
		i++;
		p=p->next;
	}
	nuovo->next=p->next;
	p->next=nuovo;
	return head;
}


Esame cancellatesta (Esame head)
{
	Esame p=head;
	head=head->next;
	free(p);
	return head;
}


Esame cancellapos (int pos, Esame head)
{
	Esame temp=head;
	int i=0;
	while(temp!=NULL && i<(pos-1))
	{
		i++;
		temp=temp->next;
	}
	Esame p=temp->next;
	temp->next=temp->next->next;
	free(p);
	return head;
}



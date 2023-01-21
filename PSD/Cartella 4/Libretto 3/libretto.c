#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"
#include"lista.h"
#include"libretto.h"


struct libretto{
	int matricola;
	char nome[20];
	char cognome[20];
	list esami;
};

libretto newLibretto(int mat, char *n, char *c){
	struct libretto *l=malloc(sizeof(struct libretto));
	if(l!=NULL){
		l->matricola=mat;
		strcpy(l->nome, n);
		strcpy(l->cognome, c);
		l->esami=newList();
	}
	return l;
}

item cercaEsame(libretto l, char *c){
	if (l==NULL)
		return NULLITEM;
	item val=newItem(c, 0, "");
	int p=posItem(l->esami, val);
	if (p==-1)
		return NULLITEM;
	printf("%d ", p);
	return cloneItem(getItem(l->esami, p));
}


int addEsame(libretto l, item e, int pos){
	if (l==NULL)
		return 0;
	if (posItem(l->esami, e)!=-1)
		return 0;
	item x=cloneItem(e);
	if (x==NULLITEM)
		return 0;
	return insertList(l->esami, pos, x);
}

int outputLibretto(libretto l){
	if (l!=NULL){
		printf("Libretto\nMatricola %d\nCognome %s\nNome %s\nEsami sostenuti:\n", l->matricola, l->cognome, l->nome);
	outputList(l->esami);
	return 1;
	}
	return 0;
}

int cercaPos(libretto l, item e){
	int i=0, pos=0;
	item x;
	while (i<sizeList(l->esami)){
		x=getItem(l->esami, i);
		i++;
		if (getVoto(e)>getVoto(x))
			pos=i;
	}
	return pos;
}

int cercaPosL(libretto l, item e){
	char *c=getCorso(e);
	char *x;
	int i=0, pos=0, z, min;
	while(i<sizeList(l->esami)){
		x=getCorso(getItem(l->esami, i));
		z=0;
		int a, b;
		a=strlen(c);
		b=strlen(x);
		if (a<b)
			min=a;
		else 	min=b;
		while(z<min){
			if (c[z]>x[z]){
				pos=i+1;
				break;
			}
			if (c[z]==x[z])
				z++;
			if (c[z]<x[z])
				break;
		}
		i++;
	}
	printf("%d ", pos);
	return pos;
}
		
void sortLib(libretto l){
	sortList(l->esami);
}
 


	
		

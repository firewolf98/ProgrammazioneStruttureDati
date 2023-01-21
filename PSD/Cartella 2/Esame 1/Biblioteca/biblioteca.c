#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "BSTree.h"
#include "biblioteca.h"

struct biblioteca{
	char nome[20];
	BSTree libri;
};

biblioteca nuovaBiblioteca(char *nome){
	struct biblioteca *b = malloc(sizeof(struct biblioteca));
	if(b!=NULL){
		strcpy(b->nome, nome);
		b->libri=newBSTree();
	}
	return b;
}

int aggiungiLibro(biblioteca b, item lib){
	if(b==NULL)
		return 0;
	return insertBSTree(b->libri, lib);
}

int outputBiblioteca(biblioteca b){
	if(b!=NULL){
		printf("BIBLIOTECA\n\n");
		outputBSTree(b->libri);
		return 1;
	}
	return 0;
}


int aggiornaNumPrest(biblioteca b,char *codice){
	item l1=getItem(b->libri, codice);
	if(l1==NULL)
		return 0;
	aggiornaPrest(&l1);
}

int aggiornaNumDisp(biblioteca b,char *codice){
	item l1=getItem(b->libri, codice);
	if(l1==NULL)
		return 0;
	aggiornaDisp(&l1);
}

item cercaLibro(biblioteca b, char *codice){
	if (b==NULL)
		return NULL;
	return getItem(b->libri, codice);
}
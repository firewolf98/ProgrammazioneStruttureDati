#include <stdio.h>
#include "item.h"
#include "biblioteca.h"
#include "BSTree.h"

int main(){
	int i,num_libri;
	biblioteca b;
	item val;
	char codice[20], nome[20];
	int num_disp, num_prest;

	printf("Inserisci il nome della biblioteca: ");
	scanf("%s",nome);

	b=nuovaBiblioteca(nome);

	printf("Quanti libri vuoi inserire? ");
	scanf("%d",&num_libri);
	for(i=0;i<num_libri;i++){
		val=inputLibro();
		aggiungiLibro(b,val);
	}
	printf("\n\n\n");
	outputBiblioteca(b);

	printf("\n\n");

	printf("Inserisci il codice del libro da mandare in prestito: ");
	scanf("%s",codice);
	aggiornaNumPrest(b,codice);
	printf("\n\n\n");
	outputBiblioteca(b);

	printf("Inserisci il codice del libro che avevi mandato in prestito per riaverlo: ");
	scanf("%s", codice);
	aggiornaNumDisp(b,codice);
	printf("\n\n\n");
	outputBiblioteca(b);

	printf("Inserisci il codice del libro da cercare: ");
	scanf("%s",codice);
	val=cercaLibro(b,codice);
	outputLibro(val);
}
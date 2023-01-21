#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "../../../librerie/list.h"
#include "libretto.h"

struct libretto{
	char cognome[20];
	char nome[20];
	int matricola;
	list esami;
};

struct libretto *newLib ( char c[], char n[], int mat ){

	struct libretto *nuovo = malloc(sizeof(struct libretto));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->cognome, c);
		strcpy(nuovo->nome, n);
		nuovo->matricola = mat;
		nuovo->esami = newList();
	}
	 
	return nuovo;
}

int searchExam ( struct libretto *lib, char corso[] ){

	if ( lib == NULL )
		return -1;
	
	item val = newItem (corso, 0, "");
	int p = posItem(lib->esami, val);
	
	free ( val );
	if ( p != -1 )
		return 1;

	return 0;
}

int addExam ( struct libretto *lib, item es ){

	if ( lib == NULL )
		return -1;
		
	if (posItem(lib->esami, es) != -1)
		return -1;
		
	return (insertList(lib->esami, 0, es));
}

int outputLib ( struct libretto *lib ){

	if ( lib == NULL )
		return -1;
		
	printf("Cognome: %s\nNome: %s\nMatricola: %d\n", lib->cognome, lib->nome, lib->matricola);
	outputList(lib->esami);
	
	return 1;
}

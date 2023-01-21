#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "a_list.h"
#include "catalogo.h"

struct catalogo{
	char nome[20];
	list viaggio;
};

struct catalogo *newCatalogo( char c[] ){

	struct libretto *nuovo = malloc(sizeof(struct catalogo));
	
	if ( nuovo != NULL ){
		strcpy(nuovo->nome, c);
		nuovo->viaggio = newList();
	}
	 
	return nuovo;
}

int searchViaggio ( struct catalogo *c, char code[] ){

	if ( c == NULL )
		return -1;
	
	item val = newItem (code, "", "", 0, 0);
	int p = posItem(c->viaggio, val);
	
	free ( val );
	if ( p != -1 )
		return 1;

	return 0;
}

int addViaggio ( struct catalogo *c, item es ){

	if ( c == NULL )
		return -1;
		
	if (posItem(c->viaggio, es) != -1)
		return -1;
		
	return (insertList(p->viaggio, sizeList(p->viaggio), es));
}

int outputLib ( struct catalogo *p ){

	if ( lib == NULL )
		return -1;
		
	printf("NOME CATALOGO: %s, p->nome);
	outputList(p->viaggio);
	
	return 1;
}

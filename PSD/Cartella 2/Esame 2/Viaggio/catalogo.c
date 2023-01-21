#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "chainedHash.h"
#include "catalogo.h"
#define MAX 20

struct catalogo{
	char nome[20];
	hashtable viaggi;
};

catalogo nuovoCatalogo(char *nom){
	struct catalogo *nuovo = malloc(sizeof(struct catalogo));
	if(nuovo!=NULL){
		strcpy(nuovo->nome, nom);
		nuovo->viaggi=newHashtable(MAX);
	}
	
	return nuovo;
}

item cercaViaggio(catalogo c, char *cod){
	if(c==NULL)
		return NULLITEM;
	return searchHash(c->viaggi, cod);
}

int aggiungiViaggio(catalogo c, item v){
	if(c==NULL)
		return 0;
	return insertHash(c->viaggi, v);
}

int cancellaViaggio(catalogo c, char *cod){
	if(c==NULL)
		return 0;
	return deleteHash(c->viaggi, cod);
}

int outputCatalogo(catalogo c){
	if(c!=NULL){
		printf("CATALOGO VIAGGI\n\nNome: %s\n",c->nome);
		outputHash(c->viaggi);
		return 1;
	}
	return 0;
}

int modificaPrezzo(catalogo c, char *cod){
	if(c==NULL)
		return 0;
	int p;
	item v=searchHash(c->viaggi, cod);
	if(v!=NULLITEM){
		printf("Inserire prezzo da modificare: ");
		scanf("%d",&p);
		modPrezzo(&v, p);
		return 1;
	}

	return 0;
}

int modificaPosti(catalogo c, char *cod){
	int p;
	item v= searchHash(c->viaggi, cod);

	if(v!=NULLITEM){
		printf("Inserire posti da modificare: ");
		scanf("%d",&p);
		modPosti(&v,p);
		return 1;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaggio.h"
#include "chainedHash.h"
#include "catalogo.h"
#define MAX 20

struct catalogo{
	char nome_cat[20];
	hashtable viaggi;
};

catalogo NewCatalogo(char nome_cat[]) 
{
	struct catalogo *c=malloc(sizeof(struct catalogo));
	if(c!=NULL)
	{	
		strcpy(c->nome_cat,nome_cat);
		c->viaggi=newHashtable(MAX);
	}
	return c;
}

int AggiungiViaggio(catalogo c,viaggio v)
{
	if(c==NULL)
		return 0;
	else
		return insertHash(c->viaggi,v);
}

viaggio SearchViaggio(catalogo c,char cod[])
{
	if(c==NULL)
		return NULL;
	return searchHash(c->viaggi,cod);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaggio.h"
#include "catalogo.h"
#include "chainedHash.h"

int main ()
{
	int v,i;
	char nome_cat[20],cod[20];
	viaggio w;
	printf("Nome catalogo:\n");
	scanf("%s",nome_cat);
	catalogo c=NewCatalogo(nome_cat);
	printf("Quanti viaggi vuoi inserire?\n");
	scanf("%d",&v);
	for(i=0;i<v;i++)
	{
		w=InputViaggio();
		AggiungiViaggio(c,w);
	}
	printf("Inserisci il codice del viaggio da cercare:\n");
	scanf("%s",cod);	
	w=SearchViaggio(c,cod);
	if(w)
		OutputViaggio(w);
}

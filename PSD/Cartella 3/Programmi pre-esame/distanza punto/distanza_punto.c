#include <stdio.h>
#include <stdlib.h>
#include "punto.h"


int main()
{
	float d;
	int n,m;
	printf("Numero punti da caricare:\n");
	scanf("%d",&n);
	punto *a=malloc(n *sizeof(punto));
	if(a==NULL)
	{
		printf("Memoria insufficiente\n");
		exit(1);
	}
	inspto(a);
	printf("Inserisci distanza:\n");
	scanf("%f",&d);
	m=Coppie_Vicine(a,n,d);
	printf("Numero di coppie di punti con distanza minore di %f: %d\n",d,m);
}

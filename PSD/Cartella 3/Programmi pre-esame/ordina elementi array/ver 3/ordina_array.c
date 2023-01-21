#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

int main(int argc,char *argv[])
{
	if(argc<2)
		printf("Numero di elementi da ordinare mancante\n");
	else
	{
		int n=atoi(argv[1]);
		int *a=(int*)calloc(n,sizeof(int));
		if(a==NULL)
			printf("Memoria insufficiente\n");
		else 
		{
			input_array(a,n);
			ordina_array(a,n);
			printf("Elementi ordinati:\n");
			output_array(a,n);
		}
	}
}

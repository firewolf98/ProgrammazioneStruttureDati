#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

int main()
{
	int *a,n;
	printf("Quanti elementi vuoi ordinare?\n");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
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

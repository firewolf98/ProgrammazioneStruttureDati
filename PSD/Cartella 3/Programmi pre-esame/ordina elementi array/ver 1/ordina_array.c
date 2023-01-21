#include <stdio.h>
#include "vettore.h"
#define MAXELEM 100

int main()
{
	int a[MAXELEM],n;
	printf("Quanti elementi vuoi ordinare?\n");
	scanf("%d",&n);
	if(n<=0)
		printf("Il numero n deve essere positivo\n");
	else if(n>MAXELEM)
		printf("Deve essere minore di MAXELEM\n");
	else 
	{
		input_array(a,n);
		ordina_array(a,n);
		printf("Elementi ordinati:\n");
		output_array(a,n);
	}
}

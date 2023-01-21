#include <stdio.h>
#include <stdlib.h>
#include "../../librerie/ordinamento.h"
#include "../../librerie/intlib.h"

int main()
{
	int dim, *array, i, k;

	printf("Quanti elementi vuoi ordinare? ");
	scanf("%d", &dim);
	
	array=calloc(dim, sizeof(int));
	
	for ( i=0, k=0; i<dim; i++, k++){
		printf("Inserisci %d elemento: ", k);
		scanf("%d", &array[i]);
	}

	stampa_array(array, dim);
	Insertionsort(array, dim);
	stampa_array(array,dim);

	free(array);
}

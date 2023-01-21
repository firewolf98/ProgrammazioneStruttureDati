#include "intlib.h"
#include <stdio.h>
#include <stdlib.h>

#define n 10

int main()
{

int array[n], min, num, dim, sum, scalare;

		//dim conterrà la dimensione attuale dell'array	

	dim=inserisci(array, n);
	stampa_array(array,dim);

		//registro in dim la nuova dimensione dell'array

	dim=inserisci_pos(array, dim);
	stampa_array(array,dim);

		//registro in dim la nuova dimensione dell'array
	
	dim=rimuovi(array, dim);
	stampa_array(array,dim);

		//min conterrà il minimo fra gli elementi dell'array

	min=minimo(array, dim);
	printf("\n\nIl minimo e': %d \n\n", min);

		//cerco un elemento all'interno dell'array

	cerca(array, dim);

		//sum conterrà la somma degli elementi di un array

	sum=sum_array(array,dim);
	printf("\nLa somma degli elementi dell'array è: %d\n\n", sum);

		//dichiaro sum_input per registrare il secondo array i cui elementi verranno sommati a quelli di un altro array

int *sum_output, sum_input[dim];

		//registro gli elementi all'interno di input array

	input_array(sum_input, dim);  

		//sum output conterrà la somma posizione per posizione degli elementi di array[] e di input_array[]

	sum_output=sum_pos_array(sum_input, array,dim);
	stampa_array(sum_output, dim);

		//scalare è un intero che contiene la somma del prodotto scalare di elementi di due array

	scalare=prod_scalare(array, sum_input, dim);	
	printf("\n\nLa somma del prodotto scalare equivale a: %d\n", scalare);
	free(sum_output);
}

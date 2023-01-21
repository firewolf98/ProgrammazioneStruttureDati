#include <stdio.h>
#include <stdlib.h>
#include "intlib.h"
/* questa funzione ti permette di inserire elementi in un array di interi*/
void input_array (int array[], int dim)
{
int i, k;
	for(i=0, k=1;i<dim;i++, k++){
		printf("Inserisci il %d elemento: ", k);
			scanf("%d", &array[i]);
	}
}

/*questa funzione ti permette di stabilire quanti elementi vuoi inserire in un array e ti permette di riempirlo*/
void inserisci( int array[], int n)
{
/*int dim;
	do{
	printf("Quanti elementi vuoi inserire?");
	scanf("%d", &dim);
		if(dim>n)
		printf("Puoi inserire al massimo %d elementi!\n", n);
	}while(dim>n);*/
		for( int i=0;i<n;i++){
			printf("Inserisci elemento:");
			scanf("%d", &array[i]);
		}
}

//questa funzione ti permette di stampare un array di interi
void stampa_array ( int array [], int n)
{
printf("\nL'array e':\n");
	for( int i=0;i<n;i++)
		printf("%d||", array[i]);
}

int inserisci_pos ( int array[], int n)
{
int num, i, pos;
	printf("\n\nChe numero vuoi inserire? ");
	scanf("%d", &num);
	printf("In che posizione lo vuoi inserire? ");
	scanf("%d", &pos);
		for(i=n;i>=pos;i--)
			array[i]=array[i-1];
				array[pos-1]=num;
					n++;
return n;
}

//questa funzione ti fa rimuovere un elemento da un array di interi
int rimuovi ( int array[], int n )
{
int num, i, temp=0;
	printf("\n\nChe numero vuoi eliminare?");
	scanf("%d", &num);
		for(i=0;i<n;i++)
			if(array[i]==num) 
				temp=i;
					for(i=temp;i<n;i++)
						array[i]=array[i+1];
		n-=1;
return(n);
}

//questa funzione cerca qual è il minimo fra gli elementi di un array di interi
int minimo ( int array[], int n )
{
int min=array[0], i;

for ( i=1; i<n; i++ )
	if(array[i]<min) min=array[i];
return min;
}

void cerca ( int array[], int n)
{
int num, i, k;
printf("\nChe elemento vuoi cercare? ");
scanf("%d", &num);
		for(i=0, k=1;i<n;i++, k++){
			if(array[i]==num) 
				printf("L'elemento si trova in posizione %d\n", k);
			if(array[i]!=num) 
				printf("L'elemento non si trova in questa posizione!\n");
		}
}

//questa funzione somma gli elementi di un array di interi
int sum_array (int array[], int n)
{
int i, sum=0;
for(i=0;i<n;i++)
	sum+=array[i];
return sum;
}

//questa funzione genera un array che contiene la somma posizione per posizione di altri due array
int *sum_pos_array(int input1[], int input2[], int n)
{
int i, *output;
output=calloc(n,sizeof(int));
	for (i=0; i<n; i++)
		output[i]=input1[i]+input2[i];
return output;
}

//questa funzione effettua la somma dei prodotti scalari posizione per poszione degli elementi di un array di interi
int prod_scalare ( int input1[], int input2[], int n)
{
int i, temp, sum=0;
	for(i=0;i<n;i++){
		temp=input1[i]*input2[i];
			sum+=temp;
	}
return sum;
}

//questa fuznione effettua la ricerca di un elemeto all'interno di un array di interi ordinato
int ricerca_binaria( int array[], int n )
{
int num, f=n-1, i=0, m;
	printf("\nChe elemento vuoi cercare? ");
	scanf("%d", &num);

		while(i<=f){
			m=(f+i)/2;
				if(num==array[m])
					return(m);
				if(num<array[m])
					f=m-1;
				if (num>array[m])
					i=m+1;
		}
	return -1;
}

//questa funzione confronta due array e vede se sono uguali
int confronta_array ( int *array1, int *array2, int n)
{
	for (int i=0;i<n;i++){
		if(array1[i]==array2[i]){
			return 1;		
		}	
	}
	return 0;
}

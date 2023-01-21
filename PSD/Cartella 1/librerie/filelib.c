#include <stdio.h>
#include <stdlib.h>

//Questa funzione scrive un array di interi in un file
void infile ( FILE *uno, int *array, int n)
{
	int i;
	for(i=0;i<n;i++)
		fprintf(uno,"%d ", array[i]);
}

//questa funzione legge degli interi da un file
void outfile ( FILE *uno, int *array, int n)
{
	int i;
	for( i=0;i<n;i++)
		fscanf(uno, "%d", &array[i]);
}

//questa funzione ritorna il numero di interi in un file
int conta_in_file ( FILE *uno )
{
	int n=0, i;
	fscanf(uno,"%d", &i);
	while(!feof(uno))
	{
		fscanf(uno,"%d", &i);
		n++;
	}
	return n;
}



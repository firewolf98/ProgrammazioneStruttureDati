#include <stdio.h>
#include <stdlib.h>
#include "esame.h"
#include "studente.h"
#include "BSTree.h"

int main(int argc, char *argv[])
{
	
	int mat, n,i;
	char nom[20], cogn[20];
	studente s;
	item esame;
	FILE *input,*output;
	
	if(argc<3) 
	{
		printf("File input e/o output Mancante!\n");
		return 0;
	}
	
	input=fopen(argv[1],"r");
	fscanf(input,"%d %s %s",&mat,cogn,nom);
	
	s=newStudente(mat,cogn,nom);
	
	printf("Quanti esami ha sostenuto lo studente? ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		esame=inputEsame();
		aggiungiEsame(s, esame);
	}
	printf("\n\n\n");
	output=fopen(argv[2],"w");	
	outputStudente(s,output);
	fclose(input);
	fclose(output);
	
}

#include <stdio.h>
#include "item.h"
#include "studente.h"
#include "chainedHash.h"

int main(int argc, char *argv[]){
	
	int mat, n,i;
	char nom[20], cogn[20];
	studente s;
	item esame;
	
	printf("Inserisci matricola studente: ");
	scanf("%d", &mat);
	printf("Inserisci cognome studente: ");
	scanf("%s", cogn);
	printf("Inserisci nome studente: ");
	scanf("%s", nom);
	
	s=newStudente(mat,cogn,nom);
	
	printf("Quanti esami ha sostenuto lo studente? ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	esame=inputEsame();
	aggiungiEsame(s, esame);
		}
	printf("\n\n\n");
	
	outputStudente(s);
}

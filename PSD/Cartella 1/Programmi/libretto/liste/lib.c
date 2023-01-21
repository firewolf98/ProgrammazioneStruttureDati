#include <stdio.h>
#include "item.h"
#include "list.h"
#include "libretto.h"

int main(){

	char cognome[20], nome[20];
	int matricola;
	
	printf("Inserisci Cognome Nome e Matricola: \n");
	scanf("%s%s%d", cognome, nome, &matricola);
	lib nuovo = newLib(cognome, nome, matricola);
	item esame = inputItem();
	int ris = addExam(nuovo, esame);
	if(ris)
		printf("****SUCCESSO****\n");
	else 
		printf("****FALLITO****\n");
		
	outputLib(nuovo);
	
	printf("Che corso vuoi cercare? ");
	char corso[20];
	scanf("%s", corso);
	int res = searchExam(nuovo, corso);
	if(res)
		printf("******ESAME PRESENTE******\n");
	else 
		printf("******ESAME NON PRESENTE******\n");
}

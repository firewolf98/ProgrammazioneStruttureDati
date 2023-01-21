#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"esame.h"
#include"libretto.h"

int main()
{
	libretto lib;
	char cognome[20], nome[20], corso[20];
	int n, matricola, ris;

	printf("Inserisci il cognome dello studente: ");
	scanf("%s", cognome);
	printf("Inserisci il nome dello studente: ");
	scanf("%s", nome);
	printf("Inserisci la matricola dello studente: ");
	scanf("%d", &matricola);
	lib= newLibretto(matricola, nome, cognome);
	
	esame val;
	printf("INSERIMENTO ESAMI - TERMINA CON VOTO NON COMPRESO TRA 18 E 31 O SE NON SI PUO’ AGGIUNGERE ESAME A LIBRETTO \n");
	do {
		val = inputEsame();
		if (val!=NULLEXAM){
			ris=addEsame(lib, val);
			if (!ris)
				printf("Impossibile effettuare l'inserimento nel libretto\n");
		}
	}
	while(val!=NULLEXAM && ris);

	if(!outputLibretto(lib))
		printf("Impossibile visualizzare il libretto.");

	
	printf("Dammi esame da cercare: ");
	scanf("%s",corso);
	val=cercaEsame(lib, corso);
	if(val!=NULLEXAM)
		outputEsame(val); // stampo l’esame trovato
	else printf("Esame non trovato\n");
	return 0;
}



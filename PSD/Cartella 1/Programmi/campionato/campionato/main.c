#include <stdio.h>
#include "item.h"
#include "ADT.h"
#include "campionato.h"
#include "ordSet.h"

int main(){

//creo un nuovo campionato
	char name[20];
	printf("Inserisci nome campionato: ");
	scanf("%s", name);
	Campionato new = newCampionato(name);

//inserisco le squadre
		int ris;
	do{
		printf("\nInserisci 1 per inserire una squadre e 0 per uscire\n");
		scanf("%d", &ris);
		if(ris){
			int p = addSquadra(new);
				if (p){
					printf("SQUADRA INSERITA CON SUCCESSO!\n");
				}
				if( p == -1)
			printf("*****ATTENZIONE*****\nINSERIMENTO FALLITO, CONTROLLARE DI AVER INSERITO CORRETTAMENTE LA SQUADRA!\n");
		}

		else break;
	}while(ris == 1);

//stampo il campionato
	printf("\nStampo campionato in ordine alfabetico: \n");
	outputCampionato(new);

//cerco giocatore
	printf("\nChe squadra vuoi cercare? ");
	char nome[20];
	scanf("%s", nome);
	item a = searchSquadra(new, nome);
	if ( a!= NULL)
		outputItem(a);
	else printf("SQUADRA NON PRESENTE!\n");
	
	printf("\n****INSERIMENTO PARTITA****\n");
	char squadra1[20], squadra2[20];
	int goal1, goal2;
	printf("Inserisci squadra 1: ");
	scanf("%s", squadra1);
	printf("Inserisci squadra 2: ");
	scanf("%s", squadra2);
	printf("Inserisci punteggio: ");
	scanf("%d%d", &goal1, &goal2);
	updateCampionato(new, squadra1, squadra2, goal1, goal2);
	printf("\nStampo la classifica in ordine di punteggio: \n");
	set t = outputPoints(new);
	outputSet(t);
}


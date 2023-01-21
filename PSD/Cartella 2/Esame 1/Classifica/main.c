#include <stdio.h>
#include "item.h"
#include "set.h"
#include "classifica.h"
#include "BSTree.h"

int main(){
	char nome[20], nome_squadra[20];;
	int i,num_squadre, reti_squadra1, reti_squadra2;
	item val;
	char nome_squadra1[20], nome_squadra2[20];
	set s=newSet();

	printf("Inserisci nome classifica: ");
	scanf("%s",nome);

	classifica c=nuovaClassifica(nome);

	printf("Quante squadre vuoi inserire? ");
	scanf("%d",&num_squadre);

	for(i=0;i<num_squadre;i++){
		val=inputSquadra();
		aggiungiSquadra(c,val);
	}
	printf("\n\n\n\n");
	printf("CLASSIFICA AGGIORNATA PER SQUADRE:\n\n\n");
	outputClassifica(c);

	printf("Inserisci i dati dell'ultima partita (squadra1, squadra2, goal1, goal2): ");
	scanf("%s %s %d %d",nome_squadra1,nome_squadra2,&reti_squadra1,&reti_squadra2);
	aggiorna(c,nome_squadra1,nome_squadra2,reti_squadra1,reti_squadra2);
	outputClassifica(c);

	printf("CLASSIFICA AGGIORNATA PER PUNTI:\n");
	s=ordinaClassifica(c);
	
	outputSet(s);

	printf("Inserisci il nome della squadra di cui vuoi trovare le statistiche: ");
	scanf("%s",nome_squadra);
	val=cercaSquadra(c,nome_squadra);
	if(val!=NULL)
		output_Squadra(val);
	else 
		printf("Squadra non trovata.");
}
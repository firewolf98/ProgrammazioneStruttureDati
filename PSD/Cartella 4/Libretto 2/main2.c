#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"
#include"lista.h"
#include"libretto.h"


int main (){
	libretto lib;
	char cognome[20], nome[20], corso[20];
	int n, matricola;

	printf("Inserisci il cognome dello studente: ");
	scanf("%s", cognome);
	printf("Inserisci il nome dello studente: ");
	scanf("%s", nome);
	printf("Inserisci la matricola dello studente: ");
	scanf("%d", &matricola);
	lib= newLibretto(matricola, nome, cognome);
	
	printf("Quanti esami vuoi inserire? ");
	scanf("%d", &n);
	item e;
	int pos;
	for (int i=0;i<n;i++){
		e=input_item();
		pos=cercaPosL(lib, e);
		//pos=cercaPos(lib, e);
		addEsame(lib, e, pos);
	}
	
	outputLibretto(lib);
	
	printf("inserisci l'esame da cercare: ");
	scanf("%s", corso);
	item val=cercaEsame(lib, corso);
	if (val!=NULLITEM)
		output_item(val);
	else
		printf("Esame non trovato\n"); 
	return 0;
}
		
		
	

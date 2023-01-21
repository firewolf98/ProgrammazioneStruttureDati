#include <stdio.h>
#include "menu.h"

int menu(){
	int scelta;
	printf("***GESTIONE LISTA***\n");
	printf("[1] Crea una lista\n");
	printf("[2] Controlla che la lista sia vuota\n");
	printf("[3] Dimensione lista\n");
	printf("[4] Ricerca la posizione di un elemento\n");
	printf("[5] Fai la reverse della lista\n");
	printf("[6] Duplica la lista\n");
	printf("[7] Inserisci un elemento alla lista\n");
	printf("[8] Elimina un elemento dalla lista\n");
	printf("[9] Cancella la lista\n");
	printf("[0] Esci\n\n");
	printf("Scelta: ");
	scanf("%d", &scelta);
	while(scelta < 0 || scelta > 10){
		printf("Scelta non valida!\n");
		printf("Inserisci un'altra scelta: ");
		scanf("%d", &scelta);
		return scelta;}
	return scelta;
}

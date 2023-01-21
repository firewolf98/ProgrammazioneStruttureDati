#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "playlist.h"

int main(){
	printf("BENVENUTO!\n");
	char title[20], autor[20];
	int a, ris;
	item e, es, res, i;
	playlist p = newPlaylist(100);

	do{
		printf("\nInserisci 1 per inserire una canzone\n");
		printf("Inserisci 2 per cercare una canzone\n");
		printf("Inserisci 3 per rimuovere una canzone\n");
		printf("Inserisci 0 per uscire dal programma\n");
		scanf("%d", &ris);
		
		if (ris == 1){
			int x = insertPlaylist(p);
			if ( p )
				printf("\n******INSERIMENTO EFFETTUATO*******\n");
			else
				printf("\n******ERRORE DURANTE L'INSERIMENTO DELLA CANZONE*******\n");
		}
		else if (ris == 2){
			printf("\nChe canzone vuoi cercare? ");
			char song[20];
			scanf("%s",song);
			res = searchPlaylist(p,song);
			if (res != NULL)
				outputItem(res);
			else if ( res == NULL )
				printf("\n*****CANZONE NON PRESENTE NELLA PLAYLIST!*****\n");
		}
		else if(ris == 3){
			printf("\nChe canzone vuoi eliminare? ");
			char song[20];
			scanf("%s", song);
			int result = removePlaylist(p, song);
			if ( result )
				printf("\n******RIMOZIONE EFFETTUATA*******\n");
			else
				printf("\n******ERRORE DURANTE LA RIMOZIONE DELLA CANZONE*******\n");
		}
		
	}while(ris != 0);
	
	printf("\n***ARRIVEDERCI***\n");
	return 0;
}

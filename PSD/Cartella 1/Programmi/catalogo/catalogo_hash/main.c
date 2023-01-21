#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "catalogo.h"

int main(){
	printf("BENVENUTO!\n");
	char codice[20];
	char localita[20];
	char nome[20];
	int durata;
	int prezzo;
	int posti;
	int a, ris;
	item e, es, res, i;
	catalogo p = newCatalogo(100);

	do{
		printf("\nInserisci 1 per inserire un viaggio\n");
		printf("Inserisci 2 per cercare un viaggio\n");
		printf("Inserisci 3 per rimuovere un viaggio\n");
		printf("Inserisci 4 per modificare un viaggio\n");
		printf("Inserisci 0 per uscire dal programma\n");
		scanf("%d", &ris);
		
		if (ris == 1){
			int x = insertCatalogo(p);
			if ( x )
				printf("\n******INSERIMENTO EFFETTUATO*******\n");
			else
				printf("\n******ERRORE DURANTE L'INSERIMENTO DEL VIAGGIO*******\n");
		}
		else if (ris == 2){
			printf("\nInserisci il codice del viaggio che vuoi cercare: ");
			char code[20];
			scanf("%s",code);
			res = searchCatalogo(p, code);
			if (res != NULL)
				outputItem(res);
			else if ( res == NULL )
				printf("\n*****VIAGGIO NON PRESENTE NEL CATALOGO*****\n");
		}
		else if(ris == 3){
			printf("\nInserisci il codice del viaggio che vuoi eliminare: ");
			char code[20];
			scanf("%s", code);
			int result = removeCatalogo(p, code);
			if ( result == 1)
				printf("\n******RIMOZIONE EFFETTUATA*******\n");
			else
				printf("\n******ERRORE DURANTE LA RIMOZIONE DEL VIAGGIO*******\n");
		}
		else if (ris == 4){
			int r;
			printf("\n\nScegli 1 per modificare il prezzo e 2 per modificare i posti: ");
			scanf("%d", &r);
			if(r==1){
				char codice_viaggio[20];
				int prezzo_viaggio;
				printf("\nInserire il codice del viaggio del quale si vuole modificare il prezzo: ");
				scanf("%s", codice_viaggio);
				item v = searchCatalogo(p,codice_viaggio);
				if(v){
					outputItem(v);				
					printf("\n\nInserire il prezzo: ");
					scanf("%d", &prezzo_viaggio);
					int l = updatePrezzo(p,codice_viaggio,prezzo_viaggio);
					if(l){
						printf("\n*****MODIFICA EFFETTUATA*****\n");
						outputItem(searchCatalogo(p,codice_viaggio));
					}
					else{
						printf("\n*****MODIFICA FALLITA*****\n");
						return 0;
					}
				}
				else
					printf("\n*****VIAGGIO NON PRESENTE NEL CATALOGO*****\n");
			}
			if(r==2){
				char codice_viaggio[20];
				int posti_viaggio;
				printf("\nInserire il codice del viaggio del quale si vogliono modificare i posti: ");
				scanf("%s", codice_viaggio);
				item v = searchCatalogo(p,codice_viaggio);
				if(v){
					outputItem(v);
					printf("\n\nInserire i posti: ");
					scanf("%d", &posti_viaggio);
					int l = updatePosti(p,codice_viaggio,posti_viaggio);
					if(l){
						printf("\n*****MODIFICA EFFETTUATA*****\n");
						outputItem(searchCatalogo(p,codice_viaggio));
					}
					else{
						printf("\n*****MODIFICA FALLITA*****\n");
						return 0;
					}
				}
				else
					printf("\n*****VIAGGIO NON PRESENTE NEL CATALOGO*****\n");	
			}
		}
				
	}while(ris != 0);
	
	printf("\n***ARRIVEDERCI***\n");
	return 0;
}

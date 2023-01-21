#include<stdio.h>
#include"item.h"
#include"catalogo.h"
#include"chainedHash.h"

int main (){
	item val;
	int n;
	char nome[20], cod[20];
	int ris;

	printf("Inserisci il nome del catalogo: ");
	scanf("%s", nome);
	catalogo c=nuovoCatalogo(nome);
	
	printf("Quanti viaggi vuoi inserire? ");
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		val=input_Viaggio();
		aggiungiViaggio(c, val);
	}
	printf("\n\n\n\n");
	outputCatalogo(c);	
	printf("\n\nInserire codice del viaggio da cercare: ");
	scanf("%s", cod);
	val=cercaViaggio(c, cod);
	if (val!=NULL)
		output_Viaggio(val);
	else
		printf("Viaggio non trovato\n");


	printf("\n\nInserisci codice del viaggio da cancellare: ");
	scanf("%s", cod);
	ris=cancellaViaggio(c, cod);
	if (ris==0)
		printf("Viaggio non trovato\n");
	else 
		printf("Viaggio cancellato\n");

	printf("\n\nInserire codice del viaggio a cui cambiare prezzo: ");
	scanf("%s", cod);
	ris=modificaPrezzo(c, cod);
	if (ris==1){
		printf("Modifica riuscita: \n");
		outputCatalogo(c);
	}
	else printf("Viaggio non trovato\n");
	
	printf("\n\n\n\n");
	printf("Inserire codice del viaggio a cui cambiare numero posti: ");
	scanf("%s", cod);
	ris=modificaPosti(c, cod);
	if (ris==1){
		printf("Modifica riuscita: \n");
		outputCatalogo(c);
	}
	else printf("Viaggio non trovato\n");
}

		

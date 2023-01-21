#include <stdio.h>
#include <stdlib.h>
#include "fun_libretto.h"


int main (){
	/*struct esame *lib = maccol(sizeof(struct esama));
	lib->esame;                       ERRORE DI DEREFERNZAZIONE */
	Esame head = NULL;		//inserito fuori dal "while" perchè altrimenti ogni volta che entro nel ciclo mi riparte da 0
	int sizeList = 0;
	while(1){
		int sel = 0;
		printf("Inserisci 1 per inserire l'esame in testa\n");
		printf("Inserisci 2 per inserire l'esame al cento\n");
		printf("Inserisci 3 per eliminare l'esame in testa\n");
		printf("Inserisci 4 per eliminare l'esame al centro\n");
		printf("Inserisci 5 per effettuare bubblesort\n");
		scanf("%d", &sel);
		if(sel == 1){
			char esame[20];
			int voto = 0;
			printf("Nome esame: \n");
			scanf("%s", esame);		
			printf("Inserire voto: \n");
			scanf("%d", &voto);
			head = inserisciEsame(esame, voto, head); //l'"head" passato sarà il secondo elemento della lista	
			if(head != NULL)
				sizeList++; 
		}				
		else if(sel == 2){
			char esame[20];
			int voto = 0;
			int pos = 0;
			printf("Inserire nome esame: \n");
			scanf("%s", esame);		
			printf("Inserire voto: \n");
			scanf("%d", &voto);
			printf("Inserisci la posizione: \n");
			scanf("%d", &pos);
			if(pos < sizeList){
				head = inserisciCentro(esame, voto, pos, head/*per scorrere lista*/);
				sizeList++;
			}
			else
				printf("ERRORE: la posizione inserita non è corretta\n");
		}
		else if(sel == 3){
			if(sizeList > 0){
				head = cancellaTesta(head);
				sizeList--;
			}
		}
		else if(sel == 4){
		int pos = 0;
			printf("Inserisci la posizione: \n");
			scanf("%d", &pos);
			if(pos > 0){
				head = cancellaCentro(pos, head);
				//sizeList--;
			}
		}
		else if(sel == 5)	
			head = bubbleSort(head);
	}
	return 0;
}

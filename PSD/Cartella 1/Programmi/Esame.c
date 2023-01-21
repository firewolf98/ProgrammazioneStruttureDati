#include <stdio.h>
#include <stdlib.h>
#include "../librerie/ADTesame.h"

int main(int argc, char const **argv){

	Esame head = NULL;
	int sizeList = 0;
	
	while(1){
		int sel=0;

		printf("Inserisci 1 per inserire in testa.\n");
		printf("Inserisci 2 per inserire in testa.\n");
		printf("Inserisci 3 per eliminare in testa.\n");
		printf("Inserisci 4 per eliminare in testa.\n");
		printf("Inserisci 5 per uscire.\n");
		scanf("%d", &sel);
		
		if(sel==1){
			char esame[20];
			int voto;
			printf("Nome esame: ");
			scanf("%s", esame);
			printf("Inserire voto: ");
			scanf("%d", &voto);
			head=inserisciEsame(esame, voto, head);
			
				if(head!= NULL)
					sizeList++;
		}
	
		if ( sel==2 ){
			int voto = 0;
			int pos = 0;
			char esame[20];
			printf("Nome esame: ");
			scanf("%s", esame);
			printf("Inserire voto: ");
			scanf("%d", &voto);
			printf("Inserisci la posizione: ");
			scanf("%d", &pos);
				if (pos<sizeList){
					head = inserisciCentro(esame, voto, pos, head);
					sizeList++;
				}
		}

		if ( sel==3){
			head = cancellaTesta(head);
			sizeList--;
		}

		if ( sel == 4 ){
			if(sizeList > 0){
				int pos=0;
				printf("Inserisci la posizione: ");
				scanf("%d", &pos);
				if(pos>0 && pos <sizeList)
				head = cancellaCentro(head, pos);
			}
		}
		
		if( sel == 5 ) return 0;

	}

	return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "item.h"
#include "list.h"

int main (){
	int scelta;
	int stampa, boolean, dim, n, pos, el, ris;
	item val;
	list l, rl, cl;
	while(scelta = menu()){
		switch(scelta){	
			case 1:
				printf("Quanti elementi deve contenere la tua lista?\n");
				scanf("%d", &n);
				l = inputList(n);
				printf("STAMPA:\n");
					if(!outputList(l))
						printf("Stampa non riuscita\n");
				break;
			case 2:
				boolean = emptyList(l);
				break;
			case 3:
				dim = sizeList(l);
				printf("La lista ha dimensione %d\n", dim);
				break;
			case 4:
				printf("Quale elemento vuoi cercare?\n");
				scanf("%d", &val);
				pos = posItem(l, val);
				printf("L'elemento che stavi cercando si trova nella posizione %d\n", pos);
				break;
			case 5:
				if(reverseList2(l)){
					if(!outputList(l))
						printf("Stampa non riuscita");
				}
				break;
			case 6:
				cl = cloneList(l);
				break;
			case 7:
				printf("Quale elemento vuoi inserire e in quale posizione?\n");
				scanf("%d\t%d", &el, &pos);
				ris = insertList(l, pos, el);
				if(ris != 0)
					stampa = outputList(l);
				break;
			case 8:
				printf("In quale posizione vuoi eliminare l'elemento?\n");
				scanf("%d", &pos);
				ris = removeList(l, pos);
				stampa = outputList(l);
				break;
			case 9:
				destroyList(&l);
				break;
			case 0:
				return 0;}
			}
	return 0;
}
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				

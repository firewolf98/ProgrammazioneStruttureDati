#include <stdio.h>
#include "../../librerie/item.h"
#include "../../librerie/list.h"




int main(){
	
	list vect=newList();

	if(!emptyList(vect))
		printf("La lista è vuota!\n");

	vect=inputList(5);

	if(emptyList(vect))
		printf("La lista non è vuota!\n");
	
	printf("1\n");
	
	outputList(vect);
	
	printf("\nLa lunghezza della lista è: %d\n", sizeList(vect));

	printf("2\n");
		
	item valore=getItem(vect, 4);
	outputItem(&valore);
	
	printf("3\n");

	insertList(vect,3,7);

	outputList(vect);

	removeList(vect,2);

	printf("4\n");

	outputList(vect);
	
	list vect1 = reverseList1(vect);
	
	printf("5\n");
	
	outputList(vect1);
	
	printf("6\n");

	reverseList2(vect);
	
	outputList(vect);
	
	printf("7\n");	

	//deleteList(vect);

	//outputList(vect);
	
	list a = cloneList(vect);
	
	outputList(a);
	
	printf("8\n");

	destroyList(&vect);
	
	destroyList(&a);
	
	

}
	
	
	
	

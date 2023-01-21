#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

struct song{
	char titolo[20];
	char autore[20];
	char durata[20];
};



Song inputSong (){
	char t[20], a[20], d[5];
	
	printf("*****INSERIMENTO CANZONE*****");
	printf("\nTitolo: ");
	scanf("%s", t);
	printf("Autore: ");
	scanf("%s", a);
	printf("Durata: ");
	scanf("%s", d);
	
	struct song *new = malloc(sizeof(struct song));
	
	if ( new == NULL )
		return NULL;
		
	else {
		strcpy (new->titolo, t);
		strcpy (new->autore, a);
		strcpy (new->durata, d);
	}
	
	return new;
}

int eq ( struct song *a, struct song *b ){

	if(strcmp(a->titolo, b->titolo) != 0) 
		return 0;
	else if (strcmp(a->autore, b->autore) != 0)
		return 0;
	else if (strcmp(a->durata, b->durata) != 0)
		return 0;
		
	return 1;
}

void outputSong ( Song a ){

	printf("Titolo: %s\nAutore: %s\nDurata: %s\n", a->titolo, a->autore, a->durata);
}

int searchAutore ( Song s, char a[] ){
	if(strcmp(s->autore, a)==0)
		return 1;
	return 0;
}
void destroySong ( Song *a ){

	free(*a);
	*a = NULL;
}

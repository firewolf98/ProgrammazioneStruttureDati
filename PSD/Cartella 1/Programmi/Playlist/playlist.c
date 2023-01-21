/*
Si implementi, mediante l’uso di opportune strutture dati, un programma per la gestione di playlist musicali.
Ogni playlist tiene traccia di una sequenza di canzoni ognuna caratterizzata dal titolo, dal nome del cantante
(o gruppo musicale) e dalla durata della canzone in secondi. Specificare e realizzare l’ADT playlist che dovrà
fornire operatori per:
• creare una playlist;
• inserire una canzone in coda ad una playlist;
• rimuovere una canzone da una playlist, data la sua posizione;
• spostare in avanti (forward) la canzone che nella playlist occupa la posizione i, scambiandola con la
canzone in posizione i+1;
• spostare all’indietro (back) la canzone che nella playlist occupa la posizione i, scambiandola con la
canzone in posizione i-1;
• estrarre da una playlist la sottoplaylist composta da tutte le canzoni di un determinato cantante;
• visualizzare una playlist.
Inserire la specifica degli operatori come commenti nell’header file del modulo che implementa l’ADT
playlist.
Il programma di test dovrà verificare la corretta implementazione della struttura dati playlist.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "playlist.h"

struct playlist{
	Song *array;
	int size;
	int dim;
};

struct playlist *newPlaylist (){

	struct playlist *new = malloc(sizeof(struct playlist));
	
	if ( new != NULL ){
		new->size = 0;
		new->dim = 50;
		new->array = calloc(new->dim, sizeof(Song));
	}
	
	return new;
}

int newSong ( Playlist p ){

	if ( p == NULL )
		return 0;
	
	if ( p->size == p->dim ){
		Song *temp = realloc(p->array,(p->dim+20)*sizeof(Song));
			
		if ( temp == NULL )
			return 0;
				
		p->array = temp;
		p->dim+=20;
	}
	
	Song new = inputSong();
	
	for (int i = 0; i < p->size; i++ ){
		if(eq(p->array[i], new)==1)
			return 0;
	}
	
	p->array[p->size] = new;
	p->size++;
	
	return 1;
}

int forwardSong ( Playlist p, int pos ){

	if ( p == NULL )
		return 0;
		
	if (pos == p->size-1)
		return 0;
		
	Song temp;
	
	temp = p->array[pos];
	p->array[pos] = p->array[pos+1];
	p->array[pos+1] = temp;
	//destroySong(&temp);
	
	return 1;
}

int backSong ( Playlist p, int pos ){
	
	if ( p == NULL )
		return 0;
	
	if(pos == p->size)
		return 0;
	
	Song temp;
	temp = p->array[pos-1];
	p->array[pos-1] = p->array[pos];
	p->array[pos] = temp;
	//destroySong(&temp);
	
	return 1;
}

struct playlist *subPlaylist ( Playlist p, char a[] ){

	if ( p == NULL )
		return NULL;
		
	struct playlist *sub = newPlaylist();
	
	int i, k;
	for ( i = 0, k = 0; i < p->size; i++ ){
		if(searchAutore(p->array[i], a)==1){
			sub->array[k] = p->array[i];
			sub->size++;
			k++;
		}
	}
	return sub;
}

int outputPlaylist ( Playlist p ){
	
	if ( p == NULL )
		return 0;
	int i;
	for ( i = 0; i < p->size; i++ )
		outputSong(p->array[i]);
		
	return 1;
}

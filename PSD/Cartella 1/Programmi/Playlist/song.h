/*
SPECIFICA ADT SONG:

	-TIPO:
		SINTATTICA:
			TIPI DI RIFERIMENTO: song
			TIPI USATI: boolean, integer, string
		SEMANTICA:
			Song è la terna formata da: <titolo, autore, durata>
	
	-OPERATORI:
		SINTATTICA:
			-inputSong()-> song
			-eq(song, song)-> boolean
			-outputSong(song)-> song
			-destroySong(song *)-> song
		SEMANTICA:
			-inputSong()-> song a'
				POST: a' = <string b>
			-eq(song a, song b)-> boolean c
				POST: se a = b, allora c=1, altrimenti c = 0
			-outputSong(song a)-> song a'
				PRE: a = <string b>
				POST: printa a schermo la canzone 
			-searchAutore(song a, string b)-> autore c
				-POST: se b appartiene ad a allora c = a 
			-destroySong(song *a)-> song a'
				POST: *a = NULL AND a' = NULL
*/

typedef struct song *Song;

Song inputSong (); //alloca una canzone e la riempie
int eq ( Song , Song ); //restituisce 1 se le canzoni sono uguali, altrimenti 0
void outputSong ( Song ); //stampa una canzone
int searchAutore ( Song s, char a[] ); //controlla se l'autore di una canzone corrisponde all'autore di input
void destroySong ( Song * ); //dealloca lo spazio per una canzone

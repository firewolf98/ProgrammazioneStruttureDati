/*
SPECIFICA ADT PLAYLIST

	-TIPO:
		SINTATTICA:
			TIPI DI RIFERIMENTO: playlist
			TIPI USATI: boolean, integer, stringa, song
		SEMANTICA:
			Playlist è la terna formata da: <canzoni, dimensione, buffer>
			
	-OPERATORI:
		-SINTATTICA:
			-newPlaylist()-> playlist
			-newSong (playlist)-> playlist
			-forwardSong(playlist, song)-> playlist
			-backSong(playlist, song)-> playlist
			-subPlaylist(playlist, string)-> playlist
			-outputPlaylist(playlist)-> playlist
		-SEMANTICA:
			-newPlaylist()-> playlist p
				POST: p != nil
			-newSong (playlist l )-> playlist l'
				PRE: a non appartiene ad l
				POST: l = <l1, l2, .., ln> AND l' = <l1, l2,.., a> AND l' != nil
			-forwardSong(playlist l, song a)-> playlist l'
				POST: l = <l1, a, l3, .., ln> AND l' = <l1, l3, a, .., ln>
			-backSong(playlist, song)-> playlist
				POST: l = <l1, l2, a, .., ln> AND l' = <l1, a, l2, .., ln>	
			-subPlaylist(playlist l, string a)-> playlist l'
				POST: se a appartiene ad l allora l' sarà l'insieme della canzoni il cui autore è a
			-outputPlaylist(playlist)-> playlist
				PRE: l != nil
*/

typedef struct playlist *Playlist;

Playlist newPlaylist (); //alloca una playlist 
int newSong ( Playlist ); //aggiunge una canzone in coda alla playlist, restituisce 1 se l'operazione è andata a buon fine, altrimenti 0
int forwardSong ( Playlist, int ); //fa avanzare la canzone di una posizione, restituisce 1 se l'operazione è andata a buon fine, altrimenti 0
int backSong ( Playlist, int ); //fa regredire la canzone di una posizione, restituisce 1 se l'operazione è andata a buon fine, altrimenti 0
Playlist subPlaylist ( Playlist, char[] ); //crea una sottoplaylist composta dalle canzoni di un preciso autore
int outputPlaylist ( Playlist ); //stampa la playlist, restituisce 1 se l'operazione è andata a buon fine, altrimenti 0

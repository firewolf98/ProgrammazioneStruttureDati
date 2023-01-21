/* 		SPECIFICHE ADT PLAYLIST

	SINTATTICA:
		-Tipo di riferimento: playlist
		-Tipi usati: integer, item, string
		
		-Operatori:
			-newPlaylist (integer)-> playlist
			-insertPlaylist (playlist, string)-> playlist
			-searchPlaylist (playlist, string)-> item
			-removePlaylist (playlist, string)-> playlist
	
	SEMANTICA:
		-Tipo: playlist è un insieme di canzoni
		
		-Operatori:
			-newPlaylist(a)-> p
				POST: p = {}
			-insertPlaylist(p)-> p'
				PRE: p = {T1, T2..,Tn}
				POST: p' = pU{Ti}
			-searchPlaylist(p, c)-> e
				POST: se c è il nome di una canzone Ti appartenente a p allora e = Ti
			-removePlaylist(p, c)-> p'
				PRE: p = {T1, T2,..,Tn}
				POST: se c è il nome di una canzone Ti appartenente a "p" allora p' = p-{Ti}
*/
typedef struct hash *banca;

banca newBanca (int); //crea una nuova playlist
int insertConto (banca); //inserisce una canzone nella playlist
item searchConto (banca, char []); //cerca una canzone nella playlist
int removeConto (banca, char []); //rimuove una canzone dalla 
item deposita(banca, char[], int); //deposita una somma di denaro in un conto

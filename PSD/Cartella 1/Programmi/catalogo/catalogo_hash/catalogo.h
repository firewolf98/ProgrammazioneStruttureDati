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
typedef struct hash *catalogo;

catalogo newCatalogo (int); //crea una nuova playlist
int insertCatalogo (catalogo); //inserisce una canzone nella playlist
item searchCatalogo (catalogo, char []); //cerca una canzone nella playlist
int removeCatalogo (catalogo, char []); //rimuove una canzone dalla playlist
int updatePosti(catalogo, char[], int);
int updatePrezzo(catalogo, char[], int);

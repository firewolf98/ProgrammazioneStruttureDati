/*	SPECIFICA ADT HASH TABLE

	-SINTATTICA: 
		Tipo di riferimento: htable
		Tipi usati: boolean, key, item
	
		-Operatori:
			-newHash()-> htable
			-insertHash(htable, key, item)-> htable
			-searchHash(htable, key)-> item
			-removeHash(htable, key)-> htable
			
	-SEMANTICA:
		Tipo: htable è l'insieme di elementi di tipo item che sono caratterizzati da una chiave univoca
		
		-Operatori:
			-newHash()-> h
				POST: h = {}
			-insertHash(h, k, e)-> h'
				PRE: h = {T1, T2..,Tn} AND key(Ti) != k con i=1..n
				POST: h' = hU{e}
			-searchHash(h, k)-> e
				POST: se key(Ti) = k AND Ti appartiene ad h, allora e = Ti
			-removeHash(h, k)-> h'
				POST: h = {T1, T2,..,Tn}, se key(Ti) = k allora h' = h-{Ti}
*/
typedef struct hash *htable;
//typedef char *key;

htable newHash(); //crea una nuova tabella
int insertHash(htable, item, key k); //aggiunge l'item alla tabella
item searchHash(htable, key); //cerca un elemento all'interno della tabella attraverso la sua chiave
int removeHash(htable, key); //rimuove l'elemento della tabella attraverso la sua chiave

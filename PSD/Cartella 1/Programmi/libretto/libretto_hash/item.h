/* 		SPECIFICA ITEM
	-SINTATTICA:
		tipo di riferimento: item
		tipi usati: string, integer, boolean
		
		-Operatori:
			-newItem ()-> item
			-inputItem (string, string, integer)-> item
			-cmp (item, item)-> boolean
		
	-SEMANTICA:
		-Tipo: item è la tripla formata da: <titolo, autore, anno>
		
		-Operatori: 
			-newItem ()-> e
				POST: e = <vuoto, vuoto, vuoto>
			-inputItem (a, a1, n)-> e
				POST: e = <a, a1, n>
			-cmp (a, a1)-> b
				POST: se a = a1 allora b = TRUE, altrimenti b = FALSE				
*/
typedef struct canzone *item;

#define NULLITEM NULL

item inputItem (); //fa l'input dei campi dell'item
int cmp (char *, char *); //compara due item
char *getISBN (item); //ritorna il campo titolo dell'item
int getCopie (item); //ritorna il campo autore dell'item
void outputItem (item); //stampa a video un item
void destroyItem ( item *a); //dealloca un item

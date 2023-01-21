/*
SPECIFICA ITEM
	-TIPO:
		SITNATTICA:
			-TIPO DI RIFERIMENTO: item;
			-TIPI USATI: integer, boolean, string
		-SEMANTICA: 
			Item è la quintupla formata da <nome squadra, partite, punti, reti, goal subiti>

	-OPERATORI:
		SINTATTICA:
			-newIitem(string, integer, integer, integer, integer)-> item
			-inputItem()-> item
			-outputItem( item )-> item
			-eq(item, item)-> boolean
			-destroyItem(item *)
		SEMANTICA:
			-newIitem(string a, integer b, integer c, integer d, integer e)-> item f
				POST: f = <a, b, c, d>
			-inputItem()-> item a
				POST: a non è vuoto
			-outputItem( item )-> item
				POST: stampa un item a video
			-eq(item a, item b)-> boolean c
				POST: se a = b, alloc c=1, altrimenti c = 0
			-destroyItem(item *a)
				POST: *a è vuoto
*/
typedef struct squadra *item;

#define NULLITEM NULL

item newItem ( char name[], int match, int points, int goal, int sub); //alloca un item e riempie i suoi campi
item inputItem (); //permette di inserire un item
void outputItem ( item a ); //stampa un item
int eq( item a, item b ); //confronta se due item sono uguali
int eq1 (item a, item b); //confronta un campo di due item
void destroyItem ( item *a ); //dealloca un item

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
		SEMANTICA:
			-newIitem(string a, integer b, integer c, integer d, integer e)-> item f
				POST: f = <a, b, c, d>
			-inputItem()-> item a
				POST: a non è vuoto
			-outputItem( item )-> item
				POST: stampa un item a video
			-eq(item a, item b)-> boolean c
				POST: se a = b, alloc c=1, altrimenti c = 0
*/

typedef struct squadra *item;

#define NULLITEM NULL

item newItem ( char name[], int match, int points, int goal, int sub);
void inputItem ( item a );
void outputItem ( item a );
int eq ( item a, item b );
int cmpItem ( item val, item val1 );
item updateItem ( item s, int val1, int val2, int val3 );

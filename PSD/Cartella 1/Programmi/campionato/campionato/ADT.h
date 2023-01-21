/*		SPECFIFICA ADT 

	-TIPO:
		Sintattica:
			tipo di riferimento: ADT
			tipi usati: boolean, integer, item
		Semantica:
			ADT è un insieme che contiene valori di tipo item
			ADT contiene anche il valore nil che rappresenta l'ADT vuoto
			
	-OPERATORI:
		Sintattica:
			-newADT()-> ADT
			-emptyADT ( ADT )-> boolean
			-cardinality ( ADT )-> integer
			-containsADT ( ADT, item )-> boolean
			-searchBinary ( ADT, item)-> item		
			-insertADT ( ADT, item )-> ADT
			-removeADT ( ADT, item )-> ADT
		Semantica:
			-newADT()-> t
				POST: t = insieme vuoto
			-emptyADT ( t )-> a
				POST: se t vuoto allora a = 1, altrimenti a = 0
			-cardinality ( t )-> a
				POST: a è il numero degli elementi appartenenti all'insieme
			-contains ( t, e )-> a
				POST: se e appartiene a t allora a = 1, altrimenti a = 0
			-searchBinary ( t, e)-> es
				POST:  se e è un elemento apparternente a t allora es = e
			-insertADT ( t, e )-> t'
				PRE: e non appartiene a t
				POST: t = <a,b,c,d> AND t' = <a,b,c,d> U <e>
			-removeADT ( t, e )-> t'
				PRE: e appartiene a t
				POST: e non appartiene a t'
*/
typedef struct adt *ADT;

ADT newADT();
int emptyADT ( ADT );
int cardinalityADT ( ADT );
int containsADT ( ADT, item );
item searchBinary ( ADT, item);
int insertADT ( ADT, item );
int removeADT ( ADT, item );
int outputADT ( ADT );
struct c_set *pointSet( ADT );

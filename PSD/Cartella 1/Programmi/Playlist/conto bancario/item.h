/* 		SPECIFICA ITEM
	-SINTATTICA:
		tipo di riferimento: item
		tipi usati: string, integer, boolean
		
		-Operatori:
			-newItem ()-> item
			-inputItem (string, string, integer)-> item
			-cmp (item, item)-> boolean
		
	-SEMANTICA:
		-Tipo: item è la tripla formata da: <IBAN, cognome, nome, codice fiscale, tipo, saldo>
		
		-Operatori: 
			-inputItem (a, a1, a2, a3, n, n1)-> e
				POST: e = <a, a1, a2, a3, n, n1>
			-cmp (a, a1)-> b
				POST: se a = a1 allora b = TRUE, altrimenti b = FALSE				
*/
typedef struct conto *item;

#define NULLITEM NULL

item inputItem (); //fa l'input dei campi dell'item
int cmp (char *, char *); //compara due item
char *getIBAN (item); //ritorna il campo IBAN dell'item
int getTipo (item); //ritorna il campo tipo dell'item
item upSaldo(item, int); //modifica il campo saldo di un item
void outputItem (item); //stampa a video un item
void destroyItem ( item *a); //dealloca un item

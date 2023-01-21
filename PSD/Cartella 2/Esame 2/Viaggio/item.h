/*
•Specifica sintattica
–Tipo: viaggio
–Tipi utilizzati: stringa, intero

•Specifica semantica del tipo di riferimento
–Squadra è l'insieme delle sestuple codice, destinazione, op_tour, durata, prezzo, posti dove:
	-codice è una stringa che rappresenta il codice del viaggio;
	-destinazione è una stringa che rappresenta la destinazione del viaggio;
	-op_tour è una stringa che rappresenta l'operatore turistico;
	-durata è un intero che indica la durata del viaggio in giorni;
	-prezzo è un intero che indica il prezzo del viaggio;
	-posti è un intero che indica il numero di posti disponibili per il viaggio.


•Specifica sintattica (Operatori)
– newViaggio(stringa, stringa, stringa, intero, intero, intero)-> viaggio
– input_Viaggio() -> viaggio
–getKey(item) -> stringa
–getNome(item) -> stringa
–modPrezzo(item, intero)
–modPosti(item, intero)

•Specifica semantica (Operatori)
-newViaggio(codice, destinazione, op_tour, durata, prezzo, posti) -> v
	•Post: v=(codice, destinazione, op_tour, durata, prezzo, posti)

–input_Viaggio() -> v
	•Post: v=(codice, destinazione, op_tour, durata, prezzo, posti)

–getKey(v) -> s
	•Post: v=(codice, destinazione, op_tour, durata, prezzo, posti) AND s=codice 

-getNome(v) -> s
	•Post: v=(codice, destinazione, op_tour, durata, prezzo, posti) AND s=nome

–modPrezzo(v, i)
	•Pre: v=(codice, destinazione, op_tour, durata, prezzo, posti)
	•Post: v'=(codice, destinazione, op_tour, durata, prezzo', posti)

–modPosti(v, i)
	•Pre: v=(codice, destinazione, op_tour, durata, prezzo, posti)
	•Post: v'=(codice, destinazione, op_tour, durata, prezzo, posti')	
*/

typedef struct viaggio *item;
#define NULLITEM NULL


item input_Viaggio();

void output_Viaggio(item v);

item newViaggio(char *cod, char*dest, char *op, int dur, int prez, int pos);

char *getKey(item x);

void modPrezzo(item *v, int p);

void modPosti(item *v, int p);

char *getNome(item v);
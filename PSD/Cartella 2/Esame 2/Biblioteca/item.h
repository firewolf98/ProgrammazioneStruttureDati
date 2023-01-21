/*
•Specifica sintattica
– Tipo di riferimento: libro
– Tipi utilizzati: stringa, intero

•Specifica semantica del tipo di riferimento
– Libro è l'insieme delle quintuple codice, titolo, autore, copie disponibili, copie in prestito, dove:
	– codice è una stringa che rappresenta il codice identificativo del libro;
	– titolo è una stringa che rappresenta il nome del libro;
	– autore è una stringa che rappresenta il nome dell'autore del libro;
	– copie disponibili è un intero che rappresenta il numero di copie del libro ancora disponibili;
	– copie in prestito è un intero che rappresenta il numero di copie del libro che sono stato mandate in prestito.

•Specifica sintattica (Operatori)
– creaLibro(stringa, stringa, stringa, intero, intero) -> libro
– cmpItem(item, item) -> boolean
– –getKey(item) -> stringa
– inputLibro() -> libro
– aggiornaPrest(item)
– aggiornaDisp(item)

•Specifica semantica (Operatori)
– creaLibro(codice, titolo, autore, copie disponibili, copie in prestito) -> l
	•post: l=(codice, titolo, autore, copie disponibili, copie in prestito)
– cmpItem(s1, s2)->b
	•pre: s1=(codice1, titolo1, autore1, copie disponibili1, copie in prestito1) AND s2=(codice2, titolo2, autore2, copie disponibili2, copie in prestito2)
	•post: b<0 se codice1<codice2, b=0 se codice1=codice2, b>0 se codice1>codice2
– getKey(v) -> s
	•Post: v=(codice, destinazione, op_tour, durata, prezzo, posti) AND s=codice 
–inputLibro() -> l
	•Post: l=(codice, titolo, autore, copie disponibili, copie in prestito)
– aggiornaPrest(i)
	•Pre: i=(codice, titolo, autore, copie disponibili, copie in prestito)
	•Post: i'=(codice, titolo, autore, copie disponibili, (copie in prestito)')
– aggiornaDisp(i)
	•Pre: i=(codice, titolo, autore, copie disponibili, copie in prestito)
	•Post: i'=(codice, titolo, autore, (copie disponibili)', copie in prestito)
*/
typedef struct libro *item;

item creaLibro(char *cod, char *tit, char *aut, int disp, int prest);

item inputLibro();

void outputLibro(item l);

char *getKey(item x);

int cmpItem(item a, item b);

void aggiornaPrest(item *l1);

void aggiornaDisp(item *l1);
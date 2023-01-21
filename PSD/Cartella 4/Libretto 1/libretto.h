/*Specifica sintattica
Tipo di riferimento: libretto
tipi usati: string, esame

Operatori:
newLibretto(int, string, string)->libretto
addEsame(libretto, esame)->int
cercaEsame(libretto, string)->esame

Specifica semantica
Libretto è l'insieme delle quadruple lib=(matricola, nome, cognome, esami) in cui:
	-matricola è un intero che rappresenta la matricola dello studente;
	-nome è una stringa che rappresenta il nome dello studente;
	-cognome è una stringa che rappresenta il cognome dello studente;
	-esami è l'insieme degli esami sostenuti dallo studente.

Operatori
- newLibretto(matricola, cognome, nome) = lib
• Post: lib = (matricola, cognome, nome, ∅)

– addEsame(lib, es) = lib
• Pre : lib = (matricola, cognome, nome, esami) AND ∀ ai ∈ esami getCorso(ai) ≠ getCorso(es)
• Post: lib’ = (matricola, cognome, nome, esami ∪ {es})

– cercaEsame(lib, corso) = es
• Pre: lib = (matricola, cognome, nome, esami)
• Post: (es ∈ esami AND getCorso(es) = corso) OR (∀ ai ∈ esami getCorso(ai) ≠ corso AND es = null)

– più correttamente, cercaEsame avrebbe dovuto restituire due valori, un valore
booleano b che indica se l’esame è stato trovato e il valore dell’esame es. Nel caso in
cui l’esame viene trovato, allora b = true e es è l’esame contenuto nel libretto il cui
nome coincide con corso, altrimenti se b = false, il valore di es non è definite.
– Per semplicità usiamo il valore null per es per indicare il fatto che l’esame cercato non
è stato trovato*/


typedef struct libretto *libretto;

libretto newLibretto(int mat, char *n, char *c);
esame cercaEsame(libretto l, char *c);
int addEsame(libretto l, esame e);
int outputLibretto(libretto l);




/*
•Specifica sintattica
– Tipo di riferimento: classifica
– Tipi utilizzati: stringa, squadra

•Specifica semantica del tipo di riferimento
– Classifica è l'insieme delle doppie class=(nome, squadre), dove:
	-nome è una stringa che indica il nome del campionato;
	-squadre è l'insieme delle squadre che partecipano al campionato.

•Specifica sintattica (Operatori)
–nuovaClassifica(stringa)->classifica
–aggiungiSquadra(classifica, squadra) -> boolean
–cercaSquadra(classifica, stringa) -> squadra
–aggiorna(classifica, stringa, stringa, intero, intero) -> boolean
–ordinaClassifica(classifica) -> 

•Specifica semantica (Operatori)
–nuovaClassifica(nome) = c
	• Post: c=(nome, ∅)

–aggiungiSquadra(c, sq) = c
	• Pre : c = (nome, squadre) AND ∀ ai ∈ squadre getKey(ai) ≠ getKey(sq)
	• Post: c’ = (nome, squadre ∪ {sq})

–cercaSquadra(c, nome) = squadra
	• Pre: c = (nome, squadre)
	• Post: (sq ∈ squadre AND getKey(sq) = nome) OR (∀ ai ∈ squadre getKey(ai) ≠ nome AND sq = null)

–aggiorna(class, nome1, nome2, reti1, reti1) = class
	• Pre: c = (nome, squadre)
	• Post: c'= (nome, squadre')

–ordinaClassifica(class)
	• Pre:
	• Post:
*/
typedef struct classifica *classifica;

classifica nuovaClassifica(char *nome);

int aggiungiSquadra(classifica c, item sq);

int outputClassifica(classifica c);

item cercaSquadra(classifica c, char *nome);

int aggiorna(classifica c, char *nome1, char *nome2, int reti1, int reti2);

set ordinaClassifica(classifica c);
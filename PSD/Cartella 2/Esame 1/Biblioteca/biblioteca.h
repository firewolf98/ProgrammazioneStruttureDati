/*
•Specifica sintattica
–Tipo di riferimento: biblioteca
–Tipi utilizzati: libri

•Specifica semantica del tipo di riferimento
–Biblioteca è l'insieme delle doppie bibl=(nome, libri), dove: 
	-nome è la stringa che identifica il nome della biblioteca;
	-libri è l'insieme dei libri contenuti nella biblioteca.


•Specifica sintattica (Operatori)
–nuovaBiblioteca(stringa) -> biblioteca
–aggiungiLibro(biblioteca, libro) -> boolean
–aggiornaNumDisp(biblioteca, stringa) -> intero
–aggiornaNumPrest(biblioteca, stringa) -> intero
–cercaLibro(biblioteca, stringa) -> libro

•Specifica semantica (Operatori)
–nuovaBiblioteca(nome) = b
	•Post: b=(nome, ∅)

–aggiungiLibro(bibl, lib) = bibl
	•Pre: bibl=(nome, libri) AND ∀ ai ∈ libri getKey(ai) ≠ getKey(lib)
	•Post: bibl'=(nome,libri u {lib})

–cercaLibro(bibl, codice) = libro
	• Pre: bibl = (nome, libri)
	• Post: (lib ∈ libri AND getKey(lib) = codice) OR (∀ ai ∈ libri getKey(ai) ≠ codice AND lib = null)
*/
typedef struct biblioteca *biblioteca;

biblioteca nuovaBiblioteca(char *nome);

int aggiungiLibro(biblioteca b, item lib);

int aggiornaNumDisp(biblioteca b,char *codice);

int aggiornaNumPrest(biblioteca b,char *codice);

int outputBiblioteca(biblioteca b);

item cercaLibro(biblioteca b, char *codice);
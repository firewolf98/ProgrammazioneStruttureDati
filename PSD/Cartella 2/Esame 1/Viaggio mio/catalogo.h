/*
•Specifica sintattica
–Tipo di riferimento: catalogo
–Tipi usati: string, viaggi

•Specifica semantica del tipo di riferimento
– Catalogo è l'insieme delle doppie catalogo=(nome, viaggi) in cui:
	-nome è una stringa che rappresenta il nome del catalogo;
	-viaggi è l'insieme dei viaggi presenti all'interno del catalogo;

•Specifica sintattica (Operatori):
–nuovoCatalogo(stringa)->catalogo
–aggiungiViaggio(catalogo, item)->int
–cercaViaggio(catalogo, stringa)-> item
–cancellaViaggio(catalogo, stringa)-> int
–modificaPosti(catalogo, stringa)-> int
–modificaPrezzo(catalogo, stringa)-> int
–outputCatalogo(catalogo)-> int


•Specifica semantica (Operatori)
– nuovoCatalogo(nome) = c
• Post: c = (nome, ∅)

– aggiungiViaggio(c, viaggio)
• Pre : c = (nome, viaggi) AND ∀ ai ∈ viaggi getKey(ai) ≠ getKey(viaggio)
• Post: c’ = (nome, viaggi ∪ {viaggio})

– cercaViaggio(c, cod) = viaggio
• Pre: c = (nome, viaggi)
• Post: (viaggio ∈ viaggi AND getKey(viaggi) = codice) OR (∀ ai ∈ viaggi getKey(ai) ≠ codice AND viaggio = null)
*/

typedef struct catalogo *catalogo;

catalogo nuovoCatalogo(char *nom);

item cercaViaggio(catalogo c, char *cod);

int aggiungiViaggio(catalogo c, item v);

int cancellaViaggio(catalogo c, char *cod);

int outputCatalogo(catalogo c);

int modificaPrezzo(catalogo c, char *cod);

int modificaPosti(catalogo c, char *cod);
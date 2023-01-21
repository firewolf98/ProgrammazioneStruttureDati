/*
SPECIFICA ADT CATALOGO VIAGGI

	-TIPO:
		SINTATTICA:
			TIPO DI RIFERIMENTO: catalogo viaggi
			TIPI USATI: boolean, integer, string, item
			
		SEMANTICA:
			catalogo viaggi è la coppia formata da: <nome agenzia, lista viaggi>
			
	-OPERATORI:
		SINTATTICA:
			-newCatalogo()-> catalogo
			-inputViaggio(catalogo, item)-> catalogo
			-searchViaggio(catalogo, string)-> viaggio
			-outputCatalogo(catalogo)->catalogo
		SEMANTICA:
			-newCatalogo()-> catalogo c
				POST: c = <NOME CATALOGO, insieme vuoto>
			-inputViaggio(catalogo c, item b)-> catalogo c'
				-POST: c = <a1, a2, .., an> AND c' = <a1, a2,..,an> U <b>
			-searchViaggio(catalogo c, string a)-> viaggio b
				POST: se a è il codice di un viaggio "v) all'interno del catalogo allora b = v
			-outputCatalogo(catalogo c)-> catalogo c
				POST: stampa a video il catalogo c
*/

typedef struct catalogo *Catalogo;

Catalogo newCatalogo(); //alloca un catalogo
item searchViaggio(Catalogo, char); //cerca un viaggio all'interno del catalogo
int addViaggio(Catalogo, item); //inserisce un viaggio in coda
void outputCatalogo(Catalogo); //stampa un catalogo a video

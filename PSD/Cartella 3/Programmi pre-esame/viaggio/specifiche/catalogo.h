/*
	specifica sintattica:
		tipi:
			tipo di riferimento: catalogo
			tipi usati: stringa,viaggi
		operatori:
			Newcatalogo(stringa)->catalogo
			aggiungiviaggio(catalogo,viaggio)->integer
			searchviaggio(catalogo,stringa)->viaggio
	speciica semantics:
		tipi:
			catalogo è l'insieme delle doppie catalogo=(nome,viaggi), dove:
				nome è una stringa e viaggi è l'insieme dei viaggi presenti all'interno del catalogo
		operatori: 
			Newcatalogo(n)->c
				post: c=<nome catalogo,insieme vuoto>
			aggiungiviaggio(c,v)->c'
				post c=<a1,a2,...,an> AND c'=<a1,a2,...,an> U <b>
			searchviaggio(c,a)->v
				post: se a=cod di un viaggio allora v  
			


*/
typedef struct catalogo *catalogo;
catalogo NewCatalogo(char nome_cat[]);
int AggiungiViaggio(catalogo c,viaggio v);
viaggio SearchViaggio(catalogo c,char cod[]);

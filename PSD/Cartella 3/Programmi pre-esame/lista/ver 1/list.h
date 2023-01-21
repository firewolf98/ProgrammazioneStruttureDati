/*
	-Specifica sintattica:
		Tipi:
			-Tipo di riferimento: list
			-Tipi usati: item, boolean
		Operatori:
			-NewList()->list
			-EmptyList(list)->boolean
			-ConsList(item,list)->list
			-TailList(list)->list
			-GetFirst(list)->item
	-Specifica semantica:
		Tipi:
			-List insieme di sequenze L=a1,a2,...,an di tipo item
			-Contiene anche Nil: rappresenta la lista vuota 
		Operatori:
			-NewList()->l
				post: l=nil
			-EmptyList(l)->b
				post: se l=nil allora b=true altrimenti b=false
			-ConsList(e,l)->l'
				post: l=<a1,a2,...,an> and l'=<e,a1,a2,...,an>
			-TailList(l)->l'
				pre: l=<a1,a2,...,an> n>0
				post: l'=<a2,...,an>
			-GetFirst(l)->e
				pre: l=<a1,a2,...,an> n>0
				post: e=a1
*/

typedef struct node *list;
list NewList(void);
int EmptyList(list l);
list TailList(list l);
list ConsList(item val,list l);
item GetFirst(list l);

#include"item.h"
typedef struct c_list *list;
/*Specifica sintattica
– Tipo di riferimento:	list
– Tipi	usati:	item, boolean, integer
• Specifica semantica
– list	è l’insieme delle sequenze L=a1,a2,...,an di tipo item
– L’insieme list contiene inoltre un elemento nil che
rappresenta la	lista vuota (priva di elementi)


/*• Specifica sintattica operatori
newList()→list
emptyList(list)	→boolean
sizeList(list)	→integer
getItem(list, integer)→item
insertList(list, integer, item)	→list
removeList(list, integer)→list	
posItem(list, item) →integer
reverseList(list) → list
cloneList(list)	→ list
deleteList(list) → list*/



/*• Specifica Semantica*/

/*newList()→l
Post: l = nil

/*emptyList(list) →b
Post: se l=nil allora b = true altrimenti b = false

/*sizeList(list)→n
Post: l=<a1,a2,...,an> AND n ≥0	

/*getItem(l, pos)→ e
Pre: pos >=0 AND sizeList(l) >	pos
• Post:	e è l’elemento che occupa in l la posizione pos

/*posItem(l,e)→p
Post: se e è contenuto in l allora p è	la posizione della prima	
occorrenza di e	in l, altrimenti p = -1	

/*insertList(l,	pos, e)	→ l’
Pre: sizeList(l) ≥ pos       //	assumiamo 0 come prima	posizione
Post: l’ si ottiene da	l inserendo e in posizione pos

/*removeList(l,	pos) → l’
Pre: sizeList(l) > pos       //	assumiamo 0 come prima	posizione
Post: l’ si ottiene da	l eliminando l’elemento in posizione pos

/*reverseList1(l)→l’
Post: l=<a1, a2,...,an>	AND l’ =<an,...,a2,a1>	

/*reverseList2(l)→l’
Post: l=<a1, a2,...,an>	AND l’ =<an,...,a2,a1>

/*deleteList(l)	→ l’
Pre: sizeList(l) > pos
Post: l	= <a1,	a2, ..., an> AND l’ = nil

/*cloneList(l)→l’
Post: l = <a1, a2, ..., an> AND l’ = <a1, a2,	..., an>*/

list newList();

int emptyList(list);

int sizeList(list l);

item getItem(list l, int pos);

int posItem(list l, item val);

int insertList(list l, int pos, item val);

int removeList(list l, int pos);

list reverseList1(list l);

int reverseList2 (list l);

int deleteList(list l);

list cloneList(list l);

//void destroyList(list *l)

int outputList(list l);

void sortList(list l);

//list inputList (int n);

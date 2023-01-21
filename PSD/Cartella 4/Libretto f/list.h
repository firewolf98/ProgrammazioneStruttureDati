/*analisi delle specifiche lista concatenata

ADT Lista: Specifica sintattica

• Tipo di riferimento: list
• Tipi usati: item, boolean, file

• Operatori

newList()	→	list
emptyList(list)	→	boolean
sizeList(list)	→	integer
getItem(list,	integer)	→	item
insertList(list,	integer,	item)	→	list
removeList(list,	integer)	→	list	
posItem(list,	item)	→	integer
reverseList(list)→	list
cloneList(list)	→	list
deleteList(list)	→	list

– newList() → list
– emptyList(list) → boolean
– sizeList(list) → integer
– posItem(list, item) → integer
– searchItem(list, item) → boolean
– reverseList(list) → list
– getItem(list, integer) → item
– insertList(list, integer, item) → list
– removeList(list, integer) → list
- outputList(list);
- cloneList(list) → list
- deleteList(list) → list
- destroyList(list) → /
– appendList(l', l'') →	 l

ADT Lista: Specifica semantica
• Tipo di riferimento list
– list è l’insieme delle sequenze L=a1,a2,...,an di tipo item
– L’insieme list contiene inoltre un elemento nil che rappresenta 
  la lista vuota (priva di elementi)


ADT Lista: Specifica semantica
• Operatori
– newList() → l
	• Post: l = nil
		
– emptyList(l) → b
	• Post: se l=nil allora b = true 
	altrimenti b = false

– sizeList(l) → n
	• Post: l = <a1, a2, ..., an> AND n ≥ 0
	
– searchItem(l, e) → b
	• Post: se e è contenuto in l allora b = true else b = false
	
– posItem(l, e) → p
	• Post: se e è contenuto in l allora p è la posizione della
	prima occorrenza di e in l, altrimenti p = -1
	
– reverseList(l) → l’
	• Post: l = <a1, a2, ..., an> AND l’ = <an, ..., a2, a1>
	
– removeItem(l, e) → l’
	• Post: se e è contenuto in l, allora l’ si ottiene da l
		eliminando la prima occorrenza di e in l, altrimenti l’ = l
		
– getItem(l, pos) → e
	• Pre: pos >= 0 AND sizeList(l) > pos
	// assumiamo 0 come prima posizione
	• Post: e è l’elemento che occupa in l la posizione pos
	
– insertList(l, pos, e) → l’
	• Pre: sizeList(l) ≥ pos // assumiamo 0 come prima posizione
	• Post: l’ si ottiene da l inserendo e in posizione pos
	
– removeList(l, pos) → l’
	• Pre: sizeList(l) > pos // assumiamo 0 come prima posizione
	• Post: l’ si ottiene da l eliminando l’elemento in posizione pos
	
- outputList(l) → /
	• Post: stampa a video di l
- inputList(n) → l
	• Post: lista l di n elementi presi in input da tastiera
	
- f_outputList(l, f) →  file_output
	• Post: stampa su file di l
- f_inputList(n, f) → l
	• Post: lista l di n elementi presi in input da file
– cloneList(l)	→	l’
	• Post:	l= <a1, a2, ..., an> AND l’ = <a1, a2, ..., an>
– deleteList(l)	→	l’
	• Pre:	sizeList(l)	> pos
	• Post:	l =	<a1, a2, ..., an> AND l’ = nil
– destroyList(l) →	/
	• Pre = deleteList(l) applicabile
	• Post =  /
– appendList(l', l'') →	 l
	• Pre:	sizeList(l'') > 0
	• Post:	l =	<a1, a2, ..., an, b1, b2, ..., bn> AND 
	l’ = <a1, a2, ..., an> AND l'' = <b1, b2, ..., bn>
*/
typedef struct c_list *list;



list newList(void);
int emptyList(list l);
int sizeList(list l);
item getItem(list l, int pos);
int posItem(list l, item val);
int insertList(list l, int pos, item e);
int removeList(list l, int pos);
list reverseList1(list l); // restituisce la reverse in una nuova lista
int reverseList2(list l); // fa la reverse della lista di input
int deleteList(list l);
list cloneList(list l);
void destroyList(list *l);
int appendList(list l1, list l2);
int outputList (list l);
list inputList (int n);
int f_outputList (list l, char *f_output);
list f_inputList (int n, char *f_input);


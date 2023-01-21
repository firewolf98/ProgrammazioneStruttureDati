/*SPECIFICA ADT ARRAY LIST

	-TIPO
		SINTATTICA:
			TIPO DI RIFERIMENTO: list;
			TIPI USATI: item, boolean, integer;
			
		SEMANTICA:
			-List è l'insieme delle sequenza L: l1,l2, l3,.., ln di tipo item;
			-L'insieme list contiene anche un elemento nil che rappresenta la lista vuota;
			
	-OPERATORI:
		SINTATTICA:
			-NEWLIST()->list;
			-EMPTYLIST(list)->integer;
			-SIZELIST(list)->integer;
			-GETITEM(list, integer)->item;
			-POSITEM(list, item)->integer;
			-INSERTLIST(list, integer, item)->integer;
			-REMOVELIST(list, integer)->integer;
			-REVERSELIST1(list)->list;
			-REVERSELIST2(list)->integer;
			-DELETELIST(list)->integer;
			-CLONELIST(list)->list;
			-OUTPUTLIST(list)->integer;
			-INPUTLIST(integer)->list;
			-DESTROYLIST( list *);
			
		SEMANTICA:
			-NEWLIST()->l;
				POST: l=nil, l->size=0;
			-EMPTYLIST(l)->b;
				POST: se l=nil allora b=TRUE, altrimenti b=FALSE
			-SIZELIST(l)->n;
				POST: l=<a1,a2,..,an> AND n>0
			-GETITEM(l, pos)->b;
				PRE: pos>=0 AND sizeList(l)>pos;
				POST: b è l'elemento che occupa in l la posizione pos;
			-POSITEM(l, a)->pos;
				POST: se a è contenuto in l allora pos sarà la posizione della prima occorrenza di a in l;
			-INSERTLIST(l, pos, e)->l';
				PRE: pos>=0 AND sizeList(l)>pos
				POST: l' si ottiene da l inserendo e in posizione pos;
			-REMOVELIST(l, pos)->l';
				PRE: pos>=0 AND sizeList(l)>pos;
				POST: l' si ottiene da l eliminando l'elemento che si trova in posizione pos;
			-REVERSELIST1(l)->l';
				POST: l=<a1,a2,..,an> AND l'=<an,..,a2,a1>;
			-REVERSELIST2(l)->l;
				PRE: l=<a1,a2,..,an>;
				POST: l=<an,..,a2,a1>;
			-DELETELIST(l)->l';
				POST:l=<a1,a2,..,an> AND l'=nil;
			-CLONELIST(l)->l';
				POST: l=l'=<a1,a2,..,an>
			-OUTPUTLIST(l)->a;
				PRE: l!=nil AND sizeList(l)>=0;
			-INPUTLIST(n)->l;
				PRE: n>0;
				POST: l=<a1,a2,..,an>;
			-DESTROYLIST(*l);
				POST: *l=nil AND *l->first=nil;
*/

typedef struct a_list *list;

list newList(void); //alloca la lista e la dichiara vuota
int emptyList(list); //restiuisce 1 se non vuota altrimenti 0 
int sizeList (list); //restituisce la size della lista 
item getItem(list, int ); //restituisce l'elemento di una data posizione 
int posItem (list, item); //restituisce la posizione di item nella lista 
int insertList(list, int, item); //aggiungi un elemento in una data posizione. Restituisce 1 se l'operazione è andata a buon fine, 0 altrimenti 
int removeList (list, int); //rimuovi l'elemento in posizione data. Restituisce 1 se l'operazione è andata a buon fine, 0 altrimenti
list reverseList1 (list); //restituisce in output una nuova lista che sarà il contrario della lista di input
int reverseList2 (list); //fa il reverse della lista e restituisce 1 se l'operazione è riuscita, altrimenti restituisce 0
int deleteList (list); //svuota la lista ma non elimina il contenitore
list cloneList(list); //restituisce una nuova lista uguale alla lista di input
int outputList (list); //stampa la lista
list inputList(int); //alloca la lista e la riempie con n elementi
void destroyList ( list *); //dealloca tutti i nodi e infine il contenitore della lista che sarà un puntatore

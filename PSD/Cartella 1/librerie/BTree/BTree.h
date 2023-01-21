/*SPECIFICA ADT BTREE
	
	TIPO:
	
		SINTATTICA:
			Tipo di riferimento: BTree
			Tipi usati: item, boolean
		
		SEMANTICA:
			-Tipo:	
			BTree è la tripla formata da due sottoalberi binari (sinistro e destro) e la radice a cui sono legati i sottoalberi.
			nil rappresenta l'albero vuoto

	OPERATORI:
	
		SINTATTICA:
			newBTree ()-> BTree
			emptyBTree (BTree)-> boolean
			getRoot (BTree)-> item
			leftBTree (BTree)-> BTree
			rightBTree (BTree)-> BTree
			consBTree (item, BTree, BTree)-> BTree
			
		SEMANTICA:
			newBTree ()-> new
				POST: new = nil (l'albero restituito è un albero vuoto)
			emptyBTree (tree)-> bool
				POST: se tree = nil allora bool è TRUE, altrimenti bool è FALSE
			getRoot (tree)-> e
				POST: se tree != nil allora e è uguale alla radice dell'albero tree
			leftBTree (tree)-> tsx
				POST: se tree != nil allora tsx è uguale al sottoalbero sinistro dell'albero tree
			rightBTree (tree)-> tdx
				POST: se tree != nil allora tdx è uguale al sottoalbero destro dell'albero tree
			consBTree (r, tsx, tdx)-> tree
				POST: tree = <r,tsx,tdx>
*/

typedef struct btree *BTree;

BTree newBTree(); //alloca spazio per un albero e restituisce un albero vuoto
int emptyBTree (BTree); //se l'albero è vuoto restituisce 1, altrimenti 0
item getRoot (BTree); //restituisce la radice dell'albero
BTree leftBTree (BTree); //restituisce il sottoalbero sinistro dell'albero di input
BTree rightBTree (BTree); //restituisce il sottoalbero destro dell'albero di input
BTree consBTree (item, BTree, BTree); //costruisce l'albero con la radice e i sottoalberi di input

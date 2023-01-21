/*
					ADT BTree

•Specifica sintattica
– Tipo di riferimento: BTree
– Tipi usati: boolean, item

• Specifica semantica del tipo di riferimento
– BTree= insieme degli alberi binari, dove:
	- nil ε BTree (albero vuoto)
	- se r ε item, t1 ε BTree e t2 ε BTree allora <r, t1, r2> ε BTree

• Specifica sintattica (Operatori)
– newBTree() → BTree
– emptyBtree(Btree) → boolean
– getRoot(BTree) → item
– leftBTree(Btree) → BTree
– rightBtree(Btree) → BTree
– consBTree(item, BTree, BTree) → BTree

•Specifica semantica (Operatori)
– newBTree() → t
	•post: t = nil
– emptyBTree(t) → b
	•post: se t = nil allora b = true altrimenti b = false
– getRoot(t) → r
	•pre: t ≠ nil
	•post: t = <r, tsx, tdx>
– leftBTree(t) → tsx
	•pre: t ≠ nil
	•post: t = <r, tsx, tdx>
– rightBTree(t) → tdx
	•pre: t ≠ nil
	•post: t = <r, tsx, tdx>
– consBTree(r, tsx, tdx) → t
	•post: t = <r, tsx, tdx>
*/
typedef struct node *BTree;

BTree newBTree();

int emptyBTree(BTree t);

BTree consBTree(item val, BTree sx, BTree dx);

item getRoot(BTree t);

BTree leftBTree(BTree t);

BTree rightBTree(BTree t);
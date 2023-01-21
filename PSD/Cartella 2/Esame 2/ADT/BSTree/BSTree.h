/*
						ADT BSTree

Specifica
• L’albero di ricerca binaria è una implementazione dell’ADT Ordered Set
• La specifica è la stessa di quella vista per ADT(Ordered) Set
• Chiamiamo BSTree (Binary Search Tree) questa specializzazione dell’ADT Set


BSTree è il nostro tipo di riferimento che implementa un insieme ordinato


• Specifica sintattica
– Tipo di riferimento: BSTree
– Tipi usati: item, integer, boolean

• Specifica semantica del tipo di riferimento
– I valori di tipo BSTree sono sottoinsiemi di elementi di tipo item
– Tra i valori di tipo BSTree, c’è il sottoinsieme vuoto: ∅

• Specifica sintattica (Operatori)
– newBSTree() → Tree
– emptyBSTree(BSTree) → boolean
– cardinality(BSTree) → integer
– contains(BSTree, item) → boolean
– insert(BSTree, item) → BSTree
– removeBSTree(BSTree, item) → BSTree
– getValue(BSTree) → integer

•Specifica semantica (Operatori)
– newBSTree() → t
	• Post: t = nil
– emptyBSTree(s) → b
	• Post: se t = ∅  allora b = true altrimenti b = false
– cardinality(t) → n
	• Post: n è il numero di elementi contenuti in t (n = |t|)
– contains(t, e) → b
	• Post: se e ∈ t allora b = true altrimenti b = false
– insert(t, e) → t’
	• Pre: e ∉ t
	• Post: t’ = t ∪ {e}
– removeBSTree(t, e) → t’
	• Pre: e ∈ t
	• Post: t = t’ ∪ {e} AND e ∉ t’
*/
#include "set.h"

typedef struct c_tree *BSTree;

BSTree newBSTree();

int emptyBSTree(BSTree t);

int cardinality(BSTree t);

int contains(BSTree t, item elem);

int insertBSTree(BSTree t, item elem);

int removeBSTree(BSTree t, item elem);

int outputBSTree(BSTree t);

item getValue(BSTree t);

item getItem(BSTree t, char *nome);

set BSTreeToSet(BSTree t);
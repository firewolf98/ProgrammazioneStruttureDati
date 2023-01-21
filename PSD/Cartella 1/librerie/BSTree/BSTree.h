/*	SPECFIFICA ADT BINARY SEARCH TREE

	-TIPO:
		Sintattica:
			tipo di riferimento: BSTree
			tipi usati: boolean, integer, item
		Semantica:
			BSTRee è un insieme che contiene valori di tipo item
			BStree contiene anche il valore nil che rappresenta l'albero vuoto
			
	-OPERATORI:
		Sintattica:
			-newBSTree()-> BSTree
			-emptyBSTree ( BSTree )-> boolean
			-cardinality ( BSTree )-> integer
			-contains ( BSTree, item )-> boolean
			-insertBSTree ( BSTree, item )-> BSTree
			-removeBSTree ( BSTree, item )-> BSTree
		Semantica:
			-newBSTree()-> t
				POST: t = insieme vuoto
			-emptyBSTree ( t )-> a
				POST: se t vuoto allora a = 1, altrimenti a = 0
			-cardinality ( t )-> a
				POST: a è il numero degli elementi appartenenti all'insieme
			-contains ( t, e )-> a
				POST: se è appartiene a t allora a = 1, altrimenti a = 0
			-insertBSTree ( t, e )-> t'
				PRE: e non appartiene a t
				POST: t = <a,b,c,d> AND t' = <a,b,c,d> U <e>
			-removeBSTree ( t, e )-> t'
				PRE: e appartiene a t
				POST: e non appartiene a t'
*/
typedef struct c_tree *BSTree;

BSTree newBSTree();
int emptyBSTree ( BSTree );
int cardinality ( BSTree );
int containsBSTree ( BSTree, item );
int insertBSTree ( BSTree, item );
int removeBSTree ( BSTree, item );
int outputBSTree ( BSTree );

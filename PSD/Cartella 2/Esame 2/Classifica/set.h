/*
• Specifica sintattica
– Tipo di riferimento: set
– Tipi usati: item, integer, boolean

• Specifica semantica del tipo di riferimento
– I valori di tipo set sono sottoinsiemi di elementi di
tipo item
– Tra i valori di tipo set, c’è l’insieme vuoto: ∅

•Operatori

•Specifica sintattica
– newSet() → set
– emptySet(set) → boolean
– cardinality(set) → integer
– contains(set, item) → boolean
– insertSet(set, item) → set
– removeSet(set, item) → set
– unionSet(set, set) → set
– intersectSet(set, set) → set
– cmpItem(item, item) → int

•Specifica semantica
– newSet() → s
	• Post: s = ∅
– emptySet(s) → b
	• Post: se s = ∅ allora b = true altrimenti b = false
– cardinality(s) → n
	• Post: n è il numero di elementi contenuti in s (n = |s|)
– contains(s, e) → b
	• Post: se e ∈ s allora b = true altrimenti b = false
– insertSet(s, e) → s’
	• Pre: e ∉ s
	• Post: s’ = s ∪ {e}
– removeSet(s, e) → s’
	• Pre: e ∈ s
	• Post: s = s’ ∪ {e} AND e ∉ s’
– unionSet(s1, s2) → s’
	• Post: s’ = s1 ∪ s2 (s’ contiene tutti gli elementi di s1 ed s2)
– intersectSet(s1, s2) → s’
	• Post: s’ = s1 ∩ s2 (s’ contiene tutti gli elementi comuni ad
s1 ed s2)
– cmpItem(x, y) → r
	• Post: se x > y allora r > 0, se x = y allora r = 0, se x < y allora r < 0
*/

typedef struct c_set *set;

set newSet(void);

int emptySet(set s);

int cardinalitys(set s);

int contanss(set s, item e);

int insertSet(set s, item e); // inseriamo e in s

int removeSet(set s, item e); // rimuoviamo e da s

int unionSet(set s1, set s2); // aggiunge elementi di s2 ad s1

int intersectSet(set s1, set s2); // rimuove da s1 gli elementi che non sono in s2

void outputSet(set s);
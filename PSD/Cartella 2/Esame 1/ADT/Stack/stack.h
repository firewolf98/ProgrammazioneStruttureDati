/*
					ADT STACK

•Specifica sintattica
– Tipo di riferimento: queue
– Tipi usati: item, boolean

•Specifica semantica del tipo di riferimento
– queue è l’insieme delle sequenze S=a1,a2,...,an di tipo item
– L’insieme queue contiene inoltre un elemento nil che rappresenta la coda vuota (priva di elementi)

•Specifica sintattica (Operatori)
–newQueue() → queue
–emptyQueue(queue) → boolean
–enqueue(item, queue) → queue
–dequeue(queue) → (item, queue)

•Specifica semantica (Operatori)
– newQueue() → q
	• Post: q = nil
– emptyQueue(q) → b
	• Post: se q=nil allora b = true altrimenti b = false
– enqueue(e, q) → q’
	• Post: se q = nil allora q’ = <e>, altrimenti se q = <a 1 , a 2 , ... a n > con n > 0 allora q’ = <e, a 1 , a 2 , ... a n >
– dequeue(q) → (a n , q’)
	• Pre: q = <a 1 , a 2 , ..., a n-1 , a n > n>0 (q ≠ nil)
	• Post: q’ = <a 1 ,a 2 , ..., a n-1 >
*/

typedef struct c_stack *stack;

//----------------

stack newStack();

int emptyStack(stack s);

int pop(stack s);

int push(item val,stack s);

item top(stack s);

item pop_val(stack s);
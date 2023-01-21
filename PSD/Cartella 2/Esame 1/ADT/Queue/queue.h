/*
					ADT QUEUE

•Specifica sintattica
–Tipo di riferimento: queue
–Tipi usati: item, boolean

•Specifica semantica del tipo di riferimento
–Queue è l’insieme delle sequenze S=a1,a2,...,an di tipo item
–L’insieme queue contiene inoltre un elemento nil che rappresenta la coda vuota (priva di elementi)

•Specifica sintattica 
-newQueue() → queue
-emptyQueue(queue) → boolean
-enqueue(item, queue) → queue
-dequeue(queue) → (item, queue)

•Specifica semantica
–newQueue() → q
	•Post: q = nil
–emptyQueue(q) → b
	•Post: se q=nil allora b = true altrimenti b = false
–enqueue(e, q) → q’
	•Post: se q = nil allora q’ = <e> altrimenti se q = <a1, a2, ... an>  con n> 0 			allora q’ = <e, a 1, a 2, ... an >
–dequeue(q) → (an, q’)
	•Pre: q = <a1, a2, ..., an-1, an>   n>0    (q≠ nil)
	•Post: q’ = <a1,a2, ..., an-1> 
*/

typedef struct c_queue *queue;

queue newQueue(int maxSize);

int emptyQueue(queue q);

item dequeue(queue q);

int enqueue(item val, queue q);

void outputQueue(queue q);

int search(queue q, item value);
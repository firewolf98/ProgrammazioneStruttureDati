typedef struct c_queue *queue;

queue newQueue (); //alloca una coda e la inizializza
int emptyQueue (queue); //restituisce 1 se la lista è vuota, 0 altrimenti
item dequeue (queue); //toglie un elemento dalla testa della coda e lo restituisce
int enqueue (item, queue); //inserisce un elemento in  testa alla coda
void outputQueue (queue); //stampa a schermo una queue

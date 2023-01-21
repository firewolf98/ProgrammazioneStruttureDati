typedef struct c_stack *stack; 

stack newStack (); //alloca uno stack
int emptyStack (stack); //restituisce 1 se la lista è vuota, altrimenti 0
int pop (stack); //leva l'elemente sul top dello stack
int push (item, stack); //aggiunge un elemento sul top dello stack
item top (stack); //restituisce l'elemento sul top dello stack

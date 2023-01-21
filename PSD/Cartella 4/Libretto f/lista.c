#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

/*list newList(void);
int emptyList(list l);
int sizeList (list l);
item getItem (list l, int pos);
int posItem (list l, item val);
int insertList(list l, int pos, item val);
int removeList(list l, int pos);
list reverseList1(list l); // restituisce la reverse in una nuova lista
int reverseList2(list l); // fa la reverse della lista di input
int deleteList(list l);
list cloneList(list l);
int outputList (list l);
list inputList (int n);
*/



struct node {
	item value;
	struct node *next;
};



struct c_list {
	struct node *first;
	int size;
};





//funzioni private
static int emptyNodo (struct node *n);
static struct node* insertNode (struct node* n, int pos, item val);
static struct node* makeNode(struct node* n, item val);
static struct node* removeNode(struct node* n, int pos);

static int emptyNodo(struct node *n){
	return n == NULL;
}

/*static nodo makeNode(item val, nodo nxt){
	nodo nuovo = malloc (sizeof(struct node));
	if (nuovo != NULL) {
		nuovo->value = val;
		nuovo->next = nxt;
	}
	return nuovo;
}
*/
//makenode rivisto
static struct node* makeNode(struct node* n, item val)
{
	struct node *nuovo;
	nuovo = malloc (sizeof(struct node));
	/*if (nuovo == NULL) 
		return NULL;
	
	item val1 = cloneItem(val);
	if(val1 == NULL) { // se non riusciamo a clonare l’item
		free(nuovo);
	// deallochiamo anche il nuovo nodo
		return NULL;
	}*/
	if(nuovo != NULL){
	nuovo->value = val;
	nuovo->next = n;
	}
	return nuovo;
}





static struct node* insertNode (struct node* n, int pos, item val){
	if(pos == 0)
		return makeNode(n, val);
	
	int i = 0;
	struct node* prec = n;
	while (i < pos-1) {
		prec = prec->next;
		i++;
	}

	struct node* n1;
	n1 = makeNode(prec->next, val); 
	if(n1 == NULL) 
		return NULL; 
	prec->next = n1;
    return n;
}

/*static nodo removeNode(nodo n, int pos){
	nodo n1;
	
	if(pos == 0) {
		n1 = n;
		n = n->next;
		free(n1);
	} else { 
		int i = 0;
		nodo prec = n;
	
		while (i < pos-1) {
			prec = prec->next;
			i++;
		}
	
		n1 = prec->next;
		prec->next = n1->next;
		free(n1);
	}
	return n;
}
*/

static struct node* removeNode(struct node* n, int pos)
{
	struct node* n1;
// puntatore al nodo da eliminare
	
/* se deallochiamo il nodo puntato da n1 dobbiamo deallocare
anche la struct a cui punta n1->value */
	if(pos == 0) {
// eliminazione in posizione 0
		n1 = n;
		n = n->next;
		//destroy(n1->value);
// deallochiamo la struct puntata da value
		free(n1);
	}
	else {
		struct node* prec=n;
		int i = 0;
		
		
		while (i < pos-1) {
			prec = prec->next;
			i++;
		}
	
		n1 = prec->next;
		prec->next = n1->next;
	//destroy(n1->value);
	// deallochiamo la struct puntata da value
		free(n1);
	}
	return n;
}


//lista
list newList(void){
	struct c_list *l;
	l = malloc (sizeof(struct c_list));
	if (l != NULL) {
		l->first = NULL;
		l->size = 0;
	}
	return l;
}

int emptyList(list l){
	if(l == NULL) 
		return -1;
	return (l -> size == 0);
}

int sizeList (list l){
	if(l == NULL) 
		return -1;
	return l->size;
}

/*item getItem(list l, int pos){
	int i = 0;
	nodo tmp = l->first;
	
	if(l == NULL) return NULLITEM;
	if (pos<0 || pos>=l->size) return NULLITEM;
	
	for(i; i < pos; i++) tmp = tmp->next;
	return tmp -> value;
}*/

//getitem rivisto

item getItem(list l, int pos){
	if(l == NULL)
		return NULLITEM;
	if (pos < 0 || pos >= l->size)
		return NULLITEM;
	struct node *temp = l->first;
	int i = 0;
	while (i < pos) {
		i++;
		temp=temp->next;
	}
	return temp->value;
}



int posItem(list l, item val){
	if(l== NULL)
		 return -1;
	int pos = 0;
	int found = 0;
	struct node *tmp = l->first;
	
	while(tmp != NULL && !found){
		
		if(eq(tmp->value, val)) 
			found = 1;
		else {
			tmp = tmp->next;
			pos++;
		}
	}
	if(!found) 
		pos = -1;
	return pos;
}


int insertList (list l, int pos, item val){
	if(l == NULL) 
		return 0;
	if (pos < 0 || pos > l->size) 
		return 0;
	
	struct node* tmp = insertNode(l->first, pos, val);

	if(tmp == NULL) 
		return 0;
	
	l->first = tmp;
	l->size++;
	return 1;
}

int removeList (list l, int pos){
	if(l == NULL) 
		return 0;
	if (pos < 0 || pos >= l->size)
		return 0;

	l->first = removeNode(l->first, pos);
	l->size--;
	return 1;
}

list reverseList1(list l){
	if(l == NULL) 
		printf("prova")	;	
		return NULL;
	
	list l1 = newList();
	struct node *tmp = l->first;
	
	tmp = l->first;
	
	while (tmp != NULL){
		printf("prova\n");
		l1->first = makeNode(l1->first, tmp->value);
		tmp = tmp->next;
	}
	
	if (l1->first!=NULL) 
		l1->size=l->size;
	
	return l1;
}


int reverseList2(list l) {
	if(l == NULL) 
		return 0;
	
	struct node *n = l->first;
	struct node *prec = NULL; 
	struct node *succ;

	while(n!=NULL) {
		succ = n->next;
		n->next = prec; 
		prec = n;
		n = succ;
	}
	
	l->first = prec;
	return 1;
}

int deleteList(list l){
	if(l == NULL) 
		return 0;
	
	struct node *tmp = l -> first;
	struct node *tmp1;
	
	while(tmp != NULL){
		tmp1 = tmp;
		tmp = tmp -> next;
		free(tmp1);  
	}
	
	l->first = NULL;
	l->size = 0;
		
	return 1;
}

list cloneList(list l){
	if(l == NULL) 
		return NULL;
	if(emptyList(l)) 
		return newList();
		
	struct node *tmp;
	tmp = l->first;
	
	list l1 = newList();
	l1->first = makeNode(NULL, tmp->value);
	
	struct node *tmp1;
	tmp1 = l1->first;
	
	while(tmp->next != NULL){
		tmp1->next = makeNode(NULL, tmp->next->value);
		tmp = tmp->next;
		tmp1 = tmp1->next;
	}
	
	l1->size = l->size;
	
	return l1;
}

void destroyList(list *l){
	if(*l != NULL) {
		deleteList(*l);
		free(*l);
	*l=NULL;
	}
}

/*int appendList(list l1, list l2){
	if(l2 == NULL) 
		return 0;
	if(emptyList(l1)) l1 = newList();
	
	struct node *tmp = l1 -> first;
	struct node *tmp1 = l2->first;
	
	while(tmp->next != NULL)
		 tmp = tmp->next;
	
	while(!emptyNodo(tmp1)){
		tmp->next = makeNode(NULL, tmp1 -> value);
		tmp = tmp->next;
		tmp1 = tmp1->next;
	}
	
	return 1;
}*/

int outputList(list l){
	if(l == NULL) 
		return 0;
	
	int i = 0;
	struct node *tmp;
	tmp = l->first; 

	while(tmp != NULL) {
		printf("Elemento di posizione %d: ", i);
		output_item(tmp->value);
		printf("\n");
		tmp = tmp->next;
		i++;
	}
	
	return 1;
}

list inputList (int n){
	if(n <= 0) 
		return newList();

	item val;
	list l = newList();
	
	printf("Elemento di posizione 0: ");
	input_item(&val);
	l->first = makeNode(NULL, val);
	
	struct node *tmp = l->first;
		
	for(int i = 1; i < n; i++) {
		printf("Elemento di posizione %d: ", i);
		input_item(&val);
		tmp->next = makeNode(NULL, val);
		tmp = tmp -> next;
	}
	
	l->size = n;
	return l;
}	

/*int f_outputList (list l, char *f_output){
	
	if(l == NULL) return 0;
	
	int i = 0;
	struct node *l1 = l->first;
	FILE *output = fopen(f_output, "w");
	
	while(l1 != NULL) {
		f_output_item(output, l1->value);
		l1 = l1 -> next;
	}
	fclose(output);
	
	return 1;
}


list f_inputList (int n, char *f_input){
	if(n <= 0) return newList();
	
	item val;
	FILE *input = fopen(f_input, "r");
	
	list l = newList();
	struct node *tmp;
	
	f_input_item(input, &val);
	l->first = makeNode(val, NULL);
	struct node *tmp;
	tmp = l->first;
	
	for(int i = 1; i < n; i++) {
		f_input_item(input, &val);
		tmp->next = makeNode(val, NULL);
		tmp = tmp -> next;
	}
	
	l->size = n;
	fclose(input);
	return l;
}
*/


#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct c_list{
	struct node* first;
	int size;
};

struct node{
	item value;
	struct node *next;
};

static struct node *makeNode(item, struct node *);
static struct node *insertNode(struct node *, int, item);
static struct node *removeNode(struct node *, int);

list newList(){
	struct c_list *l=malloc(sizeof(struct c_list));

	if (l!=NULL){
		l->first=NULL;
		l->size=0;
	}
	
	return l;
}

item getItem (list l, int pos ){
	
	int i=0;
	
	if(l==NULL)
		return NULLITEM;	

	if(pos<0 || pos>l->size)
		return NULLITEM;

	struct node *temp=l->first;
	
		while (i<pos){
			i++;
			temp=temp->next;
		}
	
	return (temp->value);
}

int posItem (list l, item val){
	if(l==NULL)
		return -1;
int pos=0, found=0;

struct node *temp= l->first;

	while (temp!=NULL && !found){
		if(eq(temp->value, val))
			found=1;		
		else{
			temp=temp->next;
			pos++;
		}
	}
	
	if(!found)
		pos=-1;
	
	return (pos);
}

int sizeList (list l){
	if(l==NULL)
		return -1;
	if(l!=NULL)
		return l->size;
}

int emptyList(list l){
	if(l==NULL)
		return -1;

	return (l->size == 0);
}

struct node *makeNode(item val, struct node *nxt){

	struct node *new=malloc(sizeof(struct node));
	
	if(new!=NULL){
		new->value=val;
		new->next=nxt;
	}
	
	return new;
}

struct node* insertNode (struct node *n, int pos, item val){
	if(pos==0)
		return makeNode(val, n);
	int i=0;
	struct node *prec=n;

	while (i<pos-1){
		prec=prec->next;
		i++;
	}
	
	struct node *n1=makeNode(val, prec->next);

	if(n1==NULL)
		return NULL;

	prec->next=n1;
	return n;
}

int insertList (list l, int pos, item val){
	if (l==NULL)
		return 0;
	if(pos>l->size || pos<0)
		return 0;

	struct node *tmp=insertNode(l->first, pos, val);
	if (tmp==NULL)
		return 0;

	l->first=tmp;
	l->size++;
	return 1;
}

static struct node *removeNode(struct node *n, int pos){

	struct node *n1;

	if(pos==0){
		n1=n;
		n=n1->next;
		free(n1);
	}
	
	else{
		int i=0;
		struct node *prec=n;
		while(i<pos-1){
			prec=prec->next;
			i++;
		}
	n1=prec->next;
	prec->next=n1->next;
	free(n1);
	}
	
	return n;
}

int removeList (list l, int pos){
	if (l==NULL)
		return 0;

	if(pos<0 || pos>=l->size)
		return 0;

	int i=0;

	l->first=removeNode(l->first, pos);
	l->size--;
	return 1;
}

list reverseList1 (list l){
	if(l==NULL)
		return NULL;

	list l1=newList();
	struct node *tmp=l->first;

	while(tmp!=NULL){
		l1->first=makeNode(tmp->value, l1->first);
		tmp=tmp->next;
	}
	
	if(l1->first!=NULL)
		l1->size=l->size;

	return l1;
}

int reverseList2 (list l){
	if (l==NULL)
		return 0;

	struct node *n=l->first;
	struct node *prec=NULL;
	struct node *succ;

	while(n!=NULL){
		succ=n->next;
		n->next=prec;
		prec=n;
		n=succ;
	}

	l->first=prec;

	return 1;
}

int deleteList (list l){

	if (l==NULL)
		return 0;

	struct node *tmp=l->first;
	struct node *tmp1;	

	while(tmp!=NULL){
		tmp1=tmp;
		tmp=tmp->next;
		free(tmp1);
	}
	
	l->first=NULL;
	l->size=0;
	return 1;
}

list cloneList(list l){

	if (l==NULL)
		return NULL;

	struct node *tmp=l->first;

	list l1=newList();
	l1->first=makeNode(tmp->value, l1->first);

	struct node *tmp1=l1->first;

	while(tmp->next !=NULL){
		tmp1->next=tmp->next;
		tmp=tmp->next;
		tmp1=tmp1->next;
	}

	l1->size=l->size;
	return l1;
}

int outputList (list l){
	if(l==NULL)
		return 0;

	int i=0;
	struct node *tmp=l->first;

	while(tmp!=NULL){

		printf("Elemento di posizione %d:", i);
		outputItem(tmp->value);

		tmp=tmp->next;
		i++;
	}
	
	return 1;
}

list inputList (int n){
	if(n<=0)
		return NULL;

	item val;
	list l=newList();
	
	printf("Elemento di posizione 0: ");
	inputItem(val);
	l->first=makeNode(val, l->first);

	struct node *tmp=l->first;
	
	for(int i=1;i<n;i++){
		printf("Elemento di posizione %d: ", i);
		inputItem(val);
		tmp->next=makeNode(val, tmp->next);
		tmp=tmp->next;
	}
	
	l->size=n;
	return l;
}

void destroyList (list *l){
	if(*l!=NULL){
		deleteList(*l);
		free(*l);
		*l = NULL;
		
	}
}

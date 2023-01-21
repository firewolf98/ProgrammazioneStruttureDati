#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"lista.h"

static struct node *insertNode(struct node *n, int pos, item val);
static struct node *makeNode (item val, struct node *n);
static struct node* removeNode(struct node *n, int pos);

struct c_list{
	struct node *first;
	int size;
};

struct node{
	item value;
	struct node *next;
};

list newList(){
	struct c_list *l;
	l=malloc(sizeof(struct c_list));
	if (l!=NULL){
		l->first=NULL;
		l->size=0;
	}
	return l;
}

int emptyList(list l){
	if (l!=NULL)
		return (l->size==0);
	else
		return -1;
}

int sizeList(list l){
	return l->size;
}

item getItem(list l, int pos){
	if (l==NULL)
		return NULLITEM;
	if (pos<0||pos>=l->size)
		return NULLITEM;

	struct node *tmp=l->first;
	int i=0;
		
	while(i<pos){
		tmp=tmp->next;
		i++;
	}
	
	return tmp->value;
}

int posItem(list l, item val){
	if (l==NULL)
		return -1;
	
	int found=0, pos=0;
	struct node *tmp=l->first;

	while(tmp!=NULL&&!found){
		if (eq(tmp->value, val))
			found=1;
		else{
			tmp=tmp->next;
			pos++;
		}
	}
	if (!found)
		pos=-1;
	return pos;
}

int insertList(list l, int pos, item val){
	if (l==NULL)
		return 0;
	if (pos<0||pos>l->size)
		return 0;
	
	struct node *tmp=insertNode(l->first, pos, val);
	if (tmp==NULL)
		return 0;
	l->first=tmp;
	l->size++;
	return 1;
}

static struct node *insertNode(struct node *n, int pos, item val){
	if (pos==0)
		return makeNode(val, n);
	
	int i=0;
	struct node *prec=n;
	
	while(i<pos-1){
		prec=prec->next;
		i++;
	}
	
	struct node *n1=makeNode(val, prec->next);
	if(n1==NULL)
		return NULL;
	prec->next=n1;
	return n;
}

static struct node *makeNode (item val, struct node *n){
	struct node *nuovo=malloc(sizeof(struct node));
		
	if (nuovo!=NULL){
		nuovo->value=val;
		nuovo->next=n;
	}
	return nuovo;
}


int removeList(list l, int pos){
	if (l==NULL)
		return 0;
	if (pos<0||pos>=l->size)
		return 0;
	l->first=removeNode(l->first, pos);
	l->size--;
	return 1;
}


static struct node* removeNode(struct node *n, int pos){
	int i=0;
	struct node *n1;
	
	if (pos==0){
		n1=n;
		n=n->next;
		return n;
	}
	
	else{
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
	
list reverseList1(list l){
	list l1=newList();
	struct node *tmp=l->first;
	
	if (l==NULL)
		return NULL;
	
	while(tmp!=NULL){
		l1->first=makeNode(tmp->value, l->first);
		tmp=tmp->next;
	}
	if (l1->first!=NULL)
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
		n->next=n;
		prec=n;
		n=succ;
	}
	l->first=prec;
	return 1;
}
	

list cloneList(list l){
	if (l==NULL)
		return NULL;
	if (emptyList(l))
		return newList();
	
	struct node *tmp=l->first;
	list l1=newList();
	l->first=makeNode(tmp->value, NULL);
	
	struct node *tmp1=l1->first;
	
	while(tmp->next!=NULL){
		tmp1->next=makeNode(tmp->next->value, NULL);
		tmp=tmp->next;
		tmp1=tmp1->next;
	}
	l1->size=l->size;
	return l1;
}

int deleteList(list l){
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


int outputList(list l){
	if (l==NULL)
		return 0;
	struct node *tmp=l->first;
	int i=0;
	while(tmp!=NULL){
		printf("Elemento di posizione %d ", i);
		output_item(tmp->value);
		printf("\n");
		tmp=tmp->next;
		i++;
	}
	return 1;
}

void swapItem(struct node *n1, struct node *n2){
	item tmp;
	tmp=n2->value;
	n2->value=n1->value;
	n1->value=tmp;
}

void sortList(list l){
	struct node *p;
	struct node *q;
	for (p=l->first; p!=NULL; p=p->next){
		for (q=p->next; q!=NULL; q=q->next){
			if (cmpItem(p->value,q->value)>-1)
				swapItem(p, q);
		}
	}
}

/*list inputList (int n){
	if (n<=0)
		return newList();

	item val;
	list l=newList();

	printf("Elemento di posizione 0 ");
	input_item(&val);
	l->first=makeNode(val, NULL);

	struct node *tmp=l->first;
	for (int i=1;i<n;i++){	
		printf("Elemento di posizione %d ", i);
		input_item(&val);
		tmp->next=makeNode(val, NULL);
		tmp=tmp->next;
	}
	l->size=n;
	return l;
}*/

/*void destroyList(list *l){
	if(*l!=NULL){
		deleteList(*l);
		free(*l);
		*l=NULL;
	}
}*/

	



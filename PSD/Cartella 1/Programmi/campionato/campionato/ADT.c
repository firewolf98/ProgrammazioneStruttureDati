#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "ordSet.h"
#include "ADT.h"

struct node {
	item value;	      
	struct node *left;    
	struct node *right;   
};

struct adt{
	struct node *radice; 
	int size;	      
};

ADT newADT()
{
	struct adt *new =malloc(sizeof(struct adt));
	
	if( new != NULL ){
		new->radice = NULL;
		new->size = 0;
	}

	return new;
}

item getRoot (struct node *r){
	return r->value;
}

int emptyADT(ADT t)
{
	if(t->size=0)
	{
		return 1;
	}
	else
		return 0;
}

int cardinalityADT(ADT t)
{
	if(t==NULL)
		return -1;
	else
		return t->size;
}
static int r_containsADT(struct node *, item);

int containsADT(ADT t, item value)
{
	if(t==NULL)
		return 0;
	
	else return r_containsADT(t->radice,value);
}


static int r_containsADT(struct node *t, item value)
{
	int res, cmp;

	if(t==NULL)
		res=0; //elemento non trovato.
	else
	{
		cmp=cmpItem(value, t->value);
		
		if(cmp==0)
			res=1; //elemento trovato.

		else if(cmp<0) 	

			res=r_containsADT(t->left,value);

		else if(cmp>0) 

			res=r_containsADT(t->right,value);

	}
	
	return res;
}

static item r_searchBinary(struct node *t, item value);

item searchBinary(ADT t, item value)
{
	if(t==NULL)
		return NULL;
	
	else return r_searchBinary(t->radice,value);
}


static item r_searchBinary(struct node *t, item value)
{
	int cmp;

	if(t==NULL)
		return NULL;//elemento non trovato.
	else
	{
		cmp=cmpItem(value, t->value);
		
		if(cmp==0)
			return (t->value); //elemento trovato.

		else if(cmp<0) 	

			return (r_searchBinary(t->left,value));

		else if(cmp>0)  

			return (r_searchBinary(t->right,value));

	}
	
}

static struct node *make_leaf(item);

static struct node *make_leaf(item elem) 
{
	struct node *leaf;
	
	leaf=malloc(sizeof(struct node));
	
	if(leaf!=NULL)
	{
		leaf->value=elem;   
		leaf->left=NULL;
		leaf->right=NULL;
	}
	
	return leaf;
}

static int r_insertADT(struct node **, item);

int insertADT(ADT t, item value)  
{
	if(t==NULL)
		return -1;

	int res;
	
	res=r_insertADT(&(t->radice),value); 

	if(res==1)
		t->size++; 

	return res;
}

static int r_insertADT(struct node **t, item value)
{
	int res, cmp;

	if(*t==NULL) 
	{
		*t=make_leaf(value); 

		if(*t!=NULL)
			res=1; //elemento inserito.
		else
			res=-1; //elemento non inserito.
	}

	else 
	{
		cmp=cmpItem(value,(*t)->value); 

		if(cmp==0)
			res=0; //elemento già presente.

		else if(cmp<0)	

			res=r_insertADT(&((*t)->left),value); 

		else if(cmp>0)  
		
			res=r_insertADT(&((*t)->right),value);
	}

	return res;
}

static void r_outputADT(struct node *t);

int outputADT(ADT t)
{
	if(t==NULL)
		return -1;
	
	r_outputADT(t->radice);

	return 1;
}

static void r_outputADT(struct node *t) //La visita viene effettuata in in-order per visualizzare l'insieme ordinato degli elementi.
{					   
	if(t != NULL)
	{
		r_outputADT(t->left);   
		outputItem(t->value);   
		r_outputADT(t->right);  
	}
}

static int r_deleteADT(struct node **, item);

static item deleteMax(struct node **);

int deleteADT(ADT t, item value)
{	
	if(t==NULL)
		return -1;

	int res;
	
	res=r_deleteADT(&(t->radice),value);

	if(res==1)
		t->size--; 

	return res;
}

static int r_deleteADT(struct node **t, item value)
{
	int res, cmp;

	if(*t==NULL) //Albero vuoto.

		res=0; //Elemento non presente, non è possibile eliminare.
	else 
	{
		cmp=cmpItem(value,(*t)->value); 

		if(cmp<0)	

			res=r_deleteADT(&((*t)->left),value); 

		else if(cmp>0)
		
			res=r_deleteADT(&((*t)->right),value);
	
		else if((*t)->left == NULL) 
		{
			struct node *temp=*t;
			*t=(*t)->right;
			free(temp);
			res=1; //eliminazione riuscita.
		}

		else if((*t)->right == NULL) 
		{
			struct node *temp=*t;
			*t=(*t)->left; 
			free(temp);
			res=1; //eliminazione riuscita.
		}
		else 	
		{ 
			(*t)->value = deleteMax(&((*t)->left)); 
			res = 1; // eliminazione riuscita
		}
	}	
	
	return res;
}

static item deleteMax(struct node **t)
{

	if((*t)->right != NULL)
		return deleteMax(&((*t)->right));

		item x = (*t)->value;
		struct node *temp = *t;
		*t = (*t)->left; 
		free(temp);

	return x;
}

static void fillNode(struct node *l, set t){
	if(l == NULL)
		return;
	else{
		fillNode(l->left, t);
		fillNode(l->right, t);
		insertSet(t,l->value);
	}
}

set pointSet( ADT t){
	set new = newSet();
	fillNode(t->radice, new);
	return new;
}

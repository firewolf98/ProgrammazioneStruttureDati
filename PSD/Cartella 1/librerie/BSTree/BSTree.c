#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BSTree.h"

struct node {
	item value;	      //rappresenta il valore del nodo.
	struct node *left;    //rappresenta il figlio sinistro del nodo data.
	struct node *right;   //rappresenta il figlio destro del nodo data.
};

struct c_tree{
	struct node *radice;  //rappresenta la radice.
	int size;	      //rappresenta il numero di nodi dell'albero.
};

BSTree newBSTree()
{
	struct c_tree *new =malloc(sizeof(struct c_tree));
	
	if( new != NULL ){
		new->radice = NULL;
		new->size = 0;
	}

	return new;
}

int emptyBSTree(BSTree t)
{
	if(t->size=0)
	{
		return 1;
	}
	else
		return 0;
}

int cardinality(BSTree t)
{
	if(t==NULL)
		return -1;
	else
		return t->size;
}
static int r_containsBSTree(struct node *, item);

int containsBSTree(BSTree t, item value)
{
	if(t==NULL)
		return 0;
	
	else return r_containsBSTree(t->radice,value);
}


static int r_containsBSTree(struct node *t, item value)
{
	int res, cmp;

	if(t==NULL)
		res=0; //elemento non trovato.
	else
	{
		cmp=cmpItem(value, t->value);
		
		if(cmp==0)
			res=1; //elemento trovato.

		else if(cmp<0) 	//Se value è minore di t->value devo andare a cercare nel sottoalbero sinistro.

			res=r_containsBSTree(t->left,value);

		else if(cmp>0)  //Se value è maggiore di t->value devo andare a cercare nel sottoalbero detro.

			res=r_containsBSTree(t->right,value);

	}
	
	return res;
}

static struct node *make_leaf(item);

static struct node *make_leaf(item elem) //Creo una foglia, mettendo l'elemento che gli passo dal main come nodo.
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

static int r_insertBSTree(struct node **, item);

int insertBSTree(BSTree t, item value)  
{
	if(t==NULL)
		return -1;

	int res;
	
	res=r_insertBSTree(&(t->radice),value); //Dereferenzio solo una volta perchè nel prototipo è come se avessi struct node *t.

	if(res==1)
		t->size++; //Se posso inserire l'elemento allora incremento la mia size dell'albero.

	return res;
}

static int r_insertBSTree(struct node **t, item value)
{
	int res, cmp;

	if(*t==NULL) //Albero vuoto.
	{
		*t=make_leaf(value); //creo la foglia da inserire nell'albero vuoto.

		if(*t!=NULL)
			res=1; //elemento inserito.
		else
			res=-1; //elemento non inserito.
	}

	else 
	{
		cmp=eq(value,(*t)->value); //Dato che passo un puntatore a puntatore devo mettere (*t)->value.

		if(cmp==0)
			res=0; //elemento già presente.

		else if(cmp<0)	//Se value è minore di t->value devo andare a cercare nel sottoalbero sinistro.

			res=r_insertBSTree(&((*t)->left),value); 

		else if(cmp>0)  //Se value è maggiore di t->value devo andare a cercare nel sottoalbero destro.
		
			res=r_insertBSTree(&((*t)->right),value);
	}

	return res;
}

static void r_outputBSTree(struct node *t);

int outputBSTree(BSTree t)
{
	if(t==NULL)
		return -1;
	
	r_outputBSTree(t->radice);

	return 1;
}

static void r_outputBSTree(struct node *t) //La visita viene effettuata in in-order per visualizzare l'insieme ordinato degli elementi.
{					   
	if(t != NULL)
	{
		r_outputBSTree(t->left);   //prima scendo nel sottoalbero sinistro, e faccio l'output in-order del sottoalbero sinistro.
		outputItem(t->value);     //stampo la radice.
		r_outputBSTree(t->right);  //poi scendo nel sottoalbero destro, e faccio l'output in-order del sottoalbero destro.
	}
}

static int r_deleteBSTree(struct node **, item);

static item deleteMax(struct node **);

int deleteBSTree(BSTree t, item value)
{	
	if(t==NULL)
		return -1;

	int res;
	
	res=r_deleteBSTree(&(t->radice),value); //Dereferenzio solo una volta perchè nel prototipo è come se avessi struct node *t.

	if(res==1)
		t->size--; //Se posso inserire l'elemento allora decremento la mia size dell'albero.

	return res;
}

static int r_deleteBSTree(struct node **t, item value)
{
	int res, cmp;

	if(*t==NULL) //Albero vuoto.

		res=0; //Elemento non presente, non è possibile eliminare.
	else 
	{
		cmp=cmpItem(value,(*t)->value); //Dato che passo un puntatore a puntatore devo mettere (*t)->value.

		if(cmp<0)	//Se value è minore di t->value devo andare a cercare nel sottoalbero sinistro.

			res=r_deleteBSTree(&((*t)->left),value); 

		else if(cmp>0)
		
			res=r_deleteBSTree(&((*t)->right),value);
	
		else if((*t)->left == NULL) //Se il sottoalbero sinistro è vuoto vado a cercare nel sottoalbero destro.
		{
			struct node *temp=*t;
			*t=(*t)->right;
			free(temp);
			res=1; //eliminazione riuscita.
		}

		else if((*t)->right == NULL) //Se il sottoalbero destro è vuoto vado a cercare nel sottoalbero sinistro.
		{
			struct node *temp=*t;
			*t=(*t)->left; 
			free(temp);
			res=1; //eliminazione riuscita.
		}
		else 	
		{ 
			(*t)->value = deleteMax(&((*t)->left)); //(*t)->value contiene entrambi i sottoalberi.
			res = 1; // eliminazione riuscita
		}
	}	
	
	return res;
}

static item deleteMax(struct node **t)
{
	// continuiamo a scendere a dx finché il sottoalbero dx è vuoto

	if((*t)->right != NULL)
		return deleteMax(&((*t)->right));

	// se sottoalbero dx è vuoto, *t->value è l’elemento max
	// e *t punta al nodo da eliminare

		item x = (*t)->value;
		struct node *temp = *t;
		*t = (*t)->left; // il nodo puntato da *t può avere figlio sx
		free(temp);

	return x;
}

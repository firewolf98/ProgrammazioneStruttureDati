#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "set.h"
#include "BSTree.h"




struct node{
	item value;
	struct node *left;
	struct node *right;
};

struct c_tree{
	int size;
	struct node *root;
};

static int r_contains(struct node *t, item elem);
static int r_insert(struct node **t, item elem);
static struct node *makeLeaf(item elem);
static int r_delete(struct node **t, item elem);
static item deleteMax(struct node **t);
static void r_output (struct node *t);
static item r_getItem(struct node *t, char *nome);
static set r_BSTreeToSet(struct node *t,set s);


BSTree newBSTree()
{
	struct c_tree *t = malloc(sizeof(struct c_tree));
	if(t!=NULL){
		t->root=NULL;
		t->size=0;
	}

	return t;
}

//----------------------------------------

int emptyBSTree(BSTree t)
{
	if(t==NULL)
		return -1;

	return (t->size)==0;
}




int cardinality(BSTree t)
{
	if(t==NULL)
		return -1;

	return t->size;
}




int contains(BSTree t, item elem)
{
	if(t==NULL)
		return -1;

	return r_contains(t->root, elem);
}

static int r_contains(struct node *t, item elem)
{
	int res, cmp;

	if(t==NULL)
		res=0;
	else {
		cmp=cmpItem(elem, t->value);
		if(cmp==0)
			res=1;	//elemento trovato

		else if(cmp<0)
			res=r_contains(t->left, elem);
		else
			res=r_contains(t->right, elem);
	}

	return res;
}




int insertBSTree(BSTree t, item elem)
{
	if(t==NULL)
		return -1;

	int res = r_insert(&(t->root),elem);
	if(res==1)
		(t->size)++;

	return res;
}


static int r_insert(struct node **t, item elem)
{
	int cmp, res;

	if(*t==NULL){
		*t=makeLeaf(elem);

		if(*t!=NULL)
			res=1;
		else res=-1;
	}

	else {
		cmp = cmpItem(elem, (*t)->value);
		if(cmp<0)
			res=r_insert(&((*t)->left), elem);
		else if(cmp>0)
			res=r_insert(&((*t)->right), elem);

		else res=0;
	}

	return res;
}

static struct node *makeLeaf(item elem){
	struct node *n=malloc(sizeof(struct node));

	if(n!=NULL) {
		n->value=elem;
		n->left=NULL;
		n->right==NULL;
	}
	return n;
}



int removeBSTree(BSTree t, item elem)
{
	if(t==NULL)
		return -1;

	int res = r_delete(&(t->root),elem);
	if(res==1)
		t->size--;

	return res;
}

static int r_delete(struct node **t, item elem)
{
	int res, cmp;

	if(*t==NULL)
		res = 0; //elemento non presente - eliminazione non riuscita
	else {
		cmp=cmpItem(elem, (*t)->value);

		if(cmp<0)
			res=r_delete(&((*t)->left),elem);

		else if(cmp>0)
			res=r_delete(&((*t)->right),elem);

		//altrimenti cmp==0 e viene trovato elemento da eliminare

		else if((*t)->left==NULL) { //non ha sottoalbero sinistro
			struct node *temp= *t; //punta a nodo da eliminare
			*t=(*t)->right; //ok anche se *t->right==NULL
			free(temp);
			res=1; //eliminazione riuscita
		}

		else if((*t)->right==NULL) {
			struct node *temp =*t;
			*t=(*t)->left;
			free(temp);
			res=1;
		}

		else {
			(*t)->value = deleteMax(&((*t)->left));
			res=1;
		}
	}

	return res;
}

static item deleteMax(struct node **t)
{
	//continuiamo a scendere a dx finchè il sottoalbero dx è vuoto
	if((*t)->right!=NULL)
		return deleteMax(&(*t)->right);

	//se sottoalbero dx è vuoto, *t->value è l'elemento max 
	//e *t punta al nodo da eliminare

	item x = (*t)->value;
	struct node *temp = *t;

	*t = (*t)->left; //il nodo puntato da *t può avere figlio sinistro
	free(temp);
	return x;
}


int outputBSTree(BSTree t)
{
	if(t==NULL)
		return -1;

	r_output(t->root);

	return 1;
}

static void r_output(struct node *t)
{
	if(t!=NULL){
		r_output(t->left);
		output_Squadra(t->value);
		r_output(t->right);
	}
}


item getItem(BSTree t, char *nome){
	if(t==NULL)
		return NULL;
	return r_getItem(t->root,nome);
}

static item r_getItem(struct node *t, char *nome){
	int cmp;
	if(t==NULL)
		return NULL;
	else {
		cmp=strcmp(nome, getKey(t->value));
		if(cmp==0)
			return t->value;
		else if(cmp<0)
			return r_getItem(t->left, nome);
		else
			return r_getItem(t->right, nome);
	}
}

set BSTreeToSet(BSTree t){
	if(t==NULL)
		return NULL;
	set s=newSet();
	return r_BSTreeToSet(t->root,s);
}

static set r_BSTreeToSet(struct node *t,set s){
	if(t==NULL)
		return NULL;
	r_BSTreeToSet(t->left,s);
	insertSet(s,t->value);
	r_BSTreeToSet(t->right,s);
	insertSet(s,t->value);

	return s;
}
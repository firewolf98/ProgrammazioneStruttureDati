#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"
#include "BTree.h"

static int verificaBST(BTree t, int min, int max);

struct node{
	item value;
	struct node *left;
	struct node *right;
};

BTree newBTree()
{
	return NULL;
}

int emptyBTree(BTree t)
{
	return t==NULL;
}

item getRoot(BTree t)
{
	if(t!=NULL)
		return t->value;
	else 
		return NULLITEM;
}

BTree leftBTree(BTree t)
{
	if(t!=NULL)
		return t->left;
	else
		return NULL;
}

BTree rightBTree(BTree t)
{
	if(t!=NULL)
		return t->right;
	else
		return NULL;
}

BTree consBTree(item val, BTree left, BTree right)
{
	struct node *nuovo = malloc(sizeof(struct node));

	if(nuovo!=NULL){
		nuovo->value = val;
		nuovo->left = left;
		nuovo->right = right;
	}

	return nuovo;
}

//----------------------------------

int height_BTree(BTree t)
{
	int altezza_sinistro, altezza_destro;

	if(t==NULL)
		return 0;
	else
		if(height_BTree(t->left)>height_BTree(t->right))
			return 1+height_BTree(t->left);

		else
			return 1+height_BTree(t->right);
}


int isBSTree(BTree t)
{
	if(t==NULL)
		return 1;

	return verificaBST(t,-1,-1);
}

static int verificaBST(BTree t, int min, int max)
{
	if(t==NULL)
		return 1;

	if(min!=-1 && getRoot(t) < min)
		return 0;
	if(max!=-1 && getRoot(t) > max)
		return 0;

	return (verificaBST(leftBTree(t), min, getRoot(t)) && verificaBST(rightBTree(t),getRoot(t),max));
}
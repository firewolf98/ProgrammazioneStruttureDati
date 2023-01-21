#include <stdlib.h>
#include "item.h"
#include "../queue.h"
#include "BTree.h"

struct btree{
	item root;
	BTree left;
	BTree right;
};

BTree newBTree (){
	return NULL;
}

int emptyBtree ( BTree tree ){
	return tree == NULL;
}

item getRoot ( BTree t ){
	if ( t == NULL )
		return NULLITEM;
	return ( t->root );
}

BTree leftBTree ( BTree t ){
	if ( t != NULL )
		return t->left;
	return NULL;
}

BTree rightBTree ( BTree t ){
	if ( t != NULL )
		return t->right;
	return NULL;
}

BTree consBTree ( item r, BTree tsx, BTree tdx ){
	BTree new = malloc(sizeof(BTree));
	
	if ( new != NULL ){
		new->root = r;
		new->left = tsx;
		new->right = tdx;
	}
	
	return new;
}

void inOrder (BTree t){
	if ( !emptyBTree(t) ){
		inOrder(t->left);
		outputItem(getRoot(t));
		inOrder(t->right);
	}
}

void preOrder ( BTree t ){
	if ( !emptyBTree(t) ){
		outputItem(getRoot(t));
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder ( BTree t ){
	if ( !emptyBTree(t) ){
		postOrder( t->left );
		postOrder( t->right );
		outputItem( getRoot(t));
	}
}

//-----------------------------------------------------------------------------------------------
//		DICHIARO E IMPLEMENTO LA STRUCT CODA CHE UTILIZZA L'ALBERO COME ITEM		|
//-----------------------------------------------------------------------------------------------

struct node{
	BTree value;
	struct node *next;
};

struct t_queue{
	struct node *head, *tail;
	int size;
};

struct t_queue *newQueuet (){
	struct t_queue *new = malloc(sizeof(struct t_queue));
	
	if ( new != NULL ){
		new->size = 0;
		new->head = new->tail = NULL;
	}
}

int emptyQueuet ( struct t_queue *q ){
	if ( q == NULL )
		return -1;
	return ( q->size == 0 );
}

int enqueuet ( struct t_queue *q, BTree t ){

	if ( q == NULL )
		return -1;
		
	struct node *nuovo = malloc(sizeof(struct node));
	
	nuovo->value = t;
	
	if ( nuovo == NULL )
		return -1;
		
	if ( q->head == NULL )
		q->head = nuovo;
	else
		q->tail->next = nuovo;
	
	q->tail = q->tail->next;
	(q->size)++;
	return 1;
}

BTree dequeuet ( struct t_queue *q){
	
	if ( q == NULL )
		return NULL;
		
	if ( q->head == NULL )
		return NULL;
		
	BTree result = q->head->value;
	struct node *temp = q->head;
	
	q->head = q->head->next;
	free(temp);
	
	if ( q->head == NULL )
		q->tail = NULL;
		
	q->size--;
	
	return result;
}	
//-------------------------------------------------------------------------------------------------------
//						FINE							|
//-------------------------------------------------------------------------------------------------------
void levelOrder ( BTree t ){
	BTree tsx, tdx, res;
	struct t_queue *q = newQueuet();
	
	enqueuet(q, t);
	
	while (!(emptyQueuet(q))){
		res = dequeuet(q);
		outputItem(getRoot(res));
		tsx = leftBTree( res );
		tdx = rightBTree( res );
		if ( tsx != NULL ) 
			enqueuet( q, tsx );
		if ( tdx != NULL )
			enqueuet( q, tdx );
	}
}

BTree reverse ( queue pre, queue in ){
	if (emptyQueue(in)) return NULL;

	queue new = newQueue();
	item root = dequeue(pre), temp = dequeue(in);
	
	while (cmpItem(root, temp) != 0 ){
		enqueue(temp, new);
		temp = dequeue(in);
	}
	BTree sx, dx;
	sx = reverse(pre, in);
	dx = reverse(pre, in);
	return consBTree(root, sx, dx);
}



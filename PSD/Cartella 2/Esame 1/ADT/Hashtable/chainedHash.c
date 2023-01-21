#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"
#include"chainedHash.h"

struct hash{
	int size;
	struct elem **table;
};

struct elem{
	char key[20];
	item val;
	struct elem *next;
};




static void deleteList(struct elem *p);
static void outputList(struct elem *l);



int hash(char *k, int m){
	int val;
	int len=strlen(k);
	val=k[0]+k[len-1]+len;
	return (val%m);
}

hashtable newHashtable(int size){
	struct hash *h=malloc(sizeof(struct hash));
	int i;
	h->size=size;
	h->table=(struct elem**)malloc(size*sizeof(struct elem *));
	
	for (i=0;i<size;i++)
		h->table[i]=NULL;
	return h;
}


static struct elem * createElem(char k[], item x);

static struct elem * createElem(char k[], item x){
	struct elem *e=malloc(sizeof(struct elem));
	if (e!=NULL){
		strcpy(e->key, k);
		e->val=x;
	}
	return e;
}

int insertHash(hashtable h, item x){
	int idx;
	struct elem *head, *curr;
	struct elem *e=createElem(getKey(x), x);
	idx=hash(e->key, h->size);
	curr=head=h->table[idx];
	
	while(curr){
		if (!strcmp(e->key, curr->key))
			return -1;	
		else curr=curr->next;
	}
	
	h->table[idx]=e;
	h->table[idx]->next=head;
	return 1;
}


item searchHash(hashtable h, char *key){
	int idx;
	struct elem *curr;
	idx=hash(key, h->size);
	curr=h->table[idx];

	while(curr){
		if (!strcmp(key, curr->key))	
			return curr->val;
		else curr=curr->next;
	}
	return NULL;
}

int deleteHash(hashtable h, char *key){
	int idx;
	struct elem *prev, *curr, *head;
	idx=hash(key, h->size);
	prev=curr=head=h->table[idx];
	
	while(curr){
		if (!strcmp(key, curr->key)){
			if (curr==head)
				h->table[idx]=curr->next;
			else
				prev->next=curr->next;
			return 1;
		}
		prev=curr;
		curr=curr->next;
	}
	return 0;
}

void destroyHash(hashtable h){
	int i;
	for (i=0;i<h->size;i++)
		deleteList(h->table[i]);
	free(h->table);
	return;
}

static void deleteList(struct elem *p){
	if (p==NULL) return;
	deleteList(p->next);
	free(p);
}


void outputHash(hashtable h){
	int i;
	if (h!=NULL){
		for (i=0;i<h->size;i++)
			outputList(h->table[i]);
	}
}

static void outputList(struct elem *l){
	if (l==NULL) return;
	outputList(l->next);
	output_item(l->val);
}
	

	

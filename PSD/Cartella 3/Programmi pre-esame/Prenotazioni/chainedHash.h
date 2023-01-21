/*
•Specifica sintattica
– Tipo di riferimento: hashtable
– Tipi usati: item, boolean, key

Usiamo un tipo generico item contenente un attributo chiave di tipo Key

•Specifica semantica del tipo di riferimento
– hashtable è l’insieme di elementi T={a1,a2,...,an} di tipo item
– Un item contiene un campo chiave di tipo key e dei dati associati


•Specifica sintattica (Operatori)
newHashTable() → hashtable
insertHash(item, hashtable) → boolean
searchHash(key, hashtable) → item
deleteHash(key, hashtable) → boolean


•Specifica semantica (Operatori)
– newHashtable() → t
	• Post: t = {}

– insertHash(e, t) → t’
	• Post: t = {a1, a2, ... an}, t’ = {a1, a2, ..., e,..., an}

– deleteHash(k,t) → t’
	• Pre: t = {a1, a2, ..., an} n>0, a i ->key=k con 1 ≤ i ≤ n
	• Post: l’ = <a1, a2, ..., a i-1 , a i+1 , ..., an>

– searchHash(k,t) → e
	• Pre: t = {a1, a2, ..., an} n>0
	• Post: e = a i con 1 ≤ i ≤ n se a i ->key=k
*/


#include "item.h"
typedef struct hash *hashtable;
typedef struct elem *elem;

int hash(char *k, int m);

hashtable newHashtable(int size);

int insertHash(hashtable h, item x);

item searchHash(hashtable h, char *key);

int deleteHash(hashtable h, char *key);

void destroyHash(hashtable h);

void outputHash(hashtable h);
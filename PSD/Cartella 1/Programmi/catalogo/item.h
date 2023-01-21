typedef struct esame *item;

#define NULLITEM NULL

item newItem ( char nome[], int val, char date[] );
item inputItem (); //alloca item e lo riempie
void outputItem ( item a ); //stampa un item
int eq( item a, item b ); //confronta se due item sono uguali
void destroyItem( item *a ); //dealloca un item

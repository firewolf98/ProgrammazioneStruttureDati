typedef struct prenotazione *item;

#define NULLITEM NULL

item NewPrenotazione ( char cogn[], char nome[], char cod_fisc[], int num_pren);
item InputPren(int num_pren); //alloca item e lo riempie
void outputItem ( item a ); //stampa un item
//int eq( item a, item b ); //confronta se due item sono uguali
//void destroyItem( item *a ); //dealloca un item
int *getKey(item x);

/*Specifica sintattica
tipo: esame
tipi utilizzati: stringa, intero, data

operatori
newEsame(stringa, intero, data)->esame
getCorso(esame)->stringa


Specifica semantica
Esame è l'insieme delle triple formate da corso, voto e data


Operatori
newEsame(corso, voto, data)->e
Post: e=(corso, voto, data)

getCorso(e)->corso
Post: e=(corso, voto, data)


Per semplicità la data verrà rappresentata con una stringa GG/MM/AAAA*/

typedef struct esame *item;
#define NULLITEM NULL

item newItem(char *nome, int voto, char *date);

char *getCorso(item e);

item input_item();

void output_item(item e);

item cloneItem(item e);

int eq(item a, item b);

int getVoto(item e);








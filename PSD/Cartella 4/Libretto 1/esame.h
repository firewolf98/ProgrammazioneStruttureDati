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

typedef struct esame *esame;
#define NULLEXAM NULL

esame newEsame(char *nome, int voto, char *date);

char *getCorso(esame e);

esame inputEsame();

void outputEsame(esame e);

esame cloneEsame(esame e);








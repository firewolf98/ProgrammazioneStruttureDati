#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20


typedef struct pokemon{
char nome[MAX];
char tipo[MAX];
int numero;
int livello;}pokemon;


void inserisci(pokemon*);
void ricerca(pokemon*);
void stampa(pokemon*);
